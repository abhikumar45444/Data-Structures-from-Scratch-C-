#include"StackUsingLinkedList.h"
#include"Queue.h"
#include<assert.h>

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

void CreateBinaryTree(struct TreeNode **root);
void DisplayTree(struct TreeNode *root);
void IterativePreorder(struct TreeNode *root);
void IterativeInorder(struct TreeNode *temp);
void IterativePostorder(struct TreeNode *temp);
int CountNodes(struct TreeNode *temp);
void FreeBinaryTree(struct TreeNode **root);
void _FreeBinaryTree(struct TreeNode *root);

void tree_traversal(struct TreeNode* root) //Inorder Traversing function
{ 
	struct TreeNode* temp = root;
	struct Stack s_temp;
    CreateStack(&s_temp);
    int flag = 1;
	while(flag) //Loop run untill temp is null and stack is empty
	{
		if(temp){
			printf("%d",temp->data);
                        Push(&s_temp,temp);
			temp = temp->left;
		}
		else{
			if(!IsEmpty(&s_temp)){
				temp = Pop(&s_temp);
				temp = temp->right;
			}
			else
				flag = 0;
		}
	 } 
}

int main()
{
    // struct TreeNode* root;
	// root = calloc(1,sizeof(struct TreeNode));
    // root->data = 10;
    // root->left = calloc(1,sizeof(struct TreeNode));
    // root->right = calloc(1,sizeof(struct TreeNode));
    // root->left->data = 20;
    // root->right->data = 30;
    // tree_traversal(root); 

    struct TreeNode *root = NULL;
    CreateBinaryTree(&root);
    // printf("root = %d\n", root->data);
    DisplayTree(root);
    IterativePreorder(root);
    // tree_traversal(root);
    IterativeInorder(root);
    // IterativePostorder(root);
    printf("nodes count : %d\n", CountNodes(root));
    printf("hello\n");
     DisplayTree(root);
    FreeBinaryTree(&root);
     DisplayTree(root);
    return 0;
}


void CreateBinaryTree(struct TreeNode **root)
{
    struct TreeNode *parent = NULL, *child = NULL;
    struct Queue queue;
    CreateQueue(&queue);
    int data = 10;
    printf("Enter the data of root node: ");
    scanf("%d", &data);
    parent = malloc(sizeof(struct TreeNode));
    assert(parent != NULL);
    parent->data = data;
    parent->left = NULL;
    parent->right = NULL;

    *root = parent;

    Enqueue(&queue, *root);
    // int i = 1;
    while(!IsQueueEmpty(queue))
    {
        parent = Dequeue(&queue);

        printf("Enter the value of left child of %d node(-1 if no child): ", parent->data);
        scanf("%d", &data);
        // if(i == 1)
        //     data = 20;
        if(data != -1){
            child = malloc(sizeof(struct TreeNode));
            assert(child != NULL);
            child->data = data;
            child->left = NULL;
            child->right = NULL;
            parent->left = child;
            Enqueue(&queue, child);
        }

        printf("Enter the value of right child of %d node(-1 if no child): ", parent->data);
        scanf("%d", &data);
        // if(i == 1)
        //     data = 30;
        if(data != -1){
            child = malloc(sizeof(struct TreeNode));
            assert(child != NULL);
            child->data = data;
            child->left = NULL;
            child->right = NULL;
            parent->right = child;
            Enqueue(&queue, child);
        }
        // i = 0;
        // data = -1;
        
    }

    FreeQueue(&queue);
}


void IterativePreorder(struct TreeNode *temp)
{
    struct Stack stack;
    CreateStack(&stack);
    // struct TreeNode *temp = root;
    printf("Iterative preorder\n");
    while(temp != NULL || !IsEmpty(&stack))
    {
        if(temp != NULL)
        {
            printf("%d ", temp->data);
            Push(&stack, temp);
            temp = temp->left;
        }
        else
        {
            temp = Pop(&stack);
            if(!temp)
                break;
            temp = temp->right;
        }
    }
    FreeStack(&stack);
    // printf("%d\n", root->data);
    printf("\n");
}


void IterativeInorder(struct TreeNode *temp)
{
    struct Stack stack;
    CreateStack(&stack);
    // struct TreeNode *temp = root;
    printf("Iterative ineorder\n");
    while(temp != NULL || !IsEmpty(&stack))
    {
        if(temp != NULL)
        {
            Push(&stack, temp);
            temp = temp->left;
        }
        else
        {
            temp = Pop(&stack);
            if(!temp)
                break;
            printf("%d ", temp->data);
            temp = temp->right;
        }
    }
    FreeStack(&stack);
    // printf("%d\n", root->data);
    printf("\n");
}


// NOTE: TO BE IMPLEMENTED
void IterativePostorder(struct TreeNode *temp)
{
    struct Stack stack;
    CreateStack(&stack);
    // struct TreeNode *temp = root;
    printf("Iterative postorder\n");
    while(temp != NULL || !IsEmpty(&stack))
    {
        if(temp != NULL)
        {
            Push(&stack, temp);
            temp = temp->left;
        }
        else
        {
            temp = Pop(&stack);
            if(!temp)
                break;
            temp = temp->right;
            printf("%d ", temp->data);
        }
    }
    FreeStack(&stack);
    // printf("%d\n", root->data);
    printf("\n");
    
}

void DisplayTree(struct TreeNode *root)
{
    if(root == NULL)
    {
        printf("Empty Tree\n");
        return;
    }

    struct TreeNode *node = NULL;
    struct Queue queue;
    CreateQueue(&queue);
    Enqueue(&queue, root);
    while(!IsQueueEmpty(queue))
    {
        node = Dequeue(&queue);
        printf("%d ", node->data);
        if(node->left != NULL)
        {
            Enqueue(&queue, node->left);
        }
        if(node->right != NULL)
        {
            Enqueue(&queue, node->right);
        }
    }
    printf("\n");
    FreeQueue(&queue);
}


int CountNodes(struct TreeNode *temp)
{
    int x, y;
    if(temp != NULL)
    {
        x = CountNodes(temp->left);
        y = CountNodes(temp->left);
        return x + y + 1;
    }
    return 0;
}


void _FreeBinaryTree(struct TreeNode *root)
{
    if(root == NULL)
        return;

    _FreeBinaryTree(root->left);
    _FreeBinaryTree(root->right);
    free(root);
}

void FreeBinaryTree(struct TreeNode **root)
{

    _FreeBinaryTree(*root);
    *root = NULL;
}

// void FreeBinaryTree(struct TreeNode **root)
// {
//     struct TreeNode *parent = NULL, *child = NULL;
//     struct Queue queue;
//     CreateQueue(&queue);

//     Enqueue(&queue, *root);
//     while(!IsQueueEmpty(queue))
//     {
//         *root = Dequeue(&queue);
//         if((*root)->left)
//         {
//             Enqueue(&queue, (*root)->left);
//         }

//         if((*root)->right)
//         {
//             Enqueue(&queue, (*root)->right);
//         }

//         free((*root));
//     }

//     *root = NULL;
//     FreeQueue(&queue);
// }