//
//  excercises.c
//  tree
//
//  Created by duoguang xu on 2020/10/11.
//

#include "excercises.h"

int main()
{
//    int tree[14]={1,2,3,666,5,0,0,0,0,0,0};
//    PREORDER(tree);
    BTREE tree = NULL;
    CREATEBT(&tree);
//1 2 4 0 0 5 6 0 0 7 0 0 3 8 0 0 0;
    printf("层序遍历：\n");
    LAYERPRINT(tree);
    
    
//4 2 1 0 0 3 0 0 5 0 6 0 0
//    int justify = ISBST(tree);
//    if(justify)
//    {
//        printf("\nthis tree is bst!\n");
//    }
//    else
//    {
//        printf("\nnot a bst\n");
//    }
    printf("\n");
    BST_ANCESTOR(tree, 6);
    
//    第九题
//    BTREE p = tree->rchild->lchild;
//    printf("\np = %d\n",p->data);
//    BTREE father = FINDPARENT(tree, p);
//    printf("p's father = %d\n",father->data);
//    BTREE brother = FINDBROTHER(tree, p);
//    if(brother)
//    {
//        printf("p's brother = %d\n", brother->data);
//    }
    //    int level = SEARCHBT(tree, p, d);
//    printf("\nlevel = %d\n",level);
//    printf("%d\n",p->data);
    
//    int level = FINDITEM(tree, 3);
//    if(level)
//    {
//        printf("\n第%d层\n",level);
//    }
//    else
//    {
//        printf("\nno such item\n");
//    }
    
//    REVERTLEVEL(tree);
    
//    printf("\n");
//    PRINTLEFT(tree);
    
//    完全二叉树判断
//    int tes = 0;
//    tes = TESTCOMTREE(tree);
//    if(tes == 1)
//    {
//        printf("\n完全二叉树\n");
//    }
//    else
//    {
//        printf("\n非完全二叉树\n");
//    }
    
    return 0;
}
