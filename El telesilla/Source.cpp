//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;




bool resuelveCaso() {
    int P, N;
    cin >> P >> N;

    if (!std::cin)
        return false;
    vector<int> pesos(N);
    for (int i = 0; i < N; ++i) {
        cin >> pesos[i];
    }

    sort(pesos.begin(), pesos.end());
    int i = 0, j=N-1, tam = N, numViajes = 0;
    
    while (N > 0) {
        if (i == j) {
            ++numViajes;
            --N;
        }
        else if (pesos[i] + pesos[j] <= P) {
            ++numViajes;
            ++i;
            --j;
            N -= 2;
        }
        else {
            --j;
            ++numViajes;
            --N;
        }
        
    }
    
    cout << numViajes << '\n';

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