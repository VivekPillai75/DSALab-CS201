#include<stdio.h>
#include<stdlib.h>

int isempty(int c1 ){
    if(c1==-1)
        return 1;

    return 0;
}
int isfull(int c1,int n){
    if(c1==n)
        return 1;

    return 0;
}

int push(int stack[],int *c1,int k,int n ){
        if(isfull(*c1,n)==1){
            printf("Stack is Full");
            return 0;
        }
        *c1++;
        stack[*c1]=k;
        return 0;
}

int pop(int stack[],int *c1){
        if(isempty(*c1)==1){
            printf("Stack is empty");
            return 0;
        }
        stack[*c1]=0;
        *c1--;
        return 0;
}

void toh (int n,int arr1[],int arr3[],int arr2[],int *p1,int *p2,int *p3,int l){
    if(n==1){
        printf("Push disk %d into rod %c",n,arr3);
        push(arr3,&p3,n,l);
        printf("Pop disk %d from rod %c",n,arr1);
        pop(arr1,&p1);
    }
    toh(n-1,arr1,arr2,arr3,&p1,&p2,&p3,l);
    printf("Push disk %d into rod %c",n,arr3);
    push(arr3,&p3,n,l);
    printf("Pop disk %d from rod %c",n,arr1);
    pop(arr1,&p1);
    toh(n-1,arr2,arr3,arr1,&p2,&p3,&p1,l);
}

int main(int argc , char* argv[]){

    FILE *fp;
    int n;
    n=atoi(argv[1]);
    int A[n],B[n],C[n];
    int p1=-1,p2=-1,p3=-1;
    for(int i=n;i>=1;i--){
    printf("Push disk %d to stack A",i);
    p1++;
    A[p1]=i;
    }
    toh(n,A,C,B,&p1,&p2,&p3,n);
}
