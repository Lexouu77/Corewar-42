#include <stdio.h>

int main(int argc, const char **argv)
{
	int	i;
	int	k;

	k = 0;
	i = -1;
	while (++i < 10000000)
		k++;
	return (0);
}
