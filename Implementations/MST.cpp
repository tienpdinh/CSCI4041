// Kruskal
void Kruskal()
{
	int parent[MAX], size[MAX];
	bool vis[MAX][MAX];
	pair<int, pair<int, int> > edge_list[2000 * 2000 + 7];

	struct UnionFind
	{
	    void MakeUnionFind(int V)
	    {
	        for(int i = 1; i < V+1; i++)
	            parent[i] = i, size[i] = 1;
	    }
	    int Find(int a)
	    {
	        return (parent[a] == a) ? a : parent[a] = Find(parent[a]);
	    }
	    void Union(int a, int b)
	    {
	        int r1 = Find(a), r2 = Find(b);
	        if(r1 == r2) return;
	        if(size[r1] > size[r2])
	            swap(r1, r2);

	        size[r2] += size[r1];
	        parent[r1] = parent[r2];
	    }
	};

	// Kruskal
	    UnionFind uf; uf.MakeUnionFind(V+1);

	    for(int i = 0; i < count and edges != V-1; i++)
	    {
	        u = edge_list[i].first, v = edge_list[i].second.first, w = edge_list[i].second.second;
	        if(uf.Find(u) != uf.Find(v))
	        {
	            uf.Union(u, v);
	            edges++; ans += w;
	        }
	    }
}

// Prim
double Prims(int n)
{
  multimap<Point, Point, cmp> queue;
  for(int i = 1; i < n; i++)
    queue.insert(make_pair(points[i], points[i]));

  // cout << "Points ";
  // for(mmi it = queue.begin(); it != queue.end(); it++)
  //   cout << it->first.x <<" " << it->first.y << " " << it->first.distance << endl;
  // cout << endl;

  // dist[u] = 0
  Point cur = points[0];
  cur.distance = 0.0;
  queue.insert(make_pair(cur, cur));

  vector<Point> to_update;
  double ans = 0.0;
  while(!queue.empty())
  {
    cur = queue.begin()->first; queue.erase(queue.find(cur));
    to_update.clear();
    ans += cur.distance;

    // cout << "Cur point " << cur.x << " " << cur.y << " " << cur.distance << endl;

    // cout << "Cur distances ";
    for(mmi it = queue.begin(); it != queue.end(); it++)
    {
      // cout << it->first.x << " " << it->first.y << " " << it->first.distance << " " << euclid(it->first, cur) << endl;
      if(it->first.distance > euclid(it->first, cur))
        to_update.push_back(it->first);
    }

    // cout << "To update ";
    for(int i = 0; i < to_update.size(); i++)
    {
      // cout << to_update[i].x << " " << to_update[i].y << " " << to_update[i].distance << endl;

      queue.erase(queue.find(to_update[i]));
      to_update[i].distance = euclid(to_update[i], cur);
      queue.insert(make_pair(to_update[i], to_update[i]));
    }
    // cout << endl;
  }
  return ans;
}