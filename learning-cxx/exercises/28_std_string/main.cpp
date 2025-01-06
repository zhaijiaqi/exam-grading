#include "../exercise.h"
#include <string>

// READ: 字符串 <https://zh.cppreference.com/w/cpp/string/basic_string>

int main(int argc, char **argv) {
    // READ: 字符串字面量 <https://zh.cppreference.com/w/cpp/string/basic_string/operator%22%22s>
    using namespace std::string_literals;   // 使用字符串字面量，允许使用更加简洁的方式创建std::string对象
    auto hello = "Hello"s;  // 可以直接使用后缀`s`创建std::string对象
    auto world = "world";   // 字符串字面量会被隐式转换为const char*类型
    // READ: `decltype` 表达式 <https://zh.cppreference.com/w/cpp/language/decltype>
    // READ: `std::is_same_v` 元编程判别 <https://zh.cppreference.com/w/cpp/types/is_same>
    ASSERT((std::is_same_v<decltype(hello), std::string>), "Fill in the missing type.");
    ASSERT((std::is_same_v<decltype(world), const char*>), "Fill in the missing type.");
    // TODO: 将 `?` 替换为正确的字符串
    ASSERT(hello + ", " + world + '!' == "Hello, world!", "Fill in the missing string.");
    return 0;
}
