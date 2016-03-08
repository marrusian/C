#include<iostream>

int main(void)
{
	using namespace std;
	
	
	int a = 0, b = 1, nr = 0;
	cout << "Introduceti numar: ";
	cin >> nr;
	
	// Generam sirul lui Fibbonaci pana la numarul dat;
	while (a <= nr)
	{
		a = a + b;
		b = a - b;
	}
	
	//   Daca numarul cautat nu este ultimul numar din sir,
	// atunci acesta nu se afla	in sir.
	if (b == nr)
		cout << "Numarul este in sirul lui fibbo." << endl;
	else
		cout << "Numarul nu se afla in sirul lui fibbo." << endl;
		
	return 0;
}

