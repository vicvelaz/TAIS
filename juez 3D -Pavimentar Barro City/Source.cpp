//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "GrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

class GrafoPavimentar {
public:
	GrafoPavimentar(GrafoValorado<int> g) :marked(g.V(), false), pq(g.V()), edgeTo(g.V()), distTo(g.V(),numeric_limits<int>::max() ) {
		llega = true;
		_coste = 0;
		Prim(g);
		llegaATodas();

		if (llega)
			costeTotal();
	}

	bool consulta() {
		return llega;
	}

	int coste() {
		return _coste;
	}

private:
	vector<bool> marked;
	vector<Arista<int>> edgeTo;
	vector<int> distTo;
	IndexPQ<int> pq;
	bool llega;
	int _coste;

	//coste O(P* log I) donde P es el número de puentes e I el número de islas
	void Prim(GrafoValorado<int> const& G) {
		pq.push(0, 0);

		while (!pq.empty()) {
			int min = pq.top().elem; pq.pop();
			visit(G, min);
		}
	}

	//coste O(log I)
	void visit(const GrafoValorado<int>& G, int v) {
		marked[v] = true;

		for (Arista<int> e : G.ady(v)) {
			int w = e.otro(v);

			if (marked[w])continue;
			if (e.valor() < distTo[w]) {
				edgeTo[w] = e;
				distTo[w] = e.valor();
				pq.update(w, distTo[w]);
			}
		}
	}

	void llegaATodas() {
		for (int i = 0; i < marked.size() && llega; i++) {
			if (!marked[i])
				llega = false;
		}
	}

	void costeTotal() {

		for (int i = 1; i < edgeTo.size(); i++) {
			_coste += distTo[i];
		}
	}
};


bool resuelveCaso() {
	int V, E;

	cin >> V;

	if (!std::cin)  // fin de la entrada
		return false;
	cin >> E;
	GrafoValorado<int> G(V);
	int a1, a2, v;

	for (int i = 0; i < E; i++) {
		cin >> a1 >> a2 >> v;
		G.ponArista({ a1 - 1,a2 - 1,v });
	}

	GrafoPavimentar grafo(G);

	if (grafo.consulta()) {
		cout << grafo.coste() << "\n";
	}
	else {
		cout << "Imposible\n";
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