//�Ŷ��� ������ ��3.2ջӦ��-���ʽ��ֵ �����д�������鷳
#include <stdio.h>
#include <stack>
using namespace std;

char str[250] = {0};//���ʽ������str�����ֵ����0
stack <int> op;//�����ջ int��
stack <double> num;
int mat[][5]=
{
    1,0,0,0,0,
    1,0,0,0,0,
    1,1,0,0,0,
    1,1,1,0,0,
    1,1,1,0,0
};//mat[i][j]=1��ʾ�����i�����ȼ�����j ��������˳����0+-*/ ���ȼ�0��� +-��*/��

void getone(bool &reto,int &retn, int &i)//��ȡ���ʽstr����һԪ��
{
    //�����ջ��Ϊ��ӱ���ַ���Ϊ������־
    if(i == 0 && op.empty() == true)
    {
        reto = true;
        retn = 0;
        return;//?������һ���ַ�����ûȡ��
    }
    if(str[i] == 0)//���ʽ������
    {
        reto = true;
        retn = 0;
        return;//�ڽ�β��ӱ�ʶ��
    }
    //�����ջ 0 ������� ��Ӧ��ֵ��0 ���ȼ����

    if(str[i] >= '0' && str[i] <= '9')//������
    {
        reto = false;//������������ֵ
    }
    else//�������
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
        i = i + 2;//�����һ����ռһ��str[i] ����һ���ǿո� ����i+2
        return;
    }

    //�������ֵ�ֵ
    retn = 0;//��ֵ
   // int r;
    for(;str[i] != ' ' && str[i] != 0; i++)
    {
        //�����һ�ȡstr[i]����������ʵֵ���߼�
        retn *= 10;
        retn = retn + str[i] - '0';
    }

    if(str[i] == ' ') i++;//����ѭ������ǰ�Ѿ�++�� ����i����+2 �����ǿո�˵�����ʽ��δ���� i+1����
    return;
}


int main()
{
    //while(scanf("%s",str)!=EOF)
    while(gets(str))//�����д���ᱻ�ո�ָ�ɶ���ַ���
    {
        printf("%s\n",str);
        printf("\n");
        if(str[0] == '0' && str[1] == 0) break;
        int number;
        bool oper;
        int loc = 0;
        //��ջ
        while(op.empty() == false) op.pop();
        while(num.empty() == false) num.pop();

        while(1)
        {
            getone(oper,number,loc);
            printf("number = %lf\n",number);
            printf("bool oper = %d\n",oper);
            printf("loc = %d\n",loc);
            if(oper == false)//����
            {
               num.push((double)number);
               printf("����%lf��ջ\n",(double)number);
            }
            else//����� �ȼ������ȼ��ߵ�
            {
                if(op.empty() == true || mat[number][op.top()] == 1)//��ջ����������ȼ��� ���������ջ
                {
                    op.push(number);
                    printf("�����%d��ջ\n",number);
                }
                else//��������ȵ�ǰջ�����ȼ��� ������ջ���������� ����һ��������������� ���ѹ������ջ
               {
                    while(mat[number][op.top()] == 0)//ջ�����ȼ�һֱ��
                {
                    double a,b;
                    int now = op.top();
                    printf("���������%d\n",now);
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
                op.push(number);//��������������ȼ���� ѹ��ջ
                printf("�����%d��ջ\n",number);
              }
            }
            if(op.size() == 2 && op.top() == 0) break;//����ѭ����ʽ �����ջ����������
        }


        printf("the result is %0.2lf\n",num.top());
        printf("\n");

    }
    return 0;
}
