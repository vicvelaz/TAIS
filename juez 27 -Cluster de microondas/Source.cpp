// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

struct tTurno {
	int hora;
	int tiempo;

	
};
bool operator < (const tTurno& t1, const tTurno& t2) {
	return t1.hora < t2.hora;
}

struct tMicro {
	int id;
	int horafin;
	
};

bool operator < (const tMicro& m1, const tMicro& m2) {
	return m1.horafin < m2.horafin || (m1.horafin == m2.horafin && m1.id < m2.id);
}

bool resuelveCaso() {

	int N, T;
	cin >> N >> T;
	if ( N == 0 && T == 0)
		return false;

	PriorityQueue<tTurno> turnos;
	PriorityQueue<tMicro> microondas;

	for (int i = 0; i < N; ++i) {
		int hora, tiempo;
		cin >> hora >> tiempo;
		turnos.push({ hora,tiempo });

	}
	int id = 0;
	while (!turnos.empty()) {
		tTurno t = turnos.top();
		turnos.pop();
		
		if (microondas.empty() || t.hora + T < microondas.top().horafin) { //si es necesario añadir un nuevo microondas
			microondas.push({ id, t.hora + t.tiempo });
			++id;
		}
		else { //si hay un microondas libre antes de p
			tMicro m = microondas.top();
			microondas.pop();
			m.horafin = t.hora + t.tiempo;
			microondas.push(m);
		}
	}

	cout << microondas.size() << endl;

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