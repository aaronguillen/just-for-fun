#include <stdio.h>

void collatzConjectureRecursive(int); //Included superfluously
void collatzConjectureIterative(int); //Included superfluously
void lab4(int);

void main(int argc, char* argv[]) {
	//Check for valid input
	if (argc < 2) {
		printf("Lack of input. Terminating program.\n");
		return;
	}

	collatzConjectureIterative(atoi(argv[1]));
}

//This is the answer to the Lab4 prompt
//
void lab4(int x) {
	//Check for valid input.
	if (x < 1) {
		printf("Invalid input for the Collatz Conjecture.\n");
		return;
	}

	while(x != 1) {
		printf("%d\n", x);
		if ((x % 2) == 0) {
			x = x / 2;
		}
		else {
			x = (3 * x) + 1;
		}
		fork();
		wait();
	}
}

// This is the recursive way to do it. I've included it for reference
// and because I think it's interesting to compare methods.
//
void collatzConjectureRecursive(int x) {
	//Check for valid input.
	if (x < 1) {
		printf("Invalid input for the Collatz Conjecture.\n");
		return;
	}

	printf("%d\n", x);
	if (x == 1) {
		return;
	}
	else if ((x % 2) == 0) {
		collatzConjectureRecursive(x / 2);
	}
	else {
		collatzConjectureRecursive((3 * x) + 1);
	}
	return;
}

// This is the iterative way to do it. I've included it for reference
// and because I think it's interesting to compare methods.
//
void collatzConjectureIterative(int x) {
	//Check for valid input.
	if (x < 1) {
		printf("Invalid input for the Collatz Conjecture.\n");
		return;
	}

	while (x > 1) {
		printf("%d\n", x);
		if ((x % 2) == 0) {
			x = x / 2;
		}
		else {
			x = (3 * x) + 1;
		}
	}
	printf("%d\n", x);
}