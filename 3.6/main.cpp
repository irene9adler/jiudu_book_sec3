//九度书 第三章 数据结构 例3.6 判断二叉排序树是否相同
//比较两个数是否相同需要前中序或中后序遍历完全相同
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

//注意下面的写法 正常字符串str1 str2 不是存两个要比较的字符串内容的 是设定str的 str用来存前中序遍历结果连接 index是这个过程的下标 size1 size2用来设定index
char str1[20],str2[20];//两个输入的要比较的序列
char * str;
int * index;
int l1,l2;

void preorder(node * T)
{
    str[*(index)++] = T -> c + '0';//把整数存到字符串里
    if(T -> lchild != NULL) preorder(T -> lchild);
    if(T -> rchild != NULL) preorder(T -> rchild);
}

void miorder(node * T)
{
    if(T -> lchild != NULL) preorder(T -> lchild);
    str[*(index)++] = T -> c + '0';
    if(T -> rchild != NULL) preorder(T -> rchild);
}

//构建二叉排序树
node * doit (node * T,int x)
{
    if(T == NULL)
    {
        T = create();
        T -> c = x;
        printf("%d插入二叉排序树\n",x);
        //T->lchild = T->rchild = NULL;
        return T;
    }
    else if(x < T -> c)
        T -> lchild = doit(T -> lchild,x);
    else if(x > T -> c)
        T -> rchild = doit(T -> rchild,x);

    return T;
}

//注意用字符串存数字 字符数字变正常整数的操作
int main (void)
{
    int n;
    //loc = 0;
    char input[11];
    while(scanf("%d",&n)!=EOF)
    {
        loc = 0;//一棵树loc置一次0
        if(n == 0) break;
        scanf("%s",input);
        //printf("%s\n",input);
        //int l1 = strlen(str1);
        int i,j;
        node * tmp = NULL;
        for(j = 0; j < strlen(input); j++)
        {
            tmp = doit(tmp,input[j] - '0');//input[j] - '0'得到的是数字
        }
        printf("第一个二叉排序树建立完成\n");
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
