#include <iostream>
#include "solucao.hpp"

Solucao::Solucao(Grafo *grafo) {
    qtdElementos = grafo->getQtdElementos();
    for (int i = 0; i < qtdElementos; ++i) {
        elementosForaDaRota.push_back(i);
    }
    matrizAdjacencia = grafo->getMatrizAdjacencia();
    somatorioTotal = 0;
    solucaoInicial(grafo);
}

Solucao::~Solucao() {
    elementosForaDaRota.clear();
    solucao.clear();
    arestas.clear();
}

void Solucao::solucaoInicial(Grafo *grafo) {
    srand(time(NULL));

    int pos = rand() % qtdElementos;

    solucao.push_back(elementosForaDaRota[pos]);
    elementosForaDaRota.erase(elementosForaDaRota.begin() + pos);

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

    std::cout << "\n\n----- Solucao inicial: -----\n";
    imprimeSolucao(somatorioTotal);
}

void Solucao::buscaTabu() {
    BuscaTabu *buscaTabu = new BuscaTabu(solucao, arestas, matrizAdjacencia);

    std::vector<int> solucaoMelhor = solucao;
    std::vector<double> arestasMelhor = arestas;
    double melhorSomatorio = somatorioTotal;

    int i = 0;
    bool melhorou = true;
    while ((i < 5) and melhorou) {
        double somatorioAux = somatorioTotal; 
        buscaTabu->realizaBuscaTabu(solucao, arestas);

        realizaSomatorio(somatorioTotal);

        if (somatorioTotal < melhorSomatorio) {
            solucaoMelhor = solucao;
            arestasMelhor = arestas;
            melhorSomatorio = somatorioTotal;
        }
        if (somatorioTotal == somatorioAux) {
            melhorou = false;
        }

        ++i;
    }

    solucao = solucaoMelhor;
    arestas = arestasMelhor;
    somatorioTotal = melhorSomatorio;

    solucaoMelhor.clear();
    arestasMelhor.clear();
    delete buscaTabu;

    std::cout << "\n\n----- Melhor solucao encontrada -----\n";
    imprimeSolucao(somatorioTotal);
}

void Solucao::realizaSomatorio(double &somatorioTotal) {
    somatorioTotal = 0;
    for (unsigned int i = 0; i < arestas.size(); ++i) {
        somatorioTotal += arestas[i];
    }
}

void Solucao::imprimeSolucao(double &somatorioTotal) {
    std::cout << "\n\nRota: ";
    for (unsigned int i = 0; i < solucao.size(); ++i) {
        std::cout << solucao[i] << " ";
    }
    somatorioTotal = 0;
    std::cout << "\n\nArestas: ";
    for (unsigned int i = 0; i < arestas.size(); ++i) {
        std::cout << arestas[i] << " ";
        somatorioTotal += arestas[i];
    }
    std::cout << "\n\nSomatorio total: " << somatorioTotal << "\n\n";
}