

// Grupo VJ13 Colin Ulrich Cop, Francisco Solano Lopez-Bleda de Castro
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <stack>




// función que resuelve el problema
// Se va sacando cada elemento de la pila con su respectivo signo, se mete en otra auxiliar y se hacen los calculos.
// 
template<typename T>
int resolver(std::stack<T> pila) {
	std::stack<int> pilaAux;
	char aux;
	int	 num;
	while (!pila.empty()) {
		aux = pila.top();
		pila.pop();

		if (aux == '-') {
			num = pila.top()-48;
			pila.pop();
			num -= 2 * num;
		}
		else if (aux == '+') {
			 num = pila.top()-48;
			pila.pop();
		}
		else num = aux-48;
		pilaAux.push(num);
	}

		while (pilaAux.size() > 1) {
			num = pilaAux.top();
			pilaAux.pop();
			num += pilaAux.top();
			pilaAux.pop();
			pilaAux.push(num);
		}

	return pilaAux.top();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;
	char var;
	std::stack<char> pila;
	for (int i = 0; i < num; i++)
	{
		std::cin >> var;
		pila.push(var);
	}
	if (!pila.empty())
		std::cout << resolver(pila);
	std::cout <<  "\n";
	// escribir sol


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}