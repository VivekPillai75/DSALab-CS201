#include <stdio.h>
#include <stdlib.h>

// While writing the code I had help from my classmates, Mandar Deshpande and Agrim Jain. Mandar helped me
// in solving an error while printing the solution in the text file toh.txt. Agrim helped me in realizing an
// error in my stack implementation.

void push(int stack[], int *c1, int k, int n)
{
    if (*c1 == n - 1) // overflow check
    {
        printf("The stack is Full \n");
    }
    stack[*c1] = k;
    *c1++;
}

void pop(int stack[], int *c1)
{
    if (*c1 == -1) // underflow check
    {
        printf("The stack is Empty \n");
    }
    stack[*c1] = 0;
    *c1--;
}

void toh(int n, int arr1[], int arr3[], int arr2[], int *p1, int *p2, int *p3, char A, char C, char B, int l, FILE *ptr1)
{
    if (n == 1)
    {
        fprintf(ptr1, "Pop disk %d from stack %c \n", n, A);
        pop(arr1, p1);
        fprintf(ptr1, "Push disk %d to stack %c \n", n, C);
        push(arr3, p3, n, l);
        return;
    }
    toh(n - 1, arr1, arr2, arr3, p1, p2, p3, A, B, C, l, ptr1);
    fprintf(ptr1, "Pop disk %d from stack %c \n", n, A);
    pop(arr1, p1);
    fprintf(ptr1, "Push disk %d to stack %c \n", n, C);
    push(arr3, p3, n, l);
    toh(n - 1, arr2, arr3, arr1, p2, p3, p1, B, C, A, l, ptr1);
    return;
}

int main(int argc, char *argv[])
{

    FILE *fp;
    fp = fopen("toh.txt", "w");
    int n;
    n = atoi(argv[1]);
    int A[n], B[n], C[n];
    int p1 = 0, p2 = 0, p3 = 0;
    int *c1 = &p1;
    int *c2 = &p2;
    int *c3 = &p3;
    for (int i = n; i >= 1; i--)
    {
        fprintf(fp, "Push disk %d to stack A \n", i);
        push(A, c1, i, n);
    }
    char a = 'A';
    char b = 'B';
    char c = 'C';
    toh(n, A, C, B, c1, c2, c3, a, c, b, n, fp);
}