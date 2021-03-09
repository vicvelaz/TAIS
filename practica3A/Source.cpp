//Victor Velazquez Cabrera
//TAIS70

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include "Grafo.h"

using namespace std;

class NodoLejano {
private:
    int accesible = 0;
    vector<bool> marked;
    vector<int> distTo;
    int nodos;
    
    void bfs(Grafo const& g, int const& ini, int const& TTL) {
        queue<int> q;
        distTo[ini] = 0;
        marked[ini] = true;
        q.push(ini);
        //cout << "DEBUG [TTL=" << TTL << "] ---------------------------" << '\n';
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int w : g.ady(v) ) {
                if (!marked[w] && distTo[v] < TTL) {
                   // cout << "Valor distTo[v]=" << distTo[v] << " Valor distTo[w]=" << distTo[w] << '\n';
                    marked[w] = true;
                    distTo[w] = distTo[v] + 1;
                    ++accesible;
                    q.push(w);
                    
                }
            }
        }
        //cout << "DEBUG---------------------------END" << '\n';
    }

public:
    NodoLejano(Grafo const& g, int const& ini, int const& TTL) : marked(g.V(), false), distTo(g.V()), nodos(g.V()) {
        bfs(g, ini, TTL);
    }

    int getInnacesibles() {
        return nodos - accesible - 1;
    }
};


bool resuelveCaso() {
    int N, C;
    cin >> N >> C;

    if (!std::cin)
        return false;

    Grafo g(N);
    for (int i = 0; i < C; ++i) {
        int a, b;
        cin >> a >> b;
        g.ponArista(a-1,b-1);
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; ++i) {
        int ini, TTL;
        cin >> ini >> TTL;
        NodoLejano nodoLejano(g, ini - 1, TTL);
        cout << nodoLejano.getInnacesibles() << '\n';
    }

    cout << "---" << '\n';

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