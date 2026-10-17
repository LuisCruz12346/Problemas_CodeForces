#include<iostream>
#include<vector>

using namespace std;

int num_reinaActual = 0;
int n, p;

bool N_Reinas(vector<bool>& renglones,vector<bool>& columnas, vector<bool>&  diagonalD , vector<bool>& diagonalI, vector<int>& posicionReina ){
	if(num_reinaActual > p)
		return true;
		
	for(int i = 0; i < n; i++){
		if(renglones[i]){ // Nos saltamos esa fila si ya tiene reina
			for(int j = 0; j < n; j++){
				if(columnas[j] && diagonalD[i + j] && diagonalI[(p - j) + i]){ // Reina posible
					posicionReina[num_reinaActual] = i * n + j;
					renglones[i] = false;
					columnas[j] = false;
					diagonalD[i + j] = false;
					diagonalI[(p - j) + i] = false;
					num_reinaActual++;
					if(N_Reinas(renglones, columnas, diagonalD, diagonalI, posicionReina)){
						return true;
					}else{
						renglones[i] = true;
						columnas[j] = true;
						diagonalD[i + j] = true;
						diagonalI[(p - j) + i] = true;
						num_reinaActual--;
					}		
				}								
			}
		}
	}
	return false;	
}


int main(){
	cin >> n;
	p = n - 1;
	
	vector<bool> renglones (n, true);
	vector<bool> columnas (n, true);
	
	vector<bool> diagonalD ( n << 2, true);
	vector<bool> diagonalI ( n << 2, true);
	
	vector<int> posicionReina (n);
	
	if(N_Reinas(renglones, columnas, diagonalD, diagonalI , posicionReina)){
		cout << "Reinas en : "<<  endl;
		for(int i: posicionReina){
			cout << "i: " << ((int)(i/n)) << " j: " << (i%n) << endl;  
		}
		return 0;
	}
	
	cout << "Sin reinas" << endl;
	
	return -1;
}
