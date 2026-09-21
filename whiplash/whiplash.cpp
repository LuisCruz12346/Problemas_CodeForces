#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// Resolucion al problema de codeForces
// https://codeforces.com/problemset/problem/2254/F

bool busquedaBinaria(const vector<unsigned int>& arreglo_entrada,int indiceLimiteIzquierdo, int indiceLimiteDerecho, int busqueda){
	int mitad;
	while(indiceLimiteIzquierdo != indiceLimiteDerecho){
		mitad = (indiceLimiteIzquierdo + indiceLimiteDerecho) >> 1;
		if(arreglo_entrada[mitad] == busqueda)
			return true;
		if(busqueda > arreglo_entrada[mitad])
			indiceLimiteIzquierdo = mitad + 1;
		else 
			indiceLimiteDerecho = mitad;
	}
	return (arreglo_entrada[indiceLimiteIzquierdo] == busqueda) ? true : false;
}

// Este posiblemente construir y ordenar me llevaria mas tiempo. 
int posibilidad(const vector<unsigned int>& a, const vector<unsigned int>& b, int baseN,int n){
	vector<unsigned int> aP;
	vector<unsigned int> aPb;
	// n
	for(int i = 0; i < n ; i++){
		aPb.push_back(a[i]^a[baseN]);
	}
	aPb[baseN] = a[baseN];
	
	//n + (n log n)
	sort(aPb.begin(), aPb.end());
	
	// n + (n log n) + n

	return (b == aPb);
}

void casot(){
	int n; 
	cin >> n;
	vector <unsigned int> a(n);
	vector <unsigned int> t(n);
	vector <unsigned int> b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		t[i] = a[i];
	}
	for(int i = 0; i < n; i++)
		cin >> b[i];
	
	// Verificamos si el primer arreglo es una posibilidad.  
	sort(b.begin(), b.end());
	sort(t.begin(), t.end());
	
	if(b == t){
		cout << "Yes" << endl;
		return;
	}
		
	
	vector<bool> renglones (n, true);
	int j;
	bool val1;
	for(int i= 0 ; i < n; i++){
		if(renglones[i]){	
			val1 = true;
			for(j = n - 1; j > i; j--){
				if(!busquedaBinaria(b, 0,  n - 1, a[i]^b[j])){
					renglones[j] = false;
					val1 = false;	
				}		
			}
			val1 = busquedaBinaria(b, 0,  n - 1, a[i]); 
			
			if(val1){ // Si esta bien entonces es una posibilidad
				if(posibilidad(a, b, i, n)){
					cout << "Yes" << endl;
					return;
				}	
			}		
		}
	}
	
	cout << "No" << endl;
	return;
}

int main(){
	
	int t;
	cin >> t;
	while(t--)
		casot();
	return 0;
}
