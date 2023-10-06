// I took help from Mandar Deshpande in implementing a part of the predecessor code.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Binary Search Tree

typedef struct binst
{
    int data;
    struct binst *left;
    struct binst *right;
} binst;

int num = 0;
binst *root = NULL;

// Inserting a node

void ins(int y, FILE *fip)
{
    binst *tem = (binst *)malloc(sizeof(binst));
    tem->data = y;
    tem->left = NULL;
    tem->right = NULL;
    binst *temp = root;

    if (root == NULL)
    {
        root = tem;
    }
    else
    {
        binst *prev = root;
        while (temp != NULL)
        {
            prev = temp;
            if (temp->data > y)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (prev->data > y)
        {
            prev->left = tem;
        }
        else
        {
            prev->right = tem;
        }
    }
    fprintf(fip, "%d inserted\n", y);
    num++;
}

// Preorder

void preorder(binst *head, FILE *fip)
{
    if (head == NULL){
        return;
    }else{
        if (head == root){
            fprintf(fip, "%d", head->data);
            preorder(head->left, fip);
            preorder(head->right, fip);
            return;
        }else{
            fprintf(fip, " %d", head->data);
            preorder(head->left, fip);
            preorder(head->right, fip);
            return;
        }
    }
}

// Inorder

void inorder(binst *head, FILE *fip)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        binst *temp = root;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        if (head == temp)
        {
            inorder(head->left, fip);
            fprintf(fip, "%d", head->data);
            inorder(head->right, fip);
            return;
        }
        else
        {
            inorder(head->left, fip);
            fprintf(fip, "%d ", head->data);
            inorder(head->right, fip);
            return;
        }
    }
    return;
}

// Postorder

void postorder(binst *head, FILE *fip)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        if (head == root)
        {
            postorder(head->left, fip);
            postorder(head->right, fip);
            fprintf(fip, "%d", head->data);
            return;
        }
        else
        {
            postorder(head->left, fip);
            postorder(head->right, fip);
            fprintf(fip, "%d ", head->data);
            return;
        }
    }
    return;
}

// Search

void search(int y, FILE *fip)
{
    binst *temp = root;
    while (temp != NULL)
    {
        if (temp->data == y)
        {
            fprintf(fip, "%d found\n", y);
            return;
        }
        else if (temp->data > y)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    fprintf(fip, "%d not found\n", y);
    return;
}

// Maximum in a BST

void max(FILE *fip)
{
    binst *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    fprintf(fip, "%d\n", temp->data);
    return;
}

// Minimum in a BST

void min(FILE *fip)
{
    binst *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    fprintf(fip, "%d\n", temp->data);
    return;
}

int i = 0;

int sea(binst *temp, int y)
{
    int m = 0;
    // binst *temp = root;
    while (temp != NULL)
    {
        if (temp->data == y)
        {
            m = 1;
            return m;
        }
        else if (temp->data > y)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return m;
}

// inorder for predecessor and successor

void inforps(binst *head, int arr[])
{
    if (head == NULL)
    {
        return;
    }
    inforps(head->left, arr);
    arr[i] = head->data;
    i++;
    inforps(head->right, arr);
}

// To find maximum in any sub-root

int maxi(binst *head)
{
    binst *k = head;
    if (head == NULL)
    {
        return 0;
    }
    while (head != NULL)
    {
        k = head;
        head = head->right;
    }
    return k->data;
}
// To find minimum in any subroot

int mini(binst *head)
{
    binst *k = head;
    if (root == NULL)
    {
        return 0;
    }
    while (head != NULL)
    {
        k = head;
        head = head->left;
    }
    return k->data;
}
// Predecessor Function

void pred(binst *head, int k, FILE *fip)
{
    int arr[num];
    if (sea(head, k) == 0)
    {
        fprintf(fip, "%d does not exist\n", k);
    }
    else
    {
        if (mini(head) == k)
        {
            fprintf(fip, "predecessor of %d does not exist\n", k);
        }
        else
        {
            i = 0;
            inforps(root, arr);
            for (int j = 1; j < num; j++)
            {
                if (arr[j] == k)
                {
                    fprintf(fip, "%d\n", arr[j - 1]);
                    return;
                }
            }
        }
    }
}
// Successor Function

void succ(binst *head, int k, FILE *fip)
{
    int arr[num];
    if (sea(head, k) == 0)
    {
        fprintf(fip, "%d does not exist\n", k);
    }
    else
    {
        if (maxi(head) == k)
        {
            fprintf(fip, "successor of %d does not exist\n", k);
        }
        else
        {
            i = 0;
            inforps(root, arr);
            for (int j = 0; j < num; j++)
            {
                if (arr[j] == k)
                {
                    fprintf(fip, "%d\n", arr[j + 1]);
                    return;
                }
            }
        }
    }
}

// INT MAIN

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("FILE doesnt exist");
        return 0;
    }
    char str[30];
    FILE *fip;
    fip = fopen("bst.txt", "w");
    // Reading the value from the text
    while (fgets(str, 30, fp))
    {
        int k = strlen(str);
        char a[20] = "";
        char nu[10] = "";
        int p = 0;
        for (int i = 0; i < k; i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                a[i] = str[i];
            }
            else if (str[i] == ' ')
            {
                a[i] = '\0';
            }
            else if (str[i] >= '0' && str[i] <= '9')
            {
                nu[p] = str[i];
                p++;
            }
        }

        int number = atoi(nu);

        if (!strcmp("insert", a))
        {
            ins(number, fip);
        }
        else if (!strcmp("inorder", a))
        {
            inorder(root, fip);
            fprintf(fip, "\n");
        }
        else if (!strcmp("preorder", a))
        {
            preorder(root, fip);
            fprintf(fip, "\n");
        }
        else if (!strcmp("postorder", a))
        {
            postorder(root, fip);
            fprintf(fip, "\n");
        }
        else if (!strcmp("maximum", a))
        {
            max(fip);
        }
        else if (!strcmp("minimum", a))
        {
            min(fip);
        }
        else if (!strcmp("search", a))
        {
            search(number, fip);
        }
        else if (!strcmp("predecessor", a))
        {
            binst *temp = root;
            pred(temp, number, fip);
        }
        else if (!strcmp("successor", a))
        {
            binst *temp = root;
            succ(temp, number, fip);
        }
    }
    fclose(fip);
    fclose(fp);
    return 0;
}



void insert(int data)
{
    binst *new = (binst *)malloc(sizeof(binst));
    new->data = y;
    new->left = NULL;
    new->right = NULL;
    binst *temp = root;
    if (root == NULL){
        root = new;
    }else{
        binst *prev = root;
        while (temp != NULL){
            prev = temp;
            if (temp->data > data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (prev->data > data){
            prev->left = new;
        }else{
            prev->right = new;
        }
    }
    printf("%d inserted\n", data);
}


void preorder(binst *head)
{
    if (head == NULL){
        return;
    }else{
        printf(" %d", head->data);
        preorder(head->left, fip);
        preorder(head->right, fip);
        return;
    }
}

void postorder(binst *head)
{
    if (head == NULL){
        return;
    }else{
        postorder(head->left);
        postorder(head->right);
        printf("%d ", head->data);
        return;
    }
}


void max()
{
    binst *temp = root;
    if(root ==NULL){
        return;
    }
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    printf("%d\n", temp->data);
    return;
}


void findPreSuc(binst* root, binst*& pre, binst*& suc, int key)
{
    if (root == NULL)  return ;
    if (root->key == key){
        if (root->left != NULL){
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
        if (root->right != NULL){
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
    if (root->key > key){
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }else{
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}


















