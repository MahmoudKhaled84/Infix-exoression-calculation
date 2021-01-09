#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
template <class itemtype>
struct nodetype
{
    itemtype info;
    nodetype* next;
};
template <class itemtype>
class Stack
{   public: Stack();
            bool push(itemtype item);
            bool pop(itemtype &item);
            bool top(itemtype &item);
            bool isEmpty();
    private : nodetype <itemtype>* topptr;
};
template <class itemtype>
Stack<itemtype>::Stack()
{
    topptr=NULL;
}
template <class itemtype>
bool Stack<itemtype>::push(itemtype item)
{
    nodetype<itemtype>* location;
    location=new nodetype<itemtype>;
    if(location==NULL) return false ;
    location->info=item;
    location->next=topptr;
    topptr=location;
    return true;
}
template <class itemtype>
bool Stack<itemtype>::pop(itemtype &item)
{
    if(topptr==NULL) return false;
    nodetype<itemtype>* temp;
    temp=topptr;
    topptr=topptr->next;
    item=temp->info;
    delete temp;
    return true;
}
template <class itemtype>
bool Stack<itemtype>::top(itemtype &item)
{
    if(topptr==NULL) return false;
    item=topptr->info;
    return true;
}
template <class itemtype>
bool Stack<itemtype>::isEmpty()
{
    if(topptr==NULL) return true;
    return false;
}

#endif // STACK_H_INCLUDED
