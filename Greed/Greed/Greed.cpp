/*
Prvn� ��st
Hladov� algoritmus - V ka�d�m sv�m kroku vyb�r� lok�ln� minimum, p�i�em� existuje �ance, 
�e takto nalezne minimum glob�ln�. Hladov� algoritmus se uplatn� v p��pad�, kdy je t�eba z 
mno�iny ur�it�ch objekt� vybrat takovou podmno�inu, kter� spl�uje jistou p�edem danou 
vlastnost a nav�c m� minim�ln� (p��padn� maxim�ln�) ohodnocen�.
Hladov� algoritmus narozd�l od dynamick�ho programovan� vyb�r� �e�en� na z�klad� 


Kruskal�v algortimus - pou��v� se k nalezen� minim�ln� kostry grafu, jeho� strany, jeho� 
hrany maj� nez�porn� ohodnocen� (d�lku).
Ekvivalentn� m��eme algoritmus popsat tak, �e se v�dy vyb�r� takov� hrana, kter� m� ze v�ech mo�n�ch 
hran spojuj�c�ch dvar�zn� podstromy ve vytv��en� kost�e tu nejmen�� v�hu.
vytvo� les (mno�inu strom�), ve kter�m je ka�d� uzel grafu samostatn�m podstromem
vytvo� mno�inu S obsahuj�c� v�echny hrany grafu, dokud je mno�ina S nepr�zdn�
z mno�iny S odeber hranu s minim�ln� v�hou pokud tato hrana spojuje dva r�zn� podstromy, 
p�idej ji do lesa F, tak �e tyto podstromy slu� do jednoho
v jin�m p��pad� hranu zaho�.
Po skon�en� b�hu algoritmu obsahuje les jedinou komponentu, tvo��c� minim�ln� kostru grafu.
*/

#include <stdio.h>
#include <iostream>
#define V 9 
using namespace std;


// Zde vybir�m sou�asn� zn�m� minimum nutn� pro chod hladov�ho alg.
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


//Dijkstr�v algoritmus
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









