#include <stdio.h>
#include <stdlib.h>

typedef struct s_btree {
    int value;
    struct s_btree *left;
    struct s_btree *right;
} t_btree;

// Function to calculate the height of the binary tree
int max(int a, int b) {
    if (a > b) 
        return a;
    else 
        return b;
}
int tree_height(t_btree *root) {
    if (root == NULL) 
	{
        return 0;
    }

    // Recursively find the height of the left and right subtrees
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);

    // Return the greater of the two heights plus 1 for the current node
    return 1 + max(left_height, right_height);
}

// Helper function to create a new tree node
t_btree *create_node(int value) {
    t_btree *new_node = (t_btree *)malloc(sizeof(t_btree));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

// Example usage
int main() {
    // Create a simple binary tree
    t_btree *root = create_node(10);
    root->left = create_node(5);
    root->right = create_node(15);
    root->left->left = create_node(2);
    root->left->right = create_node(7);
    root->right->left = create_node(12);
    root->right->right = create_node(20);

    // Calculate the height of the tree
    int height = tree_height(root);
    printf("Height of the tree: %d\n", height); // Output: 3

    // Free the allocated memory
    // Note: In a real-world scenario, you would write a function to properly free the entire tree.
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}