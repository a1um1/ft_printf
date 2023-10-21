#include "ft_printf.h"

int main(void)
{
	ft_printf("%p %p\n", -1, LONG_MAX);
	printf("%p %p\n", -1, LONG_MAX);
	return (0);
}