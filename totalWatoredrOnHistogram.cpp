
#include<bits/stdc++.h>

///Question: a Given histogram/ups and down wall ,after rain, water is contained, find the total units of water that contained on that wall.
struct Stack
{
    struct Node
    {
        char value;
        Node* next;
        Node()
        {
            next=NULL;
        }
        Node(char ch)
        {
            value=ch;
            next=NULL;
        }
    };


    int no_of_elements;
    Node* head;
    Stack()
    {
        head=NULL;
        no_of_elements=0;
    }

    /**
        The following function should
        insert a new element onto the
        stack.
    */

    void push(char ch)
    {
        if(head==NULL)
        {
            head=new Node(ch);
            no_of_elements++;
            return;

        }
        Node *newNode=new Node(ch);
        newNode->next=head;
        head=newNode;
        no_of_elements++;
        return;

    }

    /**
        The following function should
        delete the element that was last
        inserted onto the stack.
    */

    void pop()
    {
        if(head==NULL) return;
        Node* delNode=head;
        head= delNode->next;
        free(delNode);
        no_of_elements--;
    }

    /**
        The following function should
        return the character that was last
        inserted onto the stack
    */

    char top()
    {
        return head->value;
    }
    /**
        The following function should return
        the number of elements in the stack.
    */
    int size()
    {
        return no_of_elements;
    }
};





int totalWater(int arr[], int len)
{
    Stack st_in;
    Stack st;
    ///st is a descending monotonic stack
    int water_unit=0;

    for(int i=0; i<len; i++)
    {

        int pop_v;
        int min_height;

        while (st.size()!=0 && st.top() < arr[i]) //when the stack is not empty and top is smaller then input
        {
            pop_v= st.top();
            printf("pop: %d\n", pop_v);

            st.pop();//pop the top
            st_in.pop();

            // If the stack does not have any
			// bars or the popped bar
			// has no left boundary
			if (st.size()==0)
				break;


            int count_bars= i - st_in.top() -1; ///here i is the index of push value
            printf("bars %d\n", count_bars);

            if( arr[i]< st.top())
            {
                min_height= arr[i] - pop_v;
            }
            else
            {
                min_height= st.top() - pop_v;
            }
            printf("unit: %d\n", min_height*count_bars );
            water_unit+= min_height*count_bars;

        }
        printf("push %d\n", arr[i]);
        st.push(arr[i]); //inserting value
        st_in.push(i);

    }

return water_unit;
}

int main()
{
    ///1st and last index value is 0. rest are actual histogram

    int arr[11]= {3,2,5,4,3,6,4,4,4,2,6};
    int n=11;


    int mxwater=totalWater(arr,n);

    printf("%d is total units of water in the histogram\n", mxwater);

}
