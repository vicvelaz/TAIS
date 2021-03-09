// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


void resuelveCaso() {
	int N, V;
	cin >> N >> V;

	vector<int> pila(N);
	for (int i = 0; i < N; i++) {
		cin>>pila[i];
	}

	sort(pila.begin(), pila.end());
	int contCoches=0;
	int j = N - 1;
	for (int i = 0; i < j; ++i) {
		if (pila[i] + pila[j] >= V)
		{
			++contCoches;
			--j;
		}
	}

	cout << contCoches << '\n';
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