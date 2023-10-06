#include <stdio.h>
#include <stdlib.h>

void push(int stack[], int *c1, int k){
    *c1++;
    stack[*c1] = k;
}

void pop(int stack[], int *c1){
    stack[*c1] = 0;
    *c1--;
}

void toh(int n, int arr1[], int arr3[], int arr2[], int *p1, int *p2, int *p3, char A, char C, char B)
{
    if (n == 1)
    {
        printf("Pop disk %d from rod %c \n", n, A);
        pop(arr1, p1);
        printf("Push disk %d into rod %c \n", n, C);
        push(arr3, p3, n);
        return;
    }
    toh(n - 1, arr1, arr2, arr3, p1, p2, p3, A, B, C);
    printf("Pop disk %d from rod %c \n", n, A);
    pop(arr1, p1);
    printf("Push disk %d into rod %c \n", n, C);
    push(arr3, p3, n);
    toh(n - 1, arr2, arr3, arr1, p2, p3, p1, B, C, A);
    return;
}

int main()
{

    // FILE *fp;
    // int n;
    // n=atoi(argv[1]);
    int n = 3;
    int A[n], B[n], C[n];
    int p1 = -1, p2 = -1, p3 = -1;
    int *c1 = &p1;
    int *c2 = &p2;
    int *c3 = &p3;
    for (int i = n; i >= 1; i--)
    {
        printf("Push disk %d to stack A \n", i);
        p1++;
        A[p1] = i;
    }
    char a = 'A';
    char b = 'B';
    char c = 'C';
    toh(n, A, C, B, c1, c2, c3,a,c, b);
}
