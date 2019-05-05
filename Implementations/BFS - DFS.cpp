// BFS / DFS
void DFS_recursive(int source, vector<bool> &visited)
{
  if(visited[source])
    return;

  visited[source] = true;
  for(int i = 0; i < adj_list[source].size(); i++)
    DFS_recursive(adj_list[source][i], visited);

  return;
}

int shortest_path_BFS(int source, int target, int V, int E)
{  
  int distances[V+1];
  for(int i = 1; i < V+1; i++)
    distances[i] = INT_MAX;
  distances[source] = 0;

  int cur_node = source;
  queue<int> cur_layer; cur_layer.push(source);

  while(cur_layer.empty() != true and cur_node != target)
  {
    cur_node = cur_layer.front(); cur_layer.pop();
    for(int i = 0; i < adj_list[cur_node].size(); i++)
      if(distances[adj_list[cur_node][i]] == INT_MAX)
      {
        distances[adj_list[cur_node][i]] = distances[cur_node] + 1;
        cur_layer.push(adj_list[cur_node][i]);
      }
  }
  if(distances[target] != INT_MAX)
    return distances[target];
  return -1;
}