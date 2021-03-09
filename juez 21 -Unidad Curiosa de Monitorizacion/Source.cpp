// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include"PriorityQueue.h"


using namespace std;
struct ucm {
	unsigned int id;
	unsigned int periodo;
	unsigned int momento;
	ucm() : id(0), periodo(0), momento(0) {};
	//ucm(const unsigned& i, const unsigned& p, const unsigned& m) : id(i), periodo(p), momento(m) {};
};

bool operator<(const ucm& u1, const ucm& u2) {
	return u1.momento < u2.momento || (u1.momento == u2.momento && u1.id < u2.id);
}

bool resuelveCaso() {
	unsigned int n;
	std::cin >> n;

	if (n == 0) return false;

	PriorityQueue<ucm> cola;

	for (unsigned int i = 0; i < n; ++i) {
		unsigned int id, p;
		std::cin >> id >> p;
		cola.push({ id, p, p });
	}

	unsigned int envios;
	std::cin >> envios;

	for (unsigned int i = 0; i < envios; ++i) {
		ucm e = cola.top();
		cola.pop();
		std::cout << e.id << '\n';
		e.momento += e.periodo;
		cola.push(e);
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