// Grupo Videojuegos, Fran López-Bleda y Colin Cop
// VJ13
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include "map.h"
#define NULL 0
using namespace std;




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	size_t nMovs;
	cin >> nMovs;
	Map<size_t, double> Mapa;
	size_t key;
	double value;
	for (size_t i = 0; i < nMovs; i++)
	{
		cin >> key >> value;
		Mapa.insert(key, value);
	}
	cin >> nMovs;
	for (size_t i = 0; i < nMovs; i++)
	{
		cin >> key;
		cout << key << " " << setprecision(2) << fixed << Mapa.get(key) << '\n';;
	}
	cout << '\n';

		
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	//*
#ifndef DOMJUDGE
	std::ifstream in("Tarjetas.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	size_t nCasos;						  //	*/
	cin >> nCasos;

	for (size_t i = 0; i < nCasos; i++)
	{
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto
	//*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif
	//*/

	return 0;
}