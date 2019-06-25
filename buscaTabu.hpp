#ifndef BUSCATABU_HPP
#define BUSCATABU_HPP

#include <vector>

class BuscaTabu {
    private:
        int **listaTabu;
        std::vector<int> solucao;
        std::vector<double> arestas;
        double **matrizAdjacencia;

        void optMove();
        void optMoveSwap(int inicio, int fim);
        void insercaoVertice();
        void swapVertice();
        void swapVerticeAux(int pos1, int pos2);
        void swapVerticeAux1(int pos1, int pos2);
        void swapVerticeAux2(int pos1, int pos2);
    public:
        BuscaTabu(std::vector<int> &solucao, std::vector<double> &arestas, double **matrizAdjacencia);
        ~BuscaTabu();
        void realizaBuscaTabu(std::vector<int> &solucao, std::vector<double> &arestas);
};

#endif