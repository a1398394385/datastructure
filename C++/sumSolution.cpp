class Solution
{
public:
    int Sum_Solution(int n)
    {
        bool a[n][n + 1];
        return sizeof(a) >> 1;
    }
};

class assist
{
public:
    assist()
    {
        N++;
        sum += N;
    }

    static unsigned int GetSum() { return sum; }

private:
    static int N;
    static int sum;
};
int assist::N = 0;
int assist::sum = 0;
class Solution
{
public:
    int Sum_Solution(int n)
    {
        assist *p = new assist[n];
        delete[] p;
        p = nullptr;
        return assist::GetSum();
    }
};

//第二种方法:使用模板函数进行编程，显示定义输入参数为1的模块
template <int m>
inline int SumTo() { return m + SumTo<m - 1>(); }
template <>
inline int SumTo<1>() { return 1; }

//第三种方法：使用虚函数
class Base;
Base *Array[2];
class Base
{
public:
    virtual int Sum(int n) { return 0; }
};
class Derived : public Base
{
public:
    virtual int Sum(int n) { return Array[!!n]->Sum(n - 1) + n; }
};
//使用虚函数来构造递归，在基类种定义虚函数Sum(n)返回0，通过将指针数组的两个元素分别绑定到基类和派生类，其中基类的Sum()
//结束递归，!!n来构造true(1) false(0)来对指针数组进行访问
class Solution
{
public:
    int Sum_Solution(int n)
    {
        Base a;
        Derived b;
        Array[0] = &a;
        Array[1] = &b;
        return b.Sum(n);
    }
};

//使用短路计算来构造递归:重点是输入0的时候输出0来结束递归
//缺点：递归的层数不能太深<3000
class Solution
{
public:
    int Sum_Solution(int n)
    {
        int ret = n;
        n && (ret += Sum_Solution(n - 1));
        return ret;
    }
};
