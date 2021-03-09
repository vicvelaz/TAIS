//Victor Velazquez Cabrera
//TAIS70

// El problema propuesto "Ratones en el laberinto" propone un laberinto compuesto por celdas conectas entre s� por unos tramos conocidos(a veces solo un sentido),
// los cuales toman un tiempo en ser atravesados. Se supone un rat�n en cada celda (excepto salida) y se pide conocer, sabiendo cu�nto tiempo
// toma atravesar cada tramo, cu�ntos tardar�n como mucho T segundos en superar el laberinto, dada una celda de salida S.
//
// En mi soluci�n he interpretado el laberinto como un grafo dirigido valorado donde cada celda la represento como un v�rtice, cada tramo
// que conecta dos celdas como una arista entre dos v�rtices y el tiempo que toma cada tramo en ser atravesado como el valor de la arista 
// correspondiente al tramo.
// He utilizado el algoritmo de Dijkstra visto en clase para calcular dado un v�rtice del grafo los caminos m�nimos al resto de v�rtices.
// Para conocer los caminos m�nimos hasta el v�rtice correspondiente a la salida del laberinto, utilizo el grafo inverso del laberinto original, que ser�
// equivalente a conocer todos los caminos m�nimos que "entran" al v�rtice de salida.
// Tras invocar a DijkstraSP(), cuento cu�ntos v�rtices tienen una distancia m�nima al v�rtice de salida de menor o igual a T.
// 
// El coste de mi soluci�n para cada caso de prueba (por cada c�mputo de un laberinto) est� compuesto por lo siguiente:
// (V n�mero de v�rtices, E n�mero de aristas)
// - Inicializaciones de los vectores edgeTo, distTo e IndexPq pq -> V
// - DijkstraSP() va a procesar todas las aristas del grafo y los v�rtices los considera seg�n su prioridad en pq (distTo[]) -> E logV
// - Recorro distTo para contar los v�rtices que tienen una distancia m�nima al v�rtice de salida de menor o igual a T -> V
//
// Por lo tanto, al comprender el mayor de los costes propuestos (est�n sumados, V + V + E log V), el coste es E log V

#include <iostream>
#include <fstream>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"
using namespace std;

class Ratones {
private:
	vector<AristaDirigida<int>> edgeTo;
	vector<int> distTo;
	IndexPQ<int> pq;
	int salida;

	void relax(vector<AristaDirigida<int>>& edgeTo, vector<int>& distTo, IndexPQ<int>& pq, AristaDirigida<int> e) {
		int v = e.from(), w = e.to();
		if (distTo[w] > distTo[v] + e.valor()) {
			distTo[w] = distTo[v] + e.valor();
			edgeTo[w] = e;
			pq.update(w, distTo[w]);
		}
	}

public:

	Ratones(GrafoDirigidoValorado<int> G, int s):salida(s), edgeTo(G.V()), distTo(G.V(), std::numeric_limits<int>::max()), pq(G.V()) {
		distTo[salida] = 0;
		pq.push(salida, 0);

		while (!pq.empty()) {
			int v = pq.top().elem;
			pq.pop();
			for (AristaDirigida<int> e : G.ady(v)) {
				relax(edgeTo, distTo, pq, e);
			}
		}
	
	}

	int numRatonesExito(int T) {
		int num_ratones_meta = 0;
		for (int i = 0; i < distTo.size(); ++i) {
			int t = distTo[i];
			if (i != salida && t != std::numeric_limits<int>::max() && t <= T)
				++num_ratones_meta;
		}
		return num_ratones_meta;
	}

};
/*const long int INF = numeric_limits<int>::max();

void relax(vector<AristaDirigida<int>>& edgeTo, vector<int>& distTo, IndexPQ<int>& pq, AristaDirigida<int> e) {
	int v = e.from(), w = e.to();
	if (distTo[w] > distTo[v] + e.valor()) {
		distTo[w] = distTo[v] + e.valor();
		edgeTo[w] = e;
		pq.update(w, distTo[w]);
	}
}

void DijkstraSP(GrafoDirigidoValorado<int> const& gdv, vector<AristaDirigida<int>>& edgeTo, vector<int>& distTo, IndexPQ<int>& pq, int s) {
	distTo[s] = 0;
	pq.push(s, 0);

	while (!pq.empty()) {
		int v = pq.top().elem;
		pq.pop();
		for (AristaDirigida<int> e : gdv.ady(v)) {
			relax(edgeTo, distTo, pq, e);
		}
	}

}*/

bool resuelveCaso() {
	int N, S, T, P;
	cin >> N >> S >> T >> P;

	if (!cin)
		return false;
	--S; // Ajuste para que S este comprendido entre 0 y N-1

	GrafoDirigidoValorado<int> gdv(N);

	for (int i = 0; i < P; ++i) {
		int v, w, weight;
		cin >> v >> w >> weight;
		--v; --w; // Ajuste para que v y w esten comprendidos entre 0 y N-1
		gdv.ponArista({ v,w,weight });
	}

	Ratones r(gdv.inverso(), S);

	cout << r.numRatonesExito(T) << '\n';
	/*vector<AristaDirigida<int>> edgeTo(gdv.V());
	vector<int> distTo(gdv.V(), INF);
	IndexPQ<int> pq(gdv.V());

	DijkstraSP(gdv.inverso(), edgeTo, distTo, pq, S);

	int num_ratones_meta = 0;
	for (int i = 0; i < distTo.size(); ++i) {
		int t = distTo[i];
		if (i != S && t != INF && t <= T)
			++num_ratones_meta;
	}

	cout << num_ratones_meta << "\n";*/

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}