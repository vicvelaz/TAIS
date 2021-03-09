// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "Matriz.h"

int cortes(const std::vector<int>& distancias, const int& n) {
	Matriz<int> matrizEsfuerzos(n + 2, n + 2);
	//Matriz<int> matrizCortes(n + 2, n + 2);

	for (int c = 2; c < n + 2; ++c) {
		int j = 0;
		for (int i = 0; i + c < n + 2; ++i) {
			int mejor = std::numeric_limits<int>::max(), aux;

			j = i + c;
			for (int k = i + 1; k < j; ++k) {
				aux = matrizEsfuerzos[i][k] + matrizEsfuerzos[k][j];
				if (aux < mejor) {
					mejor = aux;
					//matrizCortes[i][j] = k;
				}
			}
			mejor += 2 * (distancias[j] - distancias[i]);
			matrizEsfuerzos[i][j] = mejor;
		}
	}

	return matrizEsfuerzos[0][n + 1];

}

bool resuelveCaso() {
	int l, n;
	std::cin >> l >> n;

	if (l == 0 && n == 0) return false;

	std::vector<int> dCortes(n + 2);

	for (int i = 1; i <= n; ++i) {
		std::cin >> dCortes[i];
	}

	dCortes[0] = 0;
	dCortes[n + 1] = l;

	std::cout << cortes(dCortes, n) << "\n";

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