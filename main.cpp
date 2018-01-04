#include"AdjacentMatrix.h"
#include"AdjacentList.h"


int main()
{

	int vertex;

	cout << "Enter the number of vertices in the graph : ";
	cin >> vertex;
    
	int MaxEdge = vertex*(vertex - 1);

	// To create and display adjacency matrix and calculate in and out degree of each node
	
	Adjacent_matrix G;

	double** A = G.MatrixCreation(vertex);
	G.EdgeCreation(A, vertex, MaxEdge);
	G.MatrixDisplay(A,vertex);
	G.out_degree(A, vertex);
	G.in_degree(A, vertex);
	
	// create adjacency list and does BFS or DFS to chech whether the graph is strongly connected(only for undirected graph)
	int v1;
	int v2;
	Adjacent_list g;

	vector<vector<int>> B = g.EdgeCreation(vertex,MaxEdge);
	g.ListDisplay(B);

	cout << "Enter the vertex from where to start BFS traversal:";
	cin >> v1;
	cout << endl;
	g.BFS(v1, vertex, B);

	cout << "Enter the vertex from where to start DFS traversal:";
	cin >> v2;
	cout << endl;
	g.DFS(v2, vertex, B);
	
	//For undirected graph
	g.isconnected_DFS(v2, vertex, B) ? cout << "The graph is strongly connected" : cout << "The graph is not strongly connected";
	

	//For directed graph
	g.isconnected_directed(vertex, B) ? cout << "The graph is strongly connected" : cout << "The graph is not strongly connected";

	cout << endl;


	system("pause");
	return 0;
}


