#include<iostream>
#include<cmath>

int main(void)
{
	using namespace std;
	
	// lSir = lungimea sirului;
	// mid = mijlocul vectorului principal;
	// lmid, rmid = capatul din stanga, respectiv dreapta, al vectorului principal;
	int v[50000] = {}, lSir = 0, mid = 0, lmid, rmid, nr = 0;
	
	cout << "Introduceti lungimea sirului: ";
	cin >> lSir;
	cout << "Inserati elementele din vectorul ordonat: ";
	for (int i = 1; i <= lSir; i++)
		cin >> v[i];
	cout << "Numar dorit: ";
	cin >> nr;
	
	lmid = 1;
	rmid = lSir;
	mid = ceil(double(lSir)/2);
	
	if (v[1] == nr)
		{
			cout << "Numarul cautat este pe pozitia 1 " << endl;
		}
		else if (v[lSir] == nr)
		{
			cout << "Numarul cautat este pe pozitia " << lSir << endl;		
		}
			else
			{
				while(v[mid] != nr)	 
				{
					if (((rmid == mid) || (lmid == mid)))
					{
						cout << "Numarul cautat nu este in sir" << endl;
						break;
					}
		
					if(v[mid] > nr)
					{
						rmid = mid;
						mid = ceil(double(mid+lmid)/2);
					}
					else
					{
						lmid = mid;
					mid = ceil(double(mid+rmid)/2);
					}
				}
			}

	if(v[mid] == nr)
		cout << "Numarul cautat este pe pozitia " << mid << endl;

	
	return 0;
}

/* Reprezentare grafica 1-dimensionala:

	Fie sirul v[7] = {1, 3, 6, 12, 18, 20, 25};
	nr = 20;

	Ciclul I)
	| 1 | _ | _ | 12 | _ | _ | 25 | (segment initial)
			 	  mid

	nr = 1, 12 sau 25 ? NU => rulam un nou ciclu;

	Ciclul II)
	12(mid) < 20(nr)
	| 12 | _ | 20 | 25 |	(subsegment)
		       mid

	nr = 20 ? DA
	Afiseaza numarul 20;

*/
