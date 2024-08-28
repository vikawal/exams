#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char **ft_split (char * str)
{
	int i = 0;
	int j;
	int k = 0;
	char **split;

	if (!(split = malloc(sizeof(char *) * 256)))
		return NULL;
	while (str[i] == '\t' || str[i] == '\n' ||  str[i] == ' ' )
		i++;
	while (str[i])
	{
		j = 0;
		if (!(split[k] = malloc(sizeof(char) * 4096)))
		return NULL;
		while (str[i] != '\t' && str[i] != '\n' &&  str[i] != ' ' && str[i])
			split[k][j++] = str[i++];
		while (str[i] == '\t' || str[i] == '\n' ||  str[i] == ' ' )
			i++;
		split[k][j] = '\0';
		k++;
	}
	split[k] = NULL;
	return (split);
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return(i);
}

// void ft_last_word (char *str)
// {
// 	char **split;
// 	int last_index = 0;
// 	split = ft_split(str);
// 	while(split[last_index])
// 		last_index++;
// 	if(last_index > 0)
// 	{
// 		write(1, split[last_index -1], ft_strlen(split[last_index-1]));
		
// 	}
// 	write(1, "\n", 1);
	
// }

void ft_last_word (char *str)
{
	char **split;
	int last_index = 0;
	split = ft_split(str);
	while(split[last_index])
	{
		last_index++;
	}
	if(last_index > 0)
	write (1, split[last_index - 1], ft_strlen(split[last_index - 1]));
	write (1, "\n", 1);
}

int main (int argc, char *argv[])
{
	if( argc == 2)
		ft_last_word(argv[1]);
	else 
		write(1, "\n", 1);
}

