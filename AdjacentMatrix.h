#pragma once

#include"library.h"

class Adjacent_matrix
{
public:
	//creates a square matrix of order equa;s to vertex and makes all the entiries in the matrix 0
	double** MatrixCreation (int);

	//creates the edge between the node with weights
	void EdgeCreation(double**, int, int);

	//Displays the adjacency matrix
	void MatrixDisplay(double**, int);

	//calculates the out-degree of the node
	void out_degree(double**, int);

	//calculates the in-degree of the node
	void in_degree(double**, int);

	//destructor function
	~Adjacent_matrix();


private:
	int m_vertex;
	int m_Node1;
	int m_Node2;
	int m_a;
	int m_MaxEdge;
	double** m_matrix;
};

