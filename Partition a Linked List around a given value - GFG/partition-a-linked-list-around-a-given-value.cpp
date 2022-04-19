// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
    vector<int> less;
    vector<int> more;
    int same = 0;
    
    Node* tmp = head;
    while (tmp)
    {
        if (tmp -> data < x)
            less.push_back(tmp -> data);
        
        else if (tmp -> data > x)
            more.push_back(tmp -> data);
        else
            ++same;
        tmp = tmp -> next;
    }
    
    tmp = head;
    
    for (int &i : less)
    {
        tmp -> data = i;
        tmp = tmp -> next;
    }

    
    while (same--)
    {
        tmp -> data = x;
        tmp = tmp -> next;
    }
    
    
    for (int &i : more)
    {
        tmp -> data = i;
        tmp = tmp -> next;
    }
    
    return head;
}