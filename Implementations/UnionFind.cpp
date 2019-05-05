struct UnionFind
{
    void MakeUnionFind(int V)
    {
        for(int i = 1; i < V+1; i++)
            parent[i] = i, size[i] = 1;
    }
    int Find_Set(int a)
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