#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}

void insertAtTail(node* &head,int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    
}

void deletionAtHead(node* &head){
    node* toDelete=head;
    head=head->next;
    head->prev=NULL;
    delete toDelete;
}

void deletion(node* &head,int pos){

    if(pos==1){
        deletionAtHead(head);
        return;
    }

    node* temp=head;
    int count=1;
    while (temp!=NULL&&count!=pos)
    {
        temp=temp->next;
        count++;
    }

    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }   
    
    delete temp;
}

void display(node* head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<endl;
    
}

int main(){
    node* head=NULL;
    display(head);
    insertAtTail(head,45);
    insertAtTail(head,55);
    insertAtTail(head,78);
    insertAtTail(head,48);
    display(head);
    insertAtHead(head,44);
    insertAtHead(head,56);
    display(head);
    deletion(head,3);
    display(head);
    deletionAtHead(head);
    display(head);
    deletion(head,1);
    display(head);
}