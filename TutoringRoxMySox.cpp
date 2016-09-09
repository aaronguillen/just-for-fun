#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void add(int &, int&);
void sub(int &, int &);
void mul(int &, int &);
void divide(int &, int &);
void printStat(int,int, int, int, int, int, int, int);
void PrintMenu();
void encouragement();
void definiteencouragement();

void main()
{
	int  ac,aw,sc,sw,mc,mw,dc,dw;
	ac=0;aw=0; sc=0; sw=0; mc=0; mw=0; dc=0; dw=0;
	int selection;
	char ans;
	char name[365];

	srand(time(NULL));
	cout << "Welcome to our tutoring system! What is your name?\n";
	cin.getline (name,365);
	cout << "Welcome, " << name << "! Let's begin!\n";
	
	do
	{
		do
		{
			PrintMenu();
			cin >> selection; cout << endl;
		} while ((selection <= 0) || (selection > 5));

		switch (selection)
		{
		case 1: add (ac,aw);
			break;
		case 2: sub (sc, sw);
			break;
		case 3: mul (mc, mw);
			break;
		case 4: divide (dc, dw);
			break;
		case 5: printStat(ac, aw, sc, sw, mc, mw, dc, dw);
			cout << "\nYou did a wonderful job, " << name << "!";
			exit (0);
		}
		cout << "would you like to continue (Y/N)? ";
		cin >> ans; cout << endl;
	}while ((ans == 'Y') || (ans == 'y'));
	printStat(ac, aw, sc, sw, mc, mw, dc, dw);
	cout << "\nYou did a wonderful job, " << name << "!";	

	int xxx;
	cout << "\n\nEnter any value to quit\n"; cin >> xxx;
}


void add (int & c, int& w)
{
	for (int i = 1; i == 1;)
	{
		int num1, num2, ansi=0;
		char ans = 'x';
		num1 = rand( ) % 101;
		num2 = rand( ) % 101;

		do
		{
		cout << "Solve this equations:\n";
		cout << num1 << " + " << num2 <<" = ";
		cin >> ansi;
		if (ansi != (num1 + num2))
			w++;
		} while (ansi != (num1 + num2));

		encouragement();
		c++;

		cout << "Would you like to do another addition problem? y/n\n";
		while (!((ans == 'Y') || (ans == 'y') || (ans == 'N') || (ans == 'n')))
		{
			cin >> ans;
			if ((ans == 'Y') || (ans == 'y'))
				cout << "Alright! Let's go again.\n";
			else if ((ans == 'N') || (ans == 'n'))
			{
				cout << "Alright, let's do something else.\n";
				i = 2;
			}
			else
				cout << "That wasn't an option. Try again?\n";
		}
	}
}


void sub (int & c, int & w)
{
	for (int i = 1; i == 1;)
	{
		int num1, num2, ansi=0;
		int temp;
		char ans = 'x';
		num1 = rand( ) % 101;
		num2 = rand( ) % 101;

		if (num1 > num2)
		{}
		else
		{
			temp = num1;
			num1 = num2;
			num2 = temp;
		}

		do
		{
		cout << "Solve this equations:\n";
		cout << num1 << " - " << num2 <<" = ";
		cin >> ansi;
		if (ansi != (num1 - num2))
			w++;
		} while (ansi != (num1 - num2));

		encouragement();
		c++;

		cout << "Would you like to do another subtraction problem? y/n\n";
		while (!((ans == 'Y') || (ans == 'y') || (ans == 'N') || (ans == 'n')))
		{
			cin >> ans;
			if ((ans == 'Y') || (ans == 'y'))
				cout << "Alright! Let's go again.\n";
			else if ((ans == 'N') || (ans == 'n'))
			{
				cout << "Alright, let's do something else.\n";
				i = 2;
			}
			else
				cout << "That wasn't an option. Try again?\n";
		}
	}
}
	

void mul (int & c, int & w)
{
	for (int i = 1; i == 1;)
	{
		int num1, num2, ansi=0;
		int temp;
		char ans = 'x';
		num1 = rand( ) % 101;
		num2 = rand( ) % 101;

		do
		{
		cout << "Solve this equations:\n";
		cout << num1 << " x " << num2 <<" = ";
		cin >> ansi;
		if (ansi != (num1 * num2))
			w++;
		} while (ansi != (num1 * num2));

		encouragement();
		c++;

		cout << "Would you like to do another multiplication problem? y/n\n";
		while (!((ans == 'Y') || (ans == 'y') || (ans == 'N') || (ans == 'n')))
		{
			cin >> ans;
			if ((ans == 'Y') || (ans == 'y'))
				cout << "Alright! Let's go again.\n";
			else if ((ans == 'N') || (ans == 'n'))
			{
				cout << "Alright, let's do something else.\n";
				i = 2;
			}
			else
				cout << "That wasn't an option. Try again?\n";
		}
	}
}


void divide (int & c, int & w)
{
	for (int i = 1; i == 1;)
	{
		int num1, num2, ansi=0;
		int temp;
		char ans = 'x';
		num1 = rand( ) % 101;
		num2 = rand( ) % 101;

		if (num1 > num2)
		{}
		else
		{
			temp = num1;
			num1 = num2;
			num2 = temp;
		}

		do
		{
		cout << "Solve this equations(Ignore the remainder):\n";
		cout << num1 << " / " << num2 <<" = ";
		cin >> ansi;
		if (ansi != (num1 / num2))
			w++;
		} while (ansi != (num1 / num2));

		encouragement();
		c++;

		cout << "Would you like to do another division problem? y/n\n";
		while (!((ans == 'Y') || (ans == 'y') || (ans == 'N') || (ans == 'n')))
		{
			cin >> ans;
			if ((ans == 'Y') || (ans == 'y'))
				cout << "Alright! Let's go again.\n";
			else if ((ans == 'N') || (ans == 'n'))
			{
				cout << "Alright, let's do something else.\n";
				i = 2;
			}
			else
				cout << "That wasn't an option. Try again?\n";
		}
	}
}


void printStat(int ac ,int aw, int sc, int sw, int mc, int mw, int dc, int dw)
{

	cout << "Here are your results:\n\n";
	cout << "You got" << ac << " addition problems correct.\n";
	cout << "You got" << aw << " addition problems incorrect.\n";
	cout << "Your total grade for addition is " << (ac / (ac + aw)) << "%, which is ";
	if ((ac / (ac + aw)) >= 90)
	{
		cout << "an A.\n";
		definiteencouragement();
	}
	else if ((ac / (ac + aw)) >= 80)
		cout << "a B.\n";
	else if ((ac / (ac + aw)) >= 70)
		cout << "a C.\n";
	else if ((ac / (ac + aw)) >= 60)
		cout << "a D.\n";
	else
		cout << "an F.\n";
	cout << "\n";

	cout << "You got" << sc << " subtraction problems correct.\n";
	cout << "You got" << sw << " subtraction problems incorrect.\n";
	cout << "Your total grade for subtraction is " << (sc / (sc + sw)) << "%, which is ";
	if ((sc / (sc + sw)) >= 90)
	{
		cout << "an A.\n";
		definiteencouragement();
	}
	else if ((sc / (sc + sw)) >= 80)
		cout << "a B.\n";
	else if ((sc / (sc + sw)) >= 70)
		cout << "a C.\n";
	else if ((sc / (sc + sw)) >= 60)
		cout << "a D.\n";
	else
		cout << "an F.\n";
	cout << "\n";

	cout << "You got" << mc << " multiplication problems correct.\n";
	cout << "You got" << mw << " multiplication problems incorrect.\n";
	cout << "Your total grade for multiplication is " << (mc / (mc + mw)) << "%, which is ";
	if ((mc / (mc + mw)) >= 90)
	{
		cout << "an A.\n";
		definiteencouragement();
	}
	else if ((mc / (mc + mw)) >= 80)
		cout << "a B.\n";
	else if ((mc / (mc + mw)) >= 70)
		cout << "a C.\n";
	else if ((mc / (mc + mw)) >= 60)
		cout << "a D.\n";
	else
		cout << "an F.\n";
	cout << "\n";
		
	cout << "You got" << dc << " division problems correct.\n";
	cout << "You got" << dw << " division problems incorrect.\n";
	cout << "Your total grade for division is " << (dc / (dc + dw)) << "%, which is ";
	if ((dc / (dc + dw)) >= 90)
	{
		cout << "an A.\n";
		definiteencouragement();
	}
	else if ((dc / (dc + dw)) >= 80)
		cout << "a B.\n";
	else if ((dc / (dc + dw)) >= 70)
		cout << "a C.\n";
	else if ((dc / (dc + dw)) >= 60)
		cout << "a D.\n";
	else
		cout << "an F.\n";
	cout << "\n";

	cout << "Overall, you answered a total of " << (ac + aw + sc + sw + dc + dw + mc + mw) << " problems.\n";
	cout << "You got " << (ac + sc + mc + dc) << " problems correct and " << (aw + sw + mw + dw) << " problems incorrect.\n";
	cout << "Your total grade is " << ((ac + dc + mc + sc) / ((aw + dw + mw + sw) + (ac + dc + mc + sc))) << "% which is";
	if ((ac / (ac + aw)) >= 90)
	{
		cout << "an A.\n";
		definiteencouragement();
	}
	else if (((ac + dc + mc + sc) / ((aw + dw + mw + sw) + (ac + dc + mc + sc))) >= 80)
		cout << "a B.\n";
	else if (((ac + dc + mc + sc) / ((aw + dw + mw + sw) + (ac + dc + mc + sc))) >= 70)
		cout << "a C.\n";
	else if (((ac + dc + mc + sc) / ((aw + dw + mw + sw) + (ac + dc + mc + sc))) >= 60)
		cout << "a D.\n";
	else
		cout << "an F.\n";
}


void PrintMenu()
{
	cout << "1. Addition Problem\n2. Subtraction Problem\n3. Multiplication Problem\n4. Division Problem\n5. Exit\n";
}

void encouragement ()
{
	int x;
	x = (rand () % 41);
	if (x == 1)
		cout << "Great Job!!\n";
	else if (x == 6)
		cout << "Way to go!\n";
	else if (x == 10)
		cout << "You're on a role!\n";
	else if (x == 14)
		cout << "You're a smart one, you!\n";
	else if (x == 19)
		cout << "How did you know?!\n";
	else if (x == 22)
		cout << "Genius!\n";
	else if (x == 28)
		cout << "Can't touch this!\n";
	else if (x == 31)
		cout << "Simply Outstanding!\n";
	else if (x == 25)
		cout << "Can't pass one over you, eh?\n";
	else if (x == 40)
		cout << "Knew you could do it!\n";
}

void definiteencouragement ()
{
	int x;
	x = (rand () % 11);
	if (x == 1)
		cout << "Great Job!!\n";
	else if (x == 2)
		cout << "Way to go!\n";
	else if (x == 3)
		cout << "You're on a role!\n";
	else if (x == 4)
		cout << "You're a smart one, you!\n";
	else if (x == 5)
		cout << "How did you know?!\n";
	else if (x == 6)
		cout << "Genius!\n";
	else if (x == 7)
		cout << "Can't touch this!\n";
	else if (x == 8)
		cout << "Simply Outstanding!\n";
	else if (x == 9)
		cout << "Can't pass one over you, eh?\n";
	else if (x == 10)
		cout << "Knew you could do it!\n";
}