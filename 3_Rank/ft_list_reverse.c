#include <stdlib.h>
#include <stdio.h>


typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;




// void	ft_list_reverse(t_list **begin_list)
// {
// 	t_list	*previous;
// 	t_list	*next;
// 	t_list	*current;

// 	previous = NULL;
// 	current = *begin_list;
// 	while (current != NULL)
// 	{
// 		next = current->next;
// 		current->next = previous;
// 		previous = current;
// 		current = next;
// 	}
// 	*begin_list = previous;
// }
// void	ft_list_reverse(t_list **begin_list)
// {
// 	t_list *previous;
// 	t_list *current;
// 	t_list *next;

// 	current = *begin_list;
// 	previous = NULL;
// 	while (current != NULL)
// 	{
// 		next = current->next;
// 		current->next = previous;
// 		previous = current;
// 		current = next;
// 	}
// 	*begin_list = previous;
// }

void	ft_list_reverse(t_list **begin_list)
{
	t_list *current = *begin_list;
	t_list *previous = NULL;
	t_list *next;

	while(current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*begin_list = previous;
}


t_list *create_node(void *data)
{
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void append_node(t_list **head, void *data)
{
    t_list *new_node = create_node(data);
    if (!new_node)
        return;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    t_list *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to print the list (assuming data is int for this example)
void print_list(t_list *head)
{
    while (head != NULL)
    {
        printf("%d -> ", *(int *)(head->data));
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the list
void free_list(t_list *head)
{
    t_list *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->data); // Free the data if it was dynamically allocated
        free(temp);
    }
}

int main()
{
    t_list *list = NULL;

    // Append nodes to the list with integer data
    for (int i = 1; i <= 5; i++)
    {
        int *data = malloc(sizeof(int));
        *data = i;
        append_node(&list, data);
    }

    // Print the original list
    printf("Original list:\n");
    print_list(list);

    // Reverse the list
    ft_list_reverse(&list);

    // Print the reversed list
    printf("Reversed list:\n");
    print_list(list);

    // Free the list
    free_list(list);

    return 0;
}

// void	ft_list_reverse(t_list **begin_list)
// {
// 	t_list *previous;
// 	t_list *current;
// 	t_list *next;

// 	current = *begin_list;
// 	previous = NULL;
// 	while (current != NULL)
// 	{
// 		next = current->next;
// 		current->next = previous;
// 		previous = current;
// 		current = next;
// 	}
// 	*begin_list = previous;
// }