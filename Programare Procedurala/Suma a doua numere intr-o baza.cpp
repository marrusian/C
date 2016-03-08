#include<iostream>
#include<cmath>
#include<climits>

int BTD(int, int);
int DTB(int, int);

int main(void)
{
	using namespace std;
	
	int nri1 = 0, nri2 = 0, baza = 0, nrd1 = 0, nrd2 = 0;
	int op1 = 0, op2 = 0;

	cout << "Introduceti doua numere: ";
	cin >> nri1;
	cin >> nri2;
	cout << "Introduceti baza: ";
	cin >> baza;
	
	nrd1 = BTD(nri1, baza);
	nrd2 = BTD(nri2, baza);
	
	op1 = nrd1 + nrd2;
	op2 = nrd1 * nrd2;
	
	cout << "Suma dintre " << nri1 << " si " << nri2 << " este " << DTB(op1, baza) << endl;
	cout << "Inmultirea dintre " << nri1 << " si " << nri2 << " este " << DTB(op2, baza) << endl;
	
	return 0;
}

int BTD(int n, int base)
{
	int nld = 0, i = 0, nd = 0;
	
	while (n != 0)
	{
		nld = n % 10;
		nd += (nld * pow(base, i));
		i++;
		n /= 10;
	}
	
	return nd;
}

int DTB(int n, int base)
{
	int r = 0, nd = 0;
	while(n != 0)
	{	
		for(int i = 0; i < UINT_MAX; i++)
		{
			if((pow(base, i)) > n)
			{
				r = pow(base,i-1);
				for(int j = 0; j < UINT_MAX; j++)
				{
					if((j * r) > n)
					{
						nd = (nd*10 + (j-1));
						n -= ((j-1) * r);
						break;
					}
				}
				break;	
			}	
		}	
	}
	
	return nd;
}

