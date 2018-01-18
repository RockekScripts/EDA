// Grupo Videojuegos, Fran López-Bleda y Colin Cop
// VJ13
// el coste de la solución es O(N), siendo N el numero de entradas y salidas
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include "queue_eda.h"
using namespace std;
#define MAX_PRIOR = 15;
template <typename T>
class ColaVip
{
public:
	ColaVip(int p = 2) {
		nivelesPrioridad = p;
		prioridadActual = nivelesPrioridad-1;
		colas = vector<queue<T>>(p);
		numElems = 0;
	}
	~ColaVip() {};
	// front() devuelve elemento con más prioridad de la colaVip
	// El coste de front es O(1)
	T const&front()const {
		return colas.at(prioridadActual).front();
	}
	// push(int p, T elem) mete un elemento (elem) en la cola de prioridad p
	// El coste de push es O(1)
	void push(int p, const T& elem) {
		colas.at(p).push(elem);
		prioridadActual = (p < prioridadActual) ? p : prioridadActual;
		numElems++;
	}
	
	// pop() saca el primer elemento de la cola
	// por lo general el coste de pop es O(1), pero en el peor caso, se extrae el ultimo elemento y
	// este está en en la priridad 0, el coste sería O(P), siendo P el numero de colas
	void pop() {
		if (!empty()) {
			colas.at(prioridadActual).pop();
			numElems--;
			while (prioridadActual != nivelesPrioridad&&colas.at(prioridadActual).empty())
			{
				prioridadActual++;
			}
		}
	}

	// empty() devuelve si la cola está vacia
	// el coste de empty es O(1)
	bool empty() const {
		return numElems==0;
	}

	// size() devuelve el numero de elementos en la cola
	// el coste de empty es O(1)
	size_t size() const {
		return numElems;
	}

private:
	vector<queue<T>> colas;
	size_t prioridadActual;
	size_t nivelesPrioridad;
	size_t numElems;

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	size_t prioridades, nMovs, aforoMax, aforoActual = 0;
	cin >> prioridades >> nMovs >> aforoMax;
	ColaVip<size_t> pacha(prioridades);
	char sim;
	size_t p, elem;
	for (size_t i = 0; i < nMovs; i++)
	{
		cin >> sim;
		if (sim == '+') {
			cin >> p >> elem;
			if (aforoActual == aforoMax) {
				pacha.push(p, elem);
			}
			else {
				aforoActual++;
			}
		}
		else if (sim == '-') 
		{
			if (!pacha.empty()) {
				pacha.pop();
			}
			else {
				if (aforoActual > 0)
					aforoActual--;
			}
		}
	}
	if (pacha.empty()) {
		cout << "NADIE";
	}
	while (!pacha.empty())
	{
		cout << pacha.front()<<" ";
		pacha.pop();
	}

	cout << '\n';
	
	
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	//*
#ifndef DOMJUDGE
	std::ifstream in("vip.txt");
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