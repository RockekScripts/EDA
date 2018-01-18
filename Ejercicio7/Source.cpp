//VJ13, Colin Ulrich Cop y Francisco Solano Lopez Bleda de Castro.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include "bintree_eda.h"

/* Para resolver problema hemos implementado diferentes metodos para recorrer el arbol.
Preorden:
Se empieza por la raíz y se mueve siempre a la izquierda primero, y cuando llega a una hoja, va hacia la derecha
salida.push_back(raiz->elem);
preorden_rec(raiz->izq, salida);
preorden_rec(raiz->der, salida);


Inorden:
En cuanto el hijo izquierdo llegue a una hoja, se añade su elemento al vector y luego se explora el hijo derecho
inorden_rec(raiz->izq, salida);
salida.push_back(raiz->elem);
inorden_rec(raiz->der, salida);


Postorden:
Se explora por los hijos izquierdos, estos recorren sus hijos derecho y luego se va añadiendo al vector.
postorden_rec(raiz->izq, salida);
postorden_rec(raiz->der, salida);
salida.push_back(raiz->elem);

Niveles:
se va recorriendo de arriba a abajo y de izquierda a derecha
while (!cola.empty()) {
Link actual = cola.front();
cola.pop();
aux.push_back(actual->elem);
if (actual->izq != nullptr)
cola.push(actual->izq);
if (actual->der != nullptr)
cola.push(actual->der);
}
*/
// Cada metodo ( preorden, inorden, postorden...) tiene coste O(N) siendo N el numero de elementos del arbol
template <class T>
bintree<T>leerArbol(T const& vacio) {
	T raiz;	cin >> raiz;
	if (raiz == vacio)	return bintree<T>();
	bintree<T>a1 = leerArbol(vacio);
	bintree<T>a2 = leerArbol(vacio);
	return bintree<T>(a1, raiz, a2);
}
std::vector<int> resolver(bintree<int> const & arbol, int sw){
	switch (sw)
	{
	case 0: return arbol.preorden(); break;
	case 1: return arbol.inorden(); break;
	case 2: return arbol.postorden(); break;
	case 3: return arbol.niveles(); break;

	default:
		break;
	}
	
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	bintree<int> arbol = leerArbol(0);
	
	std::vector<int> aux;
	
	for (size_t i = 0; i < 4; i++)
	{
		aux = resolver(arbol, i);
		for (size_t i = 0; i < aux.size(); i++)
		{
			std::cout << aux[i] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "==\n";
	// escribir sol


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
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