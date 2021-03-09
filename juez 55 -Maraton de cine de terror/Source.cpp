// Victor Velazquez Cabrera
// TAIS70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
# include <algorithm>
using namespace std;


/*struct Hora {
	int horas, minutos;
};

struct Pelicula {
	Hora inicio, fin;
};

Hora sumar(Hora const& hora, int const& minutos) {
	Hora resultado = hora;
	
	resultado.minutos +=  minutos;
	if (resultado.minutos >= 60) {
		resultado.horas += resultado.minutos / 60;
		resultado.minutos = resultado.minutos % 60;
	}

	return resultado;
}

bool operator < (Hora const& hora1, Hora const& hora2) {
	if (hora1.horas < hora2.horas)
		return true;
	else if (hora1.horas == hora2.horas && hora1.minutos < hora2.minutos)
		return true;
	else
		return false;
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N==0)
		return false;

	char basura;
	int duracion;
	vector<Pelicula> pelicula(N);
	for (int i = 0; i < N; i++) {
		cin >> pelicula[i].inicio.horas >> basura >> pelicula[i].inicio.minutos >> duracion;
		pelicula[i].fin=sumar(pelicula[i].inicio, duracion+10); //Los 10 minutos que tarda 
	}

	sort(pelicula.begin(), pelicula.end());

	int contPeliculas=1;
	Pelicula peliActual=pelicula[0];
	for (int i = 1; i < N; ++i) {
		if (peliActual.fin < pelicula[i].fin) {
			++contPeliculas;
			peliActual = pelicula[i];
		}
	}

	cout << contPeliculas << '\n';

	return true;

}*/

struct Hora {
	int hora;
	int minutos;
};

Hora operator+(Hora const& a, int const& minutos) {
	Hora resultado = a;
	resultado.minutos += minutos;
	while (resultado.minutos >= 60) {
		resultado.minutos -= 60;
		++resultado.hora;
	}
	return resultado;
}

bool operator<(Hora const& a, Hora const& b) {
	if (a.hora == b.hora) return a.minutos < b.minutos;
	return (a.hora < b.hora);
}

bool operator<=(Hora const& a, Hora const& b) {
	if (a.hora == b.hora) return a.minutos <= b.minutos;
	return (a.hora <= b.hora);
}

bool operator==(Hora const& a, Hora const& b) {
	return a.hora == b.hora && a.minutos == b.minutos;
}

struct Pelicula {
	Hora inicio;
	Hora fin;

	bool operator<(const Pelicula& p) const {
		return fin < p.fin;
	}

	bool operator<=(const Pelicula& p) const {
		return fin <= p.fin;
	}
};


void descanso(Hora& h) {
	h.minutos += 10;
	if (h.minutos >= 60) {
		h.minutos -= 60;
		++h.hora;
	}
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0)
		return false;
	Pelicula p;
	Hora h;
	int minutos;
	char aux;
	std::vector<Pelicula> cartelera;

	for (int i = 0; i < N; ++i) {
		std::cin >> h.hora >> aux >> h.minutos >> minutos;
		p.inicio = h;
		p.fin = h + minutos;
		cartelera.push_back(p);
	}

	std::sort(cartelera.begin(), cartelera.end());

	int maxPeliculas = 1;
	Hora t = cartelera[0].fin;
	descanso(t);
	for (int i = 1; i < cartelera.size(); ++i) {
		if (t <= cartelera[i].inicio) {
			++maxPeliculas;
			t = cartelera[i].fin;
			descanso(t);
		}
	}

	std::cout << maxPeliculas << "\n";

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