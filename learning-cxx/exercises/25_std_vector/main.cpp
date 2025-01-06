#include "../exercise.h"
#include <cstring>
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector>
// std::vector 是一个模板类，需要指定元素类型
// std::vector 的大小是动态的，支持动态改变大小
// std::vector 的大小可以通过 size() 获取，表示当前元素个数
// std::vector 的容量可以通过 capacity() 获取，表示当前内存分配大小，大于等于 size()
// std::vector 是由3个指针组成的结构体，所以 sizeof(std::vector) == 24
// std::vector 的元素可以通过 data() 获取指针
// std::vector 的元素可以通过 [下标] 或 at() 访问元素



// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "Fill in the correct value.");
        // THINK: `std::vector` 的大小是什么意思？与什么有关？
        ASSERT(sizeof(vec) == 24, "Fill in the correct value.");    // std::vector 由3个指针：begin,end,end_capacity组成，共占用 3*8=24 Byte
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
    }
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        {
            ASSERT(vec.size() == 5, "Fill in the correct value.");
            ASSERT(sizeof(vec) == 24, "Fill in the correct value.");
            double ans[]{1, 2, 3, 4, 5};
            ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
        }
        {
            vec.push_back(6);
            ASSERT(vec.size() == 6, "Fill in the correct value.");
            ASSERT(sizeof(vec) == 24, "Fill in the correct value.");
            vec.pop_back();
            ASSERT(vec.size() == 5, "Fill in the correct value.");
            ASSERT(sizeof(vec) == 24, "Fill in the correct value.");
        }
        {
            vec[4] = 6;
            ASSERT(vec[0] == 1, "Fill in the correct value.");
            ASSERT(vec[1] == 2, "Fill in the correct value.");
            ASSERT(vec[2] == 3, "Fill in the correct value.");
            ASSERT(vec[3] == 4, "Fill in the correct value.");
            ASSERT(vec[4] == 6, "Fill in the correct value.");
        }
        {
            // THINK: `std::vector` 插入删除的时间复杂度是什么？
            // 插入的时间复杂度是 O(n)，因为 std::vector 为了高效的随机访问，数据是连续存储的
            vec.insert(vec.begin() + 1, 1.5);
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 6}), "Make this assertion pass.");
            vec.erase(vec.begin()+3);
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 4, 6}), "Make this assertion pass.");
        }
        {
            vec.shrink_to_fit();    // 调整 std::vector 的容量，以使其大小正好等于当前的元素个数。
            ASSERT(vec.capacity() == 5, "Fill in the correct value.");
            vec.clear();
            ASSERT(vec.empty(), "`vec` is empty now.");
            ASSERT(vec.size() == 0, "Fill in the correct value.");
            ASSERT(vec.capacity() == 5, "Fill in the correct value.");
        }
    }
    {
        std::vector<char> vec(48, 'z'); // TODO: 调用正确的构造函数
        ASSERT(vec[0] == 'z', "Make this assertion pass.");
        ASSERT(vec[47] == 'z', "Make this assertion pass.");
        ASSERT(vec.size() == 48, "Make this assertion pass.");
        ASSERT(sizeof(vec) == 24, "Fill in the correct value.");
        {
            auto capacity = vec.capacity();
            vec.resize(16);
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            ASSERT(vec.capacity() == 48, "Fill in a correct identifier.");
        }
        {
            vec.reserve(256);
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            ASSERT(vec.capacity() == 256, "Fill in the correct value.");
        }
        {
            vec.push_back('a');
            vec.push_back('b');
            vec.push_back('c');
            vec.push_back('d');
            ASSERT(vec.size() == 20, "Fill in the correct value.");
            ASSERT(vec.capacity() == 256, "Fill in the correct value.");
            ASSERT(vec[15] == 'z', "Fill in the correct value.");
            ASSERT(vec[16] == 'a', "Fill in the correct value.");
            ASSERT(vec[17] == 'b', "Fill in the correct value.");
            ASSERT(vec[18] == 'c', "Fill in the correct value.");
            ASSERT(vec[19] == 'd', "Fill in the correct value.");
        }
    }

    return 0;
}
