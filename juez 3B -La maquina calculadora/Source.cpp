//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>






bool resuelveCaso() {


	if (!std::cin)
		return false;


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