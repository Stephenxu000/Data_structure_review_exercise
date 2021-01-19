/*
map是一种键值对容器.
每一对第一个值：key(关键字)
每个key只能在map中出现一次
第二个值成为该key的对应值
map的内部结构是R-B-tree(红黑树）实现的，保证了一个稳定的动态操作时间。
查询/插入/删除都是O(logn)。(Hashmap通过哈希表实现，建立耗时，但查询是O(1))
基本功能：
begin() 返回指向map头部的迭代器
end()   返回指向map末尾的迭代器
size()  返回map中元素的个数
max size()  返回map中元素的个数
empty() 为空返true
insert(pair<xxx,xxx>(key,value))    插入元素 
erase(iterator position)    删除迭代器指向的元素
erase(const g)  删除键值为'g'的元素
clear() 删除map中的所有元素

count() 返回指定对应值出现的次数
equal_range()   返回特殊条目的迭代器对
find()  查找元素
get_allocator() 返回map配置器
key_comp()  返回比较元素key的函数
lower_bound()   返回键值>=给定元素的第一个位置
upper_bound()   返回键值>给定元素的第一个位置
max_size() 返回可以容纳的最大元素个数
rbegin()    返回一个指向map尾部逆向迭代器
rend()  返回一个指向map头部逆向迭代器
swap()  交换两个map，而非一个容器中的元素交换
*/

#include <map>
#include <iostream>
#include <iterator>
using namespace std;
void init_map1(map<int, int> &m)
{
    //不能通过m.insert(1,40)插入键值对，主要方法有3
    m.insert(pair<int, int>(1, 40)); //方式1
    m.insert(pair<int, int>(6, 30)); //map中的元素是自动按KEY升序排序，所以不能对map用sort函数
    m.insert(pair<int, int>(3, 50));
    m.insert(pair<int, int>(4, 20));
    m.insert(map<int, int>::value_type(5, 60)); //方式2
    m[2] = 30;                                  //方式3
}

void print_map1(map<int, int> m)
{
    //前向迭代器遍历方式
    map<int, int>::iterator it;
    cout << "(iterator)The map is:\n";
    cout << "\tKEY\tELEMENT\n";
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << '\t' << it->first << '\t' << it->second << '\n';
    }
    cout << endl;
}

void print_map2(map<int, int> m)
{
    //反向迭代器遍历方式
    map<int, int>::reverse_iterator rit;
    cout << "(reverse_iterator)The map is:\n";
    cout << "\tKEY\tELEMENT\n";
    for (rit = m.rbegin(); rit != m.rend(); rit++)
    {
        cout << '\t' << rit->first << '\t' << rit->second << '\n';
    }
    cout << endl;
}

int main()
{
    map<int, int> m1;
    init_map1(m1);
    print_map1(m1);

    map<int, int> m2(m1.begin(), m1.end()); //方法1
    print_map2(m2);

    map<int, int> m3 = m1; //方法2
    print_map1(m3);

    cout << "m2:remove elements key=3:" << endl;
    int num = m2.erase(4); //删除了键=4的键值对
    print_map1(m2);
    cout << "m3:remove elements less than key=3:" << endl;
    m3.erase(m3.begin(), m3.find(3)); //删除了键=1、2的键值对
    //find没找到就返回指向map尾部的迭代器
    print_map1(m3);

    cout << "m1_elements_num:" << m1.size() << endl; //6
    cout << "m2_elements_num:" << m2.size() << endl; //5!=8,故深拷贝
    cout << "m3_elements_num:" << m3.size() << endl; //4!=8,故深拷贝

    cout << "m1.lower_bound(5) : ";
    cout << "KEY = " << m1.lower_bound(5)->first << '\t';
    cout << "ELEMENT = " << m1.lower_bound(5)->second << endl;

    cout << "m1.upper_bound(5) : ";
    cout << "KEY = " << m1.upper_bound(5)->first << '\t';
    cout << "ELEMENT = " << m1.upper_bound(5)->second << endl;

    m1.swap(m2);
    print_map1(m1);
    print_map1(m2);
    swap(m1, m3);
    print_map1(m1);
    print_map1(m3);

    return 0;
}