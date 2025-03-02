#include"total.h"
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent;
    int rank;
};
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x), yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot;
    else 
        subsets[yroot].parent = xroot,
        subsets[xroot].rank++;  
}
int compare(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}
void kruskal(struct Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(edges[0]), compare); int total = 0;
    struct Subset* subsets = (struct Subset*)malloc((V + 1) * sizeof(struct Subset));
    for (int i = 0; i <= V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    cout << "the edges in the minimum spanning tree are as follows:" << endl;
    for (int i = 0, e = 0; e < V - 1; i++) {
        int x = find(subsets, edges[i].src), y = find(subsets, edges[i].dest);
        if (x != y) 
            cout << edges[i].src << " " << edges[i].dest << " " << edges[i].weight << endl,
            total += edges[i].weight,
            unionSets(subsets, x, y),
            e++;
    }       
    cout << "the total value of these edges are:   " << total << endl;
    free(subsets);
}
void problem_3() {
    char c = 'y'; int V, E, u, v, w; // 顶点（vertex） 边（edge）顶点1 顶点2 权值
    while (c == 'y' || c == 'Y') {
        cout << "please input the number of vertices and edges:  ";  cin >> V >> E;
        struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
        cout << "please input the values of them:" << endl;
        for (int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            edges[i] = { u,v,w };
        }  
        kruskal(edges, V, E);
        cout << "whether to start problrm_3 again?(y/n)   ";
        cin >> c;
    }
}
