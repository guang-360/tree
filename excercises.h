//
//  exercises.h
//  tree
//
//  Created by duoguang xu on 2020/10/11.
//

#ifndef exercises_h
#define exercises_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *lchild, *rchild, *link;
}BTNode,*BTREE;


//exercise 1
void PREORDER(int *BT)
{
    if (BT == NULL)
    {
        return;
    }
    int stack[100]; //存放下标
    int index = 0;  //记录当前数组元素下标
    int top = -1;   //记录栈顶位置
    stack[++top] = 0;
    while(top!=-1)
    {
        while(BT[index]!=0)
        {
            printf("%d ",BT[index]);
            
            if(BT[2*index+2]!=0)
            {
                stack[++top]=2*index+2;
            }
            
            index=2*index+1;
        }
        index = stack[top--];
    }
}

//exercise 2
int SIMILARBT(BTREE T1,BTREE T2)
{
    if(T1==NULL&&T2==NULL)
    {
        printf("T1 is similar to T2, both of them are valid tree.\n");
        return 1;
    }
    if(T1!=NULL&&T2!=NULL&&SIMILARBT(T1->lchild, T2->lchild)&&SIMILARBT(T1->rchild, T2->rchild))
    {
        printf("T1 is similar to T2.\n");
        return 1;
    }
    return 0;
}


//exercise 3
int EQUALTB(BTREE T1, BTREE T2)
{
    if (T1==NULL&&T2==NULL)
    {
        return 1;
    }
    if(T1!=NULL&&T2!=NULL&&T1->data==T2->data&&EQUALTB(T1->lchild, T2->lchild)&&EQUALTB(T1->rchild, T2->rchild))
    {
        return 1;
    }
    return 0;
}


//exercise 4
void RELEASE(BTREE T)
{
    if(T!=NULL)
    {
        RELEASE(T->lchild);
        RELEASE(T->rchild);
        free(T);
    }
}

//exercise 5（两种写法）
///书上写法（每个结点都进栈）
typedef struct lnode{
    BTREE data;
    struct lnode *link;
}BLNode, *BLinklist;

int COUNT1(BTREE T)
{
    BTREE p = T;
    BLinklist q, top = NULL;
    int n = 0;
    if(T!=NULL)
    {
        do{
            while(p!=NULL)
            {
                if((p->lchild!=NULL&&p->rchild==NULL)||
                   (p->lchild==NULL&&p->rchild!=NULL))
                {
                    n++;
                }
                q = (BLinklist)malloc(sizeof(BLNode));
                q->data = p;
                q->link = top;
                top = q;
                p = p->lchild;
            }
            p = top->data;
            q = top;
            top = top->link;
            free(q);
            p = p->rchild;
        }while(!(p==NULL&&top==NULL));
    }
    return n;
}

//前序遍历模板
//写struct的时候加一个 struct node *link
//如：
//typedef struct node{
//    int data;
//    struct node *lchild, *rchild, *link;
//}BTNode,*BTREE;

int COUNT2(BTREE T)
{
    if(T==NULL)
    {
        return 0;
    }
    BTREE top = NULL;
    BTREE cur = NULL;
    int sum = 0;
    top = T;
    while(NULL != top)
    {
        while(T)
        {
            if((!T->lchild&&T->rchild)||(T->lchild&&!T->rchild))
            {
                sum++;
            }
            if(T->rchild)
            {
                cur = T->rchild;
                cur->link = top;
                cur = top;
            }
            T = T->lchild;
        }
        T = top;
        top = top->link;
    }
    return sum;
}













#endif /* exceexercisesrcises_h */
