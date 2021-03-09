//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stack>
#include "Grafo.h"

using namespace std;

class GrafoArbolLibre {
private:
    vector<bool> marked;
    bool correcto = true;

    void dfs(Grafo const& g, int v, int parent) {
        marked[v] = true;
        for (int w : g.ady(v)) {
           
            if (!marked[w])
                dfs(g, w, v);
            else if (w != parent)
                correcto = false;
        }
    }

public:
    GrafoArbolLibre(Grafo const& g) : marked(g.V(),false) {
        dfs(g, 0, -1);
        
    }

    bool esLibre() {
        return correcto && isConexo();
    }

    bool isConexo() {
        bool conexo = true;

        for (bool marcado : marked) {
            if (!marcado)
                conexo = false;
        }

        return conexo;
    }
};

bool resuelveCaso() {
    int V, E;
    cin >> V >> E;
    if (!std::cin)
        return false;

    Grafo g(V);
    for (int i = 0; i < E; ++i) {
        int a, b;
        cin >> a >> b;
        g.ponArista(a,b);
    }
    
    GrafoArbolLibre grafoArbolLibre(g);

    if (grafoArbolLibre.esLibre())
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