//Aaron Guillen
//COSC 485
//Homework 2
//Integer Overflow

#include <stdio.h>
#include <stdlib.h>

//Returns 0 if no overflow exists. 1 if overflow exists.
int checkForOverflow(int num1, int num2, int ans) {
	//To range check for overflow is rather simple
	//You must check if the product/sum is negative.
	//However, an overflow can exist such that number overflows into the negatives and
	//then back into the positives. So you must additionally check that the product/sum
	//is not less than either of the two numbers.

	//return flag
	int flag = 0;

	//Overflow from two positive numbers into a negative number.
	if (((num1 > 0) && (num2 > 0)) &&
		((ans < 0) || ((ans < num1) && (ans < num2)))) {
		flag = 1;
	}

	//Overflow from two negative numbers into a positive number.
	if (((num1 < 0) && (num2 < 0)) &&
		((ans > 0) || ((ans > num1) && (ans > num2)))) {
		flag = 1;
	}


	return flag;
}

int main(int argc, char* argv[]) {
	//Make sure they passed an argument
	if (argc != 2) {
		printf("usage: %s [POSITIVE NUMBER]\n", argv[0]);
		exit(0);
	}

	//Make sure the argument they passed is a positive number greater than zero
	if (atoi(argv[1]) < 1) {
		printf("usage: %s [POSITIVE NUMBER]\n", argv[0]);
		exit(0);
	}

	//0x7FFFFFFF is the greatest signed 32-bit number
	int baseNum = 0x7FFFFFFF;
	//Save argv[1] so we don't have to type aoti(argv[1]) so much
	//and there's generally less function calling
	int x = atoi(argv[1]);
	//And somepplace to put our answer
	int ans;


	//Have them choose whether or not they'd like to do
	//multiplication or addition.
	int temp = -1;
	printf("\nEnter\n1: Multiplication\n2: Addition\n");
	do {
		printf(">> ");
		scanf("%d", &temp);
	} while ((temp != 1) && (temp != 2));

	//The fun begins
	printf("You entered %d\n", x);
	printf("The largest signed 32-bit integer is 0x7FFFFFFF = %d\n", baseNum);
	switch(temp) {
		case 1:
			ans = x * baseNum;
			printf("%d x %d = %d\n", baseNum, x, ans);
			break;
		case 2:
			ans = x + baseNum;
			printf("%d + %d = %d\n", baseNum, x, ans);
	}

	//Some fancy output
	printf("In hex:\n%d = 0x%x\n%d = 0x%x\n%d = 0x%x\n", baseNum, baseNum, x, x, ans, ans);

	//Gotta range check, know what I'm sayin'?
	if (checkForOverflow(baseNum, x, ans)) {
		printf("\nOverflow exists.\n");
	}
	else {
		printf("\nOverflow does not exist.\n");
	}
}