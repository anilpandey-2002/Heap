#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int k)
{
    struct Node *node = new Node;
    node->data = k;
    node->right = node->left = NULL;
    return node;
}

unsigned int countNodes(struct Node *root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isCompleteUtil(struct Node *root, unsigned int index, unsigned int number_nodes)
{
    if (root == NULL)
        return (true);

    if (index >= number_nodes)
        return (false);

    return (isCompleteUtil(root->left, 2 * index + 1, number_nodes) && isCompleteUtil(root->right, 2 * index + 2, number_nodes));
}

bool isHeapUtil(struct Node *root)
{
    if (root->left == NULL && root->right == NULL)
        return (true);

    if (root->right == NULL)
    {
        return (root->data >= root->left->data);
    }
    else
    {
        if (root->data >= root->left->data && root->data >= root->right->data)
            return ((isHeapUtil(root->left)) && (isHeapUtil(root->right)));
        else
            return (false);
    }
}

bool isHeap(struct Node *root)
{
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;

    if (isCompleteUtil(root, index, node_count) && isHeapUtil(root))
        return true;
    return false;
}

int main()
{
    struct Node *root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);

    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int k)
{
    struct Node *node = new Node;
    node->data = k;
    node->right = node->left = NULL;
    return node;
}

bool isHeap(Node *root)
{
    queue<Node *> q;
    q.push(root);
    bool nullish = false;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            if (nullish || temp->left->data >= temp->data)
            {
                return false;
            }
            q.push(temp->left);
        }
        else
        {
            nullish = true;
        }
        if (temp->right)
        {
            if (nullish || temp->right->data >= temp->data)
            {
                return false;
            }
            q.push(temp->right);
        }
        else
        {
            nullish = true;
        }
    }
    return true;
}

int main()
{
    struct Node *root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);

    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";

    return 0;
}
