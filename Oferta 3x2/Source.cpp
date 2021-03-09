//Victor Velazquez Cabrera
//TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool decreciente(int a, int b) {
    return a > b;
}

bool resuelveCaso() {
    int N;
    cin >> N;

    if (!std::cin)
        return false;
    
    vector<int> libros(N);
    for (int i = 0; i < N; ++i) {
        cin >> libros[i];
    }

    sort(libros.begin(), libros.end(), decreciente);

    int tam = libros.size();
    int descuento=0;
    int i = 0;
    while (i < tam) {
        if (tam - i >= 3) {
            descuento += libros[i + 2];
            i += 3;
        }
        else if (tam - i == 2)
            i += 2;
        else
            ++i;
    }

    cout << descuento << '\n';
    
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