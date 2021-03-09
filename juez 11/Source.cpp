// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

/*struct tSol {
	int max, min;
};

int equilibrar(bintree<int> const& arbol, bool& equilb) { //Comprueba que las ramas no tengan una diferencia de altura mayor que 1
	if (arbol.empty())
		return 0;
	else {
		int izq = equilibrar(arbol.left(), equilb);
		int dcha = equilibrar(arbol.right(), equilb);
		if (izq - dcha > 1 || izq - dcha < -1)
			equilb = false;
		return 1 + max(izq, dcha);
	}
}


tSol esAVL(bintree<int> const& arbol, bool& okey) { //Comprueba que el arbol esta ordenado numericamente
	if (arbol.left().empty() && arbol.right().empty()) {
		int num = arbol.root();
		return { num,num };
	}
	else if (arbol.right().empty()){
		tSol Izq = esAVL(arbol.left(), okey);
		if (arbol.root() <= Izq.max)
			okey = false;
		return { arbol.root(),Izq.min };
	}
	else if (arbol.left().empty()) {
		tSol Dcha = esAVL(arbol.right(), okey);
		if (arbol.root() >= Dcha.min)
			okey = false;
		return{ Dcha.max, arbol.root() };
	}
	else {
		tSol Izq = esAVL(arbol.left(), okey);
		tSol Dcha = esAVL(arbol.right(), okey);
		if (arbol.root() <= Izq.max && arbol.root() >= Dcha.min)
			okey = false;
		return { Dcha.max,Izq.min };
	}
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	bool equilb,okey = true;
	int solucion = equilibrar(arbol, equilb);
	tSol sol = esAVL(arbol, okey);
	if (equilb&&okey)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;


}*/

unsigned int altura(bintree<int> arbol, bool& ok) {
	if (arbol.empty())
		return 0;
	else {
		unsigned int altIz = altura(arbol.left(), ok);
		unsigned int altDr = altura(arbol.right(), ok);
		if (altDr != altIz && altDr != altIz - 1 && altDr != altIz + 1)
			ok = false;
		return 1 + std::max(altIz, altDr);
	}
}

bool esMenor(bintree<int> arbol, int val) {

	if (arbol.empty()) return true;
	return arbol.root() < val && esMenor(arbol.left(), val) && esMenor(arbol.right(), val);
}

bool esMayor(bintree<int> arbol, int val) {

	if (arbol.empty()) return true;
	return arbol.root() > val && esMayor(arbol.left(), val) && esMayor(arbol.right(), val);
}

bool esBusqueda(bintree<int> arbol) {

	if (arbol.empty()) return true;

	return esMenor(arbol.left(), arbol.root()) && esMayor(arbol.right(), arbol.root())
		&& esBusqueda(arbol.left()) && esBusqueda(arbol.right());
}

void resuelveCaso() {
	auto arbol = leerArbol(-1);
	bool equilibrado = true;
	altura(arbol, equilibrado);

	if (equilibrado && esBusqueda(arbol))
		std::cout << "SI" << "\n";
	else 
		std::cout << "NO" << "\n";
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}