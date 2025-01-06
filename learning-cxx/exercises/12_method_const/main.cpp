#include "../exercise.h"

// READ: 有 cv 限定符的成员函数 <https://zh.cppreference.com/w/cpp/language/member_functions>

struct Fibonacci {
    int numbers[11];
    // TODO: 修改方法签名和实现，使测试通过
    int get(int i) const {  // const 限定符，表示该方法不会修改对象的状态
        return numbers[i];
    }
};

int main(int argc, char **argv) {
    Fibonacci constexpr FIB{{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55}}; // 常量对象，编译时常量，允许在编译时计算表达式的值
    ASSERT(FIB.get(10) == 55, "fibonacci(10) should be 55");    // FIB是一个常量对象，只能调用常量成员函数，因此需要在 get 方法后加上 const 限定符
    std::cout << "fibonacci(10) = " << FIB.get(10) << std::endl;
    return 0;
}
