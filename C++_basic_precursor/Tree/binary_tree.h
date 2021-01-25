/**
* FILENAME:binary_tree.h
* @author:Stephen_xu
* @data:2021-01-20 16:01
**/

/*
树和二叉树是平行概念，两个不同的树形数据结构。
任何树都可以转化为二叉树处理。
*/

/*
二、二叉树
1.二叉树定义
    binary tree是结点的有限集合。
    它或为空集，或由一个根及两颗不相交的称为这个根的左右子树的二叉树组成。
    树与二叉树主要区别是：二叉树中结点的子树分成左子树和右子树，是有序的

2.二叉树性质(默认根层数为0)
    2.1 二叉树中层数为i的结点之多有2^i个
    2.2 高度为K的二叉树中至多有2^k+1-1(k>=0)个结点
    2.3 设T是由n个结点构成的二叉树，其中叶节点个数为n0,次数为2的结点个数n2，则有n0=n2+1
        n=n0+n1+n2
        n=E+1
        E=n1+2n2

3.满二叉树定义
    一棵非空高度为k(k>=0)的perfect binary tree(满二叉树),是有2^(k+1)-1个结点的二叉树
        ① 叶结点都在k层上
        ② 每个分支结点都有两个子结点
        ③ 叶结点的个数等于非叶节点个数加1

4.完全二叉树定义
    一颗包含n个结点高度为k的二叉树T，当按层次顺序编号T的所有结点，对应编号1~n。
        ① 树中只有最下面两层结点的度可以小于2.
        ② 树中最下面一层的结点都集中在该层最左边的若干位置上。
        ③ 树中叶结点只能在层数最大的两层上出现。
        ④ 仅编号最大的非叶结点可以没有右儿子，其余非叶结点都有两个儿子结点。
        ⑤ 树中所有结点对应都有两个儿子结点。
    编号i的结点有如下性质：(堆排序的大顶堆/小顶堆利用的就是完全二叉树这种数据结构)
        ① 若 i!=1 ,则父亲编号为floor(i/2)//取底板 与之相反是ceil取顶。
        ② 若 2i<=n ,则左儿子为2i，2i>n，i无左儿子。
        ③ 若 2i+1<=n 则右儿子为2i+1，否则i无右儿子
        ④ 高度为 logn
        ps:堆排序数组下标从0开始，而非从1开始编号。
*/

/*
1.二叉树顺序存储
按层次顺序存在一块地址连续的存储空间中。
类似堆排序中的数组。
但是比较适合完全二叉树(或近似)。
对非完全二叉树，会浪费大量存储空间。
*/
#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
//2.二叉树连接存储
//2.1
#include <iostream>
#include <string>
using namespace std;
template <typename T>
struct BTnode_1
{
    T data;
    BTnode_1<T> *left, *right;
    BTnode_1(const T &item); //结点初始化
};
//2.2 特殊情况下存储父指针。
template <typename T>
struct BTnode_2
{
    T data;
    BTnode_2<T> *left, *right, *parent;
    BTnode_2(const T &item);
};

//树结点初始化
template <typename T>
BTnode_1<T>::BTnode_1(const T &item)
{
    data = item;
    left = nullptr;
    right = nullptr;
}

template <typename T>
BTnode_2<T>::BTnode_2(const T &item)
{
    data = item;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}
template <typename T>
class BTree
{
public:
    BTnode_1<T> *root;
    int nodenum;   //结点数目
    int travelnum; //记录当前遍历结点数目
    BTree();
    ~BTree();
    void create(BTnode_1<T> *&node);
    void destory(BTnode_1<T> *root);
    void delnode(BTnode_1<T> *node);
    void print_node(BTnode_1<T> *node);
    void menu();
    //***二叉树遍历***递归版
    //1.先根遍历
    void PreOrder(BTnode_1<T> *root);
    //2.中根遍历
    void InOrder(BTnode_1<T> *root);
    //3.后根遍历
    void PostOrder(BTnode_1<T> *root);
    ////***二叉树遍历***非递归版
    //void PreO(BTnode_1<T>* root);
    //void InO(BTnode_1<T>* root);
    //void PostO(BTnode_1<T>* root);
    //***二叉树层次遍历***
};
//构造函数
template <typename T>
BTree<T>::BTree()
{
    root = nullptr;
    nodenum = 0;
    travelnum = 0;
}
//析构函数
template <typename T>
BTree<T>::~BTree()
{
    destory(root);
}
//销毁二叉树
template <typename T>
void BTree<T>::destory(BTnode_1<T> *root)
{
    if (root != nullptr)
    {
        destory(root->left);
        destory(root->right);
        delete root;
    }
}
//创建二叉树
template <typename T>
void BTree<T>::create(BTnode_1<T> *&node)
{
    //以先根顺序创建树
    int choice = -1;
    bool flag = false;
    if (nodenum == 0)
    {
        cout << "Root Data:" << endl;
        T data;
        cin >> data;
        node = new BTnode_1<T>(data);
        if (!node)
        {
            cout << "Creating failed" << endl;
            return;
        }
        nodenum++;
        flag = false;
        cout << "Creating success" << endl;
    }
    else if (nodenum > 0)
    {
        cout << "current node: [" << nodenum + 1 << "]"
             << " choose: 1.Setdata/else.nullptr  ";
        cin >> choice;
        flag = true;
    }
    if (flag)
    {
        if (choice != 1)
            return;
        if (choice == 1)
        {
            cout << "BTnode Data:" << endl;
            T data;
            cin >> data;
            node = new BTnode_1<T>(data);
            if (!node)
            {
                cout << "Creating failed" << endl;
                return;
            }
            nodenum++;
            flag = false;
            cout << "Creating success" << endl;
            //cout << "nodenum: " << nodenum << endl;
        }
    }
    create(node->left);
    create(node->right);
    return;
}
//删除以结点为根的子树
template <typename T>
void BTree<T>::delnode(BTnode_1<T> *node)
{
    if (node != nullptr)
    {
        delnode(node->left);
        delnode(node->right);
        delete node;
        nodenum--;
    }
}
//打印结点
template <typename T>
void BTree<T>::print_node(BTnode_1<T> *node)
{
    cout << "[" << node->data << "] ";
}
//菜单
template <typename T>
void BTree<T>::menu()
{
    int flag = 0;
    while (flag == 0)
    {
        cout << "choose number:" << endl;
        cout << "-1.exit" << endl;
        cout << "0.destory BTree" << endl;
        cout << "1.create BTree" << endl;
        cout << "2.PreOrder Traveral" << endl;
        cout << "3.InOrder Traveral" << endl;
        cout << "4.PostOrder Traveral" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case -1:
            flag = -1;
            break;
        case 0:
        {
            if (!root)
            {
                cout << "No BTree exists, failed!" << endl;
                break;
            }
            destory(root);
            root = nullptr;
            nodenum = 0;
            cout << "Destory BTree success!" << endl;
            break;
        }
        case 1:
        {
            if (root)
            {
                cout << "BTree already exists, failed!" << endl;
                break;
            }
            create(root);
            break;
        }
        case 2:
        {
            //递归版先根遍历
            if (!root)
            {
                cout << "No BTree exists, failed!" << endl;
            }
            cout << "PreOrder Traveral:";
            PreOrder(root);
            travelnum = 0;
            cout << endl;
            break;
        }
        case 3:
        {
            //递归版中根遍历
            if (!root)
            {
                cout << "No BTree exists, failed!" << endl;
            }
            cout << "InOrder Traveral:";
            InOrder(root);
            travelnum = 0;
            cout << endl;
            break;
        }
        case 4:
        {
            //递归版后根遍历
            if (!root)
            {
                cout << "No BTree exists, failed!" << endl;
            }
            cout << "PostOrder Traveral:";
            PostOrder(root);
            travelnum = 0;
            cout << endl;
            break;
        }
        default:
            cout << "Error, Please cin again!" << endl;
            break;
        }
    }
}
//递归版遍历
/*travelnum++;
    if (travelnum % 5 == 0) {
        cout << endl;
    }
    cout << "[node " << travelnum<<"]" << "->Data";*/
template <typename T>
void BTree<T>::PreOrder(BTnode_1<T> *root)
{
    //PreOrder1.[递归出口]
    if (root == nullptr)
    {
        return;
    }
    //PreOrder2.[访问根]
    print_node(root);
    //PreOrder3.[递归]
    PreOrder(root->left);
    PreOrder(root->right);
}
template <typename T>
void BTree<T>::InOrder(BTnode_1<T> *root)
{
    //InOrder1.[递归出口]
    if (root == nullptr)
    {
        return;
    }
    //InOrder2:[左递归]
    InOrder(root->left);
    //InOrder3.[访问根]
    print_node(root);
    //InOrder4.[右递归]
    InOrder(root->right);
}
template <typename T>
void BTree<T>::PostOrder(BTnode_1<T> *root)
{
    //PostOrder1.[递归出口]
    if (root == nullptr)
    {
        return;
    }
    //PostOrder2:[递归]
    PostOrder(root->left);
    PostOrder(root->right);
    //PostOrder3.[访问根]
    travelnum++;
    print_node(root);
}
//非递归版遍历
#endif