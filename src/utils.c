#include "so_long.h"

bool ft_strncmpend(char *s1, char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s1) - 1;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		--n;
/* 		printf("VUELTA %d\n---------\n", i);
		printf("len: %zu\n", len);
		printf("n: %zu\n", n);
		printf("-----> s1 char: %c\n\n", s1[len]);
		printf("-----> s2 char: %c\n\n", s2[n]); */
		if (s1[len] != s2[n])
			return (false);
		len--;
	}
	return(true);
}