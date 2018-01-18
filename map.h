#pragma once
#include "bst.h"
template <typename KEY, typename VALUE, typename Compare = less<KEY>>
class Map
{
public:
	Map(){
	}
	~Map() {

	}
	//Con get() devuelve el valor de la clave solicitada, encaso de no existir devolvera un valor nulo
	//El coste es O(N*log(N)) siendo N el nuemero de nodos
	VALUE get(const KEY& key) const {
		Caja_struct aux = { key,NULL };
		pair<bool, Caja_struct> _Nodo = BST.search(aux);
		return (_Nodo.first)?_Nodo.second.value:NULL;
	}
	//Con contains() devuelve si existe la clave solicitada
	//El coste es O(N*log(N)) siendo N el nuemero de nodos
	bool contains(const KEY& key) const {
		Caja_struct aux = { key,NULL };
		pair<bool, Caja_struct> _Nodo = BST.search(aux);
		return _Nodo.first;
	}
	//insert() sirve para meter o modificar un valor 
	//El coste es O(2*N*log(N)) siendo N el nuemero de nodos, 
	//y cuando el valor ya existe sería O(3*N*log(N)), ya que tiene que borrar el anterior valor
	void insert(const KEY& key, const VALUE & value) {
		Caja_struct aux = { key,value };
		pair<bool, Caja_struct> _Nodo = BST.search(aux);
		if (_Nodo.first) {
			aux.value += _Nodo.second.value;
			BST.remove(aux);
		}
		BST.insert(aux);
	}

	//erase() es para eliminar el valor a dicha clave asociada
	//El coste es O(2*N*log(N)) siendo N el numero de nodos
	void erase(const KEY& key){
		Caja_struct aux = { key,NULL };
		BST.remove(aux);

	}
private:
	struct Caja_struct
	{
		KEY key;
		VALUE value;
		bool operator<(Caja_struct const & T)const {
			return key < T.key;
		}
	
	};
	bst<Caja_struct> BST;
};
