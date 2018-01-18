/*
 * queue_eda.h
 *
 * Implementación del TAD cola con nodos enlazados
 *
 * Estructuras de Datos y Algoritmos
 * Facultad de Informática
 * Universidad Complutense de Madrid
 *
 * Copyright (c) 2017 Enrique Martín Martín. All rights reserved.
 */

#ifndef QUEUE_EDA_H_
#define QUEUE_EDA_H_


#include <stdexcept>

template <typename T>
class queue {
private:

    class Nodo {
    public:
    	T elem;
    	Nodo* sig;
    	Nodo(const T& e, Nodo* n) : elem(e), sig(n) {} // Constructor
    };

    // número de elementos en la cola
    size_t nelems;

    // punteros al primer y último elemento
    Nodo* primero;
    Nodo* ultimo;

    // Libera la memoria dinámica
    void libera();

    // copia desde otra cola
    void copia(const queue<T> &other);

    // Copia una lista de nodos
    void copia_nodos(const Nodo* node);


public:

    // constructor: cola vacía
    queue();

    // destructor
    ~queue();

    // constructor por copia
    queue(const queue<T>& other);

    // operador de asignación
    queue<T> & operator=(const queue<T>& other);

    // encolar un elemento
    void push(const T& elem);

    // consultar primer elemento
    T const& front() const;

    // eliminar primer elemento
    void pop();

    // consultar si la cola está vacía
    bool empty() const;

    // consultar el tamaño de la cola
    size_t size() const;
};



template<typename T>
void queue<T>::libera() {
	Nodo* n = primero;
	while(n != nullptr) {
		Nodo* next = n->sig;
		delete n;
		n = next;
	}
	primero = nullptr;
	ultimo = nullptr;
}


template<typename T>
void queue<T>::copia(const queue<T> &other) {
	nelems = other.nelems;
	copia_nodos(other.primero);
}


template<typename T>
void queue<T>::copia_nodos(const Nodo* node){
	if (node == nullptr) {
		primero = nullptr;
		ultimo = nullptr;
	} else {
		primero = new Nodo(node->elem, nullptr);
		ultimo = primero;
		while(node->sig != nullptr) {
			Nodo* aux = new Nodo(node->sig->elem, nullptr);
			ultimo->sig = aux;
			ultimo = aux;
			node = node->sig;
		}
	}
}


template<typename T>
queue<T>::queue() : nelems(0), primero(nullptr), ultimo(nullptr) {}


template<typename T>
queue<T>::~queue() {
	libera();
}


template<typename T>
queue<T>::queue(const queue<T>& other) : nelems{0}, primero{nullptr}, ultimo{nullptr} {
	copia(other);
}


template<typename T>
queue<T> & queue<T>::operator=(queue<T> const& other) {
	if (this != &other) { // evita auto-asignación
		libera();
		copia(other);
	}
	return *this;
}



template<typename T>
void queue<T>::push(const T& elem) { // O(1)
	if(empty()) {
		primero = new Nodo(elem,nullptr);
		ultimo = primero;
	} else {
		Nodo* node = new Nodo(elem,nullptr);
		ultimo->sig = node;
		ultimo = node;
	}
	nelems++;
}


template<typename T>
T const& queue<T>::front() const { // O(1)
	if (empty()) {
		throw std::domain_error("Cola vacía");
	} else {
		return primero->elem;
	}
}


template<typename T>
void queue<T>::pop() { // O(1)
	if (empty()) {
		throw std::domain_error("Eliminar en cola vacía");
	} else {
		nelems--;
		Nodo* old_first = primero;
		primero = primero->sig;
		delete old_first;
	}
}


template<typename T>
bool queue<T>::empty() const { // O(1)
	return size() == 0;
}

template<typename T>
size_t queue<T>::size() const { // O(1)
	return nelems;
}


#endif /* QUEUE_EDA_H_ */
