//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std; 

const int INF = 1000000000;

pair<int, vector<int> > darts(vector<int> const& valores, int D) {
    // calcula cuantos dardos hacen falta
    int n = valores.size(), total_num_darts = 0;
    vector<int> V(D + 1, INF); // cuantos dardos hacen falta por cada cantidad j
    V[0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = valores[i]; j < V.size(); ++j) {
            V[j] = min(V[j], V[j - valores[i]] + 1);
        }
    }
    total_num_darts = V[V.size() - 1];

    // conoce que dardos se utilizan
    vector<int> num_dardos(n, 0); // cuantos dardos hacen falta en cada sector

    if (total_num_darts < INF ) {
        int i = n - 1, j = D;
        while (j > 0) {
            if (valores[i] <= j && V[j] == V[j - valores[i]] + 1) {
                ++num_dardos[i];
                j = j - valores[i];
            }
            else
                --i;
        }
        return { total_num_darts, num_dardos };
    }
    else
        return{ -1,num_dardos };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    int D, S; //D = puntos a conseguir ; S = nº sectores 
    cin >> D >> S;
    if (!std::cin)
        return false;

    vector<int> valores(S + 1); //Puntos de cada sector (de menor a mayor)

    for (int i = 1; i < S + 1; ++i) {
        int elem;
        cin >> valores[i];
    }

    pair<int, vector<int> > sol = darts(valores, D); //Se devuelve el menor par nºTiradas-Valor de cada tirada

    if (sol.first != -1) { //Si existe solucion
        auto num_darts = sol.second;
        cout << sol.first << ":"; //mostramos el numero de lanzamientos minimo necesario
        for (int i = num_darts.size() - 1; i > 0; --i) { // Recorremos el vector de valores de tiradas al revés, para que se muestre de mayor a menor
            for (int k = 0; k < num_darts[i]; ++k) // Mostramos k veces el valor del sector actual
                cout << " " << valores[i];
        }
    }
    else //Si no existe solucion mostramos Imposible por pantalla
        cout << "Imposible";
    cout << "\n";

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