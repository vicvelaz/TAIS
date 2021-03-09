// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;




bool resuelveCaso() {

    int N;
    cin >> N;

    if (N == 0)
        return false;

    PriorityQueue <int> gorras;

    for (int i = 0; i < N; ++i) {
        int g;
        cin >> g;
        gorras.push(g);
    }

    int a = gorras.top();
    int b = 0;
    gorras.pop();
    int numGorras = 0;
    while (!gorras.empty()) {
        if (gorras.size() == 1) {
             b = gorras.top();
            gorras.pop();
            numGorras += a + b;
        }
        else {
            b = gorras.top();
            gorras.pop();
            int sum = a + b;
            gorras.push(sum);
            numGorras += sum;
            a = gorras.top();
            gorras.pop();
        }
    }

    cout << numGorras << '\n';

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