#include "../exercise.h"
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>
// std::accumulate 用于计算范围内的元素的累加值
// std::accumulate(begin, end, init) 等价于 init + *begin + *(begin+1) + ... + *(end-1)
// std::accumulate(begin, end, init, op) 等价于 init op *begin op *(begin+1) op ... op *(end-1)

int main(int argc, char** argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    // TODO: 调用 `std::accumulate` 计算：
    //       - 数据类型为 float；
    //       - 形状为 shape；
    //       - 连续存储；
    //       的张量占用的字节数
    int size = std::accumulate(std::begin(shape), std::end(shape), 1, std::multiplies<int>());
    size *= sizeof(DataType); // 计算字节数
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
