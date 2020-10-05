/* struct Node
{
    int data;
    struct Node* next;
};

 */

//This function prints ll in forward direction
void forwardPrint(struct Node* head)
{
  while(head != NULL) {
    cout<<head->data<<"-";
    head = head->next;
  }
}

//This function prints ll in reverse direction
void backwardPrint(struct Node* head)
{
  if(head == NULL) return;
  backwardPrint(head->next);
  cout<<head->data<<"-";
}

/*
Sample Input:
1
3
1
2
3

Sample Output:
1-2-3-
3-2-1-
*/
