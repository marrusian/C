#include<iostream>

int main(void)
{
	using namespace std;
	
	int np = 0;
	bool flag = true;
	cout << "Introduceti un numar par: ";
	cin >> np;
	
	for (int i = 2; i <= (np/2); i++)
	{
		for (int j = 2; j*j <= (np-i); j++)
			if((i%j == 0) || ((np-i)%j == 0))
			{
				flag = false;
				break;
			}
			
		if(flag)
			cout << i << " " << np-i << endl;
		flag = true;	
	}
		
	return 0;
}
