//九度书 第三章 数据结构 例3.4 二叉树 由前序遍历和中序遍历求后序遍历
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    node * lchild;
    node * rchild;
    char c;
}tree[30];//用数组表示树
typedef struct node node;
char str1[30];
char str2[30];
int loc;
node * create()//建树
{
    tree[loc].lchild = tree[loc].rchild = NULL;//结构体用.指针用-> tree[loc]是正常结构体
    return &tree[loc++];//怎么理解这句话的写法？要求返回值是指针类型 tree[loc]是正常结构体类型 所以用引用的方式返回？
}

void postorder(node * T)
{
    if(T->lchild != NULL)postorder(T->lchild);
    if(T->rchild != NULL)postorder(T->rchild);
    printf("%c",T->c);
}

node * doit(int s1,int e1,int s2,int e2)//s1 e1 s2 e2 分别是前序中序遍历的头尾下标
{
    //node * res = (node *)malloc(sizeof(node));
    node * res = create();
    res -> c = str1[s1];//最初的根
    printf("%c已经建树\n",res->c);
    int rootindex;
    int i;
    for(i = s2;i <= e2; i++)
    {
        if(str2[i] == str1[s1])
        {
            rootindex = i;
            break;
        }
    }
    if(rootindex != s2)//有左子树
    {
        res -> lchild = doit(s1 + 1,s1 + rootindex - s2,s2,rootindex - 1);
    }
    if(rootindex != e2)//有右子树
    {
        res -> rchild = doit(s1 + rootindex - s2 + 1,e1,rootindex + 1,e2);
    }
    return res;
}


int main()
{
    while(scanf("%s",str1)!=EOF)
    {
        scanf("%s",str2);
        loc = 0;
        int l1 = strlen(str1);
        int l2 = strlen(str2);
        node * root = doit(0,l1 - 1,0,l2 - 1);
        postorder(root);
        //free(root);
        printf("\n");
    }
    return 0;
}
//书上代码定义node *后都直接用 没malloc 这个写法前面定义了静态数组 已经分配空间了
