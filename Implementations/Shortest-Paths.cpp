// Dijkstra
int dijkstra(int source, int target, int V, int E)
{
	vector<int> distances(V+1, INT_MAX);
	distances[source] = 0;
	
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > tmp;
	
	tmp.push(make_pair(0, source));
	int v, u, d; bool result;
	
	while(!tmp.empty())
	{
		u = tmp.top().second; d = tmp.top().first; tmp.pop();

		for(int i = 0; i < adj_list[u].size(); i++)
		{
		    v = adj_list[u][i].v;
	        // cout << u << " " << v << " " << distances[v] << " " << distances[u] + adj_list[u][i].w << endl;
			if(distances[v] > distances[u] + adj_list[u][i].w)
			{
				distances[v] = (distances[u] + adj_list[u][i].w);
				tmp.push(make_pair(distances[v], v));
			}
		}
	}
	if(distances[target] != INT_MAX)
		return distances[target];
	return -1;
}

// Bellman Ford
bool BellmanFord(int source, int V, int E, vector< vector<Edge> > adj_list)
{
	int distances[V+1];
	memset(distances, INT_MAX, sizeof(distances));
	distances[source] = 0;
	
	for(int i = 0; i < V; i++)
		for(int u = 1; u < V+1; u++)
			for(int v = 0; v < adj_list[u].size(); v++)
				distances[adj_list[u][v].v] = min(distances[adj_list[u][v].v], distances[u] + adj_list[u][v].w);

	for(int u = 1; u < V+1; u++)
		for(int v = 0; v < adj_list[u].size(); v++)
			if(distances[adj_list[u][v].v] > distances[u] + adj_list[u][v].w)
}

// Flyod Warshall
void FlyodWarshall()
{
	for(int k = 1; k < V+1; k++)
		for(int i = 1; i < V+1; i++)
			for(int j = 1; j < V+1; j++)
				if(adj_matrix[i][k] != INT_MAX and adj_matrix[k][j] != INT_MAX and
					adj_matrix[i][j] > adj_matrix[i][k] + adj_matrix[k][j])
					adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];

}

// Shortest Paths in a DAG
void ShortestPathsinaDAG()
{
	// TopSort
	shortest_path[source] = 0;
	for(int i = a.size(); i >= 0; i--)
		for(int j = 0; j < adj_list[i].size(); j++)
			shortest_path[j] = min(shortest_path[j], shortest_path[i] + 1);
}