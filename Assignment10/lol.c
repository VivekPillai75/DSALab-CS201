#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct graph
{
    int pred;
    int data;
    int dist;
} graph;

typedef struct ll
{
    int data;
    struct ll *next;
} ll;

// insert into graph if vertice exists
void insert(graph *g[], int ver1[], int ver2[], int i, int k, int qu[])
{
    for (int j = 0; j < k; j++)
    {
        if (ver1[j] == i || ver2[j] == i)
        {
            graph *temp = (graph *)malloc(sizeof(graph));
            temp->data = i;
            temp->pred = -1;
            temp->dist = INT_MAX;
            g[i] = temp;
            qu[i] = i;
            break;
        }
        else
        {
            g[i] = NULL;
        }
    }
    return;
}

// Check if the vertice exits in the file and then insert into graph
void check(graph *g[], int ver1[], int ver2[], int a, int k, int qu[], int source)
{
    for (int i = 0; i < a; i++)
    {
        insert(g, ver1, ver2, i, k, qu);
    }
    g[source]->dist = 0;
    return;
}

// Check if queue is empty
int quempty(int qu[], int a)
{
    int n = 0;
    for (int i = 0; i < a; i++)
    {
        if (qu[i] != -1)
        {
            n = 1;
            break;
        }
    }
    return n;
}

// Extract minimum of queue
int extmin(graph *g[], int a, int qu[])
{
    int m = INT_MAX;
    int j = -1;
    for (int i = 0; i < a; i++)
    {
        if (g[i]->dist < m && qu[i] != -1)
        {
            m = g[i]->dist;
            j = i;
        }
    }
    if (j == -1)
    {
        return j;
    }
    qu[j] = -1;
    return j;
}

// Creates adjacency list
void adja(int v1[], int v2[], ll *adj[], int k)
{
    for (int i = 0; i < k; i++)
    {
        ll *temp = (ll *)malloc(sizeof(ll));
        temp->data = v2[i];
        temp->next = NULL;
        if (adj[v1[i]] == NULL)
        {
            adj[v1[i]] = temp;
        }
        else
        {
            temp->next = adj[v1[i]];
            adj[v1[i]] = temp;
        }
    }

    return;
}

// Inserting a node
void ins(ll *k[], int n)
{
    ll *temp = (ll *)malloc(sizeof(ll));
    temp->data = n;
    temp->next = k[0];
    k[0] = temp;

    return;
}

// Find the weight corresponding to the particular vertices
int findw(int v1, int v2, int ver1[], int ver2[], int we[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (ver1[i] == v1 && ver2[i] == v2)
        {
            return we[i];
        }
    }
}

// Relax function to update distances
void relax(int u, int v, int w, graph *g[])
{
    if (g[v]->dist > g[u]->dist + w)
    {
        g[v]->dist = g[u]->dist + w;
        g[v]->pred = u;
    }
    return;
}

// Main Function
int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("FILE doesnt exist");
        return 0;
    }
    int source = atoi(argv[2]);
    char str[50];
    int k = 0;
    while (fgets(str, 40, f))
    {
        k += 1;
    }
    fclose(f);
    // vertex 1
    int ver1[k];
    for (int i = 0; i < k; i++)
    {
        ver1[i] = -1;
    }
    // vertex 2
    int ver2[k];
    for (int i = 0; i < k; i++)
    {
        ver2[i] = -1;
    }
    // Weights of the edges
    int we[k];
    for (int i = 0; i < k; i++)
    {
        we[i] = -1;
    }
    FILE *p;
    p = fopen(argv[1], "r");
    if (p == NULL)
    {
        printf("FILE doesnt exist");
        return 0;
    }
    int v1, v2, w;
    int i = 0;
    // Reading in the edges and their weights
    while (fscanf(p, "%d %d %d", &v1, &v2, &w) != EOF)
    {
        ver1[i] = v1;
        ver2[i] = v2;
        we[i] = w;
        i++;
    }
    // Maximum value of vertice inserted
    int a = 0;
    for (int i = 0; i < k; i++)
    {
        if (ver1[i] > a)
        {
            a = ver1[i];
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (ver2[i] > a)
        {
            a = ver2[i];
        }
    }
    a += 1;
    // Creating adjacency list
    ll *adj[a];
    for (int i = 0; i < a; i++)
    {
        adj[i] = NULL;
    }
    adja(ver1, ver2, adj, k);
    // Creating graph that conatins the distance from source and predecessor
    graph *g[a];
    for (int i = 0; i < a; i++)
    {
        g[i] = NULL;
    }
    // Innitializing queue
    int qu[a];
    for (int i = 0; i < a; i++)
    {
        qu[i] = -1;
    }
    // Check if a value is existing as a vertice and then insert them into graph and queue
    check(g, ver1, ver2, a, k, qu, source);
    ll *s[1];
    s[0] = NULL;
    // dijkstra algorithm
    FILE *r;
    r = fopen("lol1.txt", "w");
    while (quempty(qu, a))
    {
        int u = extmin(g, a, qu);
        fprintf(r, "%d\n", u);
        if (u != -1)
        {
            ins(s, u);
            ll *temp = adj[u];
            while (temp != NULL)
            {
                int v = temp->data;
                int w = findw(u, v, ver1, ver2, we, k);
                relax(u, v, w, g);
                temp = temp->next;
            }
        }
        else
        {
            break;
        }
    }
    

    // for (int i = 0; i < a; i++)
    // {
    //     if (g[i]->dist != INT_MAX)
    //     {
    //         fprintf(r, "%d %d\n", i, g[i]->dist);
    //     }
    //     else
    //     {
    //         fprintf(r, "%d -1\n", i);
    //     }
    // }
    fclose(r);
    fclose(p);
    return 0;
}