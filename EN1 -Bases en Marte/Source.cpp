// comentario sobre la solución, incluyendo el análisis del coste
/*
He utilizado una cola de prioridad para guardar las baterías y un vector para guardar inicialmente
las baterías de repuesto y guardar el orden en que entran.
O(N log N) siendo N el número de baterías.
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

struct bateria {
	int id; // identificador de la pila
	int tiempo; //tiempo hasta el que dura la pila
	int dura; // cantidad de recarga que tiene la pila
};

bool operator < (bateria const& b1, bateria const& b2) {
	return b1.tiempo < b2.tiempo || (b1.tiempo == b2.tiempo) && b1.id < b2.id;
}

bool resuelveCaso() {

	// leemos la entrada
	int B;
	cin >> B;
	if (!cin)
		return false;

	// leer el resto del caso y resolverlo
	PriorityQueue<bateria> base;
	vector<bateria> repuesto;
	int tiempo;
	int id = 1;

	for (int i = 0; i < B; ++i) {
		cin >> tiempo;
		base.push({ id,tiempo, tiempo });
		++id;
	}

	int R; //pilas de repuesto.

	cin >> R;

	for (int i = 0; i < R; ++i) {
		cin >> tiempo;
		repuesto.push_back({ id,tiempo, tiempo });
		++id;
	}
	int Z, T;
	cin >> Z >> T;


	//Resolver caso
	int rep = 0; //Primera pila de repuesto
	bateria b;
	if (!base.empty())
		b = base.top(); // primera batería

	while (!base.empty() && b.tiempo <= T) {
		base.pop();
		if ((b.dura - Z) > 0) { // La pila sigue teniendo carga
			b.dura = b.dura - Z; // Se recarga quitando la carga Z que se pierde
			b.tiempo += b.dura;
			base.push(b);
		}
		else { //La pila ya no tiene carga
			if (rep < repuesto.size()) { // Si hay pilas de repuesto
				bateria b2 = repuesto[rep];
				b2.tiempo += b.tiempo;//Tiempo actual más lo que dura la pila.
				base.push(b2); // Metemos a la cola de prioridad la batería de repuesto siguiente.
				++rep;
			}
		}
		if (!base.empty())
			b = base.top();
	}


	if (base.size() < B && !base.empty()) { // Si quedan baterías pero no las neceserias
		cout << "FALLO EN EL SISTEMA\n";
	}
	if (base.size() == B) { // Hay suficientes baterías
		cout << "CORRECTO\n";
	}
	if (base.empty()) { // No quedan baterías
		cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";
	}
	int tam = base.size();
	for (int i = 0; i < tam; ++i) { // Muestra las baterías de la base
		bateria b = base.top();
		base.pop();
		cout << b.id << " " << b.tiempo << "\n";
	}
	cout << "---\n";
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}