//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "GrafoValorado.h"

using namespace std;

void dfs(GrafoValorado<long int> const& g, int v, int destino, long int anchura, vector<bool>& marca, bool& posible) {
    marca[v] = true;
    vector<Arista<long int>> ady = g.ady(v);
    int i = 0;
    while (!posible && i < g.ady(v).size()) {
        int w = ady[i].otro(v);
        if (!marca[w] && ady[i].valor() >= anchura) {
            if (w == destino)
                posible = true;
            else
                dfs(g, w, destino, anchura, marca, posible);
        }
        ++i;
    }
}

bool caminoPosible(GrafoValorado<long int> const& g, const int&origen, const int&destino, const long int&anchura) {
    vector<bool> marca(g.V(), false);
    bool posible = false;
    dfs(g, origen, destino, anchura, marca, posible);

    return posible;
}



bool resuelveCaso() {
    int V, E;

    cin >> V >> E;

    if (!std::cin)
        return false;

    GrafoValorado<long int> g(V);
    for (int i = 0; i < E; ++i) {
        int v1, v2;
        long int ancho;
        cin >> v1 >> v2 >> ancho;
        g.ponArista({ v1-1, v2-1, ancho });
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; ++i) {
        int origen, destino;
        long int anchura;
        cin >> origen >> destino >> anchura;
        if (caminoPosible(g,origen-1, destino-1, anchura))
            cout << "SI\n";
        else
            cout << "NO\n";
    }

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