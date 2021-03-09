// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;


bool resuelveCaso() {

	int I, P;

	cin >> I >> P;
	if (I == 0 && P == 0)
		return false;

	PriorityQueue<int, std::greater<int>> izquierda;
	PriorityQueue<int> derecha;

	int primero = I;
	for (int i = 0; i < P; ++i) {
		for (int j = 0; j < 2; ++j) {
			int a;
			cin >> a;

			if (a < primero) {
				izquierda.push(a);
			}
			else
				derecha.push(a);

			
		}
		while (izquierda.size() > derecha.size()) {

			derecha.push(primero);
			primero = izquierda.top();
			izquierda.pop();

		}
		while (izquierda.size() < derecha.size()) {
			izquierda.push(primero);
			primero = derecha.top();
			derecha.pop();
		}
		cout << primero << " ";
	}

	cout << endl;

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