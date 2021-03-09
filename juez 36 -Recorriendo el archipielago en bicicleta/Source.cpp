//Victor Velazquez Cabrera	
//TAIS70

#include <iostream>
#include <fstream>
#include <queue>
#include "GrafoValorado.h"
#include "PriorityQueue.h"

class Prim {
private:
	std::vector<bool> marked;
	std::queue<Arista<int>> mst;
	PriorityQueue<Arista<int>> pq;
	bool conexo;

	void visitar(GrafoValorado<int> const& G, int v) {
		marked[v] = true;
		for (auto w : G.ady(v)) {
			if (!marked[w.otro(v)])
				pq.push(w);
		}
	}

public:

	Prim(GrafoValorado<int> const& G) :marked(G.V()), mst(), pq() {
		visitar(G, 0);
		while (!pq.empty() && mst.size() < G.V() - 1) {
			Arista<int> a = pq.top(); pq.pop();
			int v = a.uno();
			int w = a.otro(v);

			if (!marked[v] || !marked[w]) {
				mst.push(a);

				if (!marked[v])
					visitar(G, v);
				if (!marked[w])
					visitar(G, w);
			}
		}
		conexo = (mst.size() == G.V() - 1);
	}

	bool esConexo() {
		return conexo;
	}

	int sumaValoresMST() {
		int resultado = 0, tam = mst.size();
		for (int i = 0; i < tam; ++i) {
			resultado = resultado + mst.front().valor();
			mst.pop();
		}
		return resultado;
	}

};

bool resuelveCaso() {
	int V, E;
	std::cin >> V >> E;

	if (!std::cin) return false;

	GrafoValorado<int> g(V);

	for (int i = 0; i < E; ++i) {
		int A, B, coste;
		std::cin >> A >> B >> coste;
		Arista<int> temp(A - 1, B - 1, coste);
		g.ponArista(temp);
	}

	Prim p(g);

	if (!p.esConexo()) 
		std::cout << "No hay puentes suficientes\n";
	else 
		std::cout << p.sumaValoresMST() << "\n";

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