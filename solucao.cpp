#include <iostream>
#include "solucao.hpp"

Solucao::Solucao(Grafo *grafo) {
    qtdElementos = grafo->getQtdElementos();
    for (int i = 0; i < qtdElementos; ++i) {
        elementosForaDaRota.push_back(i);
    }
    matrizAdjacencia = grafo->getMatrizAdjacencia();
    somatorioTotal = 0;
    this->solucao = solucaoInicial(grafo);
}

Solucao::~Solucao() {

}

std::vector<int> Solucao::solucaoInicial(Grafo *grafo) {
    srand(time(NULL));

    int pos = rand() % qtdElementos;

    solucao.push_back(elementosForaDaRota[pos]);
    elementosForaDaRota.erase(elementosForaDaRota.begin() + pos);

    std::cout << "\n\nqtdElementos: " << qtdElementos;

    int posDisponiveis = qtdElementos - 1, posAresta = 0;
    while (posDisponiveis > 0) {
        int pos = rand() % posDisponiveis;

        solucao.push_back(elementosForaDaRota[pos]);
        elementosForaDaRota.erase(elementosForaDaRota.begin() + pos);

        --posDisponiveis;

        arestas.push_back(matrizAdjacencia[solucao[posAresta]][solucao[posAresta + 1]]);
        somatorioTotal += arestas[posAresta];
        ++posAresta;
    }
    arestas.push_back(matrizAdjacencia[solucao[posAresta]][solucao[0]]);
    somatorioTotal += arestas[posAresta];

    std::cout << "\n\narestas: ";
    for (unsigned int i = 0; i < arestas.size(); ++i) {
        std::cout << arestas[i] << " ";
    }

    std::cout << "\n\nsomatorio total: " << somatorioTotal << "\n\n";

    return solucao;
}