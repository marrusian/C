#include<iostream>
#include<cmath>

int main(void)
{
	using namespace std;
	
	int k = 0, sir_divizori[100] = {}, counter = 2;
	sir_divizori[1] = 1;
	
	cout << "Introduceti un numar intreg: ";
	cin >> k;
	
	if((k%2 == 0) && ((k%4) != 0))
		cout << "Ecuatia nu are solutii intregi";
	else if(k%2 == 1)
	{
		bool flag = true;
		
		for (int i = 2; i*i <= k; i++)
		{
			if(k%i == 0)
			{
				sir_divizori[counter] = i;
				counter++;
				flag = false;	
				for (int j = i+1; j <= (k/2); j++)
				{
					if (j%2 != 0)
						if(k%j == 0)
						{
							sir_divizori[counter] = j;
							counter++;
						}
				}
				break;			
			}
		}
		sir_divizori[counter] = k;
		
		if(flag)
		{
			cout << "X= " << int(ceil(double(k)/2));
			cout << "; Y= " << int(floor(double(k)/2)) << endl;
		}
		else
			for (int q = 1, w = counter; q < w; q++, w--)
			{
				cout << "X= " << (sir_divizori[q] + sir_divizori[w])/2;
				cout << "; Y= " << (sir_divizori[w] - sir_divizori[q])/2 << endl;
			}
	}
	else
	{
		for (int i = 2; i <= (k/2); i++)
		{
			if(k%i == 0)
			{
				sir_divizori[counter] = i;
				counter++;
			}
		}
		sir_divizori[counter] = k;
		
		for (int q = 1, w = counter; q < w; q++, w--)
		{
			if (((sir_divizori[q]%2) != 0) || (sir_divizori[w]%2 !=0))
					continue;
			cout << "X= " << (sir_divizori[q] + sir_divizori[w])/2;
			cout << "; Y= " << (sir_divizori[w] - sir_divizori[q])/2 << endl;
		}
		
	}
	
	int mid = ceil((counter)/2.);
	if (((counter % 2) != 0) && (sir_divizori[mid]*sir_divizori[mid]) == k)
	{
		cout << "X = " << sir_divizori[mid];
		cout << "; Y = " << "0";
	}
		
	return 0;
}
