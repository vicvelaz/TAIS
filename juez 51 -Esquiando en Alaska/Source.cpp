// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;


bool resuelveCaso() {
	int N;
	cin >> N;
	if (N==0)
		return false;

	PriorityQueue<int> altura;

	vector<int> altura(N);
	for (int i = 0; i < N; ++i) {
		cin>>altura[i];
	}

	vector<int>longitud(N);
	for (int i = 0; i < N; ++i) {
		cin >> longitud[i];
	}

	sort(altura.begin(), altura.end());
	sort(longitud.begin(), longitud.end());

	int resultado = 0;
	for (int i = 0; i < N; ++i) {
		resultado += abs(altura[i] - longitud[i]);
	}

	cout << resultado << '\n';

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