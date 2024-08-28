#include <unistd.h>
#include <stdio.h>

char to_low(char c)
{
		if (c >= 'A' && c <= 'Z' )
			c += 32;
  return (c);
}

void print_char (char c)
 {
	write (1, &c, 1);
 }

void commonLetters(const char *str1, const char *str2) {
    int characters[128] = {0};  // Considering the entire ASCII table

    int i = 0;
    while (str1[i] != '\0') {
        int j = 0;
        while (str2[j] != '\0') {
            if (to_low(str1[i]) == to_low(str2[j]) && (characters[(int)str1[i]] == 0))
			 {
                    characters[(int)str1[i]] = 1;
                    print_char(str1[i]);
                    break;  // Exit the inner loop once a match is found
            }
            j++;
        }
        i++;
    }

    print_char('\n');
}

int main() {
    const char *string1 = "Hello World!";
    const char *string2 = "Coding is Cool!";

    commonLetters(string1, string2);

    return 0;
}


// int ft_strlen(char *str)
// {
//     int len = 0;
//     while (str[len])
//         len++;
//     return len;
// }

// void ft_union(char *s1, char *s2)
// {
//     int ascii[256] = {0};
//     int i = 0;

//     // Mark characters from s2
//     while (s2[i])
//     {
//         ascii[(int)s2[i]] = 1;
//         i++;
//     }

//     // Print characters from s1 if they appear in both s1 and s2
//     i = 0;
//     while (s1[i])
//     {
//         if (ascii[(int)s1[i]] && !ascii[(int)s1[i]]--)
//             write(1, &s1[i], 1);
//         i++;
//     }
// }

// int main(int argc, char **argv)
// {
//     if (argc != 3)
//     {
//         write(1, "\n", 1);
//         return 0;
//     }
//     ft_union(argv[1], argv[2]);
//     write(1, "\n", 1);
//     return 0;
// }