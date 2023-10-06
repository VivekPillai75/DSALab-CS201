#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int h)
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
        merge(arr, l, m, h);
    }
}

int main(int argc, char *argv[])
{
    FILE *fp;
    int n;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("File doesnt exist");
        return 0;
    }
    int c = 0;

    while (fscanf(fp, "%d", &n) != EOF)
    {
        c++;
    }

    fclose(fp);

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("File doesnt exist");
        return 0;
    }

    int i = 0;
    int arr[c];
    while (fscanf(fp, "%d", &n) != EOF)
    {
        arr[i] = n;
        i++;
    }
    fclose(fp);

    mergesort(arr, 0, c - 1);

    fp = fopen("mergesort.txt", "w");
    for (int i = 0; i < c; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
    return 0;
}


int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int k = partition(array, low, high);
        quickSort(array, low, k - 1);
        quickSort(array, k + 1, high);
    }
}











