/*
unordered_map是一种关联容器，存储(Key,Value)键值对组成的元素。
允许根据其Key值快速检索各个元素。key值唯一。
在容器内部，元素没有按照Key值与Value值的任何顺序排序。
而是使用Hash table实现，提供给map的Key被哈希到Hash table的索引中。
从Hash table中搜索、插入和删除的平均时间复杂度都为O(1)。

底层实现上，使用一个和下标范围比较大的数组来存储元素，形成很多桶。
利用hash函数对key进行映射到不同区域保存。
at(Key) 返回Key对应的Value 
begin() 返回正向迭代器起始位置
end()   返回正向迭代器终点位置
bucket(key) 返回Key对应Value所在的桶号。
bucket_count    桶的数目，桶号编号[0,bucket_count-1]
bucket_size     返回unordered_map每个存储桶中的元素数
m.count(key)  计算下标为n的位置有无数据，有1，无0
equal_range() 返回pair对象，其first和second成员都是迭代器。
分别指向输入序列所有值=key的元素所组成的子序列的起始及末尾位置。
实际上，first成员的值等同lower_bound的返回，second成员的值等同upper_bound的返回
claer() 清除所有元素
erase() 与map操作相同
insert() 与map操作相同
merge(m1,m2) 移动两个unordered_map
*/

#include <unordered_map>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void init_unordered_map(unordered_map<string, int> &um)
{
    um["Stephen_xu"] = 0;
    um["dan_bing_gou_liang"] = 2;
    um.insert({"Github", 1});
}

void printFrequence(string s) //使用unordered_map进行计数存储
{
    //每个词存在一个Key里，Value是词的出现次数
    unordered_map<string, int> wordf;

    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        wordf[word]++;
    }
    unordered_map<string, int>::iterator it;
    for (it = wordf.begin(); it != wordf.end(); it++)
    {
        cout << "(" << it->first << ", " << it->second << ")" << endl;
    }
}
int main()
{
    unordered_map<string, int> m1;
    init_unordered_map(m1);
    for (auto it : m1)
    {
        cout << it.first << '\t' << it.second << endl;
    }
    cout << endl;

    m1.insert(make_pair("lne", 1));
    string key = "Github";
    if (m1.find(key) == m1.end())
    {
        cout << "Not found " << key << endl;
    }
    else
    {
        cout << "Found " << key << endl;
    }
    key = "Pin_duo_duo";
    if (m1.find(key) == m1.end())
    {
        cout << "Not found " << key << endl;
    }
    else
    {
        cout << "Found " << key << endl;
    }
    cout << endl;

    //创建迭代器
    unordered_map<string, int>::iterator it;
    cout << "All Elements:" << endl;
    for (it = m1.begin(); it != m1.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;

    //等号是否为深拷贝
    unordered_map<string, int> m2 = m1;
    m2.erase(m2.begin());
    m2.erase("lne");
    cout << "m2.size(): " << m2.size() << endl; //2
    cout << "m1.size(): " << m1.size() << endl; //4!=2 为深拷贝
    cout << endl;

    //测试equal_range函数
    auto it2 = m1.equal_range("Github");
    cout << "[" << it2.first->first << "," << it2.second->first << "]" << endl;
    cout << endl;

    //使用unordered_map存储计数
    string str = "bilibili is the best animation website cheers bilibili in the best way";
    printFrequence(str);

    return 0;
}

/*
1.hash_map VS unordered_map
    两个内部结构都为Hash table。
    但是unordered_map在C++11的时候被引入标准库了，而hash_map没有。
    故建议使用unordered_map。
    Hash table的查询平均时间是O(1)。
    unordered：数据是按散列函数插入到桶里的，数据之间无顺序。

2.map VS unordered_map
    内部结构不同：
        map是红黑树，保证了一个稳定的动态操作时间，查询、插入、删除都是O(logn)。
        unordered_map是哈希表,查询O(1),但是建立比较耗时。
    用途：
        当数据要求是有顺序时，建议使用map。
            红黑树每个节点都要额外保存父子节点以及红黑性质，占用大量空间。
        当大量数据且都是用来查询时，建议使用unordered_map

3.unordered_set VS unordered_map
    unordered_set就是在哈希表插入Key,没有Value。
    这些键用于查看元素是否存在，无法存储计数。
    unordered_map是键值对。
    (空间弥补时间，unordered_set查询时间因为是哈希表实现，故O（1)。)
*/