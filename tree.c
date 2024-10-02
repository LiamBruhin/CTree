#include <stdio.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} node;


void add(node *root, int newVal) 
{
    node newNode;
    newNode.val = newVal;
    newNode.left = NULL;
    newNode.right = NULL;

    node *cursor = root;
    while(1)
    {
        // NOTE: Right Case
        if(newVal > cursor->val)
        {
            if(!cursor->right)
            {
                cursor->right = &newNode;
                break;
            }
            else 
            {
                cursor = cursor->right;
            }
        }
        // NOTE: Left Case
        else if(newVal < cursor->val) 
        {
            if(!cursor->left) 
            {
                cursor->left = &newNode;
                break;
            }
            else 
            {
                cursor = cursor->left;
            }
        }
        break;
    }
}

void space(int num){
    for (int i = 0; i < num; i++) {
        printf(" ");
    }
}

void printNode(node root) {
    /*
    space(3);
    printf("%i\n", node.val);
    space(2);
    printf("/ \\\n");
    space(1);
    printf("%i", node.left->val);
    space(2);
    printf("%i", node.right->val);
    */

    node cursor = root;
    for(int i = 0; i < 5; i++)
    {
        printf("%i", cursor.val);
        cursor = *cursor.right;
    }
}

int main(int argc, char **argv) {
    node root = {};
    root.val = 5;
    for(int i = 0; i < 10; ++i) 
    {
        add(&root, i);
    }

    printNode(root);
    return 0;
}
