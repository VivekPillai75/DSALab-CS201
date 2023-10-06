#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int value;
    struct vertice *next;
} vertice;
typedef struct edge
{
    int v1;
    int v2;
    int weight;
} edge;

void sortEdgeArray(edge *arrEdge[], int sizeOfArr)
{
    for (int i = 0; i < sizeOfArr; i++)
    {
        for (int j = i; j < sizeOfArr; j++)
        {
            if (arrEdge[i]->weight > arrEdge[j]->weight)
            {
                edge *temp = arrEdge[j];
                arrEdge[j] = arrEdge[i];
                arrEdge[i] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    FILE *fp_r, *fp_w;
    fp_r = fopen(argv[1], "r");
    fp_w = fopen("mst.txt", "w");
    int u, v, w;
    int numberOfEdges = 0;
    int size = -1;
    while (fscanf(fp_r, "%d %d %d\n", &u, &v, &w) != EOF)
    {
        if (u > size)
            size = u;
        if (v > size)
            size = v;
        numberOfEdges++;
    }
    fseek(fp_r, 0, SEEK_SET);
    printf("%d\n",size);
    vertice *arrVer[size + 1];
    size=size+1;
    for(int i=0;i<size;i++){
        arrVer[i]=NULL;
    }
    // for (int i = 0; i < size + 1; i++)
    // {
    //     vertice *newRoot;
    //     newRoot = malloc(sizeof(vertice));
    //     newRoot->next = NULL;
    //     newRoot->value = i;
    //     arrVer[i] = newRoot;
    // }
    edge *arrEdge[numberOfEdges];
    for(int i=0;i<numberOfEdges;i++){
        arrEdge[i]=NULL;
    }
    int l=0;
    while(fscanf(fp_r, "%d %d %d\n", &u, &v, &w) != EOF){
        edge *newEdge;
        newEdge = malloc(sizeof(edge));
        newEdge->v1 = u;
        newEdge->v2 = v;
        newEdge->weight = w;
        arrEdge[l] = newEdge;
        l++;
    }
    // for (int i = 0; fscanf(fp_r, "%d %d %d\n", &u, &v, &w) != EOF; i++)
    // {
    //     edge *newEdge;
    //     newEdge = malloc(sizeof(edge));
    //     newEdge->v1 = u;
    //     newEdge->v2 = v;
    //     newEdge->weight = w;
    //     arrEdge[i] = newEdge;
    // }
    // for(int i=0;i<numberOfEdges;i++){
    //     printf("%d %d %d\n",arrEdge[i]->v1,arrEdge[i]->v2,arrEdge[i]->weight);
    // }
    
    for(int i=0;i<size;i++){
        printf("%d ",i);
        for(int j=0;j<numberOfEdges;j++){
            if( i==arrEdge[j]->v1 || i==arrEdge[j]->v2 && arrVer[i]==NULL){
                vertice *newRoot;
                newRoot = malloc(sizeof(vertice));
                newRoot->next = NULL;
                newRoot->value = i;
                arrVer[i] = newRoot;
                printf("%d\n",i);
            }
        }
    }    
    sortEdgeArray(arrEdge, numberOfEdges);
    for(int i=0;i<size;i++){
        if(arrVer[i]!=NULL){
            printf("%d\n",arrVer[i]->value);
        }
    }

    //********************************************
    // for (int i = 0; i < numberOfEdges; i++)
    // {
    //     int v1, v2, w;
    //     v1 = arrEdge[i]->v1;
    //     v2 = arrEdge[i]->v2;
    //     w = arrEdge[i]->weight;
    //     fprintf(fp_w, "%d %d %d\n", v1, v2, w);
    // }
    //********************************************

    for (int i = 0; i < numberOfEdges; i++)
    {
        edge *currentEdge = arrEdge[i];
        int v1 = currentEdge->v1;
        int v2 = currentEdge->v2;
        int w = currentEdge->weight;
        // printf("%d %d %d\n",v1, v2,w);
        int storageV1 = arrVer[v1]->value;
        int storageV2 = arrVer[v2]->value;
        printf("%d %d\n",storageV1, storageV2);

        if (storageV1 != storageV2)
        {
            printf("%d %d %d\n", v1, v2, w);
            fprintf(fp_w, "%d %d %d\n", v1, v2, w);
            vertice *rootv1 = arrVer[storageV1];
            vertice *rootv2 = arrVer[storageV2];
            vertice *temprootv2 = arrVer[storageV2];
            while (rootv1->next != NULL)
            {
                rootv1 = rootv1->next;
            }
            rootv1->next=rootv2;
            rootv2=NULL;
            // while (temprootv2 != NULL)
            // {
            //     int val = temprootv2->value;
            //     vertice *newVertice;
            //     newVertice = malloc(sizeof(newVertice));
            //     newVertice->value = val;
            //     newVertice->next = NULL;
            //     rootv1->next = newVertice;
            //     temprootv2 = temprootv2->next;
            // }
            // while (rootv2 != NULL)
            // {
            //     arrVer[rootv2->value]->value = storageV1;
            //     rootv2 = rootv2->next;
            // }
        }
    }
    fclose(fp_w);
    fclose(fp_r);

    // ********************************************
    // fp_r = fopen("mst.txt", "r");
    // fp_w = fopen("mst1.txt", "r");
    // int a, b, c;
    // int x, y, z;
    // while (fscanf(fp_r, "%d %d %d\n", &a, &b, &c) != EOF && fscanf(fp_w, "%d %d %d\n", &x, &y, &z) != EOF)
    // {
    //     if (!((a == x && b == y) || (a == y && b == x)))
    //     {
    //         printf("ERROR");
    //     }
    // }
    // ********************************************

    return 0;
}
