#include<bits/stdc++.h>

struct Node
{
    int value;
    Node* next;
    Node(int v) ///constructor
    {
        value=v;
        next=NULL;
    }
};
Node* head; ///head initialization
int totalNodes=0;


void addToLast(int v )
{
    if(head==NULL) ///if there is no nodes.
    {
        Node *newNode= new Node(v);
        head=newNode;
        totalNodes++;
        return;
    }
    Node* curr=head; ///if there are nodes, so traversing till null and adding new node
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    Node *newNode= new Node(v);
    totalNodes++;

    curr->next=newNode;

}


void addToFirst(int v)
{
    if(head==NULL) ///if there is no node.
    {
        Node *newNode= new Node(v);
        head= newNode;
         totalNodes++;
    }
    else ///if there are nodes
    {
        Node *newNode= new Node(v);
        newNode->next=head; /// linking with the chain.
        head=newNode; ///linking with head
        totalNodes++;

    }
}

void printLinkedList()
{
    Node*curr=head;

    while(curr!=NULL) ///what if the head is null? thats whgy curr!=NULL condition
    {
        printf("%d ",curr->value);
        curr=curr->next;

    }
    printf("\n");
}

int isSorted(Node *head)
{
    Node* prev=head; //picking the first node
    Node* curr=head->next; // picking the second node
    while(curr!=NULL)
    {
        if((prev->value) > (curr->value))
        {
            return 0;
        }
        curr=curr->next;
        prev=prev->next;

    }
    return 1;

}


void deleteLast()
{
    if(head==NULL) /// if there is nothing to delete
    {
        return;
    }
    else if(head->next==NULL)/// if there is only one node
    {
        Node *delNode= head; ///picking the address of first node
        head=NULL;
        free(delNode);
        totalNodes--;
        return; ///it means not to execute the rest of codes without conditioned
    }

    ///if there are multiple nodes

    Node *curr=head;
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    ///while here ,we are at the previous node of last node.

    free(curr->next); ///deleteting the last node
    curr->next=NULL;
    totalNodes--;




}

void deleteFirst()// deleting the first node
{
    if(head==NULL)
    {
        return;
    }
    Node* delNode= head;
    head= head->next; // linking with the rest of linkedlist.
    free(delNode);
    totalNodes--;
}

void deleteValue(int v)
{
    if(head==NULL)
    {
        return;
    }
    if (head->value==NULL)///first node value
    {
        Node* delNode= head;
        head= head->next;  // linking with the rest of linkedlist.
        free(delNode);
        totalNodes--;
    }

    Node *curr=head->next; //2nd node
    Node *prev=head; //first node
    while(curr!=NULL && curr->value!=v)
    {
        curr=curr->next;
        prev=prev->next;
    }
    ///if there is no such value
    if(curr==NULL)
    {
        return;
    }
    /// if value found
    prev->next= curr->next;
    free(curr);
    totalNodes--;

}

void deleteLinkedList()
{
    if(head==NULL) return;
    else
    {
        while(head!=NULL)
        {
            deleteLast(); //deleting every node till head becomes null
        }
    }
    totalNodes=0;

}

void deleteMiddle()
{
    int countt_mid= (totalNodes+1)/2;
    printf("\ntotal nodes %d\n", totalNodes);

    Node *curr=head->next; //2nd node
    Node *prev=head; //first node
    int pos=2; //curr node is in 2 no node.
    while(pos<countt_mid)
    {
        curr=curr->next;
        prev=prev->next;
        pos++;
    }
    prev->next= curr->next;
    free(curr);





}
int main()
{

    head=NULL; ///making head as NULL.
    addToLast(1);
    addToLast(2);
    addToLast(5);
    addToLast(3);
    addToLast(1);

    addToFirst(9);
    addToFirst(8);
    printLinkedList();

    if(isSorted(head)==1)
    {
        printf("\nThe linked list is sorted\n");
    }
    else
    {
        printf("\nThe linked list is not sorted\n");
    }

    deleteLast();
    printLinkedList();

    deleteFirst();
    printLinkedList();

    deleteValue(5);
    printLinkedList();

    deleteMiddle();
    printLinkedList();




    return 0;



}
