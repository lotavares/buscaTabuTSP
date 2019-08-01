#include <iostream>
#include <fstream>
#include "solucao.hpp"

using namespace std;

Grafo *lerArquivo(string nomeArquivo) {
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
    
    Grafo *grafo = new Grafo(qtdElementos, coordenadas);
    
    return grafo;
}

int main() {
    string pastaInstancias = "instancias/", nomeArquivo = "bier127.txt";
    cout << "\n\nNome do arquivo: " << nomeArquivo << "  "
         << "\nQuantidade de vertices: " << 127 << "\n";
    Grafo *grafo = lerArquivo(pastaInstancias + nomeArquivo);
    Solucao *solucao = new Solucao(grafo);
    solucao->buscaTabu();

    nomeArquivo = "a280.txt";
    cout << "\n\nNome do arquivo: " << nomeArquivo << "  "
         << "\nQuantidade de vertices: " << 280 << "\n";
    grafo = lerArquivo(pastaInstancias + nomeArquivo);
    solucao = new Solucao(grafo);
    solucao->buscaTabu();

    nomeArquivo = "lin318.txt";
    cout << "\n\nNome do arquivo: " << nomeArquivo << "  "
         << "\nQuantidade de vertices: " << 318 << "\n";
    grafo = lerArquivo(pastaInstancias + nomeArquivo);
    solucao = new Solucao(grafo);
    solucao->buscaTabu();

    nomeArquivo = "att532.txt";
    cout << "\n\nNome do arquivo: " << nomeArquivo << "  "
         << "\nQuantidade de vertices: " << 532 << "\n";
    grafo = lerArquivo(pastaInstancias + nomeArquivo);
    solucao = new Solucao(grafo);
    solucao->buscaTabu();

    nomeArquivo = "dsj1000.txt";
    cout << "\n\nNome do arquivo: " << nomeArquivo << "  "
         << "\nQuantidade de vertices: " << 1000 << "\n";
    grafo = lerArquivo(pastaInstancias + nomeArquivo);
    solucao = new Solucao(grafo);
    solucao->buscaTabu();

    delete grafo;
    delete solucao;
    return 0;
}