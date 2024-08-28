#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char		**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	if (!(split = (char **)malloc(sizeof(char *) * 256)))
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i += 1;
	while (str[i])
	{
		j = 0;
		if (!(split[k] = (char *)malloc(sizeof(char) * 4096)))
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			split[k][j++] = str[i++];
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i += 1;
		split[k][j] = '\0';
		k += 1;
	}
	split[k] = NULL;
	return (split);
}
int main(int argc, char *argv[]) {
    int i = 0;
    char **split;
    int first_word = 1;
    char space = ' ';

    if (argc == 2) {
        split = ft_split(argv[1]);

        // Print words with a single space between them using write
        while (split[i]) {
            if (!first_word) {
                write(1, &space, 1);
            }
            write(1, split[i], strlen(split[i]));
            first_word = 0;
            i++;
        }
        write(1, "\n", 1);

        // Free the memory
    //     i = 0;
    //     while (split[i]) {
    //         free(split[i]);
    //         i++;
    //     }
    //     free(split);
    }

    return 0;
}