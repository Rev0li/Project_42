#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	// printf("\n####################################\n");
	//
	//
	// printf("\n-------TEST 1 %%%%  %%c  %%s  ------\n\n");
	// ft_printf("My fonction %% %c %c %c %s %s %s \n", '\0', 'A', '\t', "hello", (char *)NULL, "");
	// printf("pt standard %% %c %c %c %s %s %s \n", '\0', 'A', '\t', "hello", (char *)NULL, "");
	// printf("\n-------TEST RETURN------\n\n");
	// printf("My prinft return %d\n", ft_printf(" %% %c %c %c %s %s %s \n", '\0', 'A', '\t', "hello", (char *)NULL, ""));
	// printf("standard return %d\n", printf(" %% %c %c %c %s %s %s \n", '\0', 'A', '\t', "hello", (char *)NULL, ""));
	printf("My prinft return %d\n", ft_printf(" %% \n"));
	printf("standard return %d\n", printf(" %% \n"));

	//
	// printf("\n####################################\n");
	//
	// printf("\n-------TEST 2 %%d  %%i  %%u  ------\n\n");
	// ft_printf("My fonction %d %d %d  | %i %i %i | %u %u \n", 0, 2147483647, -2147483648, 0, 2147483647, -2147483648, 0, 4294967295);
	// printf("pt standard %d %d %d  | %i %i %i | %u %u \n", 0, 2147483647, (int)-2147483648, 0, 2147483647, (int)-2147483648, 0, (unsigned int)4294967295);//min fail comp
	// printf("\n-------TEST RETURN------\n\n");
	// printf("\nMy prinft return %d\n", ft_printf(" %d %d %d  | %i %i %i | %u %u \n", 0, 2147483647, -2147483648, 0, 2147483647, -2147483648, 0, 4294967295));
	// printf("\nstandard return %d\n", printf(" %d %d %d  | %i %i %i | %u %u \n", 0, 2147483647, (int)-2147483648, 0, 2147483647, (int)-2147483648, 0, (unsigned int)4294967295));//min fail comp
	//
	//
	// printf("\n####################################\n");
	//
	// printf("\n-------TEST 3 %%p  ------\n\n");
	// char	*hello;
	// ft_printf("My fonction %p %p \n", &hello, (void *)0);
	// printf("pt standard %p %p \n", &hello, (void *)0);
	// printf("\n-------TEST RETURN------\n\n");
	// printf("\nMy prinft return %d\n", ft_printf(" %p %p \n", &hello, (void *)0));
	// printf("\nstandard return %d\n", printf(" %p %p \n", &hello, (void *)0));
	//
	// printf("\n####################################\n");
	//
	// printf("\n-------TEST 4 %%x  %%X    ------\n\n");
	// ft_printf("My fonction %x %x %x | %X %X %X \n", 0, 255, 4294967295u, 0, 255, 4294967295u);
	// printf("pt standard %x %x %x | %X %X %X \n", 0, 255, 4294967295u, 0, 255, 4294967295u);
	// printf("\n-------TEST RETURN------\n\n");
	// printf("\nMy prinft return %d\n", ft_printf(" %x %x %x | %X %X %X \n", 0, 255, 4294967295u, 0, 255, 4294967295u));
	// printf("\nstandard return %d\n", printf(" %x %x %x | %X %X %X \n", 0, 255, 4294967295u, 0, 255, 4294967295u));
	//
	return (0);
}
