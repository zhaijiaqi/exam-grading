#include "../exercise.h"

// READ: `static` 关键字 <https://zh.cppreference.com/w/cpp/language/storage_duration>
// THINK: 这个函数的两个 `static` 各自的作用是什么？
// ANSWER: 第一个 `static` 修饰的是函数的返回值，表示返回值是一个静态变量，只初始化一次。
//         第二个 `static` 修饰的是一个局部变量，表示这个变量是一个静态变量，只初始化一次。
static int func(int param) {
    static int static_ = param;     // 只初始化一次
    return static_++;
}

int main(int argc, char **argv) {
    // TODO: 将下列 `?` 替换为正确的数字
    ASSERT(func(5) == 5, "static variable value incorrect");
    ASSERT(func(4) == 6, "static variable value incorrect");
    ASSERT(func(3) == 7, "static variable value incorrect");
    ASSERT(func(2) == 8, "static variable value incorrect");
    ASSERT(func(1) == 9, "static variable value incorrect");
    return 0;
}
