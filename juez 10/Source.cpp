// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


int resolver(bintree<char> const & arbol,bool &equilibrado) {
	if (arbol.empty())
		return 0;
	else {
		int izq = resolver(arbol.left(), equilibrado);
		int dcha = resolver(arbol.right(), equilibrado);
		if (izq - dcha > 1 || izq - dcha < -1)
			equilibrado = false;
		return 1 + max(izq, dcha);
	}
}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	bool equilibrado=true;
	int solucion = resolver(arbol,equilibrado);
	if (equilibrado)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;


}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}