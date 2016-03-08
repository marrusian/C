#include<iostream>

int main(void)
{
	using namespace std;
	
	
	int A[10][10] = {}, B[10][10] = {}, n = 0, m = 0, k = 0;
	
	cout << "Introduceti numarul de linii al matricei A: ";
	cin >> n;
	cout << "Numarul de coloane al matricei A: ";
	cin >> m;
	cout << "Numarul de coloane al matricei B: ";
	cin >> k;
	
	cout << "Inserati valorile matricei A: \n";
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> A[i][j];
	
	cout << endl;
	cout << "Inserati valorile matricei B: \n";
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= k; j++)
			cin >> B[i][j];
			
	// A[n][m] x B[m][k] = C[n][k]
	int C[10][10] = {};
	
	// Acest ciclu simuleaza algoritmul obisnuit de inmultire matriciala;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			for (int v = 1; v <= m; v++)
				C[i][j] += A[i][v] * B[v][j];
	
	cout << endl;
	cout << "A x B : \n";
	// Se afiseaza rezultatul inmultirii celor 2 matrici;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
			cout << C[i][j] << " ";
		cout << endl;
	}	
	
	//   Se construieste matricea transpusa prin inversarea liniilor cu 
	// coloanele si vice-versa;
	int Ct[10][10] = {};
	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= k; i++)
			Ct[i][j] = C[j][i];
	
	// Se afiseaza matricea transpusa;	
	cout << endl;
	cout << "Transpusa lui A x B: \n";
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << Ct[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
