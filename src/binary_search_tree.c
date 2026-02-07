#include<stdio.h>  // Standard Input/Output library for printf and scanf
#include<stdlib.h> // Standard library for memory allocation and general functions

// Definition of a node in the binary search tree (BST)
struct n {
	int data;             // Data stored in the node
	struct n * left;      // Pointer to the left child
	struct n * right;     // Pointer to the right child
};
typedef struct n node; // 'node' is now an alias for 'struct n'

// Global variable to store depth
int x = 0;

// Function to calculate the depth of the binary tree
int depth(node* root) {
	if(root == NULL) {
		return x;
	}
	if(root->left == NULL && root->right == NULL) {
		return x;
	}
	x = x + 1;
	int leftdepth = depth(root->left);
	int rightdepth = depth(root->right);
	if(leftdepth > rightdepth) {
		return leftdepth;
	}
	return rightdepth;
}

// Function to calculate the sum of all leaf nodes in the binary tree
int leafsum(node *tree) {
    if (tree == NULL) {
        return 0;
    }
    if (tree->left == NULL && tree->right == NULL) {
        return tree->data;
    }
    return leafsum(tree->left) + leafsum(tree->right);
}

// Function to find the maximum value in the binary tree
int max(node *tree) {
	while(tree->right != NULL) {
		tree = tree->right;
	}
	return tree->data;
}

// Function to find the minimum value in the binary tree
int min(node *tree) {
	while(tree->left != NULL) {
		tree = tree->left;
	}
	return tree->data;
}

// Function to insert a new value into the binary search tree
node *insert(node *tree, int x) {
    if (tree == NULL) {
        node *root = (node *)malloc(sizeof(node));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (x < tree->data) {
        tree->left = insert(tree->left, x);
    } else if (x > tree->data) {
        tree->right = insert(tree->right, x);
    }
    return tree;
}

// Function to traverse and print the elements of the binary tree (in-order traversal)
void traverse(node *tree) {
	if(tree == NULL) {
		return;
	}
	traverse(tree->left);
	printf("%d ", tree->data);
	traverse(tree->right);
}

// Function for pre-order traversal (Root, Left, Right)
void preorder(node *tree) {
	if(tree == NULL) {
		return;
	}
	printf("%d ", tree->data);
	preorder(tree->left);
	preorder(tree->right);
}

// Function for post-order traversal (Left, Right, Root)
void posrtorder(node *tree) {
	if(tree == NULL) {
		return;
	}
	posrtorder(tree->left);
	posrtorder(tree->right);
	printf("%d ", tree->data);
}

// Function for in-order traversal (Left, Root, Right)
void inorder(node *tree) {
	if(tree == NULL) {
		return;
	}
	inorder(tree->left);
	printf("%d ", tree->data);
	inorder(tree->right);
}

// Function to search for a value in the binary search tree
int search(node *tree, int x) {
	if(tree == NULL) {
		return -1;
	}
	if(tree->data == x) {
		return 1;
	}
	if(search(tree->left, x) == 1) {
		return 1;
	}	
	if(search(tree->right, x) == 1) {
		return 1;
	}
	return -1;	
}

// Function to delete a value from the binary search tree
node *delet(node *tree, int x) {
	if(tree == NULL) {
		return NULL;
	}
	if(tree->data == x) {
		if(tree->right == NULL && tree->left == NULL) {
			return NULL;
		}
		if(tree->right != NULL) {
			tree->data = min(tree->right);
			tree->right = delet(tree->right, min(tree->right));
			return tree;
		}	
		tree->data = max(tree->left);
		tree->left = delet(tree->left, max(tree->left));
		return tree;
	}
	if(tree->data < x) {
		tree->right = delet(tree->right, x);
		return tree;
	}
	tree->left = delet(tree->left, x);
	return tree;
}

int main() {
    node *tree = NULL; 
    
    // Insert nodes into the binary search tree
    tree = insert(tree, 5);
    tree = insert(tree, 3);
    tree = insert(tree, 7);
    tree = insert(tree, 1);
    tree = insert(tree, 4);
    tree = insert(tree, 6);
    tree = insert(tree, 9);
    tree = insert(tree, 0);
    
    // Calculate the depth of the binary tree
    printf("Depth of the tree: %d\n", depth(tree));
 
    // Print tree using in-order traversal
    printf("In-order Traversal: ");
    inorder(tree);
    printf("\n");
    
    // Print tree using pre-order traversal
    printf("Pre-order Traversal: ");
    preorder(tree);
    printf("\n");
    
    // Print tree using post-order traversal
    printf("Post-order Traversal: ");
    posrtorder(tree);
    printf("\n");

    // Print all nodes in the tree
    printf("Tree contents (in-order): ");
    traverse(tree);
    printf("\n");
    
    // Search for a specific value in the tree
    int search_number = 4;
    if (search(tree, search_number) == 1) {
        printf("%d found in the tree.\n", search_number);
    } else {
        printf("%d not found in the tree.\n", search_number);
    }	
    
    // Delete a value from the tree
    int delete_number = 5;
    tree = delet(tree, delete_number);
    
    // Print tree contents after deletion
    printf("Tree contents after deletion: ");
	traverse(tree);
	
    return 0;
}


