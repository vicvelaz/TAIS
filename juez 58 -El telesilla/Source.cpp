//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool ordenar(const int& a, const int& b) {
	return a > b;
}


bool resuelveCaso() {
	int pesoMax, N;
	cin >> pesoMax >> N;

	if (!std::cin)
		return false;

	vector<int> pesos(N);
	for (int i = 0; i < N; ++i) {
		cin >> pesos[i];
	}

	sort(pesos.begin(), pesos.end(), ordenar);

	int contTelesillas = 0;
	int j = N - 1;
	for (int i = 0; i < N && i <= j; ++i) {
		if (pesos[i] + pesos[j] <= pesoMax) {
			j--;
		}
		contTelesillas++;
	}

	cout << contTelesillas << '\n';

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