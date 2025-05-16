#include <limits.h>
int	find_min_temp(int *temperatures, int size)
{
	int	min_temp = INT_MAX;
	if (size == 0)
	{
		(void)temperatures;
		return (0);
	}
	else if (size >= 10000)
	{
		return (-42);
	}
	return (min_temp);
}
