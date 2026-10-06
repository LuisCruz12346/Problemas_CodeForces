#include<iostream>
#include<string>
#include<vector>

/** Solucion al problema mirror Grid */ 

// https://codeforces.com/problemset/problem/1703/E 

using namespace std;
int n;

void casoN(){
	cin >> n;
	
	int p = n  - 1;
	vector<string> aij(n);	
	int cerosYunos[2] = {0, 0};
		
	for(int  i=0; i < n; i++){
		cin >> aij[i];
	}
	
	int operaciones = 0;
	int temp;
	
	// 10 000
	n--;
	for(int i = 0; i < n; i++){ 
		for(int j = i; j < n; j++){
			cerosYunos[aij[i][j] - '0']++;
			cerosYunos[aij[j][n] - '0']++;
			cerosYunos[aij[n][p - j] - '0']++;
			cerosYunos[aij[p - j][i] - '0']++;
			operaciones +=((cerosYunos[0] > cerosYunos[1]) ? cerosYunos[1]: cerosYunos[0]);
			cerosYunos[0] = 0;
			cerosYunos[1] = 0;
		}
		n--;
	}
	
	cout << operaciones << endl;
}

int main(){

	int t;
	cin >> t;
	
	while(t--){
		casoN();
	}
	
	return 0;
}
