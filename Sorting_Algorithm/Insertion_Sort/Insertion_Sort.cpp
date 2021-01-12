//3.插入排序(Insertion Sort)
/*
原理：对未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
3.1算法描述
    1.取出下一元素，在已排序元素序列从后向前扫描
    2.如果已排序元素大于新元素，已排序元素往后移一位
    3.重复步骤2，直到找到已排序元素小于等于新元素
    4.将新元素插入到改位置后
    5.重复步骤2~4
3.2
    平均 | 最坏 时间复杂度：O(n²)
    最好 时间复杂度：O(n)
    空间复杂度： O(1)
    稳定排序算法
*/
#include <vector>
#include <iostream>
using namespace std;
//打印函数
void print_vector(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << "a[" << i << "]=" << a[i] << " ";
    }
    cout << endl;
}
//数组初始化
void init_vector(vector<int> &a)
{
    a.push_back(7);
    a.push_back(9);
    a.push_back(2);
    a.push_back(16);
    a.push_back(8);
    a.push_back(5);
    a.push_back(12);
    a.push_back(13);
    a.push_back(14);
} //7 9 2 16 8 5 12 13 14

void InsertSort(vector<int> &nums)
{
    int pre, current;//pre下标，current-1向前遍历元素 current指向当前元素
    for (int i = 1; i < nums.size(); i++)//默认第一个元素为已排序元素，从第二个元素开始
    {
        pre=i-1;
        current=nums[i];
        //已排序元素i-1，从前向后扫描
        while (pre >= 0 && nums[pre] > current)
        {
            nums[pre + 1] = nums[pre];//往后移一位
            pre--;
        }//找到最左的一个比当前元素大的位置记录下（即pre+1），并将该元素后移一位
        nums[pre + 1] = current;//在该位置下插入当前元素
    }
}

int main()
{
    vector<int> a;
    init_vector(a);
    cout << "nums to be sorted :" << endl;
    print_vector(a);
    cout << "insert sort :" << endl;
    InsertSort(a);
    print_vector(a);
}