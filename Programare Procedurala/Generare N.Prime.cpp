#include<iostream>

// 	 Numarul pana la care dorim sa generam numerele prime.
const int SIZE = 300;

int main(void)
{
	using namespace std;
	bool flag = true;
	
	for (int i = 2; i <= SIZE; i++)
	{
		for (int j = 2; j*j <= i; j++)
		{							  
			if (i%j == 0)			   
			{
				flag = false;
				break;				
			}	
		}
									
		if(flag)
			cout << i << endl;
			
		flag = true;
	}
		
	
	return 0;
}
