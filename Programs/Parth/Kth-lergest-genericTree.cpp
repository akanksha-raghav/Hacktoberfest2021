#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;

    Node(int data)
    {
        this->data = data;
    }

    ~Node()
    {
        int size = children.size();
        for (int index = 0; index < size; index++)
        {
            delete children[index];
        }
    }
};

Node *takeInput()
{
    int size;

    cin >> size;

    int *input = new int[size];

    for (int index = 0; index < size; index++)
    {
        cin >> input[index];
    }

    Node *root = NULL;

    stack<Node *> nodes;

    for (int index = 0; index < size; index++)
    {
        if (input[index] == -1)
        {
            nodes.pop();
        }

        else
        {
            Node *newNode = new Node(input[index]);

            if (nodes.size() == 0)
            {
                root = newNode;
            }

            else
            {
                nodes.top()->children.push_back(newNode);
            }

            nodes.push(newNode);
        }
    }

    return root;
}

Node *maxi(Node *root)
{
    Node *maxNode = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        Node *maxChild = maxi(root->children[i]);
        if (maxNode->data < maxChild->data)
        {
            maxNode = maxChild;
        }
    }
    return maxNode;
}
int main()
{
    Node *root = takeInput();
    int k;
    cin >> k;
    for (int idx = 0; idx < k; idx++)
    {
        Node *ans = maxi(root);
        if (idx != k - 1)
        {
            ans->data = 0;
        }
        else
        {
            cout << ans->data;
        }
    }
}