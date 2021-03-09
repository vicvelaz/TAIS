//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

using namespace std;

int INF = numeric_limits<int>::max();

class paquetes {
private:
    vector<int> distTo;
    IndexPQ<int, less<int>> pq;

   

    void dijkstra(GrafoDirigidoValorado<int> const& g, int const& origen) {
        distTo[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem;
            pq.pop();
            for (AristaDirigida<int> e : g.ady(v)) {
                int v = e.from(), w = e.to();
                if (distTo[w] > distTo[v] + e.valor()) {
                    distTo[w] = distTo[v] + e.valor();
                    pq.update(w, distTo[w]);
                }
            }
        }
    }

public:
    paquetes(GrafoDirigidoValorado<int> const& g, int const & origen) :distTo(g.V(),INF) , pq(g.V()) {
        dijkstra(g, origen);
       
    }

    vector<int> getDistTo() {
        return distTo;
    }
    

};

bool resuelveCaso() {
    int N, C;
    cin >> N >> C;

    if (!std::cin)
        return false;

    GrafoDirigidoValorado<int> g(N);
    for (int i = 0; i < C; ++i) {
        int origen, dest, esfuerzo;
        cin >> origen >> dest >> esfuerzo;
        g.ponArista({ origen - 1,dest - 1,esfuerzo });
    }

    int O, P;
    cin >> O >> P;
                        
    --O;// para ajustar el indice
    paquetes paquete(g, O);
    paquetes paqueteInv(g.inverso(), O);
    int esfuerzoTotal = 0;
    bool posible = true;
    for (int i = 0; i < P; ++i) {
        int destino;
        cin >> destino;
        --destino; //para que coincida los indices
       // paquetes p(g.inverso(), destino);
        if (paquete.getDistTo()[destino] != INF && paqueteInv.getDistTo()[destino] != INF) {
            esfuerzoTotal += paquete.getDistTo()[destino] + paqueteInv.getDistTo()[destino];
        }
        else
            posible = false;
    }

    if (posible)
        cout << esfuerzoTotal << '\n';
    else
        cout << "Imposible\n";



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