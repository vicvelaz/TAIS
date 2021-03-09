//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
//#include "Grafo.h"

using namespace std;

#include "ConjuntosDisjuntos.h"

using namespace std;


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int N, M;
	cin >> N >> M;
	if (!std::cin)  // fin de la entrada
		return false;

	ConjuntosDisjuntos grafismo(N);
	for (int i = 0; i < M; ++i)
	{
		int tam, a;
		cin >> tam;
		if (tam > 0)
			cin >> a;
		for (int j = 1; j < tam; ++j)
		{
			int b;
			cin >> b;
			grafismo.unir(a - 1, b - 1);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		cout << grafismo.tam(i) << ' ';
	}
	cout << '\n';


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