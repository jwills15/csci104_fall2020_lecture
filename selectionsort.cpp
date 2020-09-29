#include <memory>
#include <iostream>
#include "selectionsort.h"
using namespace std;

shared_ptr<Item> findMin(shared_ptr<Item>& head){
    if (head == nullptr) return head;
    
    shared_ptr<Item> min = head;
    while (head->next != nullptr) {
        head = head->next;
        if (head->getValue() < min->getValue()) {
            min = head;
        }
    }

    return min;
} 

shared_ptr<Item> LLSelectionSort(shared_ptr<Item> head){
    // base case
    if (head == nullptr) return head;

    //find low of remaining elements starting from head
    shared_ptr<Item> new_head = findMin(head);

    // perform swaps from head and new head, checks for nullptr
    // ex. new_head->previous = head->previous
    // did not have enough time to implement swaps

    // recursively call next values
    head->next = LLSelectionSort(head->next);
    return head;
} 

int main(){

    shared_ptr<Item> a = make_shared<Item>(2);
 
    shared_ptr<Item> b = make_shared<Item>(11);
    shared_ptr<Item> c = make_shared<Item>(23); 
    shared_ptr<Item> d = make_shared<Item>(3); 
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    d->prev = c;
    c->next = d;

    shared_ptr<Item> sorted = LLSelectionSort(a);

    shared_ptr<Item> temp = sorted;

    while (temp != nullptr){

        cout << "Current value " << temp->getValue() << endl;
        temp = temp->next;
    }
	
    // This code has memory leaks. Why? How to fix?

}
