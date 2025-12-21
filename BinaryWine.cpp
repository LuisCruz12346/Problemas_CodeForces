#include <iostream>
#include <vector>
#include <algorithm>

// Resolucion al problema de Binary Wine
// SOLUCIONADO: LAS PRUEBAS QUE APARECEN EN LA PAGINA
// https://codeforces.com/problemset/problem/2165/C 
// 2000 puntos
using namespace std;

int main(){
    // Se proceden las entradas del arreglo
    int t, n, q, costo,p;
    unsigned int c, temporal, temp2;
    cin >> t;
    vector<int> resultados;
    while(t--){
        cin >> n >> q;
        vector<unsigned int> ai(n);
        // Procesamos las entradas ai
        for(int i=0; i<n; i++)
            cin >> ai[i];
        // Ordenamos las variables
        sort(ai.begin(), ai.end());
        // Procesamos todas las posibilidades de q
        while(q--){
            p = 0, costo = 0;
            temporal = 1073741824;
            cin >> c;
            while(c){
                temp2 = temporal & c;
                if(temp2) {
                    p++;
                    if(c>ai[ai.size()-p])
                        costo += (temporal-ai[ai.size()-p]);
                } 
                c = temp2 ^ c;
                temporal >>=1;
                if( p+1 == n) {
                    p++;
                    if(c>ai[ai.size()-p])
                        costo += (c-ai[ai.size()-p]); 
                    break;
                }
            }
            resultados.push_back(costo); 
        }   
    }
    cout << "-------------------- \n";
    for (int x : resultados)
        cout << x << "\n";
}