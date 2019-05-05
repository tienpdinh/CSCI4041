// Articulation Points
void DFS(int u, int direct_parent)
{
	if(dfs_num[u] != -1) return;
	dfs_num[u] = dfs_low[u] = dfsTime++;
	for(int i = 0; i < adj_list[u].size(); i++)
	{
		int v = adj_list[u][i];
		if(dfs_num[v] == -1)
		{
			if(u == dfsRoot) rootChildren++;
			DFS(v, u);

			if(dfs_low[v] >= dfs_num[u])
				articulation_points[u] = true;

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != direct_parent)
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

void ArticulationPoints(int V, int E)
{
	// set dfs num and lows
	dfs_num.assign(V+1, -1); dfs_low.assign(V+1, -1);
	articulation_points.assign(V+1, false);

	// call with dfs(0) 
	dfsRoot = 1, rootChildren = 0, dfsTime = 1;
	DFS(1, -1);

	// check if root is articulation point
	articulation_points[dfsRoot] = (rootChildren > 1);
}

// Topological Sort
void DFS(int source, bool visited[])
{
	if(visited[source]) return;
	visited[source] = true;

	for(int i = 0; i < adj_list[source].size(); i++)
		if(!visited[adj_list[source][i]])
			DFS(adj_list[source][i], visited);

	// cout << source << " ";
	ans.push_back(source);
}

void TopSort(int V, int E)
{
	bool visited[V+1];
	memset(visited, false, sizeof(visited));

	ans.clear();
	for(int i = 1; i < V+1; i++)
		if(!visited[i])
			DFS(i, visited);	

	reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
}


// Strongly Connected Components
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}
vector< pair<int, int> > post;

int pre_post_time = 1;
void DFS(int source, bool visited[], vector< vector<int> > adj_list)
{
	if(visited[source]) return;
	visited[source] = true;

	pre_post_time++;
	for(int i = 0; i < adj_list[source].size(); i++)
		if(!visited[adj_list[source][i]])
			DFS(adj_list[source][i], visited, adj_list);
	pair<int, int> tmp;
	tmp.first = source, tmp.second = pre_post_time++;
	post.push_back(tmp);
}

int numConnectedComponents(int V, int E, vector< vector<int> > adj_list, vector< vector<int> > reverse_adj_list)
{
	// run dfs
	bool visited[V+1];
	memset(visited, false, sizeof(visited));
	for(int i = 1; i < V+1; i++)
		if(!visited[i])
			DFS(i, visited, adj_list);

	// reverse sort by post numbers
	sort(post.begin(), post.end(), cmp);

	// for(int i = 0; i < post.size(); i++)
	// 	cout << post[i].first << " " << post[i].second << endl;
	// cout << endl;

	// run dfs on Gr
	int count = 0;
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < post.size(); i++)
		if(!visited[post[i].first])
		{
			DFS(post[i].first, visited, reverse_adj_list); count++;
		}

	return count == 1;
}



