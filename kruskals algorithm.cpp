// Kruskals algorithm 
#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int find(int parent[], int x)
{
    while (parent[x] != x)
        x = parent[x];

    return x;
}

int main()
{
    int n, e, i, j;
    int parent[20];
    struct Edge edge[50], temp;
    int total = 0, count = 0;
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v cost):\n");

    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);

    
    for (i = 0; i < e - 1; i++)
    {
        for (j = i + 1; j < e; j++)
        {
            if (edge[i].w > edge[j].w)
            {
                temp = edge[i];
                edge[i] = edge[j];
                edge[j] = temp;
            }
        }
    }

    
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");

    for (i = 0; i < e && count < n - 1; i++)
    {
        u = find(parent, edge[i].u);
        v = find(parent, edge[i].v);

        
        if (u != v)
        {
            printf("%d - %d  Cost = %d\n",
                   edge[i].u, edge[i].v, edge[i].w);

            total = total + edge[i].w;
            parent[u] = v;
            count++;
        }
    }

    printf("Minimum Cost = %d\n", total);

    return 0;
}