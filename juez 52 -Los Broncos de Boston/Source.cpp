// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;

bool decreciente(int a, int b) {
	return a > b;
}
bool resuelveCaso() {
	int N;
	cin >> N;
	if (N==0)
		return false;

	vector<int>rivales(N);
	for (int i = 0; i < N; i++)
	{
		cin >> rivales[i];
	}

	vector<int>broncos(N);
	for (int i = 0; i < N; i++)
	{
		cin >> broncos[i];
	}

	sort(rivales.begin(), rivales.end());
	sort(broncos.begin(), broncos.end(), decreciente);

	int resultado = 0;
	int aux = 0;
	for (int i = 0; i < broncos.size(); ++i) {
		bool continua = true;
		for (int j = aux; j < rivales.size() && continua; ++j) {
			++aux;
			if (broncos[i] >= rivales[j]) {
				resultado += broncos[i] - rivales[j];
				continua = false;
			}
		}
	}

	cout << resultado << '\n';

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