#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Stack node structure to hold tags
typedef struct StackNode {
    char *tag;
    struct StackNode *next;
} StackNode;

// Push a tag onto the stack
void push(StackNode **top, const char *tag) {
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    new_node->tag = (char *)malloc(strlen(tag) + 1);
    strcpy(new_node->tag, tag);
    new_node->next = *top;
    *top = new_node;
}

// Pop a tag from the stack
char *pop(StackNode **top) {
    if (*top == NULL) {
        return NULL;
    }
    StackNode *temp = *top;
    char *popped_tag = temp->tag;
    *top = (*top)->next;
    free(temp);
    return popped_tag;
}

// Check if a tag is self-closing
int is_self_closing(const char *tag) {
    return strncmp(tag, "img", 3) == 0;
}

// Check if a tag is an opening tag
int is_opening_tag(const char *tag) {
    return tag[0] != '/';
}

// Compare two tags (opening and closing)
int tags_match(const char *open_tag, const char *close_tag) {
    return strcmp(open_tag, close_tag + 1) == 0;
}

// Validate HTML tags in the input string
int validate_html(const char *input) {
    StackNode *stack = NULL;
    const char *ptr = input;
    char buffer[BUFFER_SIZE];
    
    while (*ptr) {
        if (*ptr == '<') {
            ptr++;
            int i = 0;
            while (*ptr && *ptr != '>') {
                buffer[i++] = *ptr++;
            }
            buffer[i] = '\0';
            if (*ptr == '>') {
                ptr++;
            }
            
            if (is_self_closing(buffer)) {
				//if there's >
				// ptr++; ????
                continue;
            } 
			else if (is_opening_tag(buffer)) 
			{
                push(&stack, buffer);
            } 
			else 
			{
                char *last_open_tag = pop(&stack);
                if (!last_open_tag || !tags_match(last_open_tag, buffer)) {
                    free(last_open_tag);
                    return 1;
                }
                free(last_open_tag);
            }
        } else {
            ptr++;
        }
    }
    
    int result = (stack == NULL) ? 0 : 1;
    while (stack) {
        StackNode *temp = stack;
        stack = stack->next;
        free(temp->tag);
        free(temp);
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }
    
    const char *input = argv[1];
    int result = validate_html(input);
    
    return result;
}




//ALTERNATIVE WAY

