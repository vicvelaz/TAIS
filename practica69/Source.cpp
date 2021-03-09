// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


struct tPelicula {
    int ini, fin, duracion;

    tPelicula(int i, int d) :ini(i), fin(i + d + 10), duracion(d) {};
    //tPelicula() {};
};

bool operator < (tPelicula const& p1, tPelicula const& p2) {
    return p1.ini < p2.ini;
}


int resuelve(vector<tPelicula> const& l) {
    int MAX = 24 * 60 +10;
    vector<int>peliculas(MAX+1, 0);   

    for (int i = 1; i <= l.size(); ++i) {
        for (int j = MAX; j >= 1; --j) {
            if (l[i - 1].fin <= j)
                peliculas[j] = max(peliculas[j], peliculas[ l[i - 1].ini] + l[i - 1].duracion);
        }
        //cout << "---\n";
    }

    return peliculas[MAX-10];
}


bool resuelveCaso() {
    int N;
    cin >> N;

    if (N == 0)
        return false;

    vector<tPelicula> listaPelis;

    for (int i = 0; i < N; ++i) {
        int hh, mm, duracion;
        char basura;
        cin >> hh >> basura >> mm >> duracion;
        listaPelis.push_back({ hh * 60 + mm,duracion });
    }

    sort(listaPelis.begin(), listaPelis.end());

    cout << resuelve(listaPelis) <<'\n';
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