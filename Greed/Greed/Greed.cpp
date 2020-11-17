/*
První èást
Hladový algoritmus - V každém svém kroku vybírá lokální minimum, pøièemž existuje šance, 
že takto nalezne minimum globální. Hladový algoritmus se uplatní v pøípadì, kdy je tøeba z 
množiny urèitých objektù vybrat takovou podmnožinu, která splòuje jistou pøedem danou 
vlastnost a navíc má minimální (pøípadnì maximální) ohodnocení.
Hladový algoritmus narozdíl od dynamického programovaní vybírá øešení na základì 


Kruskalùv algortimus - používá se k nalezení minimální kostry grafu, jehož strany, jehož 
hrany mají nezáporné ohodnocení (délku).
Ekvivalentnì mùžeme algoritmus popsat tak, že se vždy vybírá taková hrana, která má ze všech možných 
hran spojujících dvarùzné podstromy ve vytváøené kostøe tu nejmenší váhu.
vytvoø les (množinu stromù), ve kterém je každý uzel grafu samostatným podstromem
vytvoø množinu S obsahující všechny hrany grafu, dokud je množina S neprázdná
z množiny S odeber hranu s minimální váhou pokud tato hrana spojuje dva rùzné podstromy, 
pøidej ji do lesa F, tak že tyto podstromy sluè do jednoho
v jiném pøípadì hranu zahoï.
Po skonèení bìhu algoritmu obsahuje les jedinou komponentu, tvoøící minimální kostru grafu.
*/

#include <stdio.h>
#include <iostream>
#define V 9 
using namespace std;


// Zde vybirám souèasnì známé minimum nutné pro chod hladového alg.
int minDistance(int dist[], bool sptSet[])
{
	
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void printSolution(int dist[], int n)
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d tt %d\n", i, dist[i]);
}


//Dijkstrùv algoritmus
void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	

	bool sptSet[V];
	

	
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	
	dist[src] = 0;

	
	for (int count = 0; count < V - 1; count++) {
		
		int u = minDistance(dist, sptSet);

		
		sptSet[u] = true;

		
		for (int v = 0; v < V; v++)

			
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	
	printSolution(dist, V);
}


int main()
{
	
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstra(graph, 0);

	return 0;
}









