#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    char data[50];
    struct list *next;
} list;

// Initializing the hash table to NULL
void ini(list *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = NULL;
    }
}

// To add Elements to the hash table
void hashing(list *arr[], int sum, int n, char str[])
{
    sum -= 10;
    int k = sum % n;
    list *new = (list *)malloc(sizeof(list));
    strcpy(new->data, str);
    new->next = NULL;
    if (arr[k] == NULL)
    {
        arr[k] = new;
    }
    else
    {
        new->next = arr[k];
        arr[k] = new;
    }
    return;
}

// To check if 2 strings are Anagrams
// We sort the strings and then compare them.
// If they are equal then they are anagrams
int check(char x[], char y[])
{
    char str[100];
    strcpy(str, x);
    char s[100];
    strcpy(s, y);

    char temp;
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    char temp1;
    int a = strlen(s);
    for (int i = 0; i < a - 1; i++)
    {
        for (int j = i + 1; j < a; j++)
        {
            if (s[i] > s[j])
            {
                temp1 = s[i];
                s[i] = s[j];
                s[j] = temp1;
            }
        }
    }

    if (strcmp(s, str) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Prints the anagrams of a word from the existing Hash Table
void ana(list *arr[], char str[], int sum, int n, FILE *p)
{
    sum -= 10;
    int k = sum % n;

    if (arr[k] == NULL)
    {
        fprintf(p, "\n");
    }
    else
    {
        list *temp = arr[k];
        int c =0;
        while (temp != NULL)
        {
            int i;
            i = check(temp->data, str);
            if (i == 1)
            {
                char a[100];
                strcpy(a, temp->data);
                a[strcspn(a, "\n")] = 0;
                fprintf(p, "%s ", a);
                temp = temp->next;
                c=1;
            }
            else if (i == 0)
            {
                temp = temp->next;
            }
        }
        if(c==1){
        	fseek(p, -1, SEEK_CUR);
        	fprintf(p, "\n");        
        }else{
        	fprintf(p, "\n");
        }
    }
}

// Main Function
int main(int argc, char *argv[])
{
    int q = atoi(argv[2]);
    // Hash Table
    list *arr[q];
    ini(arr, q);
    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("FILE doesnt exist");
        return 0;
    }

    char str[40];

    while (fgets(str, 40, f))
    {
        int m = 0;
        int sum = 0;
        int k = strlen(str);
        for (int i = 0; i < k; i++)
        {
            sum += str[i];
        }
        hashing(arr, sum, q, str);
    }
    fclose(f);

    f = fopen(argv[3], "r");
    if (f == NULL)
    {
        printf("FILE doesnt exist");
        return 0;
    }

    FILE *p;
    p = fopen("anagrams.txt", "w");
    char st[40];

    while (fgets(st, 40, f))
    {
        int m = 0;
        int sum = 0;
        int k = strlen(st);
        for (int i = 0; i < k; i++)
        {
            sum += st[i];
        }
        ana(arr, st, sum, q, p);
    }

    fclose(p);
    fclose(f);

    return 0;
}

typedef struct node { 
    int data; 
    struct node *next; 
}node;
node *hash[m];


void insert(int data, int m)
{
    int k = data % m;
    node *new = (node *)malloc(sizeof(node));
    new->data =data;
    new->next = NULL;
    if(hash[k]==NULL){
        hash[k]=new;
    }else{
    new->next=hash[k];
    hash[k]=new;
    }
    return;
}

void delete(int data,int m){
    int k = data % m;
    if(hash[k]==NULL){
        printf("Element not found");
    }
    node * temp;
    node * pred=NULL;
    temp=hash[k];
    while((temp!=NULL) && (temp->data!=data)){
        pred=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Element not found");
    }else{
        pred->next=temp->next;
        free(temp);
        printf("%d deleted",data);
    }
    return
}

void search(int data,int m){
    k=data%m;
    node *temp =NULL;
    while(temp!=NULL){
        if(temp->data==data){
            printf("%d is present",data);
            return;
        }
        temp=temp->next;
    }
    return;
}
























