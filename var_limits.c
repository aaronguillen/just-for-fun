#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
	short min = 0x8000;
	short max = 0x7FFF;

	unsigned short min_u = 0;
	unsigned short max_u = 0xFFFF;

	short xs = 0;
	short ys = 0xFFFF;
	unsigned short xu = 0x8000;
	unsigned short yu = 0x7FFF;

	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", min, max, min_u, max_u, xs, ys, xu, yu);
}
