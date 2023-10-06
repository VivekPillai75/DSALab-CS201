#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[100];

int size = -1;

void print()
{
    for (int i = 0; i <= size; i++)
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
void heapify(int arr[], int i, int n)
{

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int largest = i;

    if (left >= n && right >= n)
    {
        return;
    }

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    else if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, largest, n);
        // heapify(arr, right, n);
    }

    return;
}

void insert(int k /*,FILE *f*/)
{
    // printf("insert\n");
    size += 1;
    arr[size] = k;

    for (int i = (size + 1) / 2; i >= 1; i--)
    {
        heapify(arr, i, size + 1);
    }

    printf("%d inserted\n", k);
    // fprintf(f, "%d inserted\n\n", k);

    // print();
    // printf("\n\n");
    return;
}

void max(/*,FILE* f */)
{
    // printf("maximum\n");
    if (size == -1)
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
    // printf("extract max\n");
    if (size == -1)
    {
        /*fprintf(f,"\n");*/
        // print();
        // printf("\n");
        printf("\n");
    }
    else
    {
        printf("%d\n", arr[0]);
        arr[0] = arr[size];
        size -= 1;
        heapify(arr, 0, size + 1);
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
        printf("Key at %d changed to %d\n", i, k);
    }
    // print();
    // printf("\n\n");
    return;
}

void sort()
{
    // // printf("sort\n");
    int arr1[size + 1];
    for (int i = 0; i < size; i++)
    {
        arr1[i] = arr[i];
    }
    int sz = size;

    for (int i = 0; i < size + 1; i++)
    {
        swap(&arr1[0], &arr1[sz]);
        sz -= 1;
        heapify(arr1, 0, sz + 1);
    }

    for (int i = 0; i <= size; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    // print();
    // printf("\n\n");

    // printf("\n");
    return;
}

// INT MAIN

int main(int argc, char *argv[])
{
    for (int i = 0; i < 100; i++)
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

void heapify(int size, int i)
{
    if (size == 1)
    {
        return;
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] > array[largest])
            largest = l;
        if (r < size && array[r] > array[largest])
            largest = r;
        if (largest != i)
        {
            swap(&array[i], &array[largest]);
            heapify(array, size, largest);
        }
    }
    return;
}

void insert(int array[], int newNum)
{
    if (size == 0)
    {
        array[0] = newNum;
        size += 1;
    }
    else
    {
        array[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(array, size, i);
        }
    }
}

// Max-Heap data structure in C

#include <stdio.h>
int size = 0;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(int array[], int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] > array[largest])
            largest = l;
        if (r < size && array[r] > array[largest])
            largest = r;
        if (largest != i)
        {
            swap(&array[i], &array[largest]);
            heapify(array, size, largest);
        }
    }
}
void insert(int array[], int newNum)
{
    if (size == 0)
    {
        array[0] = newNum;
        size += 1;
    }
    else
    {
        array[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(array, size, i);
        }
    }
}
void delete(int num)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == array[i])
            break;
    }
    swap(&array[i], &array[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }
}

void peek(int size){
    if(size==0)
        return;
    else{
        printf("%d",array[0])
    }
}

