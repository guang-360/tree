//
//  bst.h
//  tree
//
//  Created by duoguang xu on 2020/10/8.
//

#ifndef bst_h
#define bst_h
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *lchild, *rchild;
} BTNode, *BTREE;

#define LEN sizeof(BTNode)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//插入（非递归）
void INSERTBST(BTREE *T, int item)
{
    BTREE p, q;
    p = (BTREE)malloc(LEN);
    p->data = item;
    p->lchild = NULL;
    p->rchild = NULL;
    if (*T == NULL)
    {
        *T = p;
    }
    else
    {
        q = *T;
        while (1)
        {
            if (item < q->data) //用<而不是<=，说明相同元素插到右边
            {
                if (q->lchild != NULL)
                {
                    q = q->lchild;
                }
                else
                {
                    q->lchild = p;
                    break;
                }
            }
            else
            {
                if (q->rchild != NULL)
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

BTREE SORTTREE()
{
    BTREE tree = NULL;
    printf("Create Binary Search Tree\nplease enter the element, seperated by space, and stop input by Enter:\n");
    int key;
    while(1)
    {
        scanf("%d", &key);
        INSERTBST(&tree, key);
        if( getchar() == '\n' )
            break;
    }
    return tree;
}
//n次插入，建立二叉排序树
//BTREE SORTTREE(int K[], int n)
//{
//    BTREE T = NULL;
//    int i;
//    if (n > 0)
//    {
//        for (i = 0; i < n; i++)
//        {
//            INSERTBST(&T, K[i]); //n次调用插入函数
//        }
//    }
//    return T;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//前序遍历
void PreOrderPresent(BTREE T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", T->data);
        PreOrderPresent(T->lchild);
        PreOrderPresent(T->rchild);
    }
}

//中序遍历
void InOrderPresent(BTREE T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        InOrderPresent(T->lchild);
        printf("%d ", T->data);
        InOrderPresent(T->rchild);
    }
}

//后序遍历
void PostOrderPresent(BTREE T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        PostOrderPresent(T->lchild);
        PostOrderPresent(T->rchild);
        printf("%d ", T->data);
    }
}

//求深度
int BSTdepth(BTREE T)
{
    int level = 0;
    BTREE queue[50];
    BTREE cur = NULL;
    int rear = -1;
    int front = -1;
    int len = 0;
    queue[++rear] = T;
    while (front != rear)
    {
        len = rear - front;
        while (len--)
        {
            cur = queue[++front];
            if (cur->lchild)
            {
                queue[++rear] = cur->lchild;
            }
            if (cur->rchild)
            {
                queue[++rear] = cur->rchild;
            }
        }
        level++;
    }
    return level;
}

//逐层输出
void BSTper(BTREE T)
{
    if(NULL == T)
    {
        return ;
    }
    int level = 0;
    BTREE queue[50];
    BTREE cur = NULL;
    int rear = -1;
    int front = -1;
    int len = 0;
    queue[++rear] = T;
    while (front != rear)
    {
        printf("\n第%d层：\n", level + 1);
        len = rear - front;
        while (len--)
        {
            cur = queue[++front];
            if (cur != NULL)
            {
                printf("%d ", cur->data);
            }
            if (cur->lchild)
            {
                queue[++rear] = cur->lchild;
            }
            if (cur->rchild)
            {
                queue[++rear] = cur->rchild;
            }
        }
        level++;
    }
}

//广度优先输出
void BFSPresent(BTREE T)
{
    if(T == NULL)
    {
        return;
    }
    BTREE queue[50];
    int rear = -1;
    int front = -1;
    int len = 0;
    BTREE cur = NULL;
    queue[++rear] = T;
    while (front != rear)
    {
        len = rear - front;
        while (len--)
        {
            cur = queue[++front];
            if (cur != NULL)
            {
                printf("%d ", cur->data);
            }
            if (cur->lchild)
            {
                queue[++rear] = cur->lchild;
            }
            if (cur->rchild)
            {
                queue[++rear] = cur->rchild;
            }
        }
    }
}


//查找（非递归）
BTREE SEARCHBST1(BTREE T, int item)
{
    if(T==NULL)
    {
        printf("\nsearch fail!\n");
        return NULL;
    }
    BTREE p = T;
    while(p!=NULL)
    {
        if(p->data == item)
        {
            printf("\nsearch succeed!\n");
            return p;
        }
        if(p->data < item)
        {
            p = p->rchild;
        }
        else
        {
            p = p->lchild;
        }
    }
    if(p==NULL)
    {
        printf("\nsearch fail!\n");
        return NULL;
    }
    return p;
}

//查找（递归）
BTREE SEARCHBST2(BTREE T, int item)
{
    if(T==NULL)
    {
        printf("\nsearch fail!\n");
        return NULL;
    }
    if(T->data==item)
    {
        printf("\nsearch succeed!\n");
        return T;
    }
    if(T->data < item)
    {
        return SEARCHBST2(T->rchild, item);
    }
    else
    {
        return SEARCHBST2(T->lchild, item);
    }
}

void write2dot(BTREE tree, FILE* fw)
{
    if(tree == NULL)
        return ;
    else
    {
        fprintf(fw, "%d [label = \"<f0> | <f1> %d | <f2> \", color = black, fontcolor = white, style = filled];\n", tree->data, tree->data);
    }
    if(tree->lchild)
    {
        fprintf(fw, "%d [label = \"<f0> | <f1> %d | <f2> \", color = black, fontcolor = white, style = filled];\n", tree->lchild->data, tree->lchild->data);
        fprintf(fw, "%d:f0:sw -> %d:f1;\n", tree->data, tree->lchild->data);
    }
    if(tree->rchild)
    {
        fprintf(fw, "%d [label = \"<f0> | <f1> %d | <f2> \", color = black, fontcolor = white, style = filled];\n", tree->rchild->data, tree->rchild->data);
        fprintf(fw, "%d:f2:se -> %d:f1;\n", tree->data, tree->rchild->data);
    }
    write2dot(tree->lchild, fw);
    write2dot(tree->rchild, fw);
}

void visualization(BTREE tree, char* filename)
{
    FILE *fw;
    if( NULL == (fw = fopen(filename, "w")) )
    {
        printf("open file error");
        exit(0);
    }
    fprintf(fw, "digraph\n{\nnode [shape = Mrecord, style = filled, color = black, fontcolor = white];\n");
    write2dot(tree, fw);
    fprintf(fw, "}");
    fclose(fw);
}



void BSTinfo(BTREE tree)
{
    int depth = 0;
    char fp[] = "/Users/duoguangxu/Documents/XCODE/tree/tree/graph.dot";
    int num = 0;
    int item = 0;
    while (1)
    {
        printf("What do you want to do？\n1.广度优先\n2.前序遍历\n3.中序遍历\n4.后序遍历\n5.深度\n6.逐层查看\n7.查找\n8.插入\n9.可视化\n0.退出\n");

        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("\n广度优先：\n");
            BFSPresent(tree);
            break;
        case 2:
            printf("\n前序遍历：\n");
            PreOrderPresent(tree);
            break;
        case 3:
            printf("\n中序遍历：\n");
            InOrderPresent(tree);
            break;
        case 4:
            printf("\n后序遍历：\n");
            PostOrderPresent(tree);
            break;
        case 5:
            depth = BSTdepth(tree);
            printf("\n深度为：\n%d", depth);    //深度
            break;
        case 6:
            BSTper(tree);   //逐层
            break;
        case 7:
            printf("what do you need to search?\n");
            scanf("%d",&item);
            tree = SEARCHBST1(tree, item);
            break;
        case 8:
            printf("please input the element to be inserted:\n");
            scanf("%d",&item);
            INSERTBST(&tree, item);
            break;
        case 9:
            visualization(tree, fp);
            break;
        case 0:
            exit(0);
            break;
        }
        while (1)
        {
            printf("\n\ncontinue?\n1.yes      2.no\n");
            scanf("%d", &num);
            if (num == 1)
            {
                break;
            }
            if (num == 2)
            {
                exit(0);
            }
            else
            {
                printf("\nPlease enter correct number!\n");
            }
        }
    }

}

#endif /* bst_h */
