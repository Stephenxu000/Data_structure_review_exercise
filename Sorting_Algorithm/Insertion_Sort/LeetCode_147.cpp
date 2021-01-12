/*
https://leetcode-cn.com/problems/insertion-sort-list/

Sort a linked list using insertion sort.
来源：力扣（LeetCode）
*/
//Definition for singly-linked list.
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*版本1  数组思维交换值
不考虑链表的指针独特性，强行用数组的思维交换值，没有指针的操作。
runtime 80ms | 内存消耗 9.8MB
*/
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        /*
        题目分析：列表只有next，而不能随机遍历。即不能向前遍历。
        传统的插入排序是从前开始，后一个元素向前遍历所有元素一一比较（后移），直到找到最左的一个比他大的元素插入。
        我们不能向前遍历，只能向后遍历。
        */
        if (head == nullptr)
            return head;
        ListNode *current = head->next, *pre, *ppre; //ppre辅助记录pre->pre,即pre前一个节点，为插入点
        int ppre_value, pre_value;
        while (current != nullptr)
        {
            ppre = nullptr;
            pre = head;
            int time = 0;
            //从head开始找，找到一个比它大的元素，直接插它前面
            while (pre != current) //遍历[0,current]找第一个大元素
            {

                if (time == 1)
                {
                    break; //已找到
                }
                if (current->val < pre->val)
                {
                    ppre = pre; //找到插入点
                    time++;
                }
                pre = pre->next;
            } //找到最左一个比他大的元素,插入位置为ppre；
            if (ppre != nullptr)
            {
                //ppre->val=current->val，而[ppre,current-1]的值都后移一位
                ppre_value = ppre->val;
                ppre->val = current->val;
                while (pre != current->next)
                {
                    pre_value = pre->val;
                    pre->val = ppre_value; //数值后移
                    ppre_value = pre_value;
                    ppre = pre;
                    pre = pre->next;
                }
            }
            current = current->next;
        }
        return head;
    }
};
/*
版本1 每次操作都要将链表的值一次一次往后移动，没有考虑到链表的特性。
如果是指针操作，只要把current后面所有待排序的点插入到最后一个已排序的点后。
再将current点插入到插入点（最左的一个比它大的元素）之后。
重复节点数-1次即可排序完毕。
*/
/*
版本2 指针操作版
runtime 20ms | 内存消耗 9.7MB
*/
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        /*
        题目分析：列表只有next，而不能随机遍历。即不能向前遍历。
        传统的插入排序是从前开始，后一个元素向前遍历所有元素一一比较（后移），直到找到最左的一个比他大的元素插入。
        */
        if (head == nullptr)
            return head;
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head; //创造哑节点，便于在head节点之前插入结点
        ListNode *lastSorted = head;
        ListNode *current = head->next, *pre; //pre为插入点
        while (current != nullptr)
        {
            if (lastSorted->val <= current->val)
            {
                lastSorted = lastSorted->next;
            } //已有序，lastSort指向最后一个有序结点
            else
            {
                pre = dummyHead;
                //从哑结点开始找，找到一个比它大的元素，直接插它前面,pre即为插入点。
                while (pre->next->val <= current->val)
                {
                    pre = pre->next;
                }                                 //遍历找插入点
                lastSorted->next = current->next; //未排序结点插入到已排序节点后
                current->next = pre->next;
                pre->next = current; //这两步即将current插入到pre之后，建议理解并背下指针插入操作
            }
            current = lastSorted->next; //遍历下一个未排序结点
        }
        return dummyHead->next;
    }
};