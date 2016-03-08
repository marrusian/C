#include<iostream>
#include<cstdlib>

int main(void)
{
	using namespace std;
	
	int v[10000] = {}, lSir = 0, i = 0, temp = 0,  j = 1;
	bool flag = true;

	cout << "Introduceti lungimea sirului: ";
	cin >> lSir;
	
	for (int i = 0; i < lSir; i++)
	{
		if (i % 2 == 0)
			v[i] = rand() % 1000 + 1;
		else
			v[i] = -rand() % 1000 + 1;
	}
			
	while (flag)
	{
		flag = false;
		for (i = 0; i < (lSir - j); i++)
			if (v[i] > v[i+1])
			{
				temp = v[i];
				v[i] = v[i+1];
				v[i+1] = temp;
				flag = true;
			}	
		j++;		
	}
	
	return 0;
}
