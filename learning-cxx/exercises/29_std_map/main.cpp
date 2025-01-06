#include "../exercise.h"
#include <map>

// READ: `std::map` <https://zh.cppreference.com/w/cpp/container/map>
// READ: `std::unordered_map` <https://zh.cppreference.com/w/cpp/container/unordered_map>

// std::map 用法：
// 初始化1：`std::map<k, v> map;` 或 `std::map<k, v> map{{key1, value1}, {key2, value2}};`
// 初始化2：`std::map<k, v> map = other_map;` 拷贝构造函数，C++11标准还支持移动构造函数
// 初始化3：`std::map<k, v> map(other_map.begin()+5, other_map.end()-2);` 通过迭代器初始化部分元素
// 使用 `map[key]` 访问键值对，如果 key 不存在，会自动插入一个默认值
// 使用 `map.find(key) != map.end()` 判断 key 是否存在
// 使用 `map.insert_or_assign(key, value)` 插入或更新键值对
// 使用 `map.erase(key)` 删除键值对
// 使用 `map.size()` 获取键值对数量
// 使用 `map.clear()` 清空所有键值对
// 使用 `map.begin()` 和 `map.end()` 遍历所有键值对
// 使用 `map[key]` 访问键值对时，如果 key 不存在，会自动插入一个默认值

template<class k, class v>
bool key_exists(std::map<k, v> const &map, k const &key) {
    // TODO: 实现函数
    return map.find(key) != map.end();
}


template<class k, class v>
void set(std::map<k, v> &map, k key, v value) {
    // 使用 insert_or_assign 方法插入或更新键值对
    map.insert_or_assign(key, value);
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    using namespace std::string_literals;
    std::map<std::string, std::string> secrets;

    set(secrets, "hello"s, "world"s);
    ASSERT(key_exists(secrets, "hello"s), "\"hello\" shoud be in `secrets`");
    ASSERT(!key_exists(secrets, "foo"s), "\"foo\" shoud not be in `secrets`");

    set(secrets, "foo"s, "bar"s);
    set(secrets, "Infini"s, "Tensor"s);
    ASSERT(secrets["hello"] == "world", "hello -> world");
    ASSERT(secrets["foo"] == "bar", "foo -> bar");
    ASSERT(secrets["Infini"] == "Tensor", "Infini -> Tensor");

    set(secrets, "hello"s, "developer"s);
    ASSERT(secrets["hello"] == "developer", "hello -> developer");

    return 0;
}
