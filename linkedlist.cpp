#include <iostream>



using namespace std;



struct node {
    int data;
    node *next;
};
void insertstart(node **head ,int item)
{
    node *nptr =new node;

    nptr->data=item;
    nptr->next=(*head);
    (*head)=nptr;
}
void insertmid(node *ptr,int item)
{
    node *nptr = new node;
    nptr->data=item;


        nptr->next=ptr->next;
        ptr->next=nptr;



}

void insertend(node **head,int item)
{
    node *nptr=new node;
    nptr->data=item;
    nptr->next=NULL;
    node *curr=new node;
    if(head==NULL)
    {
        (*head)=nptr;
    }
    else{
        curr=(*head);
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=nptr;
    }
}
void dltfirst(node **head)
{
    node *ptr=(*head);
   (*head)=ptr->next;
    delete(ptr);

}
void dltany(node **head,int item)
{
    node *ptr  = (*head),*dptr;
    while(ptr->next->data!=item&&ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    dptr = ptr->next;
    ptr->next=ptr->next->next;
    delete(dptr);
}
bool searchNode(node **head, int item) {
  node* current = *head;

  while (current != NULL) {
  if (current->data == item)
    return true;

  current = current->next;
  }

  return false;
}
void printList(node* node)
{
    while (node != NULL) {

    cout << node->data << " ";
    node = node->next;
  }
  cout<<endl;
}

int main()
{
    int i, n, item;
    node *nptr, *tptr, *record;
    record = NULL;



    cout << "Number of nodes: " << endl;
    cin >> n;
    cout << "Enter data for node:" << endl;



    for (int i = 0; i < n; i++) {
        cin >> item;
        nptr = new (node);
        nptr->data = item;
        nptr->next = NULL;



        if (record == NULL) {
            record = nptr;
            tptr = nptr;
        }
        else {
            tptr->next = nptr;
            tptr = nptr;
        }
    }



    tptr = record;


    cout<<"Linked list :"<<" ";
    printList(tptr);


    insertstart(&tptr,9);
    cout<<"After inserted start:"<<" ";
    printList(tptr);
    insertmid(tptr->next,5);
    cout<<"After inserted middle:"<<" ";
    printList(tptr);
    insertend(&tptr,8);
    cout<<"After inserted end:"<<" ";
    printList(tptr);

    dltfirst(&tptr);
   cout<<"After Deleted first node:"<<" ";
    printList(tptr);
    dltany(&tptr,3);
    cout<<"After Deleted certain node:"<<" ";
    printList(tptr);
    int src;
    cout<<"Enter searching Element:";
    cin>>src;
    if(searchNode(&tptr,src)== true)
    {
        cout<<"found";
    }
    else
    {
        cout<<"Not found";
    }



    return 0;
}
