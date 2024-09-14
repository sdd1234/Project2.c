#include <stdio.h>
#include <stdlib.h>
#include "ItrTreeTrv.h"

TreeNode root[15];

void PlaceNode(TreeNode* parent, int direction, TreeNode* child) {
    if (direction == 0) {
        parent->left = child;
    }
    else if (direction == 1) {
        parent->right = child;
    }
}

void GenerateLinkTree(TreeNode root[]) {
    for (int i = 0; i < 15; i++) {
        root[i].data = i + 1;
        root[i].left = NULL;
        root[i].right = NULL;
    }
    PlaceNode(&root[0], 0, &root[1]);  
    PlaceNode(&root[0], 1, &root[4]);  
    PlaceNode(&root[1], 0, &root[2]);  
    PlaceNode(&root[2], 0, &root[3]);  
    PlaceNode(&root[1], 1, &root[5]); 
    PlaceNode(&root[4], 0, &root[6]);  
    PlaceNode(&root[4], 1, &root[7]);  
    PlaceNode(&root[7], 0, &root[8]); 
    PlaceNode(&root[7], 1, &root[9]);  
    PlaceNode(&root[9], 0, &root[10]); 
    PlaceNode(&root[9], 1, &root[11]); 
    PlaceNode(&root[11], 0, &root[12]); 
    PlaceNode(&root[11], 1, &root[13]); 
    PlaceNode(&root[13], 0, &root[14]);
}



void LinkOrders(TreeNode* root) {
    printf("Preorder: ");
    LinkPreOrder(root);
    printf("\n");
    printf("Inorder:  ");
    LinkInOrder(root);
    printf("\n");
    printf("Postorder:");
    LinkPostOrder(root);
    printf("\n");
}


int main() {
    GenerateLinkTree(root);
    LinkOrders(root);
    printf("\n");
    return 0;
}
