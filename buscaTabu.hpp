#ifndef BUSCATABU_HPP
#define BUSCATABU_HPP

#include <vector>

class BuscaTabu {
    private:
        int **listaTabu;
        int inicioLista;
        int fimLista;
        int duracaoNaLista;

        std::vector<int> solucao;
        std::vector<double> arestas;
        double **matrizAdjacencia;

        int calculaNovoFimLista();
        void insereListaTabu(int vertice, int vertice2, int pos1, int pos2);
        void removeListaTabu();
        void atualizaListaTabu();
        bool estaEmListaTabu(int vertice1, int vertice2, int pos1, int pos2);

        void optMove();
        void optMoveSwap(int inicio, int fim);
        void insercaoVertice();
        void swapVertice();
        void swapVertices(int pos1, int pos2);
        void swapVerticeAux(int pos1, int pos2);
        void swapVerticeAux1(int pos1, int pos2);
        void swapVerticeAux2(int pos1, int pos2);
    public:
        BuscaTabu(std::vector<int> &solucao, std::vector<double> &arestas, double **matrizAdjacencia);
        ~BuscaTabu();
        void realizaBuscaTabu(std::vector<int> &solucao, std::vector<double> &arestas);
};

#endif