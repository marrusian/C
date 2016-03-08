#include<iostream>
#include<cmath>

int main(void)
{
	using namespace std;
	
	int n = 0, ncopy = 0, counter = 0, sum = 0;
	
	cout << "Introduceti un numar n: ";
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		cout << i;
	}
	
	ncopy = n;
	while (ncopy != 0)
	{
		ncopy /= 10;
		counter++;
	}
	
	ncopy = 1;
	while (n != 0)
	{
		ncopy = (n - pow(10, counter-1)) + ncopy;
		sum += (ncopy * counter);
		n -= ncopy;
		ncopy = 1;	
		counter--;	
	}
	
	cout << endl << "Suma cifrelor este: " << sum;
	
	return 0;
}
