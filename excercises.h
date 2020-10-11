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
    struct node *lchild, *rchild;
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

//int COUNT2(BTREE T)
//{
//    if(T==NULL)
//    {
//        return 0;
//    }
//    BTREE top = NULL;
//    BTREE cur = NULL;
//    int sum = 0;
//    top = T;
//    while(NULL != top)
//    {
//        while(T)
//        {
//            if((!T->lchild&&T->rchild)||(T->lchild&&!T->rchild))
//            {
//                sum++;
//            }
//            if(T->rchild)
//            {
//                cur = T->rchild;
//                cur->link = top;    //push
//                cur = top;
//            }
//            T = T->lchild;
//        }
//        T = top;    //pop
//        top = top->link;
//    }
//    return sum;
//}



//exercise 6
void ANCESTOR(BTREE T, int item)
{
    if(T==NULL||T->data==item)
    {
        printf("what the fuck!\n");
        return;
    }
    BTREE stack1[100];
    int stack2[100], top = -1;
    int flag = 0;
    
    while(top != -1)
    {
        while( T != NULL)
        {
            stack1[++top] = T;
            stack2[top] = 0;
            T = T->lchild;
        }
        T = stack1[top];
        flag = stack2[top--];
        if(flag == 0)
        {
            stack1[++top] = T;
            stack2[top] = 1;
            T = T->rchild;
        }
        else
        {
            if (item == T->data)
            {
                while(top != -1)
                {
                    printf("%d ",stack1[top--]->data);
                }
                return;
            }
            T = NULL;
        }
    }
}


//exercise 7 $$$$
int SEARCHPOS(int INOD[],int n,int item)    //确定在中序中的位置
{
    int i;
    for(i = 0; i < n ; i++)
    {
        if(INOD[i] == item)
            return i+1;
    }
    return 0;
}

void INSERTITEM(BTREE *T, int item, int INOD[], int n)
{
    BTREE p,q;
    int ord;
    p = (BTREE)malloc(sizeof(BTNode));
    p->data = item;
    p->lchild = p->rchild = NULL;
    if(*T == NULL)
    {
        *T = p;
    }
    else
    {
        ord = SEARCHPOS(INOD, n, item);
        q = *T;
        while(1)
        {
            if(ord<SEARCHPOS(INOD, n, q->data))
            {
                if(q->lchild!=NULL)
                {
                    q=q->lchild;
                }
                else
                {
                    q->lchild = p;
                    break;
                }
            }
            else
            {
                if(q->rchild!=NULL)
                {
                    q = q->rchild;
                }
                else
                {
                    q->rchild = p;
                    break;
                }
            }
        }
    }
}


BTREE BUILDTREE(int PREOD[],int INOD[],int n)
{
    BTREE T = NULL;
    int i;
    for(i = 0; i<n ; i++)
    {
        INSERTITEM(&T, PREOD[i] , INOD, n);
    }
    return T;
}




#endif /* exceexercisesrcises_h */
