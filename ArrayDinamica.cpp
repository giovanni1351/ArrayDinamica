#include<iostream>

using namespace std;


template<class T>
class Lista {
private:
	T* list;
	int ultimo = 0;
	int sizeAlocado = 10;
	void duplicaTamanho() {
		sizeAlocado *= 2;
		T* temp = new T[sizeAlocado];
		copy(list, list + ultimo, temp);
		delete[] list;
		list = temp;

	}
public:


	Lista() {

		list = new T[sizeAlocado];
	}
	Lista(int tamanho) {
		list = new T[tamanho];
		sizeAlocado = tamanho;
	}
	Lista(int tamanho,T valor) {
		list = new T[tamanho];
		sizeAlocado = tamanho;
		for (int x = 0; x < tamanho; x++) {
			list[x] = valor;
			ultimo++;
		}
	}
	void colocar_atras(T valor) {
		if (ultimo + 1 > sizeAlocado) {
			duplicaTamanho();
		}
		list[ultimo] = valor;
		ultimo += 1;
	}

	void tira_atras() {
		if (ultimo) {
			ultimo -= 1;
		}
	}
	T& ver_trazeira() {
		return list[ultimo-1];
	}
	T& operator[](int pos) {
		return list[pos];
	}
	int tamanho_da_lista() {
		return ultimo;
	}


};

int main() {
	Lista<int> toma;
	for (int x = 0; x < 30; x++) {
		toma.colocar_atras(x);

	}
	cout << toma.tamanho_da_lista() << endl;
	cout << toma.ver_trazeira()<< endl;
	toma.tira_atras();
	cout << toma.ver_trazeira()<< endl;
	
	Lista<string> givasList(5, "Givas");
	for (int x = 0; x < givasList.tamanho_da_lista(); x++) {
		cout << givasList[x] << endl;
	}
	

	return 0;
}
