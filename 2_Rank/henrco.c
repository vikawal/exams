#include <stdio.h>
#include <string.h>
#include <unistd.h>
int ft_strlen(char *str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}
int is_palindrome(char *str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
            return (0);
        start++;
        end--;
    }
    return (1);
}
int main(int argc, char **argv)
{
    char *str;
    int n;
    int max_len;
    int max_start;
    int start;
    int end;
    int len;
    int i;
    str = argv[1];
    n = ft_strlen(str);
    max_len = 0;
    max_start = 0;
    start = 0;
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    while (start < n)
    {
        end = start;
        while (end < n)
        {
            len = end - start + 1;
            if (len > max_len && is_palindrome(str, start, end))
            {
                max_len = len;
                max_start = start;
            }
            end++;
        }
        start++;
    }
    i = max_start;
    while (i < max_start + max_len)
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1,"\n", 1);
    return 0;
}