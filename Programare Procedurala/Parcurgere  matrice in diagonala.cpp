#include<iostream>

void diagonal(int, int);

int matrix[10][10] = {};
int *isDG = new int, *ifDG = new int, *jsDG = new int, *jfDG = new int;

int main(void)
{
	using namespace std;
	
	int iM = 0, jM = 0;
	cout << "Introduceti numarul de linii si de coloane: ";
	cin >> iM >> jM;
	
	for (int i = 1; i <= iM; i++)
		for (int j = 1; j <= jM; j++)
			cin >> matrix[i][j];
			
	
	cout << endl;	
	diagonal(iM, jM);
	
	
	return 0;
}

void diagonal(int L, int C)
{
	*isDG = L;
	*ifDG = L;
	*jsDG = 1;
	*jfDG = 1;
	
	while(*isDG >= 1)
	{
		for (int i = *isDG, j = *jsDG; i <= *ifDG, j <= *jfDG; i++, j++)
			std::cout << matrix[i][j] << " ";
			
		(*isDG)--;
		if((*jfDG) < C)
			(*jfDG)++;
		if((*jfDG) == C && (*isDG) != 1)
			(*ifDG)--;
	}
	
	(*isDG)++;
	(*jsDG)++;

	while((*ifDG) >= 1)
	{
		for (int j = *jsDG, i = *isDG; j <= *jfDG, i<= *ifDG; j++, i++)
			std::cout << matrix[i][j] << " ";
		
		if(((*ifDG) != L && (*jfDG) == C) || ((*ifDG) == L && (*jfDG) == C))
			(*ifDG)--;
		else
			(*jfDG)++;
			
		(*jsDG)++;
	}
	
	return;
}
