#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
	write(1, "\n", 1);
}

void ft_print_aplparent()
{
	write(1, "abcdefghijklmnopqrstuvwxyz", 27);
	write(1, "\n", 1);
	write(1, "abcdefghijklmnopqrstuvwxyz", 27);
	write(1, "\n", 1);
}
int main()
{
	ft_print_aplparent();
	
}