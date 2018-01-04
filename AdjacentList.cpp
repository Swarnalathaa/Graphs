#include"AdjacentList.h"



vector<vector<int>> Adjacent_list::EdgeCreation(int vertex, int MaxEdge)
{
	m_vertex = vertex;
	m_MaxEdge = MaxEdge;
	int Node2;

	
	vector<vector<int>> m_AdjacencyList;


	int option = 0;
	int a = 0;
	int loop = 0;
	int n;

	cout << "Creation of adjacency list:" << endl;

	if (loop<m_MaxEdge)
	{
		for (int i = 0; i < vertex; i++)
		{
			vector<int> row;
			cout << "Do you want to add edge to Node" << i << ":";
			cin >> option;
			
			if (option == 1)
			{
				cout << "Enter the number of egdes to the Node " << i << ":";
				cin >> n;

				while (a<n)
				{
					cout << "enter the edge:";
					cin >> Node2;
					if (Node2 > m_vertex)
					{
						cout << "Entered edge cannot be created" << endl;
					}

					else
					{
						if (i == Node2)
						{
							cout << "Node cannot be adjacent to itlsef" << endl;
						}

						else
						{
							row.push_back(Node2);
							a++;
							loop++;
						}
					}

				} 

			}

			a = 0;

			m_AdjacencyList.push_back(row);

		}

		cout << endl;
	}

	else
	{
		cout << "Attained maximum edge limit" << endl;
	}
	
	

	
	

	return m_AdjacencyList;

}


void Adjacent_list::ListDisplay(vector<vector<int>> AdjacencyList)
{
	m_AdjacencyList = AdjacencyList;
	cout << "Created adjacency list is:" << endl;

	for (int i = 0; i < m_AdjacencyList.size(); i++)
	{
		cout << i  << "-->\t";
		for (int j = 0; j < m_AdjacencyList[i].size(); j++)
		{
			cout << m_AdjacencyList[i][j] << "\t";
		}

		cout << endl;
	}

	cout << endl;

}


void Adjacent_list::BFS(int s, int vertex, vector<vector<int>> AdjacencyList)

{
	m_AdjacencyList = AdjacencyList;
	m_vertex = vertex;
	
	bool *visited = new bool[m_vertex];

	for (int i = 0; i < m_vertex; i++)
	{
		visited[i] = false;

	}


	list<int> q;


	visited[s] = true;
	q.push_back(s);

	cout << "The BFS of the graph is :" << endl;

	while (!q.empty())
	{
		s = q.front();
		cout << s << " \t";
		q.pop_front();

		for (int i = 0; i <m_AdjacencyList[s].size(); i++)
		{
			if (!visited[m_AdjacencyList[s][i]])
			{
				visited[m_AdjacencyList[s][i]] = true;
				q.push_back(m_AdjacencyList[s][i]);
			}
		}
	}

	cout << endl;

	for (int i = 0; i < m_vertex; i++)
	{
		if (visited[i] == false)
		{
			cout << "The graph is not strongly connected" << endl;

			break;
		}

		else
		{
			cout << "The graph is strongly connected" << endl;
		}
			

	}
}

void Adjacent_list::DFS(int s, int vertex, vector<vector<int>> AdjacencyList)

{
	m_vertex = vertex;
	m_AdjacencyList = AdjacencyList;

	bool *visited = new bool[vertex];

	for (int i = 0; i < vertex; i++)
	{
		visited[i] = false;

	}


	stack<int> q;

	q.push(s);

	cout << "The DFS of the graph is :" << endl;

	while (!q.empty())
	{
		s = q.top();
		q.pop();

		if (!visited[s])
		{
			cout << s << "\t ";
			visited[s] = true;

		}

		for (int i = 0; i <AdjacencyList[s].size(); i++)
		{
			if (!visited[AdjacencyList[s][i]])
			{
				q.push(AdjacencyList[s][i]);
			}
		}
	}

	cout << endl;

}



bool Adjacent_list::isconnected_DFS (int s, int vertex, vector<vector<int>> AdjacencyList)

{
	m_vertex = vertex;
	m_AdjacencyList = AdjacencyList;

	bool *visited = new bool[vertex];

	for (int i = 0; i < vertex; i++)
	{
		visited[i] = false;

	}


	stack<int> q;

	q.push(s);

	//cout << "The BFS of the graph is :" << endl;

	while (!q.empty())
	{
		s = q.top();
		q.pop();

		if (!visited[s])
		{
			//cout << s << "\t ";
			visited[s] = true;

		}

		for (int i = 0; i <AdjacencyList[s].size(); i++)
		{
			if (!visited[AdjacencyList[s][i]])
			{
				q.push(AdjacencyList[s][i]);
			}
		}
	}
	
	
	
	for (int i = 0; i < m_vertex; i++)
	{
		if (visited[i] == false)
		{
			return false;
		}

	}

	return true;

}

bool Adjacent_list::isconnected_directed(int vertex, vector<vector<int>>Adjacent_list)
{
	
	m_vertex = vertex;
	m_AdjacencyList = Adjacent_list;

	bool* l = new bool[m_vertex];

	for (int i = 0; i < m_vertex; i++)
	{
		l[i] = isconnected_DFS(i, m_vertex, m_AdjacencyList);
	}


	for (int i = 0; i < m_vertex; i++)
	{
		if (l[i] == false)
		{
			return false;
		}
	}

	return true;

}



Adjacent_list::~Adjacent_list()
{
	delete[] visited;
}




