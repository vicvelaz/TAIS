// Victor Velazquez Cabrera
// TAIS70

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include "GrafoDirigido.h"

class juego {
public:
	juego(GrafoDirigido& g, int n, int k, int ser, int esc) : dado(k), marked(g.V(), false), distTablero(g.V(), -1),distTo(g.V()) {
		leerTablero(g, ser, esc);
		bfs(g, n);
	}
	int minMovimientos(int n) {
		return distTo[n];
	}
private:
	int dado;
	std::vector<bool>marked;
	std::vector<int>distTo;
	std::vector<int>distTablero;

	void bfs(GrafoDirigido& g, int n) {
		std::queue<int> cola;
		cola.push(n);
		distTo[n] = 0;
		marked[n] = 0;
		while (!cola.empty()) {
			auto aux = cola.front();
			cola.pop();
			for (auto t : g.ady(aux)) {
				if (!marked[t]) {
					marked[t] = true;
					distTo[t] = distTo[aux] + 1;
					cola.push(t);
				}
			}
		}
	}
	void leerTablero(GrafoDirigido& g, int ser, int esc) {
		int v, w;
		for (int i = 0; i < ser; i++) {
			std::cin >> v >> w;
			distTablero[v - 1] = w - 1;
		}
		for (int i = 0; i < esc; i++) {
			std::cin >> v >> w;
			distTablero[v - 1] = w - 1;
		}
		for (int i = 0; i < g.V(); i++) {
			for (int j = i + 1; j <= g.V() - 1 && j <= dado + i; j++) {
				
				if (distTablero[j] == -1) {
					g.ponArista(i, j);
				}
				else 
					g.ponArista(i, distTablero[j]);
			}
		}
	}
};

bool resuelveCaso() {
	// leer los datos de la entrada
	int N, K, S, E;
	std::cin >> N >> K >> S >> E;

	if (N == 0 && K == 0 && S == 0 && E == 0) {
		return false;
	}

	GrafoDirigido tablero(N * N);
	
	juego mejorPartida(tablero, 0, K, S, E);

	int min = mejorPartida.minMovimientos(tablero.V() - 1);
	std::cout << min << "\n";


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}