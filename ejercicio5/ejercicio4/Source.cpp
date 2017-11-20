/*
* stack_eda_array.h
*
* Implementación del TAD pila con arrays estáticos
*
* Estructuras de Datos y Algoritmos
* Facultad de Informática
* Universidad Complutense de Madrid
*
* Copyright (c) 2017 Enrique Martín Martín. All rights reserved.
*/

#ifndef STACK_EDA_ARRAY_H_
#define STACK_EDA_ARRAY_H_


#include <stdexcept>

template <typename T>
class stack {
private:
	static const int TAM = 6; // tamaño

							  // número de elementos en la pila
	size_t nelems;

	// array estático de TAM elementos de tipo T
	T elems[TAM];

public:

	// constructor: pila vacía
	stack();

	// destructor (por defecto)
	~stack() = default;

	// constructor por copia (por defecto)
	stack(stack<T> const& other) = default;

	// operador de asignación (por defecto)
	stack<T> & operator=(stack<T> const& other) = default;

	// apilar un elemento
	void push(T const& elem);

	// consultar la cima
	T const& top() const;

	// desapilar el elemento en la cima
	void pop();

	// consultar si la pila está vacía
	bool empty() const;

	// consultar el tamaño de la pila
	size_t size() const;
};


template<typename T>
stack<T>::stack() : nelems(0) {}

template<typename T>
void stack<T>::push(T const& elem) { // O(1)
	if (nelems == TAM) {
		throw std::domain_error("Imposible apilar en pila llena");
	}
	else {
		elems[nelems] = elem;
		nelems++;
	}
}

template<typename T>
T const& stack<T>::top() const { // O(1)
	if (nelems == 0) {
		throw std::domain_error("Cima de pila vacía");
	}
	else {
		return elems[nelems - 1];
	}
}

template<typename T>
void stack<T>::pop() { // O(1)
	if (nelems == 0) {
		throw std::domain_error("Desapilar en pila vacía");
	}
	else {
		nelems--;
	}
}

template<typename T>
bool stack<T>::empty() const {  // O(1)
	return size() == 0;
}

template<typename T>
size_t stack<T>::size() const { // O(1)
	return nelems;
}


#endif /* STACK_EDA_ARRAY_H_ */

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




// función que resuelve el problema
// Se va sacando cada elemento de la pila con su respectivo signo, se mete en otra auxiliar y se hacen los calculos.
// 
template<typename T>
int resolver(stack<T> pila) {
	stack<int> pilaAux;
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
	stack<char> pila;
	for (int i = 0; i < num; i++)
	{
		std::cin >> var;
		pila.push(var);
	}
	std::cout << resolver(pila) << "\n";
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