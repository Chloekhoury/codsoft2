#include <iostream>
#include <math.h>
using namespace std;
void main()
{
	char f;
	float x, c, y;
	float f1(float, float);
	float f2(float, float);
	float f3(float, float);
	double f4(float, float);
	int f5(void);
	do {
		cout << "Choose which operation u wanna do: 1) Press '-' for soustraction \n" << "2) Press '+' for addition\n" << "3) Press '*' for multiplication\n" << " 4) Press '/' for division\n" << "5) Press '0' to stop";
		cout << " The type of operation you wanna do is: ";
		cin >> f;
		if (f == '-')
		{
			cout << " Enter 2 numbers:";
			cin >> x >> c;
			y = f1(x, c);
			cout << " The answer of " << x << "-" << c << "is: " << y;
		}
		if (f == '+')
		{
			cout << " Enter 2 numbers:";
			cin >> x >> c;
			y = f2(x, c);
			cout << " The answer of " << x << "+" << c << "is: " << y;
		}

		if (f == '*')
		{
			cout << " Enter 2 numbers:";
			cin >> x >> c;
			y = f3(x, c);
			cout << " The answer of " << x << "*" << c << "is: " << y;
		}
		if (f == '/')
		{
			cout << " Enter 2 numbers:";
			cin >> x >> c;
			y = f4(x, c);
			cout << " The answer of " << x << "/" << c << "is: " << y;
		}
		if (f == '0')
		{
			f5();
		}
	} while (f != 0);
	system("pause");
}

float f1(float z, float t) {
	return z - t;
}
float f2(float z, float t) {
	float val; val = z + t;
	return val;
}
float f3(float z, float t) {
	return z * t;
}
double f4(float z, float t) {
	return z / t;
}
int f5(void) {
	cout << "The program ended :)";
	return 0;
}