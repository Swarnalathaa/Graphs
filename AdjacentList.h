#pragma once

#include"library.h"


class Adjacent_list
{

public:


	//creates edges between the nodes
	vector<vector<int>> EdgeCreation(int, int);

	//Displays the adjacency list
	void ListDisplay( vector<vector<int>> );

	// performs Breath first seaarch (BFS)
	void BFS(int, int, vector<vector<int>>);

	//performs Depth first search (DFS)
	void DFS(int, int, vector<vector<int>>);

	//checks if the undirected graph is strongly connected
	bool isconnected_DFS(int, int, vector<vector<int>>);

	//checks if the directed graph is strongly connected
	bool isconnected_directed(int, vector<vector<int>>);



	~Adjacent_list();

	


private:

	int m_vertex;

	int m_MaxEdge;

	vector<vector<int>> m_AdjacencyList;

	bool *visited;

 
};

