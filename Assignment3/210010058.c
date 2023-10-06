#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int po(int x, int y)
{
    int j = 1;
    for (int i = 1; i <= y; i++)
    {
        j = j * x;
    }
    return j;
}

void sort(int arr[], int digno[], int digctr[], int dig, int ctr)
{
    int finArr[ctr];
    for (int i = ctr - 1; i >= 0; i--)
    {
        finArr[digctr[digno[i]] - 1] = arr[i];
        digctr[digno[i]]--;
    }
    for (int i = 0; i < ctr; i++)
    {
        arr[i] = finArr[i];
    }
    return;
}

void countSort(int arr[], int dig, int ctr)
{
    int digno[ctr];
    for (int i = 0; i < ctr; i++)
    {
        digno[i] = ((arr[i] % (po(10, dig))) - (arr[i] % (po(10, dig - 1)))) / (po(10, dig - 1));
    }
    int digctr[10];
    for (int i = 0; i < 10; i++)
    {
        digctr[i] = 0;
    }
    for (int i = 0; i < ctr; i++)
    {
        digctr[digno[i]]++;
    }
    for (int i = 1; i < 10; i++)
    {
        digctr[i] = digctr[i] + digctr[i - 1];
    }
    sort(arr, digno, digctr, dig, ctr);
}

void radixsort(int arr[], int dig, int ctr)
{
    for (int i = 1; i <= dig; i++)
        countSort(arr, i, ctr);
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
    int l = atoi(argv[2]);
    radixsort(arr, l, c);

    fp = fopen("radix.txt", "w");
    for (int i = 0; i < c; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
    return 0;
}
