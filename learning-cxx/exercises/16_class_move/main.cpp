#include "../exercise.h"

// READ: 左值右值（概念）<https://learn.microsoft.com/zh-cn/cpp/c-language/l-value-and-r-value-expressions?view=msvc-170>
// READ: 左值右值（细节）<https://zh.cppreference.com/w/cpp/language/value_category>
// READ: 关于移动语义 <https://learn.microsoft.com/zh-cn/cpp/cpp/rvalue-reference-declarator-amp-amp?view=msvc-170#move-semantics>
// READ: 如果实现移动构造 <https://learn.microsoft.com/zh-cn/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=msvc-170>

// READ: 移动构造函数 <https://zh.cppreference.com/w/cpp/language/move_constructor>
// READ: 移动赋值 <https://zh.cppreference.com/w/cpp/language/move_assignment>
// READ: 运算符重载 <https://zh.cppreference.com/w/cpp/language/operators>

class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // TODO: 实现动态设置容量的构造器
    DynFibonacci(int capacity) : cache(new size_t[capacity]), cached(0) {
        if (capacity > 0) {
            cache[0] = 0;
        }
        if (capacity > 1) {
            cache[1] = 1;
            cached = 2;
        }
    }

    // TODO: 实现移动构造器
    // 移动构造函数（Move Constructor）是 C++11 引入的一种特殊构造函数，
    // 用于高效地“移动”资源（如动态内存、文件句柄等）从一个对象到另一个对象，而不是进行深拷贝。
    // noexcept 关键字表示移动构造函数不会抛出异常，这有助于优化代码。
    // 移动构造函数的主要作用是：
    // “窃取”资源：将源对象（other）的资源（如指针、文件句柄等）转移到新对象。
    // 置空源对象：将源对象的资源指针置为 nullptr，确保源对象析构时不会释放已转移的资源。
    DynFibonacci(DynFibonacci&& other) noexcept :
        cache(other.cache), cached(other.cached) {  // 窃取资源，避免深拷贝
        other.cache = nullptr;  // 置空源对象
        other.cached = 0;
    }

    // 移动构造函数与拷贝构造函数的区别
    // 特性	       移动构造函数	拷贝构造函数
    // 参数类型	    右值引用（ClassName&&）	常量左值引用（const ClassName&）
    // 资源管理	    窃取源对象的资源	    深拷贝源对象的资源
    // 源对象状态	源对象被置空	        源对象保持不变
    // 性能	       高效，避免深拷贝	        可能昂贵，涉及深拷贝

    // 左值：左值是指具有明确内存地址的表达式，通常可以出现在赋值操作的左侧。
    // 右值：右值是指不具有明确内存地址的表达式，不能被赋值，不能出现在赋值操作的左侧。

    // TODO: 实现移动赋值
    // NOTICE: ⚠ 注意移动到自身问题 ⚠
    DynFibonacci& operator=(DynFibonacci&& other) noexcept {
        if (this != &other) {   // 防止自我移动（如果other是自己的话，不用移动了）
            delete[] cache;
            cache = other.cache;
            cached = other.cached;
            other.cache = nullptr;
            other.cached = 0;
        }
        return *this;
    }

    // TODO: 实现析构器，释放缓存空间
    ~DynFibonacci(){
        delete[] cache;
    };

    // TODO: 实现正确的缓存优化斐波那契计算
    size_t operator[](int i) {      // [] 运算符重载
        if (i < cached) {
            return cache[i];
        }
        for (; cached<=i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }

    // NOTICE: 不要修改这个方法
    size_t operator[](int i) const {
        ASSERT(i <= cached, "i out of range");
        return cache[i];
    }

    // NOTICE: 不要修改这个方法
    bool is_alive() const {
        return cache;
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);                       // 调用有参构造函数
    ASSERT(fib[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci const fib_ = std::move(fib);   // 调用移动构造函数
    ASSERT(!fib.is_alive(), "Object moved");
    ASSERT(fib_[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci fib0(6);
    DynFibonacci fib1(12);

    fib0 = std::move(fib1);     // 调用移动赋值函数（因为fib0已经构造好了）
    fib0 = std::move(fib0);     // 检测自我移动
    ASSERT(fib0[10] == 55, "fibonacci(10) should be 55");

    return 0;
}
