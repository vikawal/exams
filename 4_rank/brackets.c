#include <unistd.h>
#define BUFF_SIZE (4096)

static int	match_brackets(char a, char b)
{
	return ((a == '[' && b == ']') || (a == '{' && b == '}') \
				|| (a == '(' && b == ')'));
}

static int	check_brackets(char *str)
{
	int		i;
	int		top;
	int		stack[BUFF_SIZE];

	i = 0;
	top = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			stack[++top] = str[i];
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			if (!match_brackets(stack[top--], str[i]))
				return (0);
		i += 1;
	}
	return (!top);
}

int			main(int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc == 1)
		write(1, "\n", 1);
	while (--argc)
	{
		if (check_brackets(argv[++i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
/////ALTERNATIVE

// int	braclose(char *str, char c, int i, int b)
// {
// 	while (b && *(++str) && (i++))
// 		if (*str == c || *str == c + c % 2 + 1)
// 			*str == c ? ++b : --b;
// 	return (i);
// }

// int	brackets(char *str, char c)
// {
// 	if (*str == c)
// 		return (1);
// 	else if (!*str || *str == ')' || *str == '}' || *str == ']')
// 		return (0);
// 	else if (*str == '(' || *str == '{' || *str == '[')
// 		return (brackets(str + 1, *str + *str % 2 + 1)
// 			* brackets(str + braclose(str, *str, 1, 1), c));
// 	else
// 		return (brackets(str + 1, c));
// }

// int	main(int ac, char **av)
// {
// 	int	i;

// 	i = 0;
// 	if (ac > 1)
// 		while (++i < ac)
// 			brackets(av[i], 0) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
// 	else
// 		write(1, "\n", 1);
// 	return (0);
// }