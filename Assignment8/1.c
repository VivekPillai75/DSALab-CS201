#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph data structure
typedef struct graph
{
    char color;
    int data;
    struct graph *next;
} graph;

// Queue
int start = -1;
int tail = -1;
int ctr = 0;

int isEmpty(int *qu)
{
    if (ctr == 0)
    {
        return 1;
    }
    return 0;
}

void enqueue(int x, int n, int *qu)
{
    tail++;
    qu[tail] = x;
    if (start == -1)
    {
        start++;
    }
    ctr++;
    return;
}

int dequeue(int n, int *qu)
{
    int k = qu[start];
    for (int i = 0; i < tail; i++)
    {
        qu[i] = qu[i + 1];
    }
    qu[tail] = -1;
    if (ctr == 1)
    {
        tail = -1;
        start = -1;
    }
    else
    {
        tail -= 1;
    }
    ctr--;
    return k;
}

// BFS traversal
void bfs(graph *arr[], int *qu, int n, int *dist, char *col)
{
    int b = 0;
    dist[b] = 0;
    col[b] = 'g';
    enqueue(0, n, qu);
    while (!isEmpty(qu))
    {
        int u = dequeue(n, qu);
        graph *temp = arr[u];
        while (temp != NULL)
        {
            if (col[temp->data] == 'w')
            {
                col[temp->data] = 'g';
                dist[temp->data] = dist[u] + 1;
                enqueue(temp->data, n, qu);
            }
            temp = temp->next;
        }
        col[u] = 'b';
    }
}

// Inserting the graph elements into Graph structure
void insert(int m, int n, graph *arr[])
{
    graph *temp = (graph *)malloc(sizeof(graph));
    temp->color = 'w';
    temp->data = n;
    temp->next = NULL;
    if (arr[m] == NULL)
    {
        arr[m] = temp;
    }
    else
    {
        temp->next = arr[m];
        arr[m] = temp;
    }
    graph *temp1 = (graph *)malloc(sizeof(graph));
    temp1->color = 'w';
    temp1->data = m;
    temp1->next = NULL;
    if (arr[n] == NULL)
    {
        arr[n] = temp1;
    }
    else
    {
        temp1->next = arr[n];
        arr[n] = temp1;
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

    char str[40];
    int l;
    int n;
    int r = 0;
    if (fgets(str, 40, f))
    {
        int k = strlen(str);
        int m = 0;
        char a[40];
        char b[40];
        int j = 0;
        for (int i = 0; i < k; i++)
        {
            if (str[i] != ' ' && m == 0)
            {
                a[i] = str[i];
            }
            if (str[i] == ' ')
            {
                m = 1;
            }
            if (m)
            {
                b[j] = str[i];
                j++;
            }
        }
        l = atoi(a);
    }
    int g = l;
    graph *arr[g];
    for (int i = 0; i < g; i++)
    {
        arr[i] = NULL;
    }
    while (fgets(str, 40, f))
    {
        int k = strlen(str);
        int m = 0;
        char a[40];
        char b[40];
        int j = 0;
        for (int i = 0; i < k; i++)
        {
            if (str[i] != ' ' && m == 0)
            {
                a[i] = str[i];
            }
            if (str[i] == ' ')
            {
                a[i] = '\0';
                m = 1;
            }
            if (m)
            {
                b[j] = str[i];
                j++;
            }
        }
        b[j] = '\0';
        int q = atoi(a);
        int w = atoi(b);
        insert(q, w, arr);
    }
    // Queue
    int qu[g];
    for (int i = 0; i < g; i++)
    {
        qu[i] = -1;
    }
    // An array containing the shortest distance of every vertex from the source vertex
    int dist[g];
    for (int i = 0; i < g; i++)
    {
        dist[i] = -1;
    }
    // An array to denote the color of the node during bfs
    char col[g];
    for (int i = 0; i < g; i++)
    {
        col[i] = 'w';
    }
    // Executing the bfs traversal
    bfs(arr, qu, g, dist, col);

    fclose(f);
    FILE *p;
    p = fopen("sd.txt", "w");
    // Printing out the shortest distance of every vertex from the source vertex
    for (int i = 0; i < g; i++)
    {
        fprintf(p, "%d\n", dist[i]);
    }
    fclose(f);

    return 0;
}