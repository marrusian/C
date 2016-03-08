#include<iostream>
#include<cmath>


int main(void)
{
	using namespace std;
	
	long double n, stack = 1;
	int ncopy, k, kcopy;
	cout << "Numar: ";
	cin >> n;
	ncopy = n;
	cout << "Putere: ";
	cin >> k;
	kcopy = k;
	
	while (k >= 2)
	{
		if (k%2 == 0)
		{
			n = pow(n, 2);
			k /= 2;
		}
		else
		{
			k -= 1;
			stack *= n;
		}	
	}
	n *= stack;
	
	cout << ncopy << "^" << kcopy << " = " << n;
	
	return 0;
}
