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

void CREATEBT(BTREE *T)
{
    int val;
    scanf("%d",&val);
    if(val == 0)
    {
        *T = NULL;
    }
    else
    {
        *T = (BTREE)malloc(sizeof(BTNode));
        if(!*T)
        {
            exit(-1);
        }
        (*T)->data = val;
        CREATEBT(&(*T)->lchild);
        CREATEBT(&(*T)->rchild);
    }
    
}

//打印
void DFSPRINT(BTREE T)
{
    if(T == NULL)
    {
        return;
    }
//    前序
//    printf("%d ",T->data);
    DFSPRINT(T->lchild);
//    中序
//    printf("%d ",T->data);
    DFSPRINT(T->rchild);
//    后序
//    printf("%d ",T->data);
}

//层次遍历打印
void LAYERPRINT(BTREE T)
{
    int rear = -1, front = -1, len = 0;
    BTREE cur = NULL;
    BTREE QUEUE[50] = {NULL};
    QUEUE[++rear] = T;
    while(front != rear)
    {
        len = rear - front;
        while(len--)
        {
            cur = QUEUE[++front];
            if(cur != NULL)
            {
                printf("%d ",cur->data);
            }
            if(cur->lchild)
            {
                QUEUE[++rear] = cur->lchild;
            }
            if(cur->rchild)
            {
                QUEUE[++rear] = cur->rchild;
            }
        }
    }
}


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
//后序遍历
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


//exercise 8
#define NodeNum 50
int TESTCOMTREE(BTREE T)
{
    if(NULL == T)
    {
        return 1;
    }
    BTREE cur, QUEUE[NodeNum] = {NULL};
    int len = 0, flag = 0, front = -1, rear = -1;
    QUEUE[++rear] = T;
    while(front != rear)
    {
        len = rear - front;
        while(len--)
        {
            cur = QUEUE[++front];
            if(NULL != cur)
            {
                if(1 == flag)
                {
                    return 0;
                }
                QUEUE[++rear] = cur->lchild;    //此处不判断孩子是否为NULL，细节
                QUEUE[++rear] = cur->rchild;
            }
            else if(NULL == cur)
            {
                flag = 1;
            }
        }
    }
    return 1;
}



//{
//    BTREE QUEUE[NodeNum],p;
//    int front, rear, flag = 1, comflag = 1;
//    if(T != NULL)
//    {
//        QUEUE[0] = T;
//        front = -1;
//        rear = 0;
//        while(front < rear)
//        {
//            p = QUEUE[++front];
//            if(p->lchild == NULL)
//            {
//                flag = 0;
//                if(p->rchild != NULL)
//                {
//                    comflag = 0;
//                }
//            }
//            else
//            {
//                comflag = flag;
//                QUEUE[++rear] = p->rchild;
//                if(p->rchild != NULL)
//                {
//                    QUEUE[++rear] = p->rchild;
//                }
//                else
//                {
//                    flag = 0;
//                }
//            }
//        }
//    }
//    return comflag;
//}

//exercise 9  找给定结点
int SEARCHBT(BTREE T, BTREE p, int level)
{
    int count = 0;
    if(T == NULL)
    {
        return 0;
    }
    if(T == p)
    {
        return level;
    }
    if((count = SEARCHBT(T->lchild, p, level+1) > 0))
    {
        printf("left\ncount=%d\n",count);
        return count;
    }
    else
    {
        printf("right\n");
        return SEARCHBT(T->rchild, p, level+1);
    }
}


//exercise 10   求数据为item的结点的深度
int FINDITEM(BTREE T, int item)
{
    if(NULL == T)
    {
        return 0;
    }
    BTREE QUEUE[50], cur = NULL;
    int front = -1, rear = -1, level = 1, len;
    QUEUE[++rear] = T;
    while(front != rear)
    {
        len = rear - front;
        while(len--)
        {
            cur = QUEUE[++front];
            if(cur->data == item)
            {
                return level;
            }
            if(cur->lchild)
            {
                QUEUE[++rear] = cur->lchild;
            }
            if(cur->rchild)
            {
                QUEUE[++rear] = cur->rchild;
            }
        }
        level++;
    }
    return 0;
}

//exercise 11 层次从右到左
void REVERTLEVEL(BTREE T)
{
    BTREE QUEUE[NodeNum] = {NULL}, cur = NULL;
    int front = -1, rear = -1, len = 0;
    QUEUE[++rear] = T;
    while(rear != front)
    {
        len = rear - front;
        while(len--)
        {
            cur = QUEUE[++front];
            if(cur->data)
            {
                printf("%d ",cur->data);
            }
            if(cur->rchild)
            {
                QUEUE[++rear] = cur->rchild;
            }
            if(cur->lchild)
            {
                QUEUE[++rear] = cur->lchild;
            }
        }
    }
}


//exercise 12  打印所有左子树
void PRINTLEFT(BTREE T)
{
    BTREE STACK[NodeNum], p = T;
    int top = -1;
    if(T != NULL)
    {
        do{
            while(p != NULL)
            {
                STACK[++top] = p;
                p = p->lchild;
                if(p != NULL)
                {
                    printf("%d ",p->data);
                }
            }
            p = STACK[top--];
            p = p->rchild;
        }while(!(p == NULL && top == -1));
    }
}

//exercise 13  找p双亲结点，递归
BTREE FINDPARENT(BTREE T, BTREE p)
{
    BTREE parent = NULL;
    if(T == NULL)
    {
        return NULL;
    }
    if(T->lchild == p || T->rchild == p)
    {
        return T;
    }
    parent = FINDPARENT(T->lchild, p);
    if(parent != NULL)
    {
        return parent;
    }
    else
    {
        return FINDPARENT(T->rchild, p);
    }
}


//exercise 14  找兄弟
BTREE FINDBROTHER(BTREE T, BTREE p)
{
    if(T == NULL)
    {
        return NULL;
    }
    BTREE STACK[NodeNum] = {NULL}, cur = NULL;
    int top = -1;
    STACK[++top] = T;
    while(top != -1)
    {
        cur = STACK[top--];
        if(cur->lchild == p)
        {
            if(cur->rchild)
            {
                return cur->rchild;
            }
            else
            {
                return NULL;
            }
        }
        if(cur->rchild == p)
        {
            if(cur->lchild)
            {
                return cur->lchild;
            }
            else
            {
                return NULL;
            }
        }
        if(cur->rchild)
        {
            STACK[++top] = cur->rchild;
        }
        if(cur->lchild)
        {
            STACK[++top] = cur->lchild;
        }
    }
    return NULL;
}

//exercise 16  判断是否为二叉排序树
//中序遍历
int ISBST(BTREE T)
{
    if(T == NULL)
    {
        return 0;
    }
    BTREE STACK[NodeNum] = {NULL};
    int top = -1, min = -1; //假设最小不小于-1
    while(!(-1 == top && NULL == T))
    {
        while(T)
        {
            STACK[++top] = T;
            T = T->lchild;
        }
        T = STACK[top--];
        if(T->data < min)
        {
            return 0;
        }
        min = T->data;
        T = T->rchild;
    }
    return 1;
}

//exercise 17  二叉排序树打印祖先结点
//与第六题对比
//由于是二叉排序树，利用特性，不用遍历
void BST_ANCESTOR(BTREE T, int item)
{
    while(T != NULL)
    {
        if(T->data == item)
        {
            return;
        }
        if(T->data < item)
        {
            printf("%d ",T->data);
            T = T->rchild;
        }
        else
        {
            printf("%d ",T->data);
            T = T->lchild;
        }
    }
}



//exercise 18



#endif /* exceexercisesrcises_h */
