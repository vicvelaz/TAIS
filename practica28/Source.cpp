//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;


struct tTarea{
    int ini, fin, rep;

    bool operator < (tTarea const& t) const {
        return this->ini < t.ini;
    }
};



bool resuelveCaso() {
    int N, M, T;
    cin >> N >> M >> T;

    if (!std::cin)
        return false;

    PriorityQueue<tTarea> tareas;

    for (int i = 0; i < N; ++i) {
        int ini, fin;
        cin >> ini >> fin;
        tareas.push({ ini,fin,0 });
    }

    for (int i = 0; i < M; ++i) {
        int ini, fin, rep;
        cin >> ini >> fin >> rep;
        tareas.push({ ini,fin,rep });
    }

    bool conflicto = false;
    tTarea t1 = tareas.top();
    tareas.pop();
    if (t1.rep != 0)
        tareas.push({ t1.ini + t1.rep,t1.fin + t1.rep, t1.rep });

    while (!conflicto && !tareas.empty() && tareas.top().ini < T) {
        if (t1.fin > tareas.top().ini)
            conflicto = true;
        else {
            t1 = tareas.top();
            tareas.pop();
            if (t1.rep != 0)
                tareas.push({ t1.ini + t1.rep,t1.fin + t1.rep, t1.rep });
        }
    }

    if (conflicto)
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