//九度书 第三章 数据结构例3.3 用小顶堆 求huffuman树
//huffuma树的建法就和上课讲的一样 手算huffuman是、值是叶子权值 * 根到叶子路径值
#include <stdio.h>
#include <queue>//队列头文件

using namespace std;

int main()
{
    int n;
    priority_queue<int, vector<int>, greater<int> > Q;//定义小顶堆
    //默认定义大顶堆priority_queue<int> Q
    while(scanf("%d",&n)!= EOF)
    {
        while(Q.empty() == false) Q.pop();
        int i;
        for(i = 0;i < n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            Q.push(tmp);
        }
        int res = 0;
        //for(i = 0;i <= Q.size();i ++)
        while(Q.size() > 1)//不是把刚建好的堆遍历一边就行 中间还要再PUSH新的 结束条件是堆中只剩一个元素
        {
            int a,b;//
            a = Q.top();
            Q.pop();
            b = Q.top();
            Q.pop();
            res = res + a + b;
            Q.push(a + b);
        }
        printf("%d\n",res);
    }
    return 0;
}
