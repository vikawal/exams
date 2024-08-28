#include <string.h>
#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}
char to_lower(char c)
{
		if (c >= 'A' && c <= 'Z' )
			c += 32;
  return (c);
}

int areAnagram(char *str1, char *str2) {
   int n1 = ft_strlen(str1);
   int n2 = ft_strlen(str2);
   if (n1 != n2) {
     return 0;
   }

   // all printable ascii
   int count[128] = {0};
   int i = 0;
   while (i < n1) {
	char char1 = to_lower(str1[i]);
	char char2 = to_lower(str2[i]);
    count[(unsigned char)char1]++;
    count[(unsigned char)char2]--;
    i++;
   }

   i = 0;
   while (i < 128) {
     if (count[i]) {
       		return 0;
     }
     i++;
   }
   return 1;
}

int main(int argc, char *argv[]) {
   if (argc != 3) {
     write(1, "mistake_with_arg\n", 17);
     return 1;
   } else {
     if (areAnagram(argv[1], argv[2])) {
       write(1, "Anagram.\n", 9);
     } else {
       write(1, "NOT.\n", 5);
     }
     return 1;
   }
}