// #include "ft_printf.h"
// #include <stdio.h>
//
// int	main()
// {
// 	int my;
// 	int	std;
//
// 	printf("\n####################################\n");
//
//
// 	printf("\n-------TEST 0 simple str  ------\n\n");
// 	my =ft_printf("Hello Word !\n");
// 	std =printf("Hello Word !\n");
// 	printf("\n");
// 	printf("My prinft return %d\n", my);
// 	printf("pt standard return %d\n", std);
//
//
// 	printf("\n####################################\n");
//
//
// 	 printf("\n-------TEST 1 %%%%  %%c  %%s  ------\n\n");
// 	my = ft_printf("My fonction %% %c %c %c %s %s %s \n", '\0', 'A', '\t', "hello", (char *)NULL, "");
// 	std = printf("pt standard %% %c %c %c %s %s %s \n", '\0', 'A', '\t', "hello", (char *)NULL, "");
// 	printf("\n");
// 	 printf("My prinft return: %d\n", my);
// 	 printf("pt standard return: %d\n", std);
//
//
//
// 	printf("\n####################################\n");
//
// 	printf("\n-------TEST 2 %%d  %%i  ------\n\n");
// 	my = ft_printf("My fonction %d %d %d  | %i %i %i \n", 0, 2147483647, -2147483648, 0, 2147483647, -2147483648);
// 	std = printf("pt standard %d %d %d  | %i %i %i \n", 0, 2147483647, (int)-2147483648, 0, 2147483647, (int)-2147483648);
// 	printf("\n-------TEST RETURN------\n\n");
// 	printf("\nMy prinft return %d\n", my);
// 	printf("\nstandard return %d\n", std);
//
// 	printf("\n####################################\n");
//
// 	printf("\n-------TEST 3  %%u  ------\n\n");
// 	my = ft_printf("My fonction %u %u \n",0, 4294967295);
// 	std = printf("pt standard %u %u \n", 0, (unsigned int)4294967295);
// 	printf("\n-------TEST RETURN------\n\n");
// 	printf("\nMy prinft return %d\n", my);
// 	printf("\nstandard return %d\n", std);
//
//
// 	printf("\n####################################\n");
//
// 	printf("\n-------TEST 4 %%p  ------\n\n");
// 	char	*hello;
// 	my = ft_printf("My fonction %p %p \n", &hello, (void *)0);
// 	std = printf("pt standard %p %p \n", &hello, (void *)0);
// 	printf("\n-------TEST RETURN------\n\n");
// 	printf("\nMy prinft return %d\n", my);
// 	printf("\nstandard return %d\n", std);
//
// 	printf("\n####################################\n");
//
// 	printf("\n-------TEST 5 %%x  %%X    ------\n\n");
// 	my = ft_printf("My fonction %x %x %x | %X %X %X \n", 0, 255, 4294967295u, 0, 255, 4294967295u);
// 	std = printf("pt standard %x %x %x | %X %X %X \n", 0, 255, 4294967295u, 0, 255, 4294967295u);
// 	printf("\n-------TEST RETURN------\n\n");
// 	printf("\nMy prinft return %d\n", my);
// 	printf("\nstandard return %d\n", std);
//
// 	return (0);
// }
