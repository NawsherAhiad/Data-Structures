#include<bits/stdc++.h>
///Question: a Given histogram ,find the largest rectangle from it.

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



int largestRectangleArea(int arr[], int len)
{
    Stack st_in;
    Stack st;
    int maxx=-1;
    for(int i=0; i<len; i++)
    {
        if(st.size()==0 )//if the stack is empty, so push
        {
            printf("push %d\n", arr[i]);
            st.push(arr[i]); //inserting value
            st_in.push(i); //corresponding index
        }


        if(st.top()<= arr[i]) ///if the top of stack is smaller then current pushing value, stack in.
        {
            //printf("push %d\n", arr[i]);
            st.push(arr[i]); //inserting value
            st_in.push(i); //corresponding index

        }
        else
        {
            int pop_v;
            while (st.top()> arr[i])
            {
                pop_v=st.top();

                st.pop();//pop the top
                st_in.pop();

                int count_bars= i - st_in.top() -1; ///here i is the index of push value
                //printf("bars %d\n", count_bars);
                int area = count_bars*  pop_v;
               // printf("area %d\n",area );

                if(maxx<=area)
                {
                    maxx=area;
                }

            }

           // printf("push %d\n", arr[i]);
            st.push(arr[i]); //now push the value into stack after the pop
            st_in.push(i);


        }

    }

    while(st.size()>0) //emptying first and last 0 values.
    {
       // printf("size: %d", st.size());
        //printf("left: %d\n",st.top() );
        st.pop();//pop the top
        st_in.pop();
/// here will be popped 3 0s, first 0 is when the stack was null,
///2nd 0 when pushing value and stack top same in the first place
///3rd 0 is when last pushed 0 value.

    }
    return maxx;

}

int main()
{
    ///1st and last index value is 0. rest are actual histogram
    int arr[10]= {0,2,4,3,5,1,6,5,4,0};
    int n=10;

    int largestArea=largestRectangleArea(arr,n);

    printf("%d is the largest rectangle in the histogram\n", largestArea);





}
