//I had help from Agrim Jain for the part pertaining to mergesort.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List
typedef struct ll
{
    int data;
    struct ll* next;
} ll;

//Inserting the vertex that is having an edge with another vertex
void ins(ll* ver[],int i){
    ll *temp = (ll *)malloc(sizeof(ll));
    temp->data=i;
    temp->next = NULL;
    ver[i]=temp;
    return;
}

//Search if the vertex is attached to another 
void sear(int arr1[],int arr2[],ll *ver[],int i,int k){
    for(int j=0;j<k;j++){
        if(arr1[j]==i || arr2[j]==i){
            ins(ver,i);
            break;
        }
    }
}

//Find the index at which a vertex is present in ver[] array
int find(int num,ll* ver[],int n){
    for(int i=0;i<n;i++){
        ll* temp=ver[i];
        while(temp!=NULL){
            if(temp->data==num){
                return i;
            }
            temp=temp->next;
        }
    }
    return 0;
}

//MergeSort Code for merging
//arr is we1
void merge1(int we1[],int ver1[],int ver2[], int l, int m, int h)
{
    int l1 = m - l + 1;
    int r1 = h - m;
    int *L=(int*) malloc(sizeof(int)*(l1));
    int *R=(int*) malloc(sizeof(int)*(r1));
    int *L1=(int*) malloc(sizeof(int)*(l1));
    int *R1=(int*) malloc(sizeof(int)*(r1));
    int *L2=(int*) malloc(sizeof(int)*(l1));
    int *R2=(int*) malloc(sizeof(int)*(r1));
    for (int i = 0; i < l1; i++)
    {
        L[i] = we1[l + i];
        L1[i] = ver1[l + i];
        L2[i] = ver2[l + i];
    }
    for (int j = 0; j < r1; j++)
    {
        R[j] = we1[m + 1 + j];
        R1[j] = ver1[m + 1 + j];
        R2[j] = ver2[m + 1 + j];
    }
    int a = 0, b = 0;
    int k = l;

    while (a < l1 && b < r1)
    {
        if (L[a] <= R[b])
        {
            we1[k] = L[a];
            ver1[k]=L1[a];
            ver2[k]=L2[a];
            a++;
            k++;
        }
        else
        {
            we1[k] = R[b];
            ver1[k]=R1[b];
            ver2[k]=R2[b];
            b++;
            k++;
        }
    }
    while (a < l1 && b >= r1)
    {
        we1[k] = L[a];
        ver1[k]=L1[a];
        ver2[k]=L2[a];
        k++;
        a++;
    }
    while (b < r1 && a >= l1)
    {
        we1[k] = R[b];
        ver1[k]=R1[b];
        ver2[k]=R2[b];
        k++;
        b++;
    }
}

//MergeSort code
void mergesort(int arr[],int ver1[],int ver2[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        mergesort(arr,ver1,ver2, l, m);
        mergesort(arr,ver1,ver2, m + 1, h);
        merge1(arr,ver1,ver2,l, m, h);
    }
}

//Swap Function
void swap(int *t,int *r){
    int k=*t;
    *t=*r;
    *r=k;
    return;
}

//Merge the set
void merge(int a,int b,ll *ver[]){
    ll* temp= ver[a];
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ver[b];
    ver[b]=NULL;
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

    char str[50];
    int k=0;
    while (fgets(str, 40, f))
    {
        k+=1;
    }
    fclose(f);
    
    //vertex 1
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
    //Weights of the edges
    int we1[k];
    for (int i = 0; i < k; i++)
    {
        we1[i] = -1;
    }
    FILE *p;
    p = fopen(argv[1], "r");
    if (p == NULL)
    {
        printf("FILE doesnt exist");
        return 0;
    }
    int v1,v2,w;
    int i=0;
    //Reading in the edges and their weights
    while (fscanf(p,"%d %d %d",&v1,&v2,&w)!=EOF)
    {
        ver1[i]=v1;
        ver2[i]=v2;
        we1[i]=w;
        i++;
    }
    //Sort the edges as per the weight
    mergesort(we1,ver1,ver2,0, k-1);

    //No. of Distinct vertices present having edges with others
    //Finding max
    int a=0;
    for(int i=0;i<k;i++){
        if(ver1[i]>a){
            a=ver1[i];
        }
    }
    for(int i=0;i<k;i++){
        if(ver2[i]>a){
            a=ver2[i];
        }
    }
    a+=1;
    //Create Linked list for edges
    ll *ver[a];
    for(int i=0;i<a;i++){
        ver[i]=NULL;
    }
    for(int i=0;i<a;i++){
        sear(ver1,ver2,ver,i,k);
    }
    FILE *q;
    q=fopen("mst.txt","w");
    for(int i=0;i<k;i++){
        int d,f;
        d=find(ver1[i],ver,a);
        f=find(ver2[i],ver,a);
        if(d!=f){
            fprintf(q,"%d %d %d\n",ver1[i],ver2[i],we1[i]);
            int l,s;
            if(d>f){
                l=d;
                s=f;
            }else{
                l=f;
                s=d;
            }
            merge(l,s,ver);
        }
    }
    fclose(q);
    fclose(p);
    return 0;
}






