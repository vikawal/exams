#include <unistd.h>
#include <stdio.h>

// int ft_strlen(char *str)
// {
// 	int i = 0;
// 	while(str[i])
// 		i++;
// 	return (i);
// }
//  void print_char (char c)
//  {
// 	write (1, &c, 1);
//  }

//  int is_palindrome( char *str, int start, int end)
//  {
// 	while (start < end)
// 	{
		
// 		if (str[start] != str[end])
// 		{
// 			return 0;
// 		}
// 		start++;
// 		end--;	
// 	}
// 	return 1;
//  }

//  void print_biggest_p (char *str)
//  {
// 	int i = 0;
// 	int maxLen = 0;
// 	int start = 0;
// 	int len = ft_strlen(str);

// 	while(i < len)
// 	{
// 		int j = i;
// 		while (j < len)
// 		{
// 			if(is_palindrome(str, i, j) && (j - i + 1) >= maxLen)
// 			{
// 				start = i;
// 				maxLen = j - i + 1;
// 			}
			
// 			j++;
// 		} 
// 		if(maxLen == len)
// 		    break;
// 		i++;
// 		// if(maxLen >= len - i + 1) // more optimizing
// 		// 	break;
	
// 	}
// 	int start1 = start;
// 	while(start1 < start + maxLen)
// 	{
// 		write(1, &str[start1], 1);
// 		start1++;
// 	}
// 	print_char ('\n');
// 	printf("%d\n", i);
//  }
 
//  int main (int argc, char *argv[])
//  {
// 	if(argc != 2)
// 	{
// 		print_char ('\n');
// 		return 0;
// 	}
// 	else
// 	{
// 		print_biggest_p(argv[1]);
// 		return 1;
// 	}
//  }

#include <unistd.h>
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}
int is_pal(const char *str, int start, int len)
{
    int i = 0;  
	while (i < (len/2))
    {
        if (str[start + i] != str[start + len - 1 - i])
            return (0);
        i++;
    }
    return (1);
}
int main(int argc, char **argv)
{
    if (argc == 2)
    {
    char    *str = argv[1];
    int     len = ft_strlen(str);
    int     i = 0;
    int     start;
        while (i <= len)
        {
            start = i;
            while (start >= 0)
            {
                if (is_pal(str, start, len - i))
                {
                    write(1, &str[start], len - i);
                    write(1, "\n", 1);
                    return (0);
                }
                start--;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}