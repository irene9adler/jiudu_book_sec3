//�Ŷ�3.1 ջ ����ƥ��
#include <stdio.h>
#include <stack>
#include <string.h>
#define M 100

using namespace std;

char str[M];
char ans[M];
stack<int> s;

int main()
{
    while(scanf("%s",&str)!=EOF)
    {
        int l = strlen(str);
        int i,j;
        for(i=0;i<l;i++)
        {
            if(str[i]=='(') //������
            {
                s.push(str[i]);
                ans[i] = ' ';
            }

            else if(str[i] == ')')//������
            {
                if(s.empty()==false)
                {
                    s.pop();
                    ans[i] = ' ';
                }
                else ans[i] = '?';
            }

            else ans[i] = ' ';//�����ַ�

        }

        while(s.empty()==false)
        {
            j = s.top();
            printf("%c\n",j);//��������� ��ô����ȷλ�ðѲ���ƥ��������Ŵ��$
            ans[s.top()] = '$';
            s.pop();
        }
        ans[i]=0;
        puts(str);
        puts(ans);

    }


    return 0;
}
