//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Grafo.h"

using namespace std;

class GrafoBipartito {
private:
	std::vector<bool> marked; 
	std::vector<char> types; 
	bool correct;

	void dfs(Grafo const& g, int v) {
		marked[v] = true;
		for (long int w : g.ady(v)) {
			if (types[w] == '=')
				types[w] = (types[v] == '-' ? '+' : '-');
			else if (types[w] == types[v])
				correct = false;
			if (!marked[w]) {
				dfs(g, w);
			}
		}
	}

public:

	GrafoBipartito(Grafo const& g) : marked(g.V(), false), types(g.V(), '='), correct(true) {
		for (int v = 0; v < g.V(); ++v) {
			if (!marked[v]) {
				types[v] = '-';
				dfs(g, v);
			}
		}
	}

	bool is_correct() const {
		return correct;
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int num_vertices, num_edges;
	cin >> num_vertices >> num_edges;
	if (!cin)
		return false;
	Grafo g(num_vertices);
	for (int i = 0; i < num_edges; ++i) {
		int lelem, relem;
		cin >> lelem >> relem;
		g.ponArista(lelem, relem);
	}
	GrafoBipartito gb(g);
	if (gb.is_correct())
		cout << "SI\n";
	else
		cout << "NO\n";
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