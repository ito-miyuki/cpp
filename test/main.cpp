
#include <iostream>

int main(void)
{

	int	i;

	i = 8;
	std::cout << "i: " << i << std::endl;

	i = i << 8;

	std::cout << "i: " << i << std::endl;
	return (0);
}
// 0000.0000.0000.0000
// 8    8    8    8

// 0000.0000.1000.0000

// 256 128 64	32	16	8	4 2
