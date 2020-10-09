//
//  main.c
//  tree
//
//  Created by duoguang xu on 2020/10/7.
//

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"




int main()
{
    BTREE tree;
    printf("input the node:\n"); //例：ABC  DE  F  G  ;   复制到“；“之前
    BUILDBT(&tree);
    
//    删除二叉树
    tree = DELETBT(&tree, 'D');
    
//    交换所有结点左右子树的位置
//    EXCHANGEBT(tree);
    
    
//    PreOrderexchange(tree);
    
    
//    复制
//    BTREE fake;
//    fake = COPYBT(tree);
//    检查复制树是否相同
//    int test = EQUALBT(tree, fake);
//    if(test)
//    {
//        printf("same\n");
//    }
//    else
//    {
//        printf("different\n");
//    }
    
//    销毁
//    CLEARBT(&tree);
//    if(tree == NULL)
//    {
//        printf("clear successful!\n");
//    }
    
//    深度
//    int depth = 0;
//    depth = DEEP_BFS(tree);
//    printf("depth:%d\n", depth);
    
//    广度优先遍历输出元素值
    printf("广度优先：\n");
    BFS(tree);
    
    
//    深度优先遍历输出元素
    printf("\n前序遍历：\n");
    PreOrderTraverse (tree);
    printf("\n中序遍历：\n");
    InOrderTraverse(tree);
    printf("\n后续遍历：\n");
    PostOrderTraverse(tree);
    
//    求结点层次
//    int level = 0;
//    level = LAYERBT(tree,'U');
//    if(level)
//    {
//        printf("level = %d\n",level);
//    }
//    else
//    {
//        printf("no such item!\n");
//    }
    
    
    
    
    
    
    return 0;
}
