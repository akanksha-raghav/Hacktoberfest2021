#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
};

void insertAtFirst(Node** head, int data) {
    Node* newNode = new Node();

    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = NULL;

    if((*head) != NULL) (*head)->prev = newNode;

    (*head) = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = new Node();
    Node* temp = *head;

    newNode->data = data;
    newNode->next = NULL;
    
    if(*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while(temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    newNode->prev =  temp;
}

void deleteNode(Node** head, Node* delNode) {
    if((*head) == NULL || delNode == NULL)  return;

    if((*head) == delNode)          
        (*head) = delNode->next;

    if(delNode->next != NULL)
        delNode->next->prev = delNode->prev;
    
    if(delNode->prev != NULL)
        delNode->prev->next = delNode->next;

    free(delNode);    
}

void printList(Node* node) {
    Node* last;
    while(node != NULL) {
        cout << " " << node->data;
        last = node;
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    insertAtFirst(&head, 1);
    insertAtFirst(&head, 2);
    insertAtFirst(&head, 3);
    cout << "Node list After Insertion at first:\n";
    printList(head);

    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    cout << "\nNode list After Insertion at end:\n";
    printList(head);

    deleteNode(&head, head);
    cout << "\nNode list after deletion at first:\n";
    printList(head);

    deleteNode(&head, head->next->next->next->next);
    cout << "\nNode list after deletion at end:\n";
    printList(head);

    return 0;
}