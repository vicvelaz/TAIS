// comentario sobre la solución, incluyendo el análisis del coste

// Coste O(V+E) siendo V los nodos y E las conexiones entre ellos

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#include "Grafo.h"

// esta es la clase que resuelve el problema  COMPLÉTALA
class NodoLejano {
public:
	NodoLejano(int origen, Grafo const& g, int& TTL) : marked(g.V(), false), distTo(g.V()), nodos(g.V()) {
		//nodos = g.V(); // Guardo el número de nodos totales del grafo
		bfs(g, origen, TTL); // Búsqueda en anchura
	}

	int inalcanzables() const {
		return nodos - cont - 1; // Resto los nodos totales del grafo menos los que he podido visitar
	}

private:
	/* atributos */
	int nodos;
	int cont = 0;
	vector<bool>marked; // vector de marcados
	vector<int>distTo; // vector de distancias al origen


	void bfs(Grafo const& G, int s, int const TTL) // Búsqueda en anchura guardando los nodos visitados en una cola y marcándolos
	{
		queue<int> q;
		distTo[s] = 0;
		marked[s] = true;
		q.push(s);
		while (!q.empty())
		{
			int v = q.front(); q.pop();
			for (int w : G.ady(v))
			{
				if (!marked[w] && distTo[v] < TTL) // Si no he visitado ya ese nodo y la distancia es menor al TTL
				{
					++cont; // Sumo 1 al contador de nodos visitados dentro del grafo
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					q.push(w);
				}
			}
		}
	}
};


bool resuelveCaso() {

	int V, E;
	cin >> V >> E;
	if (!cin)
		return false;

	Grafo G(V);
	int u, v;
	for (int i = 0; i < E; ++i) {
		cin >> u >> v;
		G.ponArista(u - 1, v - 1);
	}

	int K; // número de preguntas
	cin >> K;
	while (K--) {
		int origen, TTL;
		cin >> origen >> TTL;
		--origen;

		NodoLejano nl(origen, G, TTL);
		cout << nl.inalcanzables() << "\n";
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