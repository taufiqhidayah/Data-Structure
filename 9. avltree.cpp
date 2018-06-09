#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}* root;

    int height(Node *);
    Node *rr_rotation(Node *);
    Node *ll_rotation(Node *);
    Node *lr_rotation(Node *);
    Node *rl_rotation(Node *);
    Node* balance(Node *);
    Node* insert(Node *, int );
    void display(Node *, int);

int main()
{
    int choice, item;
    while (1)
    {
        system("cls");
        printf("\n---------------------");
        printf("\nAVL TREE");
        printf("\n---------------------");
        printf("\n1.Insert Element into the tree");
        printf("\n2.Display Balanced AVL Tree");
        printf("\n3.Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter value to be inserted: ");
            scanf("%d",&item);
            root = insert(root, item);
            break;
        case 2:
            if (root == NULL)
            {
                printf("Tree is Empty......");
                getchar();getchar();
                continue;
            }
            printf("Balanced AVL Tree:");
            display(root, 1);
            printf("\nNext....");getchar();getchar();
            break;
            case 6:
            exit(1);    
            break;
        }
    }
    return 0;
}
 //count heigh of tree
int height(Node *temp){
      int leftheight, rightheight;
      if(temp==NULL)
      return 0;
      else {
        leftheight = height(temp->left);
        rightheight = height(temp->right);
        if(leftheight > rightheight)
        return (leftheight + 1);
        else
        return (rightheight + 1);
      }
}
 // save value to temp before balancing
int diff(Node *temp){
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
 // do right -> right rotate
Node *rr_rotation(Node *parent){
    Node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
// do left -> left rotation
Node *ll_rotation(Node *parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
//do left right rotation
Node *lr_rotation(Node *parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
 //do right left rotation
Node *rl_rotation(Node *parent)
{
    Node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
 //check balancing of tree
Node *balance(Node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}
 //insert new to tree
Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}
 //display tree balannce
void display(Node *ptr, int level){
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
        printf("root->");
        for (i = 0; i < level && ptr != root; i++)
        printf( "        ");
        printf("%d", ptr->data);
        display(ptr->left, level + 1);
    }
}
