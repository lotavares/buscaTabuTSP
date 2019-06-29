#ifndef SOLUCAO_HPP
#define SOLUCAO_HPP

#include <vector>
#include "grafo.hpp"
#include "buscaTabu.hpp"

class Solucao {
    private:
        int qtdElementos;
        double **matrizAdjacencia;
        std::vector<int> elementosForaDaRota;
        std::vector<int> solucao;
        std::vector<double> arestas;
        double somatorioTotal;
        
        void solucaoInicial(Grafo *grafo);
    public:
        Solucao(Grafo *grafo);
        ~Solucao();
        void buscaTabu();
        void realizaSomatorio(double &somatorioTotal);
        void imprimeSolucao(double &somatorioTotal);
};

#endif