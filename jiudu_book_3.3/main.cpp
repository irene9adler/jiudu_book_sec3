//九度3.3 queue建小顶堆实现哈夫曼树
#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int ,vector<int> ,greater<int> >Q;//从小到大的优先级队列，可将greater改为less，即为从大到小

int main (void)
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(Q.empty()==false) Q.pop();//清空原来的队列
        int i;
        for(i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            Q.push(x);
        }
        int ans = 0;
        while(Q.size()>1)
        {
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();

            ans+= (a+b);
            Q.push(a+b);//不是ans
        }
        printf("%d\n",ans);
    }
    return 0;
}
