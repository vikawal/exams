#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

typedef struct StackNode {
    char *tag;
    struct StackNode *next;
} StackNode;

void push(StackNode **top, const char *tag) {
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    new_node->tag = (char *)malloc(strlen(tag) + 1);
    strcpy(new_node->tag, tag);
    new_node->next = *top;
    *top = new_node;
}

char *pop(StackNode **top) {
    if (*top == NULL) 
		return NULL;
    StackNode *temp = *top;
    char *tag = temp->tag;
    *top = (*top)->next;
    free(temp);
    return tag;
}
// EXPERIMENT
void last_pop(StackNode *top) 
{
	if (top == NULL)
		return;
	while ((top)->next != NULL)
	{
		(top)++;
	}
	free((top)->next);
	// return (top); 
}
// END

int validate_html(const char *input) {
    StackNode *stack = NULL;
    const char *ptr = input;
    char buffer[BUFFER_SIZE];

    while (*ptr) {
        if (*ptr == '<') {
            ptr++;
            int i = 0;
            while (*ptr && *ptr != '>') 
			{
                buffer[i++] = *ptr++;
            }
            buffer[i] = '\0';
            if (*ptr == '>') 
				ptr++;
			//EXPERIMENT
			else
			{
				last_pop(stack);
			}
			// END

            if (strncmp(buffer, "img", 3) == 0) 
				continue;
            if (buffer[0] != '/') {
                push(&stack, buffer);
            } 
			else 
			{
                char *last_tag = pop(&stack);
				printf("LAST TAG:%s\n", last_tag);
				printf("NEXT TAG:%s\n", buffer + 1);
                if (!last_tag || strncmp(last_tag, buffer + 1, strlen(last_tag)) != 0) 
				{
                    free(last_tag);
                    return 1;
                }
                free(last_tag);
            }
        } else {
            ptr++;
        }
    }

    // int result = stack == NULL ? 0 : 1;
	int result;

	if (stack == NULL) 
    	result = 0;
	else 
    	result = 1;
	//freeing NOT NECESSARY
    // while (stack) {
    //     StackNode *temp = stack;
    //     stack = stack->next;
    //     free(temp->tag);
    //     free(temp);
    // }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }
    return validate_html(argv[1]);
}

