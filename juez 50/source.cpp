//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;



bool resuelveCaso() {
	int N, L;
	cin >> N >> L;
	if (!std::cin)
		return false;

	vector<int> agujeros(N);
	for (int i = 0; i < N; ++i) {
		cin >> agujeros[i];
	}

	/*vector<int> distancias;
	for (int i = 0; i < N - 1; ++i) {
		distancias.push_back(agujeros[i + 1] - agujeros[i]);
	}

	int longitudActual=0;
	int numParches=1;
	for (int i = 0; i < distancias.size(); ++i) {
		if (longitudActual + distancias[i] <= L) {
			longitudActual += distancias[i];
		}
		else {
			longitudActual = 0;
			++numParches;
		}
	}

	cout << numParches << '\n';*/

	int longitudActual = agujeros[0];
	int numParches = 1;

	for (int i = 0; i < agujeros.size(); ++i) {
		if (longitudActual + L < agujeros[i]) {
			numParches++;
			longitudActual = agujeros[i];
		}
	}

	cout << numParches << '\n';

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