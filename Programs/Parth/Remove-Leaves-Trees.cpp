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

void print(Node *root)
{
    cout << root->data << " -> ";
    for (int idx = 0; idx < root->children.size(); idx++)
    {
        int c = 0;
        Node *child = root->children[idx];
        if (child->data != 0)
            cout << child->data << ", ";
        else
        {
            cout << ".";
        }
    }

    cout << ".";
    cout << endl;

    for (int idx = 0; idx < root->children.size(); idx++)
    {
        print(root->children[idx]);
    }
}
void removeele(Node *root)
{
    for (int idx = root->children.size() - 1; idx >= 0; idx--)
    {
        Node *child = root->children[idx];
        if (child->children.size() == 0)
        {
            root->children.erase(root->children.begin() + idx);
        }
    }
    for (int idx = 0; idx < root->children.size(); idx++)
    {

        removeele(root->children[idx]);
    }
}
int main()
{
    Node *root = takeInput();
    removeele(root);
    print(root);
}