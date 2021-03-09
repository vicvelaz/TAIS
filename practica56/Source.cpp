// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

struct tActiviad {
    int ini, fin;
};

bool operator <(tActiviad const& a1, tActiviad const& a2) {
    return a1.ini < a2.ini;
}

struct tAlumnos {
    int fin;
};

bool operator <(tAlumnos const& a1, tAlumnos const& a2) {
    return a1.fin < a2.fin;
}

bool resuelveCaso() {

    int N;

    cin >> N;
    if (N == 0)
        return false;
    
    PriorityQueue<tActiviad> actividades;
    for (int i = 0; i < N; ++i) {
        int ini, fin;
        cin >> ini >> fin;
        actividades.push({ ini, fin });
    }
   
    int numAmigos = 0;
    PriorityQueue<tAlumnos> alumnos;
    alumnos.push({ actividades.top().fin });
    actividades.pop();

    while (!actividades.empty()) {
        if (alumnos.top().fin <= actividades.top().ini)
            alumnos.pop();
        else 
            ++numAmigos;
        
        alumnos.push({ actividades.top().fin });
        actividades.pop();
    }

    cout << numAmigos << "\n";

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