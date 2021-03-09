//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "Matriz.h"


std::string resuelve(std::string const& word1, std::string const& word2) {


	const int N = word1.size(), M = word2.size();
	Matriz<int> mat(N + 1, M + 1, 0);

	for (int i = 1; i <= N; ++i) {
		for (int f = 1; f <= M; ++f) {
			if (word1[i-1] == word2[f-1])
				mat[i][f] = mat[i - 1][f - 1] + 1;
			else
				mat[i][f] = std::max(mat[i - 1][f], mat[i][f - 1]);
		}
	}
	int tam = mat[N][M];



	std::string subcadena = "", aux = "";
	int i = N, j = M;

	while (tam > 0) {
		if (word1[i - 1] == word2[j - 1]) {
			subcadena += word1[i - 1];

			--tam;
			--i;
			--j;
		}
		else {
			if (mat[i][j] == mat[i][j - 1])
				--j;
			else
				--i;
		}
	}



	std::string palabra = "";


	for (int i = subcadena.size(); i > 0; i--) {
		palabra += subcadena[i - 1];
	}





	return palabra;
}


bool resuelveCaso() {
	std::string word1, word2;
	std::cin >> word1 >> word2;

	if (!std::cin) return false;

	std::cout << resuelve(word1, word2) << "\n";

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