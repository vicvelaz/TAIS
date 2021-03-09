//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

struct tIntervalo {
	int inicio, final, repeticion;
};

bool operator < (tIntervalo const& i1, tIntervalo const& i2)
{
	return i1.inicio > i2.inicio;
}
/*bool operator >(tIntervalo const& i1, tIntervalo const& i2)
{
	return !(i1 < i2);
}*/
bool resuelveCaso() {
	int N, M, T;
	tIntervalo a;
	cin >> N >> M >> T;

	if (!cin)
		return false;

	priority_queue<tIntervalo> cola;

	bool problema = false;
	while (N--)
	{
		cin >> a.inicio >> a.final;
		a.repeticion = 0;
		cola.push(a);
	}
	while (M--)
	{
		cin >> a.inicio >> a.final >> a.repeticion;
		cola.push(a);
	}
	if (!cola.empty())
	{
		int limite=0;
		while (!problema && !cola.empty() && cola.top().inicio < T) { 
			if (cola.top().inicio >= limite) {
				limite = cola.top().final;
				a = cola.top();
				cola.pop();
				if (a.repeticion > 0)
				{
					a.inicio += a.repeticion;
					a.final += a.repeticion;
					cola.push(a);
				}
			}
			else 
				problema = true;
		}
	}
	if (problema)
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