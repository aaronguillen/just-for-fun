#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void usage(char* argv) {
	printf("usage: ");
	printf(argv);
	printf(" [first integer] [second integer]\n");
	printf("This program takes two positive integers and finds the greatest common denominator between them");
	exit(0);
}

int main(int argc, char* argv[]) {	
	if (argc != 3) {
		usage(argv[0]);
	}
	
	
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	
	if ((a < 1) || (b < 1)) {
		usage(argv[0]);
	}
	
	int temp = 1;
	int gcd = temp;
	int low;
	bool diva, divb;
	
	if (argv[1] < argv[2]) {
		low = a;
	}
	else {
		low = b;
	}
	
	
	while (temp <= low) {
		diva = false; divb = false;
		if (a % temp == 0) {
			diva = true;
		}
		if (b % temp == 0) {
			divb = true;
		}
		if ((diva == true) && (divb == true)) {
			gcd = temp;
		}
		temp++;
	}
	
	printf("The greatest common divisor of %d and %d is %d.\n", a, b, gcd);
	
	if (gcd == 1) {
		printf("This means that %d and %d are coprime.\n", a, b);
	}
	
	return 0;
}