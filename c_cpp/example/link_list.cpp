/*
linked list -> x[i+1] , x[i]
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdbool>
using namespace std;

struct node 
{
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;

void insertElement(int key, int data)
{
    struct node *link = (struct node*)malloc(sizeof(struct node));
    link->data =data;
    link->key = key;
    link->next = head;
    head = link;
}
void printList()
{
    struct node *ptr = head;
    while(ptr != NULL)
    {
        cout<<ptr->key<<" "<<ptr->data<<endl;
        ptr = ptr->next;
    }
    cout<<"-----------------------------------"<<endl;
}
struct node *deleteElement()
{
    struct node *templink = head;
    head = head->next;
    return templink;

}

void isEmpty()
{

    if(head==NULL) cout<<"linkde list is empty"<<endl;
    else cout<<"linked list in not empty"<<endl;

}

int length()
{
    int len = 0;
    struct node *temp;
    for(temp=head;temp!=NULL;temp= temp->next)
    {
        len++;
    }

    return len;
}
struct node *find(int key)
{
    struct node *current = head;
    if(head == NULL) return NULL;

    while(current->key != key)
    {
        if(current->next == NULL) return NULL;
        else current = current->next;
    }

    return current;
}
struct node *deleteFunc(int key)
{
    struct node *current = head;
    struct node *prev = NULL;

    if(head==NULL) return NULL;
    while(current->key != key)
    {
        if(current->next == NULL) return NULL;
        else 
        {
            prev = current;
            current = current->next;
        }
    }

    if(current == head) head = head->next;
    else
    {
        prev->next = current->next;
    }
    return current;
}

int main()
{
insertElement(1,20);
insertElement(2,30);
printList();
deleteElement();
printList();
}
