//�Ŷ��� ������ ���ݽṹ��3.3 ��С���� ��huffuman��
//huffuma���Ľ����ͺ��Ͽν���һ�� ����huffuman�ǡ�ֵ��Ҷ��Ȩֵ * ����Ҷ��·��ֵ
#include <stdio.h>
#include <queue>//����ͷ�ļ�

using namespace std;

int main()
{
    int n;
    priority_queue<int, vector<int>, greater<int> > Q;//����С����
    //Ĭ�϶���󶥶�priority_queue<int> Q
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
        while(Q.size() > 1)//���ǰѸս��õĶѱ���һ�߾��� �м仹Ҫ��PUSH�µ� ���������Ƕ���ֻʣһ��Ԫ��
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
