#include "../exercise.h"
#include <array>
#include <cstring>

// READ: std::array <https://zh.cppreference.com/w/cpp/container/array>
// std::array 是一个模板结构体，需要指定元素类型和数组大小
// std::array 的大小是固定的，不支持动态改变大小
// std::array 的大小可以通过 size() 获取
// std::array 的元素可以通过 data() 获取指针
// std::array 的元素可以通过 [下标] 或 at() 访问元素
// std::array 的元素可以通过 at() 访问，如果下标越界会抛出异常
// std::array 的元素可以通过 front() 获取第一个元素
// std::array 的元素可以通过 back() 获取最后一个元素
// std::array 的元素可以通过 fill() 填充  a.fill(0);
// std::array 支持迭代器
// std::array 支持比较操作符
// std::array 支持 swap() 交换两个数组  a.swap(b);


// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::array<int, 5> arr{ {1, 2, 3, 4, 5} };   // 初始化一个包含5个元素的数组（魔板结构体） 
        ASSERT(arr.size() == 5, "Fill in the correct value.");
        ASSERT(sizeof(arr) == 20, "Fill in the correct value.");
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(arr.data(), ans, sizeof(int)*5) == 0, "Fill in the correct values.");
    }
    {
        std::array<double, 8> arr;
        ASSERT(arr.size() == 8, "Fill in the correct value.");
        ASSERT(sizeof(arr) == 64, "Fill in the correct value.");
    }
    {
        std::array<char, 21> arr{"Hello, InfiniTensor!"};
        ASSERT(arr.size() == 21, "Fill in the correct value.");
        ASSERT(sizeof(arr) == 21, "Fill in the correct value.");
        ASSERT(std::strcmp(arr.data(), "Hello, InfiniTensor!") == 0, "Fill in the correct value.");
    }
    return 0;
}
