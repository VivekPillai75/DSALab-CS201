#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *fp;
    int n;
    fp = fopen(argv[1], "r");
    if (fp = NULL)
    {
        printf("File doesnt exist");
        exit(0);
    }
    int count = 0;
    int sum = 0;
    int min;
    int max;

    fscanf(fp, "%d", &min);

    max = min;

    while (fscanf(fp, "%d", &n) != EOF)
    {
        count++;
        sum += n;
        if (min > n)
            min = n;
        if (max < n)
            max = n;
    }
    float avg = (1.0) * (sum / count);
    fclose(fp);
    fp = fopen(argv[2], "w");
    printf("The no. of elements : %d\n", &count);
    printf("Minimum of all elements: %d\n", &min);
    printf("Maximum of all elements : %d\n", &max);
    printf("Sum of all elements : %d\n", &sum);
    printf("Average of all elements : %0.2f\n", &avg);

    fclose(fp);
    return 0;
}
