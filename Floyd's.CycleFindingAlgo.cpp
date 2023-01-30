#include<bits/stdc++.h>

struct Node
{
    int value;
    Node* next;

    Node(int v)
    {
        value=v;
        next=NULL;
    }
};

void cycleFinding(Node * head)
{
    Node *hare, *tortoise;
    hare= head; //hare two step
    tortoise=head; //tortoise one step

    int flag=0;
    while(hare->next->next!=NULL && hare->next!=NULL)
    {
        ///Now both are at the same point, so traversing
        hare=hare->next->next;
        tortoise= tortoise->next;

        if(tortoise==hare) ///they met so ,cycle exist.
        {
            tortoise=head;
            while(hare!=tortoise)
            {
                tortoise=tortoise->next;
                hare= hare->next;

            }
            ///when they meet again
            if(hare==tortoise)
            {
                printf("Yes! a loop is found at %d\n", hare->value);
                flag=1;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    int cnt=1;
    if(flag==1)
    {
        tortoise=tortoise->next;//moving to one step as they both are at the same node
        while(tortoise!=hare)
        {
            cnt++;
            tortoise=tortoise->next;
        }

    }
    printf("The size of the loop is %d\n", cnt);

}

int main()
{
    ///memory allocation and input.
    Node* head= new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    ///here node 4 is connected to node 2
    ///linking
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=second;

    cycleFinding(head);


}
