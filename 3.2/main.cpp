//九度书 第三章 例3.2栈应用-表达式求值 唉这个写法超级麻烦
#include <stdio.h>
#include <stack>
using namespace std;

char str[250] = {0};//表达式结束后str后面的值都是0
stack <int> op;//运算符栈 int型
stack <double> num;
int mat[][5]=
{
    1,0,0,0,0,
    1,0,0,0,0,
    1,1,0,0,0,
    1,1,1,0,0,
    1,1,1,0,0
};//mat[i][j]=1表示运算符i的优先级高于j 标号运算符顺序是0+-*/ 优先级0最低 +-比*/低

void getone(bool &reto,int &retn, int &i)//获取表达式str中下一元素
{
    //运算符栈人为添加标记字符作为结束标志
    if(i == 0 && op.empty() == true)
    {
        reto = true;
        retn = 0;
        return;//?这样第一个字符不就没取？
    }
    if(str[i] == 0)//表达式结束了
    {
        reto = true;
        retn = 0;
        return;//在结尾添加标识？
    }
    //运算符栈 0 是运算符 对应的值是0 优先级最低

    if(str[i] >= '0' && str[i] <= '9')//是数字
    {
        reto = false;//后面再求数字值
    }
    else//是运算符
    {
        if(str[i] == '+')
        {
            reto = true;
            retn = 1;
            //return;
        }
        else if(str[i] == '-')
        {
            reto = true;
            retn = 2;
            //return;
        }
        else if(str[i] == '*')
        {
            reto = true;
            retn = 3;
            //return;
        }
        else if(str[i] = '/')
        {
            reto = true;
            retn = 4;
            //return;
        }
        i = i + 2;//运算符一定是占一个str[i] 下面一定是空格 所以i+2
        return;
    }

    //计算数字的值
    retn = 0;//初值
   // int r;
    for(;str[i] != ' ' && str[i] != 0; i++)
    {
        //从左到右获取str[i]计算数字真实值的逻辑
        retn *= 10;
        retn = retn + str[i] - '0';
    }

    if(str[i] == ' ') i++;//上面循环结束前已经++了 所以i不用+2 下面是空格说明表达式还未结束 i+1就行
    return;
}


int main()
{
    //while(scanf("%s",str)!=EOF)
    while(gets(str))//上面的写法会被空格分割成多个字符串
    {
        printf("%s\n",str);
        printf("\n");
        if(str[0] == '0' && str[1] == 0) break;
        int number;
        bool oper;
        int loc = 0;
        //清栈
        while(op.empty() == false) op.pop();
        while(num.empty() == false) num.pop();

        while(1)
        {
            getone(oper,number,loc);
            printf("number = %lf\n",number);
            printf("bool oper = %d\n",oper);
            printf("loc = %d\n",loc);
            if(oper == false)//数字
            {
               num.push((double)number);
               printf("数字%lf入栈\n",(double)number);
            }
            else//运算符 先计算优先级高的
            {
                if(op.empty() == true || mat[number][op.top()] == 1)//比栈顶运算符优先级高 新运算符入栈
                {
                    op.push(number);
                    printf("运算符%d入栈\n",number);
                }
                else//新运算符比当前栈顶优先级低 从数字栈弹出两个数 弹出一个运算符用来计算 结果压入数字栈
               {
                    while(mat[number][op.top()] == 0)//栈顶优先级一直高
                {
                    double a,b;
                    int now = op.top();
                    printf("计算运算符%d\n",now);
                    op.pop();
                    a = num.top();
                    num.pop();
                    b = num.top();
                    num.pop();
                    double c;
                    if(now == 1)
                        c = a + b;
                    if(now == 2)
                        c = a - b;
                    if(now == 3)
                        c = a * b;
                    if(now == 4)
                        c = a / b;
                    num.push(c);
                }
                op.push(number);//现在新运算符优先级最高 压入栈
                printf("运算符%d入栈\n",number);
              }
            }
            if(op.size() == 2 && op.top() == 0) break;//跳出循环方式 运算符栈到结束条件
        }


        printf("the result is %0.2lf\n",num.top());
        printf("\n");

    }
    return 0;
}
