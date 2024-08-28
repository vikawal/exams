#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// char **ft_split (char * str)
// {
// 	int i = 0;
// 	int j;
// 	int k = 0;
// 	char **split;

// 	if (!(split = malloc(sizeof(char *) * 256)))
// 		return NULL;
// 	while (str[i] == '\t' || str[i] == '\n' ||  str[i] == ' ' )
// 		i++;
// 	while (str[i])
// 	{
// 		j = 0;
// 		if (!(split[k] = malloc(sizeof(char) * 4096)))
// 		return NULL;
// 		while (str[i] != '\t' && str[i] != '\n' &&  str[i] != ' ' && str[i])
// 			split[k][j++] = str[i++];
// 		while (str[i] == '\t' || str[i] == '\n' ||  str[i] == ' ' )
// 			i++;
// 		split[k][j] = '\0';
// 		k++;
// 	}
// 	split[k] = NULL;
// 	return (split);
// }
char **ft_split (char *str)
{
	int i = 0;
	int k = 0;
	int j;
	char **split;

	if(!(split = malloc(sizeof(char *) * 300)))
		return NULL;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		i++;
	while(str[i])
	{
		j = 0;
		if(!(split[k] = malloc(sizeof(char) *4096)))
			return NULL;
		while (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i])
			split[k][j++] = str[i++];
		while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			i++;
		split[k][j] = '\0';
		k++;
	}
	split[k] = NULL;
	return (split);
}

int main (int argc, char *argv[])
{
	int		i;
	char	**split;

	if (argc == 2)
	{
		split = ft_split(argv[1]);
		i = 0;
		while (split[i])
		{
			printf("%s\n", split[i]);
			i++;
		}
	}
	return (0);
}

