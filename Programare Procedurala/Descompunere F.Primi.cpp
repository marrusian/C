#include<iostream>

int main(void)
{
	using namespace std;
	
	// n = numar; d = divizor; p = putere;
	int n = 0, d = 2, p = 0;

	cout << "Introduceti numar: ";
	cin >> n;
	while(n > 1)
	{
		while(n%d == 0)
		{
			p++;
			n /= d;
		}
		
		if(p)
		{
			cout << d << " la puterea a " << p << "\n";	
			p = 0;
		}
				
		d++;
	}
	
	return 0;
}
