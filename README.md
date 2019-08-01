### Busca Tabu para resolver o TSP

O Problema do Caixeiro Viajante (Traveling Salesman Problem - TSP) consiste em, dado um conjunto de *n* cidades com distâncias entre cada par de cidades, sair de um ponto inicial, encontrar o menor caminho para percorrer todas as cidades passando por cada uma apenas uma vez, e retornar para o ponto inicial ao final. A meta-heurística Busca Tabu foi utilizada para resolução do TSP. A versão utilizada na implementação do trabalho foi a básica, onde, além da Busca Local, há a adição da Lista Tabu, utilizada para impedir que a solução desfaça um movimento recentemente feito, impedindo que a busca caia em um ciclo. O espaço de busca contém apenas soluções factíveis, para a estrutura da vizinhança foi utilizada uma busca local contendo dois movimentos possíveis, o 2-opt move e a troca de vértices.

O TSP considerado para implementação é o TPS simétrico.

O programa executa 5 instâncias utilizadas para teste, que se encontram na pasta *instancias*. As instâncias estão disponíveis em [TSPLIB](http://elib.zib.de/pub/mp-testdata/tsp/tsplib/tsplib.html), mas as utilizadas na execução têm algumas modicações.

O formato de instância aceita é:

		<quantidadeDeVertices>
		<vertice0> <coordenadaX0> <coordenadaY0>
		<vertice1> <coordenadaX1> <coordenadaY1>
		...
e vai até o vértice *quantidadeDeVertices - 1*.

Após o comando *make* no terminal, basta rodar o executável com *./main*.

Os resultados são impressos no terminal ao final da execução, e são eles:

- Nome do arquivo e quantidade de vértices
- Solução inicial:
	* rota
	* arestas
	* somatório total da rota
- Solução após Busca Tabu:
	* rota
	* arestas
	* somatório total da rota

Copyright (c) 2019 Lorena Kerollen Botelho Tavares