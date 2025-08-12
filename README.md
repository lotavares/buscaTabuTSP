### Tabu Search to Solve the TSP

The Traveling Salesman Problem (TSP) consists of, given a set of *n* cities with distances between each pair of cities, starting from an initial point, finding the shortest path to visit all cities passing through each city only once, and returning to the initial point at the end. The metaheuristic Tabu Search was used to solve the TSP. The version used in this implementation is the basic one, where, in addition to Local Search, there is the addition of the Tabu List, used to prevent undoing a recently made move, thus avoiding the search falling into a cycle. The search space contains only feasible solutions. For the neighborhood structure, a local search was used with two possible moves: the 2-opt move and vertex swap.

The TSP considered for the implementation is the symmetric TSP.

The program runs 5 instances used for testing, which are located in the *instancias* folder. The instances are available at [TSPLIB](http://elib.zib.de/pub/mp-testdata/tsp/tsplib/tsplib.html), but the ones used in the execution have some modifications.

The accepted instance format is:

		<numberOfVertices>
		<vertex0> <coordinateX0> <coordinateY0>
		<vertex1> <coordinateX1> <coordinateY1>
		...
and goes up to vertex `<numberOfVertices - 1>`.

After running the *make* command in the terminal, just run the executable with *./main*.

The results are printed in the terminal at the end of execution, and they are:

- File name and number of vertices
- Initial solution:
	* route
	* edges
	* total sum of the route
- Solution after Tabu Search:
	* route
	* edges
	* total sum of the route

Copyright (c) 2019 Lorena Kerollen Botelho Tavares
