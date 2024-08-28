#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// #define MAX_TAG_LENGTH 100

// typedef struct Stack {
//     char tags[1000][MAX_TAG_LENGTH];
//     int top;
// } Stack;

// void push(Stack *s, const char *tag) {
//     if (s->top < 999) {
//         strcpy(s->tags[++s->top], tag);
//     }
// }

// char *pop(Stack *s) {
//     if (s->top >= 0) {
//         return s->tags[s->top--];
//     }
//     return NULL;
// }

// int is_self_closing(const char *tag) {
//     return (strncmp(tag, "img", 3) == 0);
// }

// int validate_html(const char *html) {
//     Stack stack;
//     stack.top = -1;
    
//     char tag[MAX_TAG_LENGTH];
//     int in_tag = 0;
//     int tag_index = 0;
    
//     for (int i = 0; html[i] != '\0'; i++) {
//         if (html[i] == '<') {
//             in_tag = 1;
//             tag_index = 0;
//         } else if (html[i] == '>') {
//             in_tag = 0;
//             tag[tag_index] = '\0';
            
//             if (tag[0] == '/') {
//                 char *opening_tag = pop(&stack);
//                 if (opening_tag == NULL || strncmp(opening_tag, tag + 1, strlen(tag) - 1) != 0) {
//                     return 1;
//                 }
//             } else if (!is_self_closing(tag)) {
//                 push(&stack, tag);
//             }
            
//             tag_index = 0;
//         } else if (in_tag) {
//             if (tag_index < MAX_TAG_LENGTH - 1) {
//                 tag[tag_index++] = html[i];
//             }
//         }
//     }
    
//     return (stack.top == -1) ? 0 : 1;
// }


// int main(int argc, char *argv[]) {
//     if (argc != 2) {
//         write(1, "1\n", 2);
//         return 1;
//     }
    
//     int result = validate_html(argv[1]);
//     char output = result + '0';
//     write(1, &output, 1);
//     write(1, "\n", 1);
//     return result;
// }

// int validate_html(const char *html) {
//     char **stack = malloc(1000 * sizeof(char*));
//     int top = -1;
    
//     while (*html) {
//         if (*html++ == '<') {
//             char *tag = malloc(100);
//             int i = 0;
//             while (*html && *html != '>') 
// 				tag[i++] = *html++;
//             tag[i] = '\0';
            
//             if (*html != '>') 
// 				return 1; // Error if '>' is missing
//             html++; // Skip the closing '>'
            
//             if (tag[0] == '/') {
//                 if (top < 0 || strncmp(stack[top], tag+1, strlen(tag)-1) != 0)
//                     return 1;
//                 top--;
//             } 
// 			else if (strncmp(tag, "img", 3) != 0) {
//                 stack[++top] = tag;
//             }
//         }
//     }
// 	if (top == -1) 
//         return 0;
//     else 
//         return 1;
    
// }
    
    // return (top == -1) ? 0 : 1; // Ensure all tags are closed
// }

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int validate_html(const char *html) {
    char stack[1000][100];  // Fixed-size stack for storing tags
    int top = -1;           // Stack pointer
    int i = 0;              // Index for traversing the input string

    while (html[i]) {
        if (html[i++] == '<') {  // Find the opening '<'
            char tag[100];  // Temporary storage for the current tag
            int j = 0;

            // Read until closing '>' or end of tag name
            while (html[i] && html[i] != '>' && j < 99) {
                tag[j++] = html[i++];
            }
            tag[j] = '\0';

            if (html[i] != '>') {
                return 1; // Error if '>' is missing
            }
            i++; // Skip the closing '>'

            if (tag[0] == '/') {  // Closing tag
                if (top < 0 || strncmp(stack[top], tag + 1, strlen(stack[top]) + 1) != 0) {
                    return 1; // Mismatched closing tag
                }
                top--; // Pop from stack
            } else if (strncmp(tag, "img", 3) != 0 || (tag[3] != '\0' && tag[3] != ' ')) {
                // Not a self-closing <img> tag, push to stack
                strncpy(stack[++top], tag, 99);  // Push to stack
                stack[top][99] = '\0';           // Ensure null-termination
            }
        }
    }

    // Return 0 if stack is empty, 1 otherwise
    if (top == -1) {
        return 0;
    } else {
        return 1;
    }
}

// int main(int argc, char *argv[]) {
//     if (argc != 2) {
//         return 1;  // Return 1 if no argument is provided
//     }

//     return validate_html(argv[1]);
// }

int main(int argc, char *argv[]) {
    if (argc != 2) 
		return (write(1, "1\n", 2), 1);
    char r = validate_html(argv[1]) + '0';
    write(1, &r, 1);
    write(1, "\n", 1);
    return r - '0';
}