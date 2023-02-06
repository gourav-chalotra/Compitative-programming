//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
    Node *next;
    int data;
};

// Utility function to insert a node at the
// beginning
void push(Node **head, int data)
{
    Node *newNode = new Node;
    newNode->next = (*head);
    newNode->data = data;
    (*head) = newNode;
}

// Utility function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data;
        if (head->next != NULL)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution
{

public:
    Node *sortList(Node **head)
    {
        Node *temp = *head;
        Node *ptr = temp;
        int sizeArr = 0, i = 0;

        while (temp != NULL)
        {
            sizeArr++;
            temp = temp->next;
        }

        Node *arr[sizeArr];

        temp = *head;
        while (temp != NULL)
        {
            arr[i] = temp;
            temp = temp->next;
            i++;
        }
        int frount = 0, rear = sizeArr;

        while (frount < rear)
        {
            if ((arr[rear]->data) < arr[frount]->data)
            {
                int temp = arr[frount]->data;
                arr[frount]->data = arr[rear]->data;
                arr[rear]->data = temp;
                frount++;
            }
            else if((arr[rear]->data) > arr[frount]->data)
            {
                rear--;
            }
        }

        return *head;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{

    int t = 0;
    int n = 0;
    cin >> t;
    while (t--)
    {
        Node *head = NULL;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            // push(&head, a);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            push(&head, arr[i]);
        }
        // printList(head);

        Solution ob;
        head = ob.sortList(&head);

        printList(head);
    }
    return 0;
}

// } Driver Code Ends