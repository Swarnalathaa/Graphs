#include"AdjacentMatrix.h"

double** Adjacent_matrix :: MatrixCreation(int vertex)
{
	m_vertex = vertex;
	double** m_matrix = new double*[m_vertex];

	for (int i = 0; i < m_vertex; i++)
	{
		m_matrix[i] = new double[m_vertex];
		for (int j = 0; j < m_vertex; j++)
		{
			m_matrix[i][j] = 0;
		}
	}
	return m_matrix;
}

void Adjacent_matrix::EdgeCreation(double** matrix, int vertex, int MaxEdge)
{
	m_vertex = vertex;
	m_matrix = matrix;
	m_MaxEdge = MaxEdge;
	int loop = 0;
	
	do
	{
		if (loop < m_MaxEdge)
		{
			cout << "Enter the edge v1 --> v2 :";
			cin >> m_Node1 >> m_Node2;
			if (m_Node1 == exit && m_Node2 == exit) //problem to be fixed
			{
				break;
			}

			if (m_Node1 > m_vertex || m_Node2 > m_vertex || m_Node1 <= 0 || m_Node2 <= 0)
			{
				cout << "Entered edge cannot be created" << endl;
			}
			else
			{
				if (m_Node1 == m_Node2)
				{
					cout << "Vertex cannot be adjacent to itself" << endl;
				}
				else
				{
					cout << "enter the weight of the edge:";
					loop++ ; 
					if (m_matrix[m_Node1 - 1][m_Node2 - 1] != 0)
					{
						//cin >> m_matrix[m_Node1 - 1][m_Node2 - 1];
						cout << "Edge has already been created" << endl;
						loop--;
					}

					else
					{
						cin >> m_matrix[m_Node1 - 1][m_Node2 - 1];
					}
					

				}
			}

			cout << " To add an edge type 1 else type 0 :";
			cin >> m_a;

		}

		else
		{
			cout << "Attained Maximum edge limit" << endl;
			m_a = 0;
		}
	

	} while (m_a == 1);

	cout << "********************************************************************************" << endl;

}


void Adjacent_matrix::MatrixDisplay(double** matrix, int vertex)
{
	m_vertex = vertex;
	m_matrix = matrix;
	cout << "ADJACENCY MATRIX IS :" << endl << endl;
	for (int i = 0; i < m_vertex; i++)
	{
		for (int j = 0; j < m_vertex; j++)
		{
			cout << m_matrix[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "********************************************************************************" << endl;
}

void Adjacent_matrix :: out_degree(double** matrix, int vertex)
{
	m_vertex = vertex;
	m_matrix = matrix;
	int out_degree = 0;

	cout << "OUT-DEGREE VALUE OF NODES ARE : " << endl << endl;

	for (int i = 0; i < m_vertex; i++)
	{
		for (int j = 0; j < m_vertex; j++)
		{
			if (m_matrix[i][j] != 0)
			{
				out_degree++;
			}
		}
		cout << "out-degree of node " << i + 1 << " is " << out_degree << endl;
		out_degree = 0;

	}

	cout << "********************************************************************************" << endl;
}

void Adjacent_matrix::in_degree(double** matrix, int vertex)
{
	m_vertex = vertex;
	m_matrix = matrix;
	int in_degree = 0;

	cout << "IN-DEGREE VALUE OF THE NODES ARE : " << endl << endl;

	for (int j = 0; j < m_vertex; j++)
	{
		for (int i = 0; i < m_vertex; i++)
		{
			if (m_matrix[i][j] != 0)
			{
				in_degree++;
			}
		}
		cout << "in-degree of node " << j + 1 << " is " << in_degree << endl;
		in_degree = 0;

	}

	cout << "********************************************************************************" << endl;
}

Adjacent_matrix::~Adjacent_matrix()
{
	for (int j = 0; j < m_vertex; j++)
	{
		delete m_matrix[j];
	}


	delete m_matrix;
}