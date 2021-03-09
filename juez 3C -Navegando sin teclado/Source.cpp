// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <fstream>
#include <queue>
#include <limits>
#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"

//Dijkstra
int resuelve(const GrafoDirigidoValorado<int>& G, const std::vector<int>& tCargas) {
	std::vector<int> distTo(G.V(), std::numeric_limits<int>::max());
	IndexPQ<int, std::less<int>> pq(G.V());

	distTo[0] = 0;
	pq.push(0, 0);

	while (!pq.empty()) {
		int v = pq.top().elem;
		pq.pop();
		for (AristaDirigida<int> e : G.ady(v)) {
			int v = e.from(), w = e.to();
			if (distTo[w] > distTo[v] + e.valor() + tCargas[v]) {
				distTo[w] = distTo[v] + e.valor() + tCargas[v];
				pq.update(w, distTo[w]);
			}
		}
	}

	if (distTo[G.V() - 1] == std::numeric_limits<int>::max()) 
		return -1;

	return distTo[G.V() - 1] + tCargas[G.V() - 1];

}

bool resuelveCaso() {
	int N, M;
	std::cin >> N;

	if (N == 0) return false;

	std::vector<int> tCargas(N);

	for (int i = 0; i < N; ++i)
		std::cin >> tCargas[i];

	std::cin >> M;

	GrafoDirigidoValorado<int> g(N);

	for (int i = 0; i < M; ++i) {
		int A, B, coste;
		std::cin >> A >> B >> coste;
		AristaDirigida<int> temp(A-1, B-1, coste);
		g.ponArista(temp);
	}

	int sol = resuelve(g, tCargas);

	if (sol == -1) std::cout << "IMPOSIBLE\n";
	else std::cout << sol << "\n";

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