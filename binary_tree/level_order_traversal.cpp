#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// very important concept, to understand the concept of right view and left view in binary tree
struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrder(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *n = q.front(); // n is a pointer that traverse through the tree
        q.pop();

        if (n != NULL)
        {
            cout << n->data << " ";

            if (n->left != NULL)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }

        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int main()
{
    node *root = NULL;
    root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    printLevelOrder(root);
}