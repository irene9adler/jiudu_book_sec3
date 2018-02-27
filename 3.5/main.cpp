//�Ŷ��� ������ ���ݽṹ��3.5 �������������� ����ǰ�к����
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

node * doit(node * T,int x)//��x���뵽��ΪT�����Ϲ������������� Tһֱ������
{
    if(T == NULL)
    {
        T = create();
        T -> c = x;
        return T;
    }
    else if(x < T -> c)
        T->lchild = doit(T->lchild,x);//��x���뵽������ ����
    else if(x > T-> c)
        T->rchild = doit(T->rchild,x);
    //���ڲ���
    return T;//ֱ�ӷ��ظı���T��
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
