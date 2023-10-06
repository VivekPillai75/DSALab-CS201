#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ll
{
    int data;
    struct ll *next;
} ll;
int j = 0;
int time = 0;
// DFS traversal
void dfs(ll *arr[], int fin[], char col[], int i, FILE *r, int ult[])
{
    time = time + 1;
    col[i] = 'g';
    ll *temp = arr[i];
    while (temp != NULL)
    {
        if (col[temp->data] == 'w')
        {
            dfs(arr, fin, col, temp->data, r, ult);
        }
        temp = temp->next;
    }
    col[i] = 'b';
    time = time + 1;
    fin[i] = time;
    ult[j] = i;
    j += 1;
}
// Creating adjacency list
void insert(int m, int n, ll *arr[])
{
    ll *temp1 = arr[m];
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    ll *temp = (ll *)malloc(sizeof(ll));
    temp->data = n;
    temp->next = NULL;
    temp1->next = temp;
    return;
}
// Main Function
int main(int argc, char *argv[])
{
    FILE *p;
    p = fopen(argv[1], "r");
    if (p == NULL)
    {
        printf("FILE doesnt exist");
        return 0;
    }
    int vertices, edges;
    char str[40];
    fscanf(p, "%d %d", &vertices, &edges);
    int l = vertices;
    ll *arr[l];
    for (int i = 0; i < l; i++)
    {
        ll *temp = (ll *)malloc(sizeof(ll));
        temp->data = i;
        temp->next = NULL;
        arr[i] = temp;
    }
    // Creating the adjacency list
    int v1, v2;
    while (fscanf(p, "%d %d", &v1, &v2) != EOF)
    {
        insert(v1, v2, arr);
    }
    // The distance for DFS
    int fin[l];
    for (int i = 0; i < l; i++)
    {
        fin[i] = -1;
    }
    // An array to denote the color of the node during dfs
    char col[l];
    for (int i = 0; i < l; i++)
    {
        col[i] = 'w';
    }
    FILE *r;
    r = fopen("ts.txt", "w");
    int ult[l];
    for (int i = 0; i < l; i++)
    {
        ult[i] = -1;
    }
    // Executing the dfs traversal
    for (int i = 0; i < l; i++)
    {
        if (col[i] == 'w')
        {
            dfs(arr, fin, col, i, r, ult);
        }
    }
    for (int i = l - 1; i >= 0; i--)
    {
        fprintf(r, "%d\n", ult[i]);
    }
    fclose(p);
    fclose(r);
    return 0;
}


typedef struct graph
{
    char color;
    int data;
    int pred;
    struct graph *next;
} graph;

graph* arr[n];

for (int i = 0; i < l; i++)
 {
    graph *temp =arr[i];
    if (temp->color == 'w')
    {
        dfs(arr, fin, col, i, r, ult);
    }
 }


void dfs(ll *arr[],int node)
{
    time = time + 1;
    changedist(arr,node,time);
    changecolor(arr,node);
    grpah *temp = arr[node];
    temp=temp->next;
    while (temp != NULL)
    {
        if (col[temp->data] == 'w')
        {
            dfs(arr,temp->data);
        }
        temp = temp->next;
    }
    changecolor(arr,node);
    time = time + 1;
    changefin(arr,node,time);
}


void newbfs(graph *arr[],int s,int dist[]){
    createQueue();
    
}

void bfs(graph *arr[], int *queue, int n, int *dist,int source)
{
    dist[source] = 0;
    changecolor(arr, source , 'g');
    setpred(arr,source,NULL);
    enqueue(source, n, queue);
    while (!isEmpty(queue))
    {
        int u = dequeue(n, queue);
        graph *temp = arr[u];
        while (temp != NULL)
        {
            if (col[temp->data] == 'w')
            {
                changecolor(arr,temp->data,'g');
                dist[temp->data] = dist[u] + 1;
                setpred(arr,source,u);
                enqueue(temp->data, n, queue);
            }
            temp = temp->next;
        }
        changecolor(arr,u,'b');
    }
}








