//�Ŷ��� ������ ���ݽṹ ��3.4 ������ ��ǰ����������������������
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    node * lchild;
    node * rchild;
    char c;
}tree[30];//�������ʾ��
typedef struct node node;
char str1[30];
char str2[30];
int loc;
node * create()//����
{
    tree[loc].lchild = tree[loc].rchild = NULL;//�ṹ����.ָ����-> tree[loc]�������ṹ��
    return &tree[loc++];//��ô�����仰��д����Ҫ�󷵻�ֵ��ָ������ tree[loc]�������ṹ������ ���������õķ�ʽ���أ�
}

void postorder(node * T)
{
    if(T->lchild != NULL)postorder(T->lchild);
    if(T->rchild != NULL)postorder(T->rchild);
    printf("%c",T->c);
}

node * doit(int s1,int e1,int s2,int e2)//s1 e1 s2 e2 �ֱ���ǰ�����������ͷβ�±�
{
    //node * res = (node *)malloc(sizeof(node));
    node * res = create();
    res -> c = str1[s1];//����ĸ�
    printf("%c�Ѿ�����\n",res->c);
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
    if(rootindex != s2)//��������
    {
        res -> lchild = doit(s1 + 1,s1 + rootindex - s2,s2,rootindex - 1);
    }
    if(rootindex != e2)//��������
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
//���ϴ��붨��node *��ֱ���� ûmalloc ���д��ǰ�涨���˾�̬���� �Ѿ�����ռ���
