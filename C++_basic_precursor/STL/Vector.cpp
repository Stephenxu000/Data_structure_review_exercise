//vector 是一个封装动态大小数组的顺序容器，即能存放任意类型的动态数组
//int初始化0，bool初始化false
/*
    push_back(x);向量尾部增长元素x
    pop_back();删除向量中的最后一个元素
    clear();清空所有元素
    empty();是否为空
    size();返回向量元素个数
    insert(iterator pos,elem)||(iterator pos,n,elem);在pos位置上插入1||n个元素elem
    erase(pos)||(pos1,pos2)：删除pos位置||[pos1,pos2]区间数据 pos_i为迭代器类型
*/
#include<vector>
#include<iostream>
using namespace std;

void print_vector(vector<int> a){
    for(int i=0;i<a.size();i++)
    {
        cout<<"a["<<i<<"]="<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>a;
    for(int i=0;i<10;i++){
        a.push_back(i);//尾部加元素i
    }
     cout<<"a["<<5<<"]="<<a[5]<<endl;
    for(int i=0;i<5;i++){
        a.pop_back();//删除尾部
    }
    cout<<"a["<<5<<"]="<<a[5]<<endl;//实际上此时没有a[5]了
    print_vector(a);
    
    //迭代器（还未复习）
    vector<int>::iterator it=a.begin();
    a.insert(it,3,9);//在a的开始处插入3个10
    print_vector(a);
    a.erase(it);//删除a在开始处的值
    print_vector(a);
    a.insert(it+3,5);//改变a[3]=5
    print_vector(a);

    //2维数组定义 2方式
    //vector<vector<int> >的最外<>要有空格。否则在比较旧的编译器下无法通过
    int row=5,col=3;
    //1
    vector<vector<int> > two_a(row);//5行
    //2
    vector<vector<int> > two_b(row,vector<int> (col));
    for(int i=0;i<two_a.size();i++){
        two_a[i].resize(col);//3列,填充默认值
    }
    for(int i=0;i<two_a.size();i++){
        for(int j=0;j<two_a[i].size();j++){
            cout<<"two_a["<<i<<"]["<<j<<"] = "<<two_a[i][j]<<" ";
        }
        cout<<"\n";
    }
     cout<<"two_b["<<2<<"]["<<2<<"] = "<<two_b[2][2]<<" ";
    return 0;
}

/*
对vector的理解如下：
vector维护的是一个连续线性空间，所以vector支持随机存取。
另外vector动态增加大小时,并不是在原空间之后持续新空间
因为无法保证原空间之后尚有可供配置的空间.
而是以原大小的两倍另外配置一块较大的空间，然后将原内容拷贝过来.
然后才开始在原内容之后构造新元素，并释放原空间。
因此，对vector的任何操作，一旦引起空间重新配置，指向原vector的所有迭代器就都失效了。
*/

//附上某大佬摘录的vector源码网址：https://www.cnblogs.com/sooner/p/3273395.html
//感兴趣的可以去看源码