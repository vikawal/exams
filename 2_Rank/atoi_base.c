#include <stdio.h>
#include <stdbool.h>

// int char_to_digit(char c) {
//     if (c >= '0' && c <= '9') {
//         return c - '0';
//     } else if (c >= 'a' && c <= 'z') {
//         return 10 + (c - 'a');
//     } else if (c >= 'A' && c <= 'Z') {
//         return 10 + (c - 'A');
//     }
//     return -1; // Invalid character
// }

// int ft_atoi_base(const char *str, int str_base) {
//     int result = 0;
//     int sign = 1;
//     int digit;

//     if (*str == '-') {
//         sign = -1;
//         str++;
//     }

//     while (*str) {
//         digit = char_to_digit(*str);
//         if (digit == -1 || digit >= str_base) {
//             return 0; // Invalid character for base
//         }
//         result = result * str_base + digit;
//         str++;
//     }

//     return result * sign;
// }



// int ft_atoi(const char *str) 
// {
// 	int result = 0; 
// 	int sign = 1;
// 	int i = 0;
// 	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
// 		i++;
// 	if (str[i] == '-')
// 	{
// 		sign = -1;
// 		i++;
// 	}
// 	if (str[i] == '+')
// 	{
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = result * 10 + str[i] - '0';
// 		i++;
// 	}
// 	return (result * sign);
	
// }

// int main() {
//     printf("%d\n", ft_atoi("123")); 
//     printf("%d\n", ft_atoi("-123")); 
//     return 0;
// }

#include <stdio.h>
#include <stdbool.h>

int char_to_digit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'z') {
        return 10 + (c - 'a');
    } else if (c >= 'A' && c <= 'Z') {
        return 10 + (c - 'A');
    }
    return -1; // Invalid character
}

int ft_atoi_base(const char *str, int str_base) {
    int result = 0;
    int sign = 1;
    int digit;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str) {
        digit = char_to_digit(*str);
        if (digit == -1 || digit >= str_base) {
            return 0; // Invalid character for base
        }
        result = result * str_base + digit;
        str++;
    }

    return result * sign;
}

int main() {
    printf("%d\n", ft_atoi_base("12fdb3", 16)); // Output: 1991379
    printf("%d\n", ft_atoi_base("123", 4));     // Output: 27
    printf("%d\n", ft_atoi_base("-123", 10));   // Output: -123
    printf("%d\n", ft_atoi_base("garbage", 10));// Output: 0 (invalid character)
    printf("%d\n", ft_atoi_base("1010", 2));    // Output: 10 (binary)
    printf("%d\n", ft_atoi_base("FF", 16));     // Output: 255 (hexadecimal)
    return 0;
}