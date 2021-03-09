// Victor Velazquez Cabrera
// TAIS70


#include <fstream>
#include <iostream>
#include <vector>

#include "TreeMap_AVL.h"
using namespace std;
template <typename Clave, typename Valor, typename Comparador = less<Clave>>
class TreeMapRan : public map<Clave, Valor, Comparador> {
public:

	TreeMapRan(Comparador c = Comparador()) : map<Clave, Valor, Comparador>(c) {};

	vector<Clave> rango(Clave const& k1, Clave const& k2) const {
		vector<Clave> rango;
		this->rango(k1 - 1, k2 + 1, this->raiz, rango);
		return rango;
	}

protected:
	using TreeNode = typename map<Clave, Valor, Comparador>::TreeNode;
	using Link = TreeNode *;

	void rango(Clave const& k1, Clave const& k2, Link a, vector<Clave>& lista) const {
		if (a == nullptr)
			return;
		if (a->iz != nullptr && this->menor(k1, a->cv.clave))
			rango(k1, k2, a->iz, lista);
		if (this->menor(k1, a->cv.clave) && this->menor(a->cv.clave, k2))
			lista.push_back(a->cv.clave);
		if (a->dr != nullptr && this->menor(a->cv.clave, k2))
			rango(k1, k2, a->dr, lista);
	}
};


bool resuleveCaso() {
	TreeMapRan<int, int, less<int>> arbol;
	int numElem, clave, k1, k2;
	vector<int> lista;

	cin >> numElem;
	if (numElem <= 0) return false;

	for (int i = 0; i < numElem; i++) {
		cin >> clave;
		arbol.insert(clave);
	}

	cin >> k1 >> k2;

	lista = arbol.rango(k1, k2);

	auto it = lista.cbegin();

	if (!lista.empty()) {
		while (it != lista.cend()) {
			cout << *it;
			++it;
			if (it != lista.cend())
		     cout << " ";
		}
	}
	 cout << '\n';
	return true;
}

int main() {// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	     ifstream in("datos.txt");
	auto cinbuf =      cin.rdbuf(in.rdbuf());
#endif

	while (resuleveCaso());
#ifndef DOMJUDGE
	     cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}