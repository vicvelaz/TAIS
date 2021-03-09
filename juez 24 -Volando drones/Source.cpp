//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"


using namespace std;

struct tDron {
	int tiempo;
};

bool operator<(tDron const& a, tDron const& b) {
	return a.tiempo > b.tiempo;
}


bool resuelveCaso() {


	if (!std::cin)
		return false;

	int N, A, B;

	cin >> N >> A >> B;
	 
	PriorityQueue<tDron> pilasA;

	for (int i = 0; i < A; ++i) {
		int a;
		cin >> a;
		pilasA.push({ a });
	}

	PriorityQueue<int> pilasB;
	for (int i = 0; i < B; ++i) {
		int b;
		cin >> b;
		pilasB.push({b});
	}

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