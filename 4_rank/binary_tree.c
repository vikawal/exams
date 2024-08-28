#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

//CREATE A NODE
t_btree		*btree_create_node(void *item)
{
	t_btree	*elem;

	elem = malloc(sizeof(t_btree));
	if (elem)
	{
		elem->left = NULL;
		elem->right = NULL;
		elem->item = item;
	}
	return (elem);
}
// TESTING

// void print_node(t_btree *node)
// {
// 	if (node && node->item)
// 		printf("%s\n", (char *)node->item);
// }

// int main(void)
// {
// 	t_btree *root = btree_create_node("root");
// 	t_btree *left = btree_create_node("left");
// 	t_btree *right = btree_create_node("right");

// 	root->left = left;
// 	root->right = right;

// 	// Print the items
// 	print_node(root);
// 	print_node(root->left);
// 	print_node(root->right);

// 	// Free allocated memory
// 	free(root);
// 	free(left);
// 	free(right);

// 	return 0;
// }

//INSERT INT

void btree_insert(t_btree **root, int item)
{
    if (*root == NULL)
    {
        // If the tree is empty, create a new node as the root
        *root = btree_create_node(item);
    }
    else
    {
        // Recursively find the correct position to insert the new item
        if (item < (*root)->item)
        {
            btree_insert(&(*root)->left, item);
        }
        else
        {
            btree_insert(&(*root)->right, item);
        }
    }
}

// APPLY PREFIX
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	(*applyf)(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}
//APPLY INFIX
void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_infix(root->left, applyf);
	(*applyf)(root);
	btree_apply_infix(root->right, applyf);
}
//APPLY SUFFIX

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	(*applyf)(root);
}

//INERT DATA

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *,
	void *))
{
	t_btree	*node;

	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	node = *root;
	if ((*cmpf)(item, node->item) < 0)
	{
		if (node->left)
			btree_insert_data(&node->left, item, cmpf);
		else
			node->left = btree_create_node(item);
	}
	else
	{
		if (node->right)
			btree_insert_data(&node->right, item, cmpf);
		else
			node->right = btree_create_node(item);
	}
}
void print_tree(t_btree *root)
{
	if (!root)
		return ;
	printf("%s ", root->item);
	print_tree(root->left);
	print_tree(root->right);
}

int main(int ac, char *av[])
{
	t_btree *root = NULL;
	for (size_t i = 1; i < ac; i++)
		btree_insert_data(&root, av[i], (int (*)(void *, void *))&strcmp);
	print_tree(root);
	return 0;
}

//SEARCH ITEM

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *,
	void *))
{
	if (!root)
		return NULL;
	if ((*cmpf)(root->item, data_ref) > 0)
		return btree_search_item(root->left, data_ref, cmpf);
	else if (root && (*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	else if ((*cmpf)(root->item, data_ref) < 0)
		return btree_search_item(root->right, data_ref, cmpf);
	else
		return (NULL);
}

char *getNum(int n)
{
	char *str;
	asprintf(&str, "%d", n);
	return str;
}

int main(void)
{
	t_btree *root = NULL;
	for (size_t i = 0; i < 5; i++)
		btree_insert_data(&root, getNum(i), (int (*)(void *, void *))&strcmp);
	print_tree(root);
	printf("%s\n", btree_search_item(root, "2", (int (*)(void *, void *))&strcmp));
	return 0;
}