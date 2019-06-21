#include <iostream>
#include <fstream>

#include "grafo.hpp"

using namespace std;

Grafo* leArquivo(string nomeArquivo) {
    ifstream arquivo;
    arquivo.open(nomeArquivo.c_str());

    int qtdElementos;
    arquivo >> qtdElementos;

    int aux;
    double **coordenadas = new double*[qtdElementos];
    for (int i = 0; i < qtdElementos; ++i) {
        coordenadas[i] = new double[2];
        arquivo >> aux
                >> coordenadas[i][0]
                >> coordenadas[i][1];
    }
    
    arquivo.close();

    cout << "\n\nvertices e coordenadas\n\n";
    for (int i = 0; i < qtdElementos; ++i) {
        cout << i << " "
             << coordenadas[i][0] << " "
             << coordenadas[i][1] << endl;
    }
    
    Grafo* grafo = new Grafo(qtdElementos, coordenadas);
    
    return grafo;
}

int main() {
    string nomeArquivo = "teste.txt";
    leArquivo(nomeArquivo);

    return 0;
}