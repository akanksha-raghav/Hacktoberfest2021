#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val){
    node* n=new node(val);

    if(head==NULL){
        head=n;
        return;
    }
    
    node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head,int val){
    node* n=new node(val);

    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    n->next=head;
    head=n;
}

void display(node* head){
    if(head==NULL){
        cout<<"Linked List is empty."<<endl;
        return;
    }
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->next;
        
    }
    cout<<"NULL"<<endl;
}

bool search(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            cout<<"Found"<<endl;
            return true;
        }
        temp=temp->next;
    }
    cout<<"Not Found"<<endl;
    return false;
}

node* reverse(node* &head){
    node* prevPtr=NULL;
    node* currPtr=head;
    node* nextPtr;
    while (currPtr!=NULL)       
    {
        nextPtr=currPtr->next;
        currPtr->next=prevPtr;

        prevPtr=currPtr;
        currPtr=nextPtr;
    }
    return prevPtr;
    
}

node* reverseRecursive(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newHead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newHead;
}

node* reverseK(node* head,int k){
    node* prevPtr=NULL;
    node* currPtr=head;
    node* nextPtr;
    int count=0;
    while (currPtr!=NULL && count<k)       
    {
        nextPtr=currPtr->next;
        currPtr->next=prevPtr;

        prevPtr=currPtr;
        currPtr=nextPtr;
        count++;
    }
    if(nextPtr!=NULL){
        head->next=reverseK(nextPtr,k);
    }
    return prevPtr;
}

int getLength(node* head){
    node* temp=head;
    int c=0;
    while (temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

void deleteAtHead(node* &head){
    node* toDelete=head;
    head=head->next;
    delete toDelete;
}

void deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
    }

    node* temp=head;
    for (int i = 0; i < getLength(head) && temp->next!=NULL; i++)
    {
        if(temp->next->data==val){
            node* toDelete=temp->next;
            temp->next=temp->next->next;
            delete toDelete;
            return;
        }
        temp=temp->next;
    } 
    
    return;
}

node* kappend(node* &head,int k){
    node* newHead;
    node* newTail;
    node* tail=head;
    int l=getLength(head);
    // k=k%l;
    int count=1;
    while (tail->next!=NULL){
        if(count==l-k){
            newTail=tail;
        }
        if(count==l-k+1){
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }

    newTail->next=NULL;
    tail->next=head;

    return newHead;
    
}

int main(){
    // node* head=NULL;
    // display(head);
    // insertAtTail(head,21);
    // insertAtTail(head,12);
    // insertAtTail(head,55);
    // insertAtTail(head,78);
    // insertAtTail(head,98);
    // insertAtTail(head,88);
    // display(head);
    // getLength(head);
    // insertAtHead(head,45);
    // display(head);
    // getLength(head);
    // search(head,45);
    // search(head,455);
    // deletion(head,88);
    // display(head);
    // getLength(head);
    // deletion(head,99);
    // // display(head);
    // // display(head);
    // deleteAtHead(head);
    // display(head);
    // cout<<getLength(head)<<endl;
    // deletion(head,88);
    // display(head);
    // deletion(head,99);
    // display(head);
    // deleteAtHead(head);
    // cout<<"Kshitiz"<<endl;
    // display(head);

    node* head=NULL;
    insertAtTail(head,21);
    insertAtTail(head,12);
    insertAtTail(head,55);
    insertAtTail(head,78);
    insertAtTail(head,98);
    insertAtTail(head,88);
    display(head);


    node* newHead=kappend(head,3);
    display(newHead);

    // node* newHead=reverse(head);
    // display(newHead);

    // node* nodeRec=reverseRecursive(newHead);
    // display(nodeRec);

    // node* nodeRecK=reverseK(nodeRec,2);
    // display(nodeRecK);

    return 0;
}