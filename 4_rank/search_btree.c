#include <stdio.h>
#include <stdlib.h>


typedef struct s_btree {
    int value;
    struct s_btree *left;
    struct s_btree *right;
} t_btree;

int search_binary_tree(t_btree *root, int value) {
    if (root == NULL) 
        return 0;
  
    if (root->value == value) 
        return 1;

    if (search_binary_tree(root->left, value) || search_binary_tree(root->right, value))
        return 1;
		
    return 0;
}

//TESTING

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

    // Search for values in the tree
    printf("Searching for 7: %d\n", search_binary_tree(root, 7)); // Output: 1
    printf("Searching for 9: %d\n", search_binary_tree(root, 9)); // Output: 0

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