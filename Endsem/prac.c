#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph data structure
typedef struct graph
{
    char color;
    int time;
    struct graph *next;
} graph;

typedef struct ll
{
    int data;
    struct ll *next;
} ll;

// // Queue
// int start = -1;
// int tail = -1;
// int ctr = 0;

// int isEmpty(int *qu)
// {
//     if (ctr == 0)
//     {
//         return 1;
//     }
//     return 0;
// }

// void enqueue(int x, int n, int *qu)
// {
//     tail++;
//     qu[tail] = x;
//     if (start == -1)
//     {
//         start++;
//     }
//     ctr++;
//     return;
// }

// int dequeue(int n, int *qu)
// {
//     int k = qu[start];
//     for (int i = 0; i < tail; i++)
//     {
//         qu[i] = qu[i + 1];
//     }
//     qu[tail] = -1;
//     if (ctr == 1)
//     {
//         tail = -1;
//         start = -1;
//     }
//     else
//     {
//         tail -= 1;
//     }
//     ctr--;
//     return k;
// }
int time = 0;
// // BFS traversal
void dfs(ll *arr[], int fin[], char col[], int i, FILE *r)
{
    time = time + 1;
    col[i] = 'g';
    ll *temp = arr[i];
    while (temp != NULL)
    {
        if (col[temp->data] == 'w')
        {
            dfs(arr, fin, col, temp->data,r);
        }
        temp = temp->next;
    }
    col[i] = 'b';
    time = time + 1;
    fin[i] = time;
    fprintf(r,"%d\n", i);
}

// Creating adjacency list
void insert(int m, int n, ll *arr[])
{
    ll *temp = (ll *)malloc(sizeof(ll));
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
    if (fscanf(p, "%d %d", &vertices, &edges))
    {
        // printf("%d %d",vertices,edges);
    }
    int l = vertices;
    ll *arr[l];
    fclose(p);
    p = fopen(argv[1], "r");
    for (int i = 0; i < l; i++)
    {
        arr[i] = NULL;
    }
    int v1, v2;
    while (fscanf(p, "%d %d", &v1, &v2) != EOF)
    {
        insert(v1, v2, arr);
    }

    // for(int i=0;i<l;i++){
    //     ll* temp=arr[i];
    //     while(temp!=NULL){
    //         printf("%d ",temp->data);
    //         temp=temp->next;
    //     }
    //     printf("\n");
    // }

    // // Queue
    // int qu[g];
    // for (int i = 0; i < g; i++)
    // {
    //     qu[i] = -1;
    // }

    // An array containing the shortest distance of every vertex from the source vertex
    int fin[l];
    for (int i = 0; i < l; i++)
    {
        fin[i] = -1;
    }
    // An array to denote the color of the node during bfs
    char col[l];
    for (int i = 0; i < l; i++)
    {
        col[i] = 'w';
    }
    FILE *r;
    r = fopen("ts.txt", "w");
    // Executing the dfs traversal
    for (int i = 0; i < l; i++)
    {
        if (col[i] == 'w')
        {
            dfs(arr, fin, col, i, r);
        }
    }
    fclose(p);
    // FILE *p;
    // p = fopen("sd.txt", "w");
    // // Printing out the shortest distance of every vertex from the source vertex
    // for (int i = 0; i < g; i++)
    // {
    //     fprintf(p, "%d\n", dist[i]);
    // }
    // fclose(f);

    return 0;
}