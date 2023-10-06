// The code takes more than 40 seconds to execute for input3.graph. I believe it is due to the fact that the number of vertices are greater than 5300. 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

typedef struct linked{
    int data;
    struct linked *next;
}linked;

void insert(linked *ptr[], int data) { // insert in linked list
    linked* newnode = (linked*)malloc (sizeof (linked));
    newnode->data = data;
    newnode->next = NULL;
    ptr[data]=newnode;
    return;
}

int search(int arr1[], int arr2[], int index, int ct){ // search for element in both arrays of vertices
    int x=0;
    int count=0;
    for(x=0; x<ct; x++){
        if(arr1[x]==index && count==0){
            count+=1;
            break;
        }
    }
    for(x=0; x<ct; x++){
        if(arr2[x]==index && count==0){
            count+=1;
            break;
        }
    }
    return count;
}

int findindex(int ctr, linked *ptr[], int m){ // find the index at which a vertex is placed
    int i=0;
    for(i=0;i<m;i++){
        linked *p= ptr[i];
        while(p!=NULL){
            if (ctr==p->data){
                return i;
            }
            p=p->next;
        }
    }
    return 0;
}

void merge(linked *ptr[], int a, int b){ // merging the linked lists after finding a connection between the two
    linked *p= ptr[a];
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr[b];
    ptr[b]=NULL;
    return;
}

// void merge1(int arr[], int l, int m, int h){
//     int l1 = m - l + 1;
//     int r1 = h - m;
//     int L[l1];
//     int R[r1];
//     for (int i = 0; i < l1; i++){
//         L[i] = arr[l + i];
//     }
//     for (int j = 0; j < r1; j++){
//         R[j] = arr[m + 1 + j];
//     }
//     int a = 0, b = 0;
//     int k = l;

//     while (a < l1 && b < r1){
//         if (L[a] <= R[b]){
//             arr[k] = L[a];
//             a++;
//             k++;
//         }
//         else{
//             arr[k] = R[b];
//             b++;
//             k++;
//         }
//     }
//     while (a < l1 && b >= r1){
//         arr[k] = L[a];
//         k++;
//         a++;
//     }
//     while (b < r1 && a >= l1){
//         arr[k] = R[b];
//         k++;
//         b++;
//     }
// }

// void mergesort(int arr[], int l, int h){
//     if (l < h){
//         int m = (l + h) / 2;
//         mergesort(arr, l, m);
//         mergesort(arr, m + 1, h);
//         merge1(arr, l, m, h);
//     }
// }

void mergesort(int *fh, int len1, int *sh, int len2, int *a, int fhv1[], int fhv2[], int shv1[], int shv2[], int v1[], int v2[]){ // merge two sorted arrays
    int ctr1=0, ctr2=0, i=0; // ctr1 is for first half(fh) array
    // ctr2 is for second half(sh) array
    // i is counter for merged array that will be formed
    while(i < (len1+len2)){
        if(ctr1<len1 && ctr2<len2){ // both first half and second half are non empty
            if(fh[ctr1] < sh[ctr2]){ 
                a[i] = fh[ctr1];
                v1[i]=fhv1[ctr1];
                v2[i]=fhv2[ctr1]; 
                ctr1+=1;
            }
            else{ 
                a[i] = sh[ctr2]; 
                v1[i]=shv1[ctr2];
                v2[i]=shv2[ctr2]; 
                ctr2+=1;
            }
        }
        else if(ctr1 < len1){ // elements left in first half only
            a[i] = fh[ctr1]; 
            v1[i]=fhv1[ctr1];
            v2[i]=fhv2[ctr1];
            ctr1+=1;
        }
        else{ // elements left in second half only
            a[i] = sh[ctr2]; 
            v1[i]=shv1[ctr2];
            v2[i]=shv2[ctr2];
            ctr2+=1;
        }
        i+=1;
    }
}

void sort(int *a, int len, int v1[], int v2[]){ // Sorts array "a" of length 'len'
    if(len==1){
        return;
    }
    int *fh = (int*) malloc(sizeof(int)*(len/2)); // creating 2 arrays to store first half and second half
    int *sh = (int*) malloc(sizeof(int)*(len-len/2)); 
    int *fhv1 = (int*) malloc(sizeof(int)*(len/2)); // creating 2 arrays to store first half and second half
    int *shv1 = (int*) malloc(sizeof(int)*(len-len/2)); 
    int *fhv2 = (int*) malloc(sizeof(int)*(len/2)); // creating 2 arrays to store first half and second half
    int *shv2 = (int*) malloc(sizeof(int)*(len-len/2)); 
    for(int i=0; i<len/2; i++){ // first half
        fh[i]=a[i];
        fhv1[i]=v1[i];
        fhv2[i]=v2[i];
    } 
    for(int j=0; j<len-len/2; j++){ // second half
        int k=j+len/2; // 0 to (len/2)-1 are for first half
        sh[j]=a[k]; 
        shv1[j]=v1[k];
        shv2[j]=v2[k];
    }
    sort(fh,len/2,fhv1,fhv2);
    sort(sh,len-len/2,shv1,shv2);
    mergesort(fh, len/2, sh, len-len/2, a,fhv1,fhv2,shv1,shv2,v1,v2); // joining the two halves into original array 'a'
    free(fh);
    free(sh);
}


int main(int argc,char* input[]){
    FILE *f, *out;
    char words[100];
    int one,two,weigh;
    f = fopen(input[1],"r");
    out = fopen("mst.txt","w");
    int ctr=0;
    while(fgets(words,sizeof(words),f)){
        ctr+=1;
    }
    int v1[ctr],v2[ctr],wt[ctr];
    fclose(f);
    f = fopen(input[1],"r");
    int c=0;
    int i=0;
    while(fscanf(f,"%d %d %d",&one,&two,&weigh)!=EOF){
        v1[c]=one;
        v2[c]=two;
        wt[c]=weigh;
        c+=1;
    }
    sort(wt,ctr,v1,v2);

    int max=0;
    for(i=0;i<ctr;i++){
        if(v1[i]>max){
            max=v1[i];
        }
    }
    for(i=0;i<ctr;i++){
        if(v2[i]>max){
            max=v1[i];
        }
    }
    max+=1;
    linked *arr[max];
    for(i=0;i<max;i++){
        arr[i]=NULL;
    }
    for(i=0;i<max;i++){
        int exist = search(v1,v2,i,ctr);
        if(exist){
            insert(arr,i);
        }
    }
    for(i=0;i<ctr;i++){ // Kruskal Algorithm 
        if(!(findindex(v1[i],arr,max)==findindex(v2[i],arr,max))){
            fprintf(out,"%d %d %d\n",v1[i],v2[i],wt[i]);
            merge(arr,findindex(v1[i],arr,max),findindex(v2[i],arr,max));
        }
    }
    fclose(f);
    fclose(out);
}