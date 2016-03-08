#include<iostream>

int main(void)
{
	using namespace std;
	
	int v[15] = {};
	int lSir = 0;
	int tempVar = 0;
	
	cout << "Introduceti lungimea sirului: ";
	cin >> lSir;
	cout << "Introduceti datele: ";
	for (int i = 0; i < lSir; i++)
		cin >> v[i];
	
	for (int i = 0, j = lSir-1; i < j; i++, j--)
	{
		tempVar = v[i];
		v[i] = v[j];
		v[j] = tempVar;
	}
	
	for (int i = 0; i < lSir; i++)
		cout << v[i] << " ";
	
	
	
	return 0;
}
