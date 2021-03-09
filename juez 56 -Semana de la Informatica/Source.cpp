// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

struct Actividad {
	int ini, fin;
};

bool menor(Actividad const& act1, Actividad const& act2)  {
	return act1.ini < act2.ini;
}

struct tAlumnos {
	int tiempoFin;

	bool operator< (tAlumnos const &a) const {
		return this->tiempoFin < a.tiempoFin;
	}
};

bool resuelveCaso() {
	int N;
	cin >> N;

	if (N==0)
		return false;

	vector<Actividad> actividad(N);
	for (int i = 0; i < N; ++i) {
		cin >> actividad[i].ini >> actividad[i].fin;
	}

	sort(actividad.begin(), actividad.end(),menor);
	PriorityQueue<tAlumnos> alumnos;
	int totalAlumnos = 0;

	for (int i = 0; i < N; ++i) {

		if (alumnos.empty() || alumnos.top().tiempoFin > actividad[i].ini) {
			alumnos.push({ actividad[i].fin });
			++totalAlumnos;
		}
		else {
			alumnos.pop();
			alumnos.push({ actividad[i].fin });
		}

	}

	cout << totalAlumnos-1 << '\n';

	/*int contActividades = 1;
	int finActual = actividad[0].fin;
	for (int i = 1; i < N; ++i) {
		if (finActual < actividad[i].ini) {
			++contActividades;
			finActual = actividad[i].fin;
		}
	}

	cout << contActividades << '\n';*/

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