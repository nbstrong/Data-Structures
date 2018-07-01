/*#include <iostream>

#include "Book.h"

class double_linked
{
    struct node
    {
        Book book;
        node* prev;
        node* next;
        //node(Book t, node* p, node* n) : data(t), prev(p), next(n) {}
    };

protected:
    node* head;
    node* tail;

public:
    double_linked() : head( NULL ), tail ( NULL ) {}
    template<int N>
    /*double_linked( T (&arr) [N]) : head( NULL ), tail ( NULL )
    {
        for( int i(0); i != N; ++i)
            push_back(arr[i]);
    }*/

   /* bool empty() const { return ( !head || !tail ); }
    operator bool() const { return !empty(); } 
    void push_back(T);
    void push_front(T);
    T pop_back();
    T pop_front();

    ~double_linked()
    {
        while(head)
        {
            node* temp(head);
            head=head->next;
            delete temp;
        }
    }*/
//};