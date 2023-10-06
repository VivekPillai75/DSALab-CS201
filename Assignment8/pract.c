#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graph
{
    int pred;
    char color;
    int data;
    int dis;
    struct graph *next;
} graph;

void insert(int m, int n, graph *arr[])
{
    graph *temp = (graph *)malloc(sizeof(graph));
    temp->pred = -1;
    temp->color = 'w';
    temp->data = n;
    temp->dis = 0;
    temp->next = NULL;
    if (arr[m] == NULL)
    {
        arr[m] = temp;
    }
    else
    {
        temp->next = arr[m];
        arr[m] = temp;
    }
    graph *temp1 = (graph *)malloc(sizeof(graph));
    temp1->pred = -1;
    temp1->color = 'w';
    temp1->data = m;
    temp1->dis = 0;
    temp1->next = NULL;
    if (arr[n] == NULL)
    {
        arr[n] = temp1;
    }
    else
    {
        temp1->next = arr[n];
        arr[n] = temp1;
    }
}

// Main Function
int main(int argc, char *argv[])
{
    printf("lol");
    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("FILE doesnt exist");
        return 0;
    }

    char str[40];
    printf("lol");
    int r = 0;
    int l;
    int n;
    if(fgets(str, 40, f)){
        int k = strlen(str);
            int m = 0;
            char a[40];
            char b[40];
            int j = 0;
            for (int i = 0; i < k; i++)
            {
                if (str[i] != ' ')
                {
                    a[i] = str[i];
                }
                if (str[i] == ' ')
                {
                    m = 1;
                }
                if (m)
                {
                    b[j] = str[i];
                    j++;
                }
            }
            l = atoi(a);
            n = atoi(b);
    }
    graph *arr[l];
        for (int i = 0; i < l; i++)
        {
            arr[i] = NULL;
        }
    while (fgets(str, 40, f))
    {       
            if(r==0){
                r=1;
                break;
            }
            int k = strlen(str);
            int m = 0;
            char a[40];
            char b[40];
            int j = 0;
            for (int i = 0; i < k; i++)
            {
                if (str[i] != ' ')
                {
                    a[i] = str[i];
                }
                if (str[i] == ' ')
                {
                    m = 1;
                }
                if (m)
                {
                    b[j] = str[i];
                    j++;
                }
            }
            int l = atoi(a);
            int n = atoi(b);
            insert(l, n, arr);
    }

    fclose(f);
    printf("lol");
    for(int i=0;i<l;i++){
        graph* temp;
        temp=arr[i];
        while(temp!=NULL){
            printf("%d ",temp->data);
        printf("\n");
    }
    }

    return 0;
}