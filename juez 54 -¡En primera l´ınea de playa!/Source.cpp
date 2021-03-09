// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edificio {
	int oeste, este;
};

bool operator< (Edificio const &a, Edificio const &b) {
		return a.oeste < b.oeste;
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N==0)
		return false;

	vector<Edificio> edificio(N);
	for (int i = 0; i < N; ++i) {
		cin >> edificio[i].oeste >> edificio[i].este;
	}

	sort(edificio.begin(), edificio.end());

	int contTuneles = 1;
	int actualEste = edificio[0].este;
	for (int i = 1; i < N; ++i) {
		if (edificio[i].oeste < actualEste) {
			if (actualEste > edificio[i].este) {
				actualEste = edificio[i].este;
			}
		}
		else{
			++contTuneles;
			actualEste = edificio[i].este;
		}
	}
	

	cout << contTuneles << '\n';

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