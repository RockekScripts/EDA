// Grupo VJ13 Colin Ulrich Cop, Francisco Solano Lopez-Bleda de Castro

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <stack>




// Cada caracter que se lee, se manda a tratar a la funcion resolver, que segun el tipo de caracter, se hace una cosa u otra
//puede meterse directamente a la pila si es el numero, y si es un signo, se sacan los 2 primeros numeros de la pila y se resta
//o se suma, depende del signo que le haya venido.
// La funcion tiene coste lineal, O (n). Siendo n el numero de caracteres que tiene que leer el programa
 
void resolver(std::stack<int> & pila, char caracter) {

	if (caracter != '+' && caracter != '-'){
		caracter -= 48;
		pila.push(caracter);

	}

	else if (caracter == '-') {
		int aux1 = pila.top();
		pila.pop();
		int aux2 = pila.top();
		pila.pop();
		pila.push(aux2 - aux1);
	}
	else if (caracter == '+') {
		int aux1 = pila.top();
		pila.pop();
		int aux2 = pila.top();
		pila.pop();
		pila.push(aux1 + aux2);
	}

}




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;
	char var;
	std::stack<int> pila;
	for (int i = 0; i < num; i++)
	{
		std::cin >> var;		//cada caracter que se lee se manda a tratar a resolver
		resolver(pila, var);
	}

	std::cout << pila.top() << "\n";
	// escribir sol


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Source1.txt");
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