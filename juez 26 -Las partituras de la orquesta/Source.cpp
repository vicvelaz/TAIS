//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

struct tInstrumento {
	int musicos;
	int grupos;
	int musicos_grupo;

	bool operator<(tInstrumento const& i) const {
		return this->musicos_grupo > i.musicos_grupo;
	}
};



bool resuelveCaso() {

	int P, I;
	cin >> P >> I; 

	if (!std::cin)
		return false;

	PriorityQueue<tInstrumento> info;

	for (int i = 0; i < I; ++i) {
		int num;
		cin >> num;
		info.push({ num,1,num });
	}

	int partituras = P - I;
	while (partituras > 0 && info.top().musicos_grupo > 1) {

		tInstrumento elem = info.top();
		info.pop();
		elem.grupos++;

		if (elem.musicos % elem.grupos == 0) {
			elem.musicos_grupo = elem.musicos / elem.grupos;
		}
		else {
			elem.musicos_grupo = (elem.musicos / elem.grupos)+1;
		}
		info.push(elem);

		partituras--;
	}

	cout << info.top().musicos_grupo << endl;

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