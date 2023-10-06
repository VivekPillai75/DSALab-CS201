#include <stdio.h>
#include <stdlib.h>

#define MAX 100000000

typedef struct edge{
    int src;
    int dest;
    int wt;
}edge;

typedef struct edgearray{
    edge arr[MAX];
    int n;
}edgearr;

typedef struct linkedlistnode{
    int vertex;
    struct linkedlistnode* next;
}llnode;

edgearr elist;

// void bubble_sort(){
//     int i,j;
//     edge temp;
//     for(i=1;i<elist.n;i++){
//         for(j=0;j<elist.n-1;j++){
//             if(elist.arr[j].wt>elist.arr[j+1].wt){
//                 temp=elist.arr[j];
//                 elist.arr[j]=elist.arr[j+1];
//                 elist.arr[j+1]=temp;
//             }
//         }
//     }
// }
int find(llnode array[],int vertexno){
    return array[vertexno].vertex;
}

// void unionFunc(llnode root[],llnode vertex1,llnode vertex2){
//     int l1 = (root+vertex1.vertex)->vertex;
//     int l2 = (root+vertex2.vertex)->vertex;
//     llnode *iter = (root+vertex2.vertex)->next;
//     (root+vertex1.vertex)->next = (root+vertex2.vertex)->next;
//     while (iter!=NULL)
//     {
//         (root+iter->vertex)->vertex=l1;
//         iter=iter->next;
//     }
//     (root+vertex2.vertex)->next=NULL;
//     return;
// }


void merge(edge L[],int ls,edge R[],int rs,edge A[]){
    int lf=0,rf=0;                                      //initialising index of left and right sequences
    for(int sb=0;sb<ls+rs;sb++){                    
        if(lf<ls && rf<rs){                             //when both sequences are non empty
            if(L[lf].wt<R[rf].wt){
                A[sb]=L[lf];lf++;                       //copying into sorted array
            }
            else{
                A[sb]=R[rf];rf++;
            } 
        }
        else if(lf<ls && rf>=rs){                                 //when only left sequence is non empty
            A[sb]=L[lf];lf++;
        }
        else if(lf>=ls && rf<rs){                                           //when only right sequence is non empty
            A[sb]=R[rf];rf++;
        }
    }
}

void mergesort(edge A[],int n){
    edge L[n/2],R[n-n/2];                                //dividing the original array into two smaller arrays
    for(int i=0;i<n/2;i++){
        L[i]=A[i];                                      //copying elements into left array
    }
    for(int i=0;i<n-n/2;i++){
        R[i]=A[i+n/2];                                  //copying elements into right array
    }
    mergesort(L,n/2);                                   //using recursion till we get single element array
    mergesort(R,n-n/2);                                 //using recursion till we get single element array
    merge(L,n/2,R,n-n/2,A);                             //merging to get a sorted array
}

// void kruskal(){
    
// }

// int find(llnode* array[],int vertexno){
//     return array[vertexno]->vertex;
// }

// void union1(int belongs[],int c1,int c2)
// {
// int i;
// for(i=0;i<max;i++)
// if(belongs[i]==c2)
// belongs[i]=c1;
// }

// void print(FILE *ptr,edgearr A){
//     for(int i=0;i<A.n;i++){
//         fprintf(ptr,"%d %d %d\n",A.arr[i].src,A.arr[i].dest,A.arr[i].wt);
//     }
// }

int main(int argc,char* argv[]){
    FILE *fread;
    fread = fopen(argv[1],"r");
    int u,v,w;
    elist.n = 0;
    while(fscanf(fread,"%d %d %d",&u,&v,&w)!=EOF){
        elist.arr[elist.n].src = u;
        elist.arr[elist.n].dest = v;
        elist.arr[elist.n].wt = w;
        elist.n++;
    }
    // bubble_sort();
    printf("saf");
    mergesort(elist.arr,elist.n);
    printf("%d\n",elist.n);
    for(int i=0;i<elist.n;i++){
        printf("%d %d %d\n",elist.arr[i].src,elist.arr[i].dest,elist.arr[i].wt);
    } 
    // FILE *fwrite;
    // fwrite = fopen("mst.txt","w");
    // int max=0;
    // for(int i=0;i<elist.n;i++){
    //     if(elist.arr[i].src>max) max = elist.arr[i].src;
    //     else if(elist.arr[i].dest>max) max = elist.arr[i].dest;
    // }
    
    // llnode vertices[max+1];
    // llnode root[max+1];
    
    // for(int i=0;i<max+1;i++){
    //     vertices[i].vertex = i;
    //     vertices[i].next = NULL;
    // }
    
    // for(int i=0;i<max+1;i++){ 
    //     root[i].vertex=i;
    //     root[i].next=(vertices+i);
    // }
    
    // edgearr spanlist;
    // spanlist.n = 0;
    // int first,second;
    // for(int i=0;i<elist.n;i++){
    //     first = find(root,elist.arr[i].src);
    //     second = find(root,elist.arr[i].dest);
    //     llnode vertex1 = vertices[first];
    //     llnode vertex2 = vertices[second];
    //     if(first != second && ((root+vertex1.vertex)->vertex)!=((root+vertex2.vertex)->vertex)){
    //         spanlist.arr[spanlist.n] = elist.arr[i];
    //         spanlist.n = spanlist.n+1;
    //         int l1 = (root+vertex1.vertex)->vertex;
    //         int l2 = (root+vertex2.vertex)->vertex;
    //         llnode *iter = (root+vertex2.vertex)->next;
    //         (root+vertex1.vertex)->next = (root+vertex2.vertex)->next;
    //         while (iter!=NULL)
    //         {
    //             (root+iter->vertex)->vertex=l1;
    //             iter=iter->next;
    //         }
    //         (root+vertex2.vertex)->next=NULL;          
    //     }
    // }
    
    // for(int i=0;i<spanlist.n;i++){
    //     fprintf(fwrite,"%d %d %d\n",spanlist.arr[i].src,spanlist.arr[i].dest,spanlist.arr[i].wt);
    // }
    
}