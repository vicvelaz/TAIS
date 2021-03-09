// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "TreeMap_AVLTaml.h"




bool resuelveCaso() {
	unsigned int numElem;

	std::cin >> numElem;
	if (numElem == 0) return false;

	int claves;
	int m;
	int posicion;

	map<int, int, std::less<int>> arbol;
	for (int i = 0; i < numElem; i++) {
		std::cin >> claves;
		arbol.insert(claves);
	}

	std::cin >> m;
	//arbol.print();
	for (int j = 0; j < m; j++) {
		std::cin >> posicion;
		int claves = arbol.k_esimo(posicion);
		if (claves == -1) std::cout << "??\n";
		else std::cout << claves << '\n';
	}

	std::cout << "---\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}