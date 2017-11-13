// grupo 17, Colin Cop y Fran Lopez-Bleda
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <array>

#define INT_MIN -2147483647



bool esValida(std::vector<int>& sol, int k) {
	bool vale = true;

	return vale;
}
// función que resuelve el problema
// ya que tiene que comprobar todas las posibilidades el coste cuadratico O(N*N)
void resolver(std::vector<int>& monedero, int const & cantidad, int& NMonedas,int & acumulado,int& totalMonedas) {
	for (int i = monedero.size()-1; i >= 0; i--)
	{
		if (monedero[i] != 0) {
			monedero[i]--;
			switch (i)
			{
			case 0:	acumulado++; break;
			case 1:	acumulado += 2;	break;
			case 2:	acumulado += 5; break;
			case 3:	acumulado += 10; break;
			case 4: acumulado += 20; break;
			case 5: acumulado += 50; break;
			case 6: acumulado += 100; break;
			case 7: acumulado += 200; break;
			default:break;
			}
			NMonedas++;
			if (acumulado == cantidad) {
				if(NMonedas>totalMonedas){
					totalMonedas = NMonedas;
				}
			}
			else if (acumulado < cantidad) {
				resolver(monedero, cantidad, NMonedas, acumulado, totalMonedas);
			}

			monedero[i]++;
			switch (i)
			{
			case 0:	acumulado--; break;
			case 1:	acumulado -= 2;	break;
			case 2:	acumulado -= 5; break;
			case 3:	acumulado -= 10; break;
			case 4: acumulado -= 20; break;
			case 5: acumulado -= 50; break;
			case 6: acumulado -= 100; break;
			case 7: acumulado -= 200; break;
			default:break;
			}
			NMonedas--;
		}
		
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int Cantidad;
	std::cin >> Cantidad;

	std::vector<int> solucion(8);
	int aux = 0;
	for (size_t i = 0; i < 8; i++)
	{
		std::cin>>aux;
		solucion.at(i)= aux;
		
	}

	int NMonedas = 0;
	int acu = 0;
	int totalMonedas = INT_MIN;
	resolver(solucion,Cantidad,NMonedas,acu,totalMonedas);

	((totalMonedas != INT_MIN) ? std::cout << totalMonedas : std::cout << "IMPOSIBLE") ;
	std::cout << '\n';
	// escribir sol


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Monedero.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}