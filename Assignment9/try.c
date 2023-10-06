//I had help from Agrim Jain for the 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void merge1(int arr[], int l, int m, int h)
{
    int l1 = m - l + 1;
    int r1 = h - m;
    int L[l1];
    int R[r1];
    for (int i = 0; i < l1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < r1; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    int a = 0, b = 0;
    int k = l;

    while (a < l1 && b < r1)
    {
        if (L[a] <= R[b])
        {
            arr[k] = L[a];
            a++;
            k++;
        }
        else
        {
            arr[k] = R[b];
            b++;
            k++;
        }
    }
    while (a < l1 && b >= r1)
    {
        arr[k] = L[a];
        k++;
        a++;
    }
    while (b < r1 && a >= l1)
    {
        arr[k] = R[b];
        k++;
        b++;
    }
}

void mergesort(int arr[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, h);
        merge1(arr, l, m, h);
    }
}

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
    // printf("lol");
    
    //vertex 1
    int ver1[k];
    // int finver1[k];
    for (int i = 0; i < k; i++)
    {
        ver1[i] = -1;
        // finver1[i]=-1;
    }
    // printf("lol1");
    // vertex 2
    int ver2[k];
    // int finver2[k];
    for (int i = 0; i < k; i++)
    {
        ver2[i] = -1;
        // finver2[i]=-1;
    }
    // printf("lol2");
    //Weights of the edges
    int we[k];
    int we1[k];
    for (int i = 0; i < k; i++)
    {
        we[i] = -1;
        we1[i]=-1;
    }
    // printf("lol3");
    // int we1[k];
    // for (int j = 0; j < k; j++)
    // {

    //     we1[j] = -1;
    // }
    // printf("lol4");
    FILE *p;
    p = fopen(argv[1], "r");
    if (p == NULL)
    {
        printf("FILE doesnt exist");
        return 0;
    }
    // printf("lol5");
    int v1,v2,w;
    int i=0;
    // printf("lol6");
    while (fscanf(p,"%d %d %d",&v1,&v2,&w)!=EOF)
    {
        ver1[i]=v1;
        ver2[i]=v2;
        we[i]=w;
        we1[i]=w;
        i++;
    }
    // printf("lol7");
    // printf("%d",k);
    //Sort the edges as per their weights
    // for(int j=0;j<k;j++){
    //     for(int l=j+1;l<k;l++){
    //         if(we[j]>we[l]){
    //             int r=we[j];
    //             we[j]=we[l];
    //             we[l]=r;

    //             r=ver1[j];
    //             ver1[j]=ver1[l];
    //             ver1[l]=r;

    //             r=ver2[j];
    //             ver2[j]=ver2[l];
    //             ver2[l]=r;
    //         }
    //     }
    // }

    // printf("lol5");
    // int finver1[k];
    // int finver2[k];
    // printf("lol");
    mergesort(we1, 0, k-1);
    // printf("lol");

    int l=0;
    int temp1=0,temp2=0;
    clock_t x=clock();
    for(int i=0; i<k; i++){
        if(l==k){
            break;
        }
        if (we1[l]==we[i]){
            int *p1=&ver1[i];
            int *p2=&ver1[l];
            swap(p1,p2);
            int *q1=&ver2[i];
            int *q2=&ver2[l];
            swap(q1,q2);
            int *r1=&we[i];
            int *r2=&we[l];
            swap(r1,r2);
            l++;
            i=0;
        }
    }
    clock_t y=clock();
    printf("%f",((double)y-x)/CLOCKS_PER_SEC);


    // for(int c=0;c<k;c++){
    //     for(int j=0;j<k;j++){
    //         if(we1[c]==we[j]){
    //             // finver1[c]=ver1[j];
    //             // finver2[c]=ver2[j];
    //             int *p1=&ver1[i];
    //         int *p2=&ver1[c];
    //         swap(p1,p2);
    //         int *q1=&ver2[i];
    //         int *q2=&ver2[c];
    //         swap(q1,q2);
    //         }
    //     }
    // }
    // printf("lol");

    // for(int i=0;i<k;i++){
    //     printf("%d\n",we[i]);
    // }

    //No. of Distinct vertices present having edges with others
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