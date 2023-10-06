#include<stdio>
#include<stdlib>

bool isempty(int c1 ){
    if(c1==-1)
        return 1;

    return 0;
}
bool isfull(int c1,int n){
    if(c1==n)
        return 1;

    return 0;
}


int push(int stack[],int &c1,int k ){
        if(isfull==1){
            printf("Stack is Full");
            return 0;
        }
        c1++;
        stack[c1]=k;
        printf("")
        return 0;
}


int pop(int stack[],int &c1){
        if(isempty==-1){
            printf("Stack is empty");
            return 0;
        }
        stack[c1]=0;
        c1--;
        return 0;
}

int toh(int n,int arr1[],int arr3[],int arr2[]){
    if(n==1){
        push(arr3,,n)
        pop(arr1,)
    }
    toh(n-1,arr1,arr2,arr3);
    push(arr3,,n)
    pop(arr1,)
    toh(n-1,arr2,arr3,arr1);

}

int main(int argc , char* argv[]){

    FILE *fp;
    int n;
    n=argv[1];
    int arr1[n],arr2[n],arr3[n];

    for(int i=n;i>=1;i--){
    printf("Push disk %d to stack A",i);
    arr[p1]=i;
    p1++;
    }

    toh(n,arr1,arr3,arr2);




}
