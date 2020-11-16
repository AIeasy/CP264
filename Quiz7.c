#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
    int height; 
}; 
int getTreeHeight(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
struct Node* newNode(int key) 
{ 
    struct Node* node = (struct Node*) 
                        malloc(sizeof(struct Node)); 
    node->key   = key; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1;  // new node is initially added at leaf 
    return(node); 
} 
struct Node *Rotateright(struct Node *y) 
{ 
    struct Node *x = y->left; 
    struct Node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(getTreeHeight(y->left), getTreeHeight(y->right))+1; 
    x->height = max(getTreeHeight(x->left), getTreeHeight(x->right))+1; 
  
    // Return new root 
    return x; 
} 
struct Node *Rotateleft(struct Node *x) 
{ 
    struct Node *y = x->right; 
    struct Node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(getTreeHeight(x->left), getTreeHeight(x->right))+1; 
    y->height = max(getTreeHeight(y->left), getTreeHeight(y->right))+1; 
  
    // Return new root 
    return y; 
} 
struct Node *rrRotation(struct Node *T){
   T=Rotateleft(T);
    return(T);
}
struct Node *llRotation(struct Node *T){
    T=Rotateright(T);
	return(T);
}
struct Node *lrRotation(struct Node *T){
    T->left=Rotateleft(T->left);
	T=Rotateright(T);
	
	return(T);
}
struct Node *rlRotation(struct Node *T){
    T->right=Rotateright(T->right);
	T=Rotateleft(T);
	return(T);
}
void inorder(struct Node *root) {
	if (root != NULL) {
		inorder(root->left);
		printf(" current value: %c\n", root->key);
		inorder(root->right);
	}
}
struct Node * minValueNode(struct Node* node) 
{ 
    struct Node* temp = node; 
    while (temp->left != NULL){
        temp = temp->left; 
    }
        return temp; 
} 
int BalanceFactor(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return getTreeHeight(N->left) - getTreeHeight(N->right); 
} 
struct Node* insertInTree(struct Node* node, int key) 
{ 
    if (node == NULL) 
        return(newNode(key)); 
    if (key < node->key) 
        node->left  = insertInTree(node->left, key); 
    else if (key > node->key) 
        node->right = insertInTree(node->right, key); 
    else
        return node; 
  
    node->height = 1 + max(getTreeHeight(node->left), getTreeHeight(node->right)); 
    int balance = BalanceFactor(node); 
  
  
    if (balance > 1 && key < node->left->key){
        return llRotation(node); 
    }
    if (balance < -1 && key > node->right->key){
        return rrRotation(node); 
    }   
    if (balance > 1 && key > node->left->key) 
    { 
        return lrRotation(node);
    } 
    if (balance < -1 && key < node->right->key) 
    { 
        return rlRotation(node);
    } 
    return node; 
} 
struct Node* deleteFromTree(struct Node* root, int key) 
{ 
  
    if (root == NULL) 
        return root; 
    if ( key < root->key ) 
        root->left = deleteFromTree(root->left, key); 
    else if( key > root->key ) 
        root->right = deleteFromTree(root->right, key); 
  
    else
    { 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            struct Node *temp = root->left ? root->left : root->right; 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else{
                *root = *temp; 
            }
             
            free(temp); 
        } 
        else{ 
            struct Node* temp = minValueNode(root->right); 
            root->key = temp->key; 
            root->right = deleteFromTree(root->right, temp->key); 
        } 
    } 
    if (root == NULL){
        return root; 
    }
      
    root->height = max(getTreeHeight(root->left) +1, getTreeHeight(root->right)); 
  
    int balance = BalanceFactor(root); 
    // LeftLeft Case 
    if (balance > 1 && BalanceFactor(root->left) >= 0) 
        return llRotation(root); 
  
    // LeftRight Case 
    if (balance > 1 && BalanceFactor(root->left) < 0) 
    { 
        
        return lrRotation(root); 
    } 
  
    // RightRight Case 
    if (balance < -1 && BalanceFactor(root->right) <= 0) 
        return rrRotation(root); 
  
    // RightLeft Case 
    if (balance < -1 && BalanceFactor(root->right) > 0) 
    { 
        return rlRotation(root); 
    } 
  
    return root; 
} 
int main() 
{ 
  struct Node *root = NULL; 
    char choice;
    char x;
    do{
        printf("===============================\n");
        printf("        'C'reate a tree:\n");
        printf(" 'I'nsert into the tree:\n");
        printf("     'D'elete from tree:\n");
        printf("           'P'rint the tree:\n");
        printf("   'Q'uit the program:\n");
        printf("\n===============================\n");
        printf("Input your selection:");
        scanf(" %c", &choice);
    switch (choice){
        case 'C': 
                root = insertInTree(root, 'e');
                root = insertInTree(root, 'v');
                root = insertInTree(root, 'e');
                root = insertInTree(root, 'r');
                root = insertInTree(root, 'y');
                root = insertInTree(root, 'b');
                root = insertInTree(root, 'o');
                root = insertInTree(root, 'd');
                root = insertInTree(root, 'y');
                root = insertInTree(root, 'i');
                root = insertInTree(root, 's');
                root = insertInTree(root, 'a');
                root = insertInTree(root, 'g');
                root = insertInTree(root, 'e');
                root = insertInTree(root, 'n');
                root = insertInTree(root, 'i');
                root = insertInTree(root, 'u');
                root = insertInTree(root, 's');
				break;
				
			case 'I': printf("\nEnter a data:");
					scanf("%c",&x);
					root=insertInTree(root,x);
					break;
					
			case 'D': printf("\nEnter a data:");
					scanf("%c",&x);
					root=deleteFromTree(root,x);
					break;
			
			case 'P': 
					printf("\n\nInorder sequence:\n");
					inorder(root);
					printf("\n");
					break;			
		}
    }while (choice!='Q');
    
    return 0; 
} 