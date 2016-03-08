#include<iostream>
#include<cmath>

void initCoord(int, int);
void rightward(void);
void downward(void);
void leftward(void);
void upward(void);
void spiral(int);

int matrix[10][10] = {};
/*
	s = start;
	f = final;
*/
int *isRW = new int, *jsRW = new int, *jfRW = new int;
int *isDW = new int, *jsDW = new int, *ifDW = new int;
int *isLW = new int, *jsLW = new int, *jfLW = new int;
int *isUW = new int, *jsUW = new int, *ifUW = new int;

int main(void)
{
	using namespace std;

	int iM = 0, jM = 0; // M = matrix;

	cout << "Introduceti numarul de linii si de coloane: ";
	cin >> iM;
	cin >> jM;
		
	for (int i = 1; i <= iM; i++)
		for (int j = 1; j <= jM; j++)
			cin >> matrix[i][j];
	
	cout << endl;
	
	initCoord(iM, jM);

	spiral(iM);
	
	delete isRW, delete jsRW, delete jfRW;
	delete isDW, delete ifDW, delete jsDW;
	delete isLW, delete jsLW, delete jfLW;
	delete isUW, delete jsUW, delete ifUW;
				
	return 0;
}

void initCoord(int L, int C) // L = linii; C = coloane (din matricea data)
{
	// Coordonatele initiale ale functiei "spre dreapta"
	*jfRW = C;
	*isRW = *jsRW = 1;	
	
	// Coordonatele initiale ale functiei "in jos"
	*isDW = 2;
	*jsDW = C;
	*ifDW = L;
	
	// Coordonatele initiale ale functiei "spre stanga"
	*isLW = L;
	*jsLW = C - 1;
	*jfLW = 1;
	
	// Coordonatele initiale ale functiei "in sus"
	*isUW = L - 1;
	*jsUW = 1;
	*ifUW = 2;
	
	return;
}

void rightward(void)
{
	// Afisarea elementelor corespunzatoare directiei functiei
	for (int i = *isRW, j = *jsRW; j <= *jfRW; j++)
		std::cout << matrix[i][j] << " ";
	
	// Deplasarea coordonatelor functiei in matrice
	(*isRW)++;
	(*jsRW)++;
	(*jfRW)--;
	
	return;
}

void downward(void)
{
	// Afisarea elementelor corespunzatoare directiei functiei
	for (int i = *isDW, j = *jsDW; i <= *ifDW; i++)
		std::cout << matrix[i][j] << " ";
	
	// Deplasarea coordonatelor functiei in matrice
	(*isDW)++;
	(*jsDW)--;
	(*ifDW)--;
	
	return;
}

void leftward(void)
{
	// Afisarea elementelor corespunzatoare directiei functiei
	for (int i = *isLW, j = *jsLW; j >= *jfLW; j--)
		std::cout << matrix[i][j] << " ";
		
	// Deplasarea coordonatelor functiei in matrice
	(*isLW)--;
	(*jsLW)--;
	(*jfLW)++;
	
	return;
}

void upward(void)
{
	// Afisarea elementelor corespunzatoare directiei functiei
	for (int i = *isUW, j = *jsUW; i >= *ifUW; i--)
		std::cout << matrix[i][j] << " ";
	
	// Deplasarea coordonatelor functiei in matrice
	(*isUW)--;
	(*jsUW)++;
	(*ifUW)++;
	
	return;
}

void spiral(int L)
{
	int rtR = 0, rtD = 0, rtL = 0, rtU = 0; // rt = run time;
		
	// Calculul numarului de executari ale functiilor
	rtR = ceil(double(L)/2);
	rtD = floor(double(L)/2);
	L%2 == 0 ? rtL = rtR : rtL = rtR - 1;
	L%2 == 0 ? rtU = rtD - 1 : rtU = rtD;

	while(rtR != 0)
	{
		rightward();
		rtR--;
		if(rtD != 0)
		{
			downward();
			rtD--;
		}
		if(rtL != 0)
		{
			leftward();
			rtL--;
		}
		if(rtU != 0)
		{
			upward();
			rtU--;
		}
	}
	
}
