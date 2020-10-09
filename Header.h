//
//  Header.h
//  tree
//
//  Created by duoguang xu on 2020/10/8.
//
#include<stdio.h>
#include<stdlib.h>
#ifndef Header_h
#define Header_h

//结构声明
typedef struct node
{
    char data;
    struct node *lchild, *rchild;
} BTNode, *BTREE;

#define LEN sizeof(BTNode)

//创建一棵二叉树
void BUILDBT(BTREE *T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == ' ')
    {
        *T = NULL;
    }
    else
    {
        *T = (BTREE)malloc(sizeof(BTNode));
        if (!*T)
        {
            exit(-1);
        }
        (*T)->data = ch;
        BUILDBT(&(*T)->lchild);
        BUILDBT(&(*T)->rchild);
    }
}

void PreOrderTraverse(BTREE T) //二叉树的先序遍历
{
    if (T == NULL)
        return;
    printf("%c ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BTREE T) //二叉树的中序遍历
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c ", T->data);
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BTREE T) //后序遍历
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c ", T->data);
}

void BFS(BTREE root) //广度优先遍历（层次遍历）
{
    // 一、初始化
    BTREE queue[100];
    int front = -1;
    int rear = -1;

    BTREE cur = NULL;
    int len = 0;
    // 二、根节点入队
    queue[++rear] = root; // 入队

    // 三、广度优先
    // 队是否为空
    while (front != rear)
    {
        len = rear - front; /////////////////////

        while (len--) ///////////////////////////
        {             //////////////////////////////////////
            // 1.访问
            front++; // 出队
            cur = queue[front];
            /***************添加其他操作**********************/
            // if (cur->data == item)
            // {
            //     return level; // P177、6
            // }
            if (cur != NULL)
            {
                printf("%c ", cur->data);
            }
            // 2.孩子节点入队
            if (cur->lchild)
            {
                queue[++rear] = cur->lchild;
            }

            if (cur->rchild)
            {
                queue[++rear] = cur->rchild;
            }
        } ///////////////////////////////////////
        //  其他关于层的操作
        /***************添加其他操作**********************/
    }
}

// 广度优先 模板二 （P176、5）
// 求树的深度
int DEEP_BFS(BTREE root)
{
    // 一、初始化
    BTREE queue[100];
    int front = -1;
    int rear = -1;

    BTREE cur = NULL;
    int len = 0;
    int level = 0;
    // 二、根节点入队
    queue[++rear] = root; // 入队

    // 三、广度优先
    // 队是否为空
    while (front != rear)
    {
        len = rear - front; /////////////////////

        while (len--) ///////////////////////////
        {             //////////////////////////////////////
            // 1.访问
            front++; // 出队
            cur = queue[front];
            /***************添加其他操作**********************/
            // if (cur->data == item)
            // {
            //     return level; // P177、6
            // }
            // 2.孩子节点入队
            if (cur->lchild)
            {
                //                rear++;
                queue[++rear] = cur->lchild;
            }

            if (cur->rchild)
            {
                //                rear++;
                queue[++rear] = cur->rchild;
            }
        } ///////////////////////////////////////
        //  其他关于层的操作
        /***************添加其他操作**********************/
        level++; ///////////////////////////////
    }
    return level;
}

//二叉树的销毁（后续遍历）
//删除并释放二叉树中所有结点，CLEARBT的工具函数
void DESTROYBT(BTREE T)
{
    if (T != NULL)
    {
        DESTROYBT(T->lchild);
        DESTROYBT(T->rchild);
        free(T);
    }
}
//将根结点置为NULL（实际调用用这个）
void CLEARBT(BTREE *root)
{
    DESTROYBT(*root);
    *root = NULL;
}

//二叉树的复制
BTREE COPYBT(BTREE T1)
{
    BTREE T2;
    if (T1 == NULL)
    {
        return NULL;
    }
    else
    {
        T2 = (BTREE)malloc(LEN);
        T2->data = T1->data;
        T2->lchild = COPYBT(T1->lchild);
        T2->rchild = COPYBT(T1->rchild);
    }
    return T2;
}

//测试两棵树是否等价
int EQUALBT(BTREE T1, BTREE T2)
{
    if (T1 == NULL && T2 == NULL)
    {
        return 1;
    }
    if (T1 != NULL && T2 != NULL && T1->data == T2->data && EQUALBT(T1->lchild, T2->lchild) && EQUALBT(T1->rchild, T2->rchild))
    {
        return 1;
    }
    return 0;
}

//求结点所在层次
#define M 50 //定义二叉树中结点最大数目
int LAYERBT(BTREE T, char item)
{
    BTREE STACK1[M], p = T;
    int STACK2[M], flag, top = -1;
    do
    {
        while (p != NULL)
        {
            STACK1[++top] = p;
            STACK2[top] = 0;
            p = p->lchild;
        }
        p = STACK1[top];
        flag = STACK2[top];
        if (0 == flag)
        {
            STACK1[top] = p;
            STACK2[top] = 1;
            p = p->rchild;
        }
        else
        {
            if (p->data == item)
            {
                return (top + 1);
            }
            top--;
            p = NULL;
        }
    } while (!(p == NULL && top == -1));
    return 0;
}


//二叉树的删除P178
BTREE DELETBT(BTREE* T, char item)
{
    BTREE stack[M],q = NULL,p=*T;
    int top = -1;
    if((*T)->data == item)
    {
        DESTROYBT(*T);
        return NULL;
    }
    else
    {
        do{
            while(p!=NULL)
            {
                if(p->data==item)
                {
                    if(q->lchild==p)
                    {
                        q->lchild=NULL;
                    }
                    else
                    {
                        q->rchild=NULL;
                    }
                    DESTROYBT(p);
                    return *T;
                }
                stack[++top]=p;
                q=p;
                p=p->lchild;
            }
            p=stack[top--];
            q=p;
            p=p->rchild;
        }while(!(p==NULL&&top==-1));
    }
    return *T;
}


//void PreOrderexchange(BTREE T) //二叉树的先序遍历:有问题，改
//{
//    if (T == NULL)
//        return;
//    if(!(T->lchild==NULL && T->rchild==NULL))
//        return;
//    BTREE temp = NULL;
//    temp = T->lchild;
//    T->lchild = T->rchild;
//    T->rchild = temp;
//    PreOrderTraverse(T->lchild);
//    PreOrderTraverse(T->rchild);
//}

//    交换所有结点左右子树的位置  P179、8
void EXCHANGEBT(BTREE T)
{
    BTREE QUEUE[M],temp,p=T;
    int front, rear;
    if(T!=NULL)
    {
        QUEUE[0]=T;
        front=-1;
        rear=0;
        while(front<rear)
        {
            p=QUEUE[++front];
            temp = p->lchild;
            p->lchild = p->rchild;
            p->rchild = temp;
            if(p->lchild!=NULL)
            {
                QUEUE[++rear]=p->lchild;
            }
            if(p->rchild!=NULL)
            {
                QUEUE[++rear]=p->rchild;
            }
        }
    }
}

#endif /* Header_h */
