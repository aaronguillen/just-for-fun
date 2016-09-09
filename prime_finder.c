#include <stdio.h>
#include <stdlib.h>

//In gcc, this program must be compiled with the following option:
// -std=c99

int isprime(int n) {
	for (int i = 2; i < n / 2; i++) { //We start at 2 because you cannot divide by zero, and everything is divisible by 1 
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

void usage(char* argv) {
	printf("usage: %s [integer]\n", argv);
	printf("This program takes a numbers and finds the next smallest prime.\n");
	exit(0);
}

int main (int argc, char* argv[]) {
	if (argc != 2) {
		usage(argv[0]);
	}
	
	int n = atoi(argv[1]);
	
	if (n < 2) {
		printf("From %d, the next prime is 2.\n", n);
		return 0;
	}
	
	int count = n + 1;
	
	while (1) {
		if (isprime(count) == 1) {
			printf("From %d, the next prime is %d.\n", n, count);
			return 0;
		}
		count++;
	}
}