#include<iostream>

int main(void)
{
	using namespace std;

	cout << "Introduceti numarul pe care doriti sa-l descompuneti: ";
	int number, fibo[50] = {};
	int fibodiv[50] = {};
	int totalsum = 0;
	int cFib = 0, cDiv = 1;
	cin >> number;
	
	int a = 0, b = 1;
	while (a < number)
	{
		fibo[cFib] = a;
		cFib++;
		a = a+b;
		b = a-b;
	}
	
	fibodiv[0] = fibo[cFib-1];
	totalsum = fibo[cFib-1];
	for (int i = cFib-2; i > 0; i--)
		if ((totalsum + fibo[i]) <= number)
		{
			fibodiv[cDiv] = fibo[i];
			totalsum += fibo[i];
			cDiv++;
			if (totalsum == number)
				break;
		}
				
	for (int i = 0; i < cDiv; i++)
		cout << fibodiv[i] << endl;
	
	
	
	
	return 0;
}
