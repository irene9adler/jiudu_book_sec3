//�Ŷ�3.3 queue��С����ʵ�ֹ�������
#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int ,vector<int> ,greater<int> >Q;//��С��������ȼ����У��ɽ�greater��Ϊless����Ϊ�Ӵ�С

int main (void)
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(Q.empty()==false) Q.pop();//���ԭ���Ķ���
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
            Q.push(a+b);//����ans
        }
        printf("%d\n",ans);
    }
    return 0;
}
