#include<bits/stdc++.h>
using namespace std;


// Linked List Implementation
class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode(int v)
    {
        val = v;
    }
};

void appendLNode(ListNode **head, int data)
{
    ListNode *node = new ListNode(data);
    node->next = nullptr;
    if(*head == nullptr)
    {
        *head = node;
        return;
    }

    ListNode* curr = *head;
    while(curr->next != nullptr)
        curr = curr->next;
    curr->next = node;
    return;
}
void printLList(ListNode* head)
{
    if(head == nullptr)
        return;
    while(head != nullptr)
    {
        cout<<head->val<<" ";
        head = head->next;
    }

    cout<<endl;
    return;
}



//Merge Sort for Arrays

void mergeArray(int arr[],int s, int e)
{
    int temp[100005];
    int mid = s + (e-s)/2;
    int i = s;
    int j = mid+1;
    int k = s;

    while(i<=mid && j<=e)
    {
        temp[k++] = (arr[i]<arr[j]) ? arr[i++] : arr[j++] ;
    }
    while(i<=mid)
        temp[k++] = arr[i++];
    while(j<=e)
        temp[k++] = arr[j++];

    for(int t=0;t<=e;t++)
        arr[t] = temp[t];
}

void mergeSortArray(int arr[], int s, int e)
{

    if(s>=e)
        return;

    int mid = s + (e-s)/2;
    mergeSortArray(arr,s,mid);
    mergeSortArray(arr,mid+1,e);

    mergeArray(arr,s,e);
}



// Merge Sort For Linked List

void splitter(ListNode *head, ListNode **a, ListNode **b)
{
    ListNode *slow = head, *fast = head->next;

    while(fast != nullptr)
    {
        fast = fast ->next;
        if(fast != nullptr)
        {
            fast = fast->next;
            slow = slow -> next;
        }
    }

    *a = head;
    *b = slow ->next;
    slow->next = nullptr;
}

ListNode* mergeLList(ListNode* a, ListNode* b)
{
    ListNode* result = nullptr;
    if(a == nullptr)
        return b;
    else if(b==nullptr)
        return a;

    if(a->val <= b->val)
    {
        result = a;
        result->next = mergeLList(a->next,b);
    }
    else
    {
        result = b;
        result->next = mergeLList(a,b->next);
    }
    return result;
}

void mergeSortLList(ListNode **head)
{
    if(*head ==nullptr )
        return;

    ListNode *headref = *head;
    if(headref->next == nullptr)
        return;

    ListNode *a = nullptr, *b = nullptr;

    splitter(headref, &a, &b);

    mergeSortLList(&a);
    mergeSortLList(&b);

    *head = mergeLList(a,b);
}

int main()
{

    // Input Array Initialisation
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    mergeSortArray(arr,0,n-1);
    cout<<"Sorted Array is :-"<<endl;
    for(int i : arr)
        cout<<i<<" ";
    cout<<endl;

    // Input Linked List Initialisation
    int m;
    cin>>m;
    ListNode *head = nullptr;
    int temp;
    for(int i =0; i<m;i++)
    {
        cin>>temp;
        appendLNode(&head,temp);
    }

    mergeSortLList(&head);
    cout<<"Sorted Linked List is :- "<<endl;
    printLList(head);
    return 0;
}