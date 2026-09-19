#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct node

{

    char *key;

    int count;

    struct node *left, *right;

};


struct node *newNode(char *item)

{

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->key = (char *)malloc(sizeof(strlen(item)));

    strcpy(temp->key, item);

    temp->count = 1;

    temp->left = temp->right = NULL;

    return temp;

}


void inorder(struct node *root)

{

    if (root != NULL)

    {

        inorder(root->left);

        cout << root->key << ": " << root->count << "\n";

        inorder(root->right);

    }

}



struct node *insert(struct node *node, char *key)

{


    if (node == NULL)

        return newNode(key);

    if (strcmp(key, node->key) < 0)

        node->left = insert(node->left, key);
    else if (strcmp(key, node->key) > 0)

        node->right = insert(node->right, key);
    else

    {
        node->count++;

    }

    return node;

}





int main()

{
    char *input = "aadabcdaa";

    int n = strlen(input);

    string line;

    int k=2;

    ifstream myfile("input1.txt");

    int lasthour = 0, lastmin = 0;

    if (myfile.is_open())

    {

        while (getline(myfile, line))

        {

            char *token = strtok(const_cast<char *>(line.c_str()), " ");

            while (token != nullptr)

            {

                input = token;

                cout << token;

                token = strtok(NULL, " ");

                k = atoi(token);

                cout << k;

                token = strtok(NULL, " ");

            }

        }

    }

    else

    {

        cout << "Cannot Open the file \n" ;

    }

    struct node *root = NULL;


    for (int len = 1; len <= k; len++)

    {



        for (int i = 0; i <= n - len; i++)

        {



            int j = i + len - 1;

            int size = j - i + 1;

            char *item;

            item = new char[size];

            int z = 0;

            for (int k = i; k <= j; k++)

            {

                item[z++] = input[k];

            }

            item[z] = '\0';


            root = insert(root, item);

        }

    }





    inorder(root);



    return 0;

}