#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


// int *ft_range(int min, int max)
// {
// 	int i = 0;
// 	int *array;
// 	if (min > max)
// 		return NULL;
// 	array = malloc(sizeof (*array) * (max - min + 1));
// 	while (min <= max)
// 	{
// 		array[i] = min;
// 		i++;
// 		min++;
// 	}
// 	return (array);

// }


int *ft_range(int min, int max)
{
	int i = 0;
	int *array;
	if (min > max)
		return NULL;
	array = malloc(sizeof(*array) * (max - min + 1));
	while (min <=max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

int main() {

    int min, max;
    int *result;
    
    // Test Case 1: Normal range [5, 10)
    min = 5;
    max = 10;
    result = ft_range(min, max);
    if (result != NULL) {
        printf("Range [%d, %d):\n", min, max);
        for (int i = 0; i < (max - min + 1); i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    
    return 0;
}
}