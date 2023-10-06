#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[70];
int size=0;

void print()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void heapify(int arr[], int N, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, N, largest);
    }
}

void buildHeap(int arr[], int N)
{
    // Index of last non-leaf node
    int startIdx = (N / 2) - 1;
 
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, N, i);
    }
}

void insert(int k /*,FILE *f*/)
{
    // printf("insert\n");
    arr[size] = k;
    size += 1;

    buildHeap(arr,size);

    printf("%d inserted\n", k);
    // fprintf(f, "%d inserted\n\n", k);

    // print();
    // printf("\n");

    return;
}

void max(/*,FILE* f */)
{
    // printf("maximum\n");
    if (size == 0)
    {
        /*fprintf(f,"\n");*/
        // print();
        printf("\n");
        // printf("\n");
        return;
    }
    else
    {
        printf("%d\n", arr[0]);
    }
    // print();
    // printf("\n\n");
    return;
}

void extmax()
{
    // // printf("extract max\n");
    if (size == 0)
    {
        /*fprintf(f,"\n");*/
        // print();
        // printf("\n");
        printf("\n");
    }
    else
    {
        printf("%d\n", arr[0]);
        arr[0] = arr[size-1];
        size -= 1;
        buildHeap(arr,size);
    }
    // print();
    // printf("\n\n");
    return;
}

void inckey(int i, int k)
{
    // printf("inserted at\n");
    if (arr[i] > k)
    {
        printf("%d is less than the current key at %d\n", k, i);
        // print();
        // printf("\n\n");
        // return;
    }
    else if (arr[i] < k)
    {
        arr[i] = k;
        buildHeap(arr,size);
        printf("Key at %d changed to %d\n", i, k);
    }
    // print();
    // printf("\n\n");
    return;
}


// void sort()
// {
//     // // printf("sort\n");
//     int arr1[size + 1];
//     for (int i = 0; i < size; i++)
//     {
//         arr1[i] = arr[i];
//     }
//     int sz = size;

//     for (int i = 0; i < size + 1; i++)
//     {
//         swap(&arr1[0], &arr1[sz]);
//         sz -= 1;
//         heapify(arr1, 0, sz + 1);
//     }

//     for (int i = 0; i <= size; i++)
//     {
//         printf("%d ", arr1[i]);
//     }
//     printf("\n");
//     // print();
//     // printf("\n\n");

//     // printf("\n");
//     return;
// }

void heapSort(int arr[], int N)
{

	// Build max heap
	for (int i = N / 2 - 1; i >= 0; i--)

		heapify(arr, N, i);

	// Heap sort
	for (int i = N - 1; i >= 0; i--) {

		swap(&arr[0], &arr[i]);

		// Heapify root element to get highest element at
		// root again
		heapify(arr, i, 0);
	}
}

void Sort(){
    int arr1[size];
    for(int i=0;i<=size;i++){
        arr1[i]=arr[i];
    }
}


void sort()
{
    int N=size;
    int arr1[N];
    for(int i=0;i<N;i++){
        arr1[i]=arr[i];
    }
    // for(int i=0;i<N;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");
    // for(int i=0;i<N;i++){
    //     printf("%d ",arr1[i]);
    // }
    // printf("\n");

 
    // // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--){
        heapify(arr1, N, i);
    }

    
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
 
        swap(&arr1[0], &arr1[i]);
        heapify(arr1, i, 0);
    }
    // for(int i=0;i<N;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");
    for(int i=0;i<N;i++){
        printf("%d ",arr1[i]);
    }
    printf("\n");

    // for(int i=1;i<=N;i++){
    //     printf("%d ",arr1[i]);
    // // }
    // printf("\n");
}







// INT MAIN

int main(int argc, char *argv[])
{
    for (int i = 0; i < 70; i++)
    {
        arr[i] = -1;
    }

    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("FILE doesnt exist");
        return 0;
    }

    char str[40];
    // FILE *fip;
    // fip = fopen("bst.txt", "w");
    // Reading the value from the text
    while (fgets(str, 40, f))
    {
        int k = strlen(str);
        char a[20] = "";
        char b[10] = "";
        char c[10] = "";
        int p = 0;
        int q = 0;
        int i = 0;
        int m = 0;
        for (; i < k; i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z' || str[i] == '-')
            {
                a[i] = str[i];
            }
            else if (str[i] == ' ' && m == 0)
            {
                a[i] = '\0';
                m = 1;
            }
            else if (str[i] >= '0' && str[i] <= '9' && m == 1)
            {
                b[p] = str[i];
                p++;
            }
            else if (str[i] == ' ' && m == 1)
            {
                b[p] = '\0';
                m = 2;
            }
            else if (str[i] >= '0' && str[i] <= '9')
            {
                c[q] = str[i];
                q++;
            }
            else if (str[i] == ' ' && m == 2)
            {
                c[q] = '\0';
            }
        }

        //     char a[20] = "";
        // char nu[10] = "";
        // int p = 0;
        // for (int i = 0; i < k; i++)
        // {
        //     if (str[i] >= 'a' && str[i] <= 'z')
        //     {
        //         a[i] = str[i];
        //     }
        //     else if (str[i] == ' ')
        //     {
        //         a[i] = '\0';
        //     }
        //     else if (str[i] >= '0' && str[i] <= '9')
        //     {
        //         nu[p] = str[i];
        //         p++;
        //     }
        // }

        int num1 = atoi(b);
        int num2 = atoi(c);
        // printf("%s\n", a);
        if (!strcmp("insert", a))
        {
            insert(num1);
        }
        else if (!strcmp("maximum", a))
        {
            max();
            // fprintf(fip, "\n");
        }
        else if (!strcmp("extract-max", a))
        {
            extmax();
            // fprintf(fip, "\n");
        }
        else if (!strcmp("increase-key", a))
        {
            inckey(num1, num2);
            // fprintf(fip, "\n");
        }
        else if (!strcmp("sort", a))
        {
            sort();
            // max(fip);
        }
    }
    fclose(f);
    return 0;
}