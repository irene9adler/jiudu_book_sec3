//九度书 第三章 数据结构例3.5 构建二叉排序树 进行前中后遍历
#include <stdio.h>

struct node
{
    node * lchild;
    node * rchild;
    int c;
}tree[100];
typedef struct node node;
int loc;
node * create()
{
    tree[loc].lchild = tree[loc].rchild = NULL;
    return &tree[loc++];
}

void preorder(node * T)
{
    printf("%d",T->c);
    if(T->lchild != NULL) preorder(T->lchild);
    if(T->rchild != NULL) preorder(T->rchild);
}

void miorder(node * T)
{
    if(T->lchild != NULL) miorder(T->lchild);
    printf("%d",T->c);
    if(T->rchild != NULL) miorder(T->rchild);
}

void postorder(node * T)
{
    if(T->lchild != NULL) postorder(T->lchild);
    if(T->rchild != NULL) postorder(T->rchild);
    printf("%d",T->c);
}

node * doit(node * T,int x)//把x插入到根为T的树上构建二叉排序树 T一直是树根
{
    if(T == NULL)
    {
        T = create();
        T -> c = x;
        return T;
    }
    else if(x < T -> c)
        T->lchild = doit(T->lchild,x);//把x插入到左子树 构造
    else if(x > T-> c)
        T->rchild = doit(T->rchild,x);
    //等于不管
    return T;//直接返回改变后的T树
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        loc = 0;
        node * T = NULL;
        int i;
        int tmp;
        for(i = 0;i < n; i++)
        {
            scanf("%d",&tmp);
            T = doit(T,tmp);

        }
        preorder(T);
        printf("\n");
        miorder(T);
        printf("\n");
        postorder(T);
        printf("\n");
    }
    return 0;
}
