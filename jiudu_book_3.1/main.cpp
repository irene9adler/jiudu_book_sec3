//九度3.1 栈 括号匹配
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
            if(str[i]=='(') //左括号
            {
                s.push(str[i]);
                ans[i] = ' ';
            }

            else if(str[i] == ')')//右括号
            {
                if(s.empty()==false)
                {
                    s.pop();
                    ans[i] = ' ';
                }
                else ans[i] = '?';
            }

            else ans[i] = ' ';//其他字符

        }

        while(s.empty()==false)
        {
            j = s.top();
            printf("%c\n",j);//这儿有问题 怎么在正确位置把不能匹配的左括号打成$
            ans[s.top()] = '$';
            s.pop();
        }
        ans[i]=0;
        puts(str);
        puts(ans);

    }


    return 0;
}
