#include<iostream>

const int SIZE = 5;

int main(void)
{
	using namespace std;

	char s[SIZE] = {};
	for (int i = 0; i < SIZE; i++)
		cin >> s[i];
	
	//   Parcurgem toate cele (2^n - 1) combinatii, folosindu-ne
	// de operatorii pe biti "&" si "<<";
	for (int i = 0; i < (1<<SIZE); i++)
	{
		for (int j = 0; j < SIZE; j++)
			if((i & (1<<j)) != 0)
				cout << s[j] << " ";
		cout << endl;		
	}
			
	return 0;
}

/* Caz particular:

Fie s[5] = {'a', 'b', 'c', 'd', 'e'};
i = 11;
Reprezentarea binara a lui "i" : 01011;
Prin al 2-lea ciclu, facem toate verificarile de tipul :
00001, 00010, 00100, 01000, 10000;
Daca reprezentarea binara a lui "i" si a lui "j" au valoarea "1" pe
aceeasi pozitie, afisam caracterul de pe pozitia respectiva;

Exemplu :
'a', 'b', 'c', 'd', 'e'
 0    1    0    1    1  = i;
 							 => (i&j) = 0 1 0 0 0;
 0    1    0    0    0  = j;
 Afiseaza caracterul 'b';
--------------------------------
 0    0    0    1    0  = j;
							=> (i&j) = 0 0 0 1 0;
 Afiseaza caracterul 'd';
 
 Si asa mai departe.
 
*/
