//�Ŷ��� ������ ���ݽṹ ��3.6 �ж϶����������Ƿ���ͬ
//�Ƚ��������Ƿ���ͬ��Ҫǰ������к��������ȫ��ͬ
#include <stdio.h>
#include <string.h>

struct node
{
    node * lchild;
    node * rchild;
    int c;
}tree[100];

typedef struct node node;
int  loc;

node * create()
{
    tree[loc].lchild = tree[loc].rchild = NULL;
    return &tree[loc++];//attention
}

//ע�������д�� �����ַ���str1 str2 ���Ǵ�����Ҫ�Ƚϵ��ַ������ݵ� ���趨str�� str������ǰ�������������� index��������̵��±� size1 size2�����趨index
char str1[20],str2[20];//���������Ҫ�Ƚϵ�����
char * str;
int * index;
int l1,l2;

void preorder(node * T)
{
    str[*(index)++] = T -> c + '0';//�������浽�ַ�����
    if(T -> lchild != NULL) preorder(T -> lchild);
    if(T -> rchild != NULL) preorder(T -> rchild);
}

void miorder(node * T)
{
    if(T -> lchild != NULL) preorder(T -> lchild);
    str[*(index)++] = T -> c + '0';
    if(T -> rchild != NULL) preorder(T -> rchild);
}

//��������������
node * doit (node * T,int x)
{
    if(T == NULL)
    {
        T = create();
        T -> c = x;
        printf("%d�������������\n",x);
        //T->lchild = T->rchild = NULL;
        return T;
    }
    else if(x < T -> c)
        T -> lchild = doit(T -> lchild,x);
    else if(x > T -> c)
        T -> rchild = doit(T -> rchild,x);

    return T;
}

//ע�����ַ��������� �ַ����ֱ����������Ĳ���
int main (void)
{
    int n;
    //loc = 0;
    char input[11];
    while(scanf("%d",&n)!=EOF)
    {
        loc = 0;//һ����loc��һ��0
        if(n == 0) break;
        scanf("%s",input);
        //printf("%s\n",input);
        //int l1 = strlen(str1);
        int i,j;
        node * tmp = NULL;
        for(j = 0; j < strlen(input); j++)
        {
            tmp = doit(tmp,input[j] - '0');//input[j] - '0'�õ���������
        }
        printf("��һ�������������������\n");
        l1 = 0;
        str = str1;
        index = &l1;
        preorder(tmp);
        miorder(tmp);

        for(i = 0;i < n;i++)
        {
            scanf("%s",input);
            node * tmp1 = NULL;
            for(j = 0;j < strlen(input);j++)
                tmp1 = doit(tmp1,input[j] - '0');
            l2 = 0;
            str = str2;
            index = &l2;
            preorder(tmp1);
            miorder(tmp1);
            if(strcmp(str1,str2) == 0) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
