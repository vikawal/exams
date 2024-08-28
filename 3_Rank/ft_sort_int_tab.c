#include <stdio.h> 
// void	ft_sort_int_tab(int *tab, int size)
// {
// 	int		swap;
// 	int 	count;

// 	count = 0;
// 	while ( count < (size - 1))
// 	{
// 		if (tab[count] > tab[count + 1])
// 		{
// 			swap = tab[count];
// 			tab[count] = tab[count + 1];
// 			tab[count + 1] = swap;
// 			count = 0;
// 		}
// 		else
// 			count++;
// 	}
// }

// void	ft_sort_int_tab(int *tab, int size)
// {
// 	int count = 0;
// 	int swap;

// 	while(count < (size - 1))
// 	{
// 		if (tab[count] > tab[count+1])
// 		{
// 			swap = tab[count];
// 			tab[count] = tab[count + 1];
// 			tab[count + 1] = swap;
// 			count = 0;
// 		}
// 		else
// 			count++;
// 	}
// }

void	ft_sort_int_tab(int *tab, int size)
{
	int count = 0;
	int swap;
	while (count < (size -1))
	{
		if (tab[count] > tab[count +1])
	{
		swap = tab[count];
		tab[count] = tab[count +1];
		tab[count +1] = swap;
		count = 0;
	}
	else
		count++;
	}
	

}

int		main(void)
{
	int tab[9] = {30,5,2,3,4,8,16,20,24};
	ft_sort_int_tab(tab, 9);
	for(int i = 0; i < 9; i++)
	{
		printf("%d ", tab[i]); 
	}
}
// int main()
// {
//     int arr[] = {6, 1, 2, 4, 3, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     ft_sort_int_tab(arr, size);

//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }

// void	ft_sort_int_tab(int *tab, int size)
// {
// 	int count = 0;
// 	int swap;

// 	while(count < (size -1))
// 	{
// 		if (tab[count] > tab[count+1])
// 		{
// 			swap = tab[count];
// 			tab[count] = tab[count + 1];
// 			tab[count + 1] = swap;
// 			count = 0;
// 		}
// 		else
// 			count++;
// 	}
// }