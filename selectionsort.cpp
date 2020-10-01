#include <memory>
#include <iostream>
#include "selectionsort.h"
using namespace std;

shared_ptr<Item> findMin(shared_ptr<Item>& head){
    if (head == nullptr) return head;
    
    shared_ptr<Item> min = head;
    shared_ptr<Item> cursor = head;
    while (cursor->next != nullptr) {
        cursor = cursor->next;
        if (cursor->getValue() < min->getValue()) {
            min = cursor;
        }
    }

    if (min == head) {
        head = head->next;
        head->prev = nullptr;
    }
    if (min->next != nullptr) {
        min->next->prev = min->prev;
    }
    if (min->prev != nullptr) {
        min->prev->next = min->next;
    }
    
    min->next = nullptr;
    min->prev = nullptr;
    return min;
} 

shared_ptr<Item> LLSelectionSort(shared_ptr<Item> head){
    // base case
    if (head == nullptr || head->next == nullptr) return head;

    //find low of remaining elements starting from head
    shared_ptr<Item> min = findMin(head);

    // perform swaps from head and new head, checks for nullptr
    min->next = LLSelectionSort(head);
    if (head != nullptr) head->prev = min;

    return min;
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
