//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "Matriz.h"

/*
 tablero(i,j) = Maximo valor posible hasta la fila i y la columna j del mismo.
 tablero(i,j) = max(tablero[i-1][j-1],tablero[i-1][j],tablero[i-1][j+1]) + tablero[i][j]

 Costes:
	O(N^2) en espacio.
	O(N^2 + N) en tiempo
 */

void resuelve(Matriz<int>& tablero, int& colIni, int& sumaTotal, const int& N) {

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			tablero[i][j] = std::max(tablero[i - 1][j - 1], std::max(tablero[i - 1][j], tablero[i - 1][j + 1])) + tablero[i][j];
	}

	sumaTotal = 0;
	colIni = 0;

	for (int i = 1; i <= N; ++i) {
		if (sumaTotal < tablero[N][i]) {
			sumaTotal = tablero[N][i];
			colIni = i;
		}
	}

}


bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (!std::cin) return false;

	Matriz<int> mat(N + 1, N + 2, 0);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			std::cin >> mat[i][j];
	}

	int sol = 0, max = 0;
	resuelve(mat, sol, max, N);

	std::cout << max << " " << sol << "\n";

	return true;
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}