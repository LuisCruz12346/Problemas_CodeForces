#include<iostream>
#include<list>
#include<vector>

using namespace std;
// Resolucion al problema de cullingGame con iteradores a listas. 
/* El concept general es:
	1. Los numeros descendentes se pueden agrupar en un solo conjunto, y solo se guarda una referencia al primer valor. 
	2. Solo se valida hasta que no existe un 1 a la derecha debido a que no habra mas cambios. 
	3. Si se conoce la referencia del nodo a eliminar entonces el borrado y modificacion del nodo es O(1)

*/
// https://codeforces.com/problemset/problem/2262/B

void casoN(){
	
	list<int> grupalAcumlados; // 200 000 * 4= 800 000 
	vector<list<int>::iterator> referenciaGrupalAcumlados; // 1 600 000
	list<bool> validacion;	// 2 400 000
	vector<list<bool>::iterator> referenciaValidacion; // 3 200 000
	list<int> raiz; // 4 000 000
	vector<list<int>::iterator> referenciaRaiz; // 4 800 000 		
	list <int> grupal; // 5 600 000
	vector<list<int>::iterator> referenciaGrupal; // 6 400 000
	
	vector<int> enteros; // 7 200 000
	vector<int> enterosArreglosCorresponde; // 8 000 000
	
	int n, temp, ai;
	
	cin >> n;
	
	cin >> temp; 
	
	int pn = n, acumulados = temp;
	n--;
	pn--;
	
	referenciaGrupal.push_back(grupal.insert(grupal.end(), temp)); // 0
	referenciaRaiz.push_back(raiz.insert(raiz.end(), 1)); // 0
	referenciaValidacion.push_back(validacion.insert(validacion.end(), true)); // 0
	referenciaGrupalAcumlados.push_back(grupalAcumlados.insert(grupalAcumlados.end(), acumulados)); // 0
	
	
	int k = 0;
	
	enteros.push_back(temp);
	enterosArreglosCorresponde.push_back(k);
	
	int retiradas = 0;
	while(n--){
		cin >> ai;
		if(ai > temp){
			referenciaGrupal.push_back(grupal.insert(grupal.end(), 0)); // 0
			referenciaRaiz.push_back(raiz.insert(raiz.end(), raiz.back())); // 0
			referenciaValidacion.push_back(validacion.insert(validacion.end(), true)); // 0
			referenciaGrupalAcumlados.push_back(grupalAcumlados.insert(grupalAcumlados.end(), 0)); // 0
			if(ai > acumulados){
				validacion.back() = false;
				acumulados = 0;
				retiradas++;
			}
			k++;
		}
		grupal.back() += ai;
		raiz.back()+=1;
		acumulados+=ai;
		grupalAcumlados.back() = acumulados;
		temp = ai;
		
		enteros.push_back(ai);
		enterosArreglosCorresponde.push_back(k);
	}
	
	cout << retiradas << " ";
	pn--;
	while(pn--){
		cin >> ai;
		ai--;
		
		// No estoy en el primer punto(no hay raices atras) y ademas, lo que quiero quitar es una raiz
		if(((enterosArreglosCorresponde[ai]) > 0) && (ai == *referenciaRaiz[enterosArreglosCorresponde[ai] - 1] ) ){
			++(*referenciaRaiz[enterosArreglosCorresponde[ai]  - 1]);
			// Si es 0, significa que voy a quitar una retirada
			if(!(*referenciaValidacion[enterosArreglosCorresponde[ai]]))
				retiradas--;	
		}
		
		// Moficamos el grupal
		(*referenciaGrupal[enterosArreglosCorresponde[ai]]) -=  enteros[ai];
		// Se modifica su estado
		(*referenciaValidacion[enterosArreglosCorresponde[ai]]) = true;
		// Se modifica el acumuado actual
		(*referenciaGrupalAcumlados[enterosArreglosCorresponde[ai]]) -= enteros[ai];
		
		// Se guarda el nodo anterior, para empezar a validar desde ahi;
		auto it = referenciaValidacion[enterosArreglosCorresponde[ai]];
		auto ra = referenciaRaiz[enterosArreglosCorresponde[ai]];
		auto grR = referenciaGrupal[enterosArreglosCorresponde[ai]];
		
		// Obtenemos el acumulado anterior
		auto gru = referenciaGrupalAcumlados[enterosArreglosCorresponde[ai]];
		
		// Si es igual a 0, entonces no se puede retrasar. 
		if(enterosArreglosCorresponde[ai]){
			--ra;
			--gru;
		}else{ // Si es 0, saltame el primero 
			++it;
			++grR;
			if(!(*it)) // Si es cero vamos a poner como 1, ya que por definicion el primero no puede ser retirada
				retiradas = (retiradas > 0)? (retiradas - 1): 0; 
		}
		
		acumulados = (*gru);
		
		++gru;
		
		// Si es 0, se elimina el nodo 
		if(!(*referenciaGrupal[enterosArreglosCorresponde[ai]])){
			grupal.erase(referenciaGrupal[enterosArreglosCorresponde[ai]]);
			validacion.erase(referenciaValidacion[enterosArreglosCorresponde[ai]]);
			raiz.erase(referenciaRaiz[enterosArreglosCorresponde[ai]]);
			grupalAcumlados.erase(referenciaGrupalAcumlados[enterosArreglosCorresponde[ai]]);
			// Apuntamos al siguiente
			++it;
			++grR;
			++gru;
		}
		
		for ( ; it != validacion.end() && *it; ++it, ++ra,++gru, ++grR){
			if(enteros[*ra] > acumulados){
				(*it) = false;
				acumulados = (*grR);
				retiradas++;
			}else{
				acumulados += (*grR);
			}
			(*gru) = acumulados;	
		}
		
		cout << retiradas << " ";
		
	}
	cin >> ai >> acumulados;
	cout << 0 << endl;	
	
}

int main(){
	int t;
	cin >> t;
	while(t--){
		casoN();
	}
	return 0;
}
