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

adj *list[n];

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
    while (quempty(qu, a))
    {
        int u = extmin(g, a, qu);
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
    FILE *r;
    r = fopen("dijkstra.txt", "w");
    for (int i = 0; i < a; i++)
    {
        if (g[i]->dist != INT_MAX)
        {
            fprintf(r, "%d %d\n", i, g[i]->dist);
        }
        else
        {
            fprintf(r, "%d -1\n", i);
        }
    }
    fclose(r);
    fclose(p);
    return 0;
}



graph *arr[n];


void prim (graph *arr[],int queue[],int n,ll* adj){
    while (quempty(queue, n))
    {
        int node1 = extmin(arr, n, queue);
        graph *temp = adj[node1];
        while (temp != NULL)
        {
            int node2 = temp->data;
            int weight = findweight(arr,n,node1,node2);
            if( (search(queue,node2,n) && weight <graph[node2]->key) ){
                graph[node2]->pred = node1;
                graph[node2]->key = weight;
            }
            temp = temp->next;
        }
    }
    return;
}



void dijkstra(graph *arr[],int *queue,int n){
    while (quempty(queue, n))
    {
        int node1 = extmin(arr, n, queue);
        graph *temp = arr[node1];
        while (temp != NULL)
        {
            int node2 = temp->data;
            int weight = findweight(arr,n,node1,node2);
            relax(node1, node2, weight, arr);
            temp = temp->next;
        }
    }
    return;
}


void relax(int node1, int node2, int weight, graph *arr[])
{
    if (arr[node2]->dist > arrr[node1]->dist + weight)
    {
        changedist(node1,node2,weight,arr);
        changepred(node1,node2,arr);
        // arr[node2]->dist = arr[node1]->dist + weight;
        // arr[node2]->pred = node1;
    }
    return;
}


typedef struct adj
{
    int data;
    struct adj *next;
} adj;


bool bellmanford(adj *list[],int n,graph* arr[]){
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<n;j++){
            adj *temp=list[j];
            while(temp!=NULL){
                int node1=j;
                int node2=temp->data;
                int weight=temp->weight;
                relax(node1,node2,weight,arr);
            }
        }
    }
    for(int j=0;j<n;j++){
        adj *temp=list[j];
        while(temp!=NULL){
            int node1=j;
            int node2=temp->data;
            int weight=temp->weight;
            if(arr[node2]->dist > arr[node1]->dist + weight){
                return false;
            }
        }
    }
    return true;
}


void relax(int node1, int node2, int weight, graph *arr[])
{
    if (arr[node2]->dist > arrr[node1]->dist + weight)
    {
        arr[node2]->dist = arr[node1]->dist + weight;
        arr[node2]->pred = node1;
    }
    return;
}


// // Floyd-Warshall Algorithm in C

// #include <stdio.h>

// // defining the number of vertices
// #define nV 4

// #define INF 999

// void printMatrix(int matrix[][nV]);

// Implementing floyd warshall algorithm
void floydWarshall(int adj[][n],int n) {
    int dist[n][n];

    for(int i = 0; i < nV; i++)
        for(int j = 0; j < nV; j++)
            dist[i][j] = adj[i][j];

    for(int k = 0; k < nV; k++) {
        for(int i = 0; i < nV; i++) {
            for(int j = 0; j < nV; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    print(dist);
    return;
}

void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int graph[nV][nV] = {{0, 3, INF, 5},
             {2, 0, INF, 4},
             {INF, 1, 0, INF},
             {INF, INF, 2, 0}};
  floydWarshall(graph);
}


void selectionSort(int arr[],int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min]){
                min=j;
            }
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
    return;    
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j] > arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return;
}

void insertionSort(int arr[], int n){
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(key < arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
    }
    return;
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0) {
        array[j + 1] = array[j];
        --j;
        }
        array[j + 1] = key;
    }
}

int orderedLinSearch(int array[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]=key){
            return 1;
        }else if(arr[i]> key){
            return 0;
        }
    }
    return 0;
}

int binarySearch(int array[], int key, int l, int h) {
    if(l>=h){
        return -1;
    }else{
        int mid = l+ (h-l)/2;
        if(arr[mid]==key){
            return mid;
        }else{
            if(arr[mid] > key){
                h=mid;
            }else{
                l=mid;
            }
        }
    }
    return -1;
}


int interpolationSearch(int arr[], int l, int h, int key)
{
    if (l <= h && key >= arr[l] && key <= arr[h]) {
        int pos = l + (((double)(h - l) / (arr[h] - arr[l])) * (key - arr[l]));
        if (arr[pos] == key)
            return pos;
        if (arr[pos] < key){
            return interpolationSearch(arr, pos + 1, h, key);
        }  
        else if (arr[pos] > key){
            return interpolationSearch(arr, l, pos - 1, key);
        }
            
    }
    return -1;
}













