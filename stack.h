#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctype.h>
#include <string.h>
using namespace std;

template <class StackElementType>

class stack {
public:
    stack();
    bool push(StackElementType& item);
    bool pop(StackElementType& item);
    bool top(StackElementType& item);
    bool isEmpty();
    ~stack();

private:
    struct Node;
    typedef Node* link;
    struct Node {
        StackElementType item;
        link previous;
    };
    link head;
};

template <class StackElementType>
stack<StackElementType>::stack()
{
    head = NULL;
}
template <class StackElementType>
bool stack<StackElementType>::push(StackElementType& item)
{
    link addedNode = new Node;
    if (addedNode == NULL) {
        return false;
    }
    else {
        addedNode->item = item;
        addedNode->previous= head;
        head = addedNode;
        return true;
    }
}

template <class StackElementType>
bool stack<StackElementType>::pop(StackElementType& item)
{
    if(head!=NULL)
    {	
	item=head->item;
	head=head->previous;    	
	return true;
    }
    else
	return false;
}

template <class StackElementType>
bool stack<StackElementType>::top(StackElementType& item)
{
    if(head!=NULL)
    {	
	item=head->item;
    	return true;
    }
    else
	return false;
}

template <class StackElementType>
bool stack<StackElementType>::isEmpty()
{
    return bool(head == NULL);
}

template <class StackElementType>
stack<StackElementType>::~stack()
{
    link current = head;
    while( current != 0 ) 
	{    	
	link previous = current->previous;
    	delete current;
    	current = previous;
	}
	head = 0;
}






class exp 
{
    private:
    char * expr ;
    public:
    exp(char* expression)
    {expr=expression;}
    double expression()
{
    double result = terms();
    while (show() == '+' || show() == '-')
        if (getN() == '+')
            result += terms();
        else
            result -= terms();
    return result;
}
    
    private:
    
char show()
{
    return *expr;
}
char getN()
{
    return *expr++;
}
double num()
{
    double result = getN() - '0';
    while ((show() >= '0' && show() <= '9'))//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    {
        result = 10*result + getN() - '0';
    }
    return result;
}
double factors()
{
    if ((show() >= '0' && show() <= '9'))
        return num();
    else if (show() == '(')
    {
        getN(); // '('
        double result = expression();
        getN(); // ')'
        return result;
    }
    else if (show() == '-')
    {
        getN();
        return -factors();
    }
    return 0; // error
}
double terms()
{
    double result = factors();
    while (show() == 'x' || show() == '/')
        if (getN() == 'x')
            result *= factors();
        else
            {   double x=factors();
                if(x!=0)                
                    result /=x;
                else
                    {
				        cout<<"Invalid Expression";		
				        exit(1); 
                    }
            }
    return result;
}  
};
