#ifndef BUSCATABU_HPP
#define BUSCATABU_HPP

#include <vector>

class BuscaTabu {
    private:
        /* Matriz com (qtdVertices / 4) linhas e 5 colunas,
        a coluna 0 sendo a quantidade de iteraçãos que aquele
        movimento ainda permanecerá na lista, que começa em 10
        para todos os movimentos, a coluna 1 é o vértice 1,
        a coluna 2 é o vértice 2, a coluna 3 é a posição do vértice 1,
        e a coluna 4 é a posição do vértice 2.
        Apenas o movimento de troca de vértices utiliza a Lista Tabu. */
        int **listaTabu;
        int inicioLista;
        int fimLista;
        int duracaoNaLista;

        std::vector<int> solucao;
        std::vector<double> arestas;
        double **matrizAdjacencia;

        int calculaNovoFimLista();
        void inserirNaListaTabu(int vertice, int vertice2, int pos1, int pos2);
        void removerDaListaTabu();
        void atualizarListaTabu();
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
        void realizarBuscaTabu(std::vector<int> &solucao, std::vector<double> &arestas);
};

#endif