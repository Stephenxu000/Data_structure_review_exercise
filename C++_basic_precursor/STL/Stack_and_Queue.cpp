/*
Stack是一种具有LIFO（后进先出）类型的容器适配器（container adapter）。
元素只能从栈顶插入。
Stack不能遍历，不提供迭代器。
empty() 返回栈是否空
size() 返回栈大小
top() 返回栈顶元素
push(x) 在栈顶增加元素
pop() 移除栈顶元素
*/

/*
Queue是一种具有FIFO（先进先出）类型的容器适配器。
元素插入队尾，从队首删除。
Queue不能遍历，不提供迭代器。
empty() 返回队列是否为空
size() 返回队列大小
swap() 元素交换
emplace() 参数为T的构造函数，在队尾生成对象
front() 返回队首
back() 返回队尾
push(x) 队尾增加元素
pop() 移除队首元素
*/

#include <stack>
#include <queue>
#include <iostream>
using namespace std;
void print_stack(stack<int> s)
{
    while (!s.empty())
    {
        cout << " " << s.top();
        s.pop();
    }
    cout << endl;
    return;
}

void print_queue(queue<int> q)
{
    while (!q.empty())
    {
        cout << " " << q.front();
        q.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> s;
    for (int i = 0; i < 5; i++)
    {
        s.push(i);
    }
    cout << "stack:";
    print_stack(s);
    cout << "s.size():" << s.size();
    cout << "\ns.top():" << s.top();
    cout << "\ns.pop():";
    s.pop();
    print_stack(s);

    queue<int> q;
    for (int i = 0; i < 5; i++)
    {
        q.push(i);
    }
    cout << endl;
    cout << "queue:";
    print_queue(q);
    cout << "q.size():" << q.size();
    cout << "\nq.front():" << q.front();
    cout << "\nq.back():" << q.back();
    cout << "\nq.pop():";
    q.pop();
    print_queue(q);

    //队列使用迭代器访问~
    /*
    为什么队列没有迭代器，但能通过迭代器访问呢？
    因为它有独特的front&back吗？
    */
    cout << "iterators:";
    for (auto i = q.front(); i <= q.back(); i++)
    {
        cout << i << " ";
    }
    /*
    auto 原理是根据后面值，来推测类型是什么。
         作用是简化变量初始化。
    */
    return 0;
}
/*
C++迭代器用于对数据结构中的元素进行顺序访问或随机访问。
因此，根据定义不允许顺序或随机访问的数据结构，迭代器没有意义。
这就是堆栈和队列没有迭代器的原因。
另一方面，vector和list运行对元素进行顺序/随机访问。迭代器有意义。
Stack类似一堆巨大的书，放书在顶部，要拿书，得把前面的书挪走。
Queue类型排队，不能插队，只能排在队尾，队首排完出队列。

*/