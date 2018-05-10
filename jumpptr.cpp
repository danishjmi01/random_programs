// C++ program to detect loop in a linked list
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
    struct Node* jump;
};
unordered_map<struct Node*,struct Node*>addrmap; 
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
// Returns true if there is a loop in linked list
// else returns false.
/*bool detectLoop(struct Node *h)
{
    unordered_set<Node *> s;
    while (h != NULL)
    {
        // If we have already has this node
        // in hashmap it means their is a cycle
        // (Because you we encountering the
        // node second time).
        if (s.find(h) != s.end())
            return true;
 
        // If we are seeing the node for
        // the first time, insert it in hash
        s.insert(h);
 
        h = h->next;
    }
 
    return false;
}
*/ 
void copylist(struct Node* head1, struct Node** head2){

	if(head1==NULL)
	return;
	push(head2,head1->data);
	addrmap[head1]=*head2;
	(*head2)->next=NULL;
	struct Node* ptr = (*head2)->next;
	copylist(head1->next,&((*head2)->next));
	(*head2)->jump = addrmap[head1->jump];

} 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
    struct Node* head2 = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    head->jump = head->next->next;
    head->next->jump = head->next->next->next;
    head->next->next->jump = head->next;
    head->next->next->next->jump = NULL;
    /* Create a loop for testing */
    //head->next->next->next->next = head;
 
    //if (detectLoop(head))
      //  cout << "Loop found";
   // else
     //   cout << "No Loop";
 copylist(head,&head2);
struct Node* temp = head;
while(temp!=NULL){
cout<<temp->data<<" ";
temp = temp->jump;
}
    return 0;
}
