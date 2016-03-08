#include<iostream>

const int SIZE = 50;
const int S1 = 3, S2 = 5;

int main(void)
{
	using namespace std;
	
	int n1[SIZE] = {}, n2[SIZE] = {}, n3[SIZE] = {};
	int L1 = 0, L2 = 0, Lmax = 0, dif = 0, r = 0;
	
	while(L1 < S1)
	{
		cin >> n1[L1];
		L1++;
	}
	
	while(L2 < S2)
	{
		cin >> n2[L2];
		L2++;
	}
		
	L1 < L2 ? dif = L2-L1 : dif = L1-L2;
	
	if(dif > 0)
		if(L1 < L2)
		{
			for (int i = (L1 - 1); i >= 0; i--)
				n1[i + dif] = n1[i];
			for (int i = dif-1; i >= 0; i--)
				n1[i] = 0;
		}
		else if (L2 < L1)
		{
			for (int i = (L2 - 1); i >= 0; i--)
				n2[i + dif] = n2[i];
			for (int i = dif-1; i >= 0; i--)
				n2[i] = 0;
		}
	
	L1 < L2 ? Lmax = L2 : Lmax = L1;
	
	for (int i = Lmax - 1; i >= 0; i--)
	{
		if(r > 0)
		{
			n3[i] = ((n1[i] + n2[i])%10 + r)%10;
			r = ((n1[i] + n2[i]) + r)/10;
		}
		else
		{
			n3[i] = (n1[i] + n2[i])%10;
			r = (n1[i] + n2[i])/10;
		}	
	}
	
	if(r != 0)
	{
		for (int i = (Lmax - 1); i >= 0; i--)
			n3[i + r] = n3[i];
		for (int i = r-1; i >= 0; i--)
			n3[i] = r;
	}
	
	cout << endl;
	int counter = 0;
	bool A = true;
	
	for (int i = 0; i < Lmax+r; i++)
	{
		cout << n3[i];
		counter++;
		if((Lmax+r) > 3)
			if(A)
			{
				if(counter == ((Lmax+r)%3) || (counter%3 == 0))
				{
					cout << ",";
					A = false;
					counter = 0;
				}
			}
			else if((counter%3 == 0) && (i != (Lmax+r-1)))
			{
				cout << ",";
				counter = 0;
		}
	}
	
		
	return 0;
}
