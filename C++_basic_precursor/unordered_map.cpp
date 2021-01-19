/*
unordered_map是一种关联容器，存储(Key,Value)键值对组成的元素。
允许根据其Key值快速检索各个元素。key值唯一。
在容器内部，元素没有按照Key值与Value值的任何顺序排序。
而是使用Hash table实现，提供给map的Key被哈希到Hash table的索引中。
从Hash table中搜索、插入和删除的平均时间复杂度都为O(1)。

at()
begin()
end()
bucket()
bucket_count
bucket_size
count()
equal_range

*/

#include <unordered_map>
#include <iostream>
using namespace std;

void init_unordered_map(unordered_map<string, int> &um)
{
    um["Stephen_xu"] = 0;
    um["dan_bing_gou_liang"] = 2;
    um.insert({"Github", 1});
}

int main()
{
    unordered_map<string, int> m1;
    init_unordered_map(m1);
    for (auto it : m1)
    {
        cout << it.first << '\t' << it.second << endl;
    }
}

/*
1.hash_map VS unordered_map
    两个内部结构都采用Hash table实现，但是unordered_map在C++11的时候被引入标准库了，而hash_map没有。
    故建议使用unordered_map
    Hash table的查询平均时间是O(1)。
    unordered：数据是按散列函数插入到桶里的，数据之间无顺序科研。

2.map VS unordered_map
内部结构不同：
    map是红黑树，保证了一个稳定的动态操作时间，查询、插入、删除都是O(logn)
    unordered_map是哈希表

3.unordered_set VS unordered_map
    unordered_set就是在哈希表插入value，而不是unordered_map的键值对。
    (空间弥补时间，unordered_set查询时间因为是哈希表实现，故O（1)）

*/