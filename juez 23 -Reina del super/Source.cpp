// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include "PriorityQueue.h"

using namespace std;

class Cajas {
public:
    struct caja {
        int orden;
        int tiempo;
    };

    bool operator() (const caja& c1, const caja& c2) {
        return c1.tiempo < c2.tiempo || (c1.tiempo == c2.tiempo && c1.orden < c2.orden);
    }
};



bool resuelveCaso() {
   
    int N, C;

    cin >> N >> C;
    
    if (N == 0 && C == 0)
        return false;

    PriorityQueue <Cajas::caja, Cajas> cola;
    queue<int> clientes;

    for (int i = 0; i < C; ++i) {
        int tiempo;
        cin >> tiempo;
        clientes.push(tiempo);
    }

    if (C < N) {
        cout << C + 1 << "\n";
        return true;
    }
  
    for (int i = 0; i < C; ++i) {
        if (i < N){
            cola.push({ i + 1, clientes.front() });
        }
        else {
            Cajas::caja c = cola.top();
            cola.pop();
            cola.push({ c.orden, clientes.front() + c.tiempo });
        }
        clientes.pop();
    }
    
    cout << cola.top().orden << "\n";
    
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