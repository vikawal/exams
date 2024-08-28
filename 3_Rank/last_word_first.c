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
void print_last_word_first(char *input) {
    char **split;
    int i = 0;
    int last_index = 0;
    char space = ' ';

    // Split the input string into words
    split = ft_split(input);

    // Find the last word
    while (split[last_index])
        last_index++;

    if (last_index > 0) {
        // Print the last word first
        write(1, split[last_index - 1], strlen(split[last_index - 1]));
        // Print the remaining words
        // i = 0;
        // while (i < last_index - 1) {
        //     write(1, &space, 1);
        //     write(1, split[i], strlen(split[i]));
        //     i++;
        // }
        write(1, "\n", 1);
    }

    // Free the memory
    // i = 0;
    // while (split[i]) {
    //     free(split[i]);
    //     i++;
    // }
    // free(split);
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        print_last_word_first(argv[1]);
    }
    return 0;
}