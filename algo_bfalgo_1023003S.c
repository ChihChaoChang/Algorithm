#include <stdio.h>
#define INFINITY 9999
typedef struct {
    int u, v, w;
} Edge;
 
int n; /* the number of nodes */
int e; /* the number of edges */
Edge edges[4096]; /* large enough for n <= 2^6=64  64*64=4096 */
int d[64]; /* d[i] is the minimum distance from node s to node i */
 
void printDist() {
    int i;
    printf("Distances:\n");
    for (i = 0; i < n; ++i)
        printf("vertex %d: %d\n", i + 1,d[i]);
}
 
void bellman_ford(int s) {
    int i, j;
    for (i = 0; i < n; ++i)
        {
        	d[i] = INFINITY;
        }
    d[s] = 0;
 
    for (i = 0; i < n - 1; ++i)
        {
        for (j = 0; j < e; ++j)
           {
            if (d[edges[j].u] + edges[j].w < d[edges[j].v])
                {
                d[edges[j].v] = d[edges[j].u] + edges[j].w;
            	}
		  }	
		}
}

int main() {
    int i, j;
    int w;
	printf("Enter the number of vertex:\n");
    scanf("%d", &n);
    e = 0;
	printf("Enter the adjacency matrix of the graph:\n");
    for (i = 0; i < n; ++i)
        {
        	for (j = 0; j < n; ++j) 
			{
        		scanf("%d", &w);
            	if (w != 0) 
				{
                	edges[e].u = i;
                	edges[e].v = j;
                	edges[e].w = w;
                	++e;
            	}
        	}
    	}
    bellman_ford(0);
    printDist();
    return 0;
}
