#include "../exercise.h"
#include <memory>

// READ: `std::shared_ptr` <https://zh.cppreference.com/w/cpp/memory/shared_ptr>
// std::shared_ptr 是一种通过指针保持对象共享所有权的智能指针。多个 shared_ptr 对象可持有同一对象。

// READ: `std::weak_ptr` <https://zh.cppreference.com/w/cpp/memory/weak_ptr>
// std::weak_ptr 是一种不增加对象引用计数的智能指针，它指向一个由 std::shared_ptr 管理的对象。

// TODO: 将下列 `?` 替换为正确的值
int main(int argc, char **argv) {
    auto shared = std::make_shared<int>(10);    // 创建一个 shared_ptr 对象，指向一个 int 类型的对象，值为 10
    std::shared_ptr<int> ptrs[]{shared, shared, shared};    // 创建一个 shared_ptr 对象数组，每个元素都指向 shared_ptr 对象 shared

    std::weak_ptr<int> observer = shared;   // 创建一个 weak_ptr 对象，指向 shared_ptr 对象 shared
    ASSERT(observer.use_count() == 4, "");  // use_count() 返回 shared_ptr 对象的引用计数
    
    ptrs[0].reset();
    ASSERT(observer.use_count() == 3, "");

    ptrs[1] = nullptr;
    ASSERT(observer.use_count() == 2, "");

    ptrs[2] = std::make_shared<int>(*shared);   // 将 ptr[2] 指向一个新的 shared_ptr 对象
    ASSERT(observer.use_count() == 1, "");

    ptrs[0] = shared;
    ptrs[1] = shared;
    ptrs[2] = std::move(shared);
    ASSERT(observer.use_count() == 3, "");

    std::ignore = std::move(ptrs[0]);
    ptrs[1] = std::move(ptrs[1]);
    ptrs[1] = std::move(ptrs[2]);
    ASSERT(observer.use_count() == 2, "");

    shared = observer.lock();
    ASSERT(observer.use_count() == 3, "");

    shared = nullptr;
    for (auto &ptr : ptrs) ptr = nullptr;
    ASSERT(observer.use_count() == 0, "");

    shared = observer.lock();
    ASSERT(observer.use_count() == 0, "");

    return 0;
}
