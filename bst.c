//
//  bst.c
//  tree
//
//  Created by duoguang xu on 2020/10/8.
//

//arithmetic about binary sort tree


#include "bst.h"

int main()
{
    int k[]={8,23,5,2,4,23,5,45,23,65,1};
    int len = sizeof(k)/sizeof(k[0]);
    BTREE tree = NULL;
    tree = SORTTREE(k, len);
    
    BSTinfo(tree);
    return 0;
}
