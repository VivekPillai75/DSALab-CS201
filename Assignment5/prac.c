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
int daw; // for predecessor and successor

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

void preorder(binst *head, FILE *fip)
{
    int c = 1;
    if (head == NULL)
    {
        return;
    }
    else
    {
        fprintf(fip, "%d ", head->data);
        preorder(head->left, fip);
        preorder(head->right, fip);
        return;
    }
    return;
}

void inorder(binst *head, FILE *fip)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        inorder(head->left, fip);
        fprintf(fip, "%d ", head->data);
        inorder(head->right, fip);
    }
    return;
}

void postorder(binst *head, FILE *fip)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        postorder(head->left, fip);
        postorder(head->right, fip);
        fprintf(fip, "%d ", head->data);
        return;
    }
    return;
}

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

int sea(int y)
{
    int m = 0;
    binst *temp = root;
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

binst *prede;
binst *succe;

void prsu(binst *head, int k, FILE *fip)
{
    if (head == NULL)
    {
        return;
    }
    if (head->data == k)
    {
        if (head->left != NULL)
        {
            binst *temp = head->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            prede = temp;
        }
        if (head->right != NULL)
        {
            binst *tep = head->right;
            while (tep->left != NULL)
            {
                tep = tep->left;
            }
            succe = tep;
        }
        return;
    }
    if (head->data > k)
    {
        succe = root;
        prsu(head->left, k, fip);
    }
    else
    {
        prede = root;
        prsu(head->right, k, fip);
    }
}

// void pred(int k, FILE *fip)
// {
//     int a = sea(k);
//     if (a == 1)
//     {
//         binst *temp = root;
//         while (temp->data != k)
//         {
//             if (temp->data > k)
//             {
//                 temp = temp->left;
//             }
//             else
//             {
//                 temp = temp->right;
//             }
//         }
//         if (temp->left != NULL)
//         {
//             temp = temp->left;
//             while (temp->right != NULL)
//             {
//                 temp = temp->right;
//             }
//             fprintf(fip, "%d\n", temp->data);
//         }
//         else
//         {
//             fprintf(fip, "predecessor of %d does not exist\n", k);
//         }
//     }
//     else
//     {
//         fprintf(fip, "%d does not exist\n", k);
//         return;
//     }
// }

// void succ(int k, FILE *fip)
// {
//     int a = sea(k);
//     if (a == 1)
//     {
//         binst *temp = root;
//         if(temp->data > y){
//         while (temp->data != k)
//         {
//             if (temp->data > k)
//             {
//                 temp = temp->left;
//             }
//             else
//             {
//                 temp = temp->right;
//             }
//         }
//         if (temp->right != NULL)
//         {
//             temp = temp->right;
//             while (temp->left != NULL)
//             {
//                 temp = temp->left;
//             }
//             fprintf(fip, "%d\n", temp->data);
//         }
//         else
//         {

//             fprintf(fip, "successor of %d does not exist\n", k);
//         }
//     }
//     else
//     {
//         fprintf(fip, "%d does not exist\n", k);
//         return;
//     }
// }








// int sea(int y)
// {
//     int m = 0;
//     binst *temp = root;
//     while (temp != NULL)
//     {
//         if (temp->data == y)
//         {
//             m = 1;
//             return m;
//         }
//         else if (temp->data > y)
//         {
//             temp = temp->left;
//         }
//         else
//         {
//             temp = temp->right;
//         }
//     }
//     return m;
// }

// int mi()
// {
//     binst *temp = root;
//     while (temp->left != NULL)
//     {
//         temp = temp->left;
//     }
//     return temp->data;
// }

// void pred(int k, FILE *fip)
// {
//     int a = sea(k);
//     if (a == 1)
//     {
//         int l = mi();
//         if (k == l)
//         {
//             fprintf(fip, "predecessor of %d does not exist\n", k);
//             return;
//         }
//         else
//         {
//             binst *temp = root;
//             while (temp->data != k && temp!=NULL)
//             {
//                 if (temp->data > k)
//                 {
//                     temp = temp->left;
//                 }
//                 else if (temp->data < k)
//                 {
//                     temp = temp->right;
//                 }
//             }
//             temp = temp->left;
//             if(temp!=)
//              while (temp->right != NULL && temp != NULL)
//              {
//              temp = temp->right;
//              }
//              int g = temp->data;
//              fprintf(fip, "%d\n", g);
//              return;
//         }
//     }
//     else
//     {
//         fprintf(fip, "%d does not exist\n", k);
//         return;
//     }
// }

// int ma()
// {
//     binst *temp = root;
//     while (temp->right != NULL)
//     {
//         temp = temp->right;
//     }
//     return temp->data;
// }

// void succ(int k, FILE *fip)
// {
//     fprintf("olo");
//     int a = sea(k);
//     if (a == 1)
//     {
//         int l = ma();
//         if (k == l)
//         {
//             fprintf(fip, "successor of %d does not exist\n", k);
//             return;
//         }
//         else
//         {
//             binst *temp = root;
//             while (temp->data != k)
//             {
//                 if (temp->data > k)
//                 {
//                     temp = temp->left;
//                 }
//                 else if (temp->data < k)
//                 {
//                     temp = temp->right;
//                 }
//             }
//             temp = temp->right;
//             while (temp->left != NULL)
//             {
//                 temp = temp->left;
//             }
//             int g = temp->data;
//             fprintf(fip, "%d\n", g);
//             return;
//         }
//     }
//     else
//     {
//         fprintf(fip, "%d does not exist\n", k);
//         return;
//     }
// }

// void inforps(binst *head, int arr[])
// {
//     if (head == NULL)
//     {
//         return;
//     }
//     else
//     {
//         inforps(head->left, arr);
//         arr[daw] = head->data;
//         inforps(head->right, arr);
//     }
//     return;
// }

// void pred(int k, FILE *fip)
// {
//     fprintf(fip,"lol");
// }
// {
//     int arr[num];
//     daw = -1;
//     for (int i = 0; i < num; i++)
//     {
//         arr[i] = -1;
//     }
//     binst *temp = root;
//     inforps(temp, arr);
//     for (int q = 0; q < num; q++)
//     {
//         if (arr[q] == k)
//         {
//             if (q == 0)
//             {
//                 printf("%d", arr[q]);
//                 fprintf(fip, "predecessor of %d does not exist\n", k);
//                 return;
//             }
//             else
//             {
//                 fprintf(fip, "%d\n", arr[q - 1]);
//                 return;
//             }
//         }
//     }
//     fprintf(fip, "%d does not exist\n", k);
//     return;
// }

// void succ(int k, FILE *fip)
// {
//     int arr[num];
//     daw = -1;
//     binst *temp = root;
//     inforps(temp, arr);
//     for (int q = 0; q < num; q++)
//     {
//         if (arr[q] == k)
//         {
//             if (q == num - 1)
//             {
//                 fprintf(fip, "successor of %d does not exist\n", k);
//                 return;
//             }
//             else
//             {
//                 fprintf(fip, "%d\n", arr[q + 1]);
//                 return;
//             }
//         }
//     }
//     fprintf(fip, "%d does not exist\n", k);
//     return;
//  }

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
    fip = fopen("bst1.txt", "w");

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
            prede = NULL;
            binst *temp = root;
            int l = sea(number);
            if (l == 1)
            {
                prsu(temp, number, fip);
                if (prede == NULL)
                {
                    fprintf(fip, "successor of %d does not exist\n", number);
                }
                else
                {
                    fprintf(fip, "%d\n", prede->data);
                }
            }
            else if (l == 0)
            {
                fprintf(fip, "%d does not exist\n", number);
            }
        }
        else if (!strcmp("successor", a))
        {
            succe = NULL;
            binst *temp = root;
            int l = sea(number);
            if (l == 1)
            {
                prsu(temp, number, fip);
                if (prede == NULL)
                {
                    fprintf(fip, "successor of %d does not exist\n", number);
                }
                else
                {
                    printf("%d\n", succe->data);
                    fprintf(fip, "%d\n", succe->data);
                }
            }
            else if (l == 0)
            {
                fprintf(fip, "%d does not exist\n", number);
            }
        }
    }
    fclose(fip);
    fclose(fp);
    return 0;
}