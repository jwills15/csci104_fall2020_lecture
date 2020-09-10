#include <memory>
#include <iostream>
#include "DoubleLL.h"



DoubleLL::DoubleLL(DoubleLL const & other){
         //place holder
}
	
	// assignment operator
DoubleLL& DoubleLL::operator=(DoubleLL const & other){
        // placeholder really
        return *this;
}

	// Destructor. Should delete all data allocated by the list. 
DoubleLL::~DoubleLL(){
  // we'll write this during class
    while(!this->empty()) {
        this->remove(tail);
    }
}

	// Gets item at an index.
int DoubleLL::get(size_t index) const {
      //does nothing useful
      return -1;
}

	// get length of list.
size_t DoubleLL::size() const {
       return count;
}

	// returns true iff the list is empty.
bool DoubleLL::empty() const {
	return (count == 0);
}

	// Inserts (a copy of) the given item at the end of list.
void DoubleLL::push_back(int value) {
      //also not useful yet...
}

void DoubleLL::push_front(int value) {
        if (count == 0){
           head = std::make_shared<Item>(value);
           tail = head;
        } else {

           std::shared_ptr<Item> tmp = head;
           head = std::make_shared<Item>(value);
           head->next = tmp;
           if (head->next) head->next->prev = head;
        }
        count++;
}

	// Sets the item at the given index to have the given value.
	// If an index is passed that is >= the number of items in the list, it should "wrap around" back to the first element.
void DoubleLL::set(size_t index, int value){
        // place holder
}

	// Removes the item at the given index from the list.
void DoubleLL::remove(size_t index){
      // also place holder
}

void DoubleLL::remove(std::shared_ptr<Item> p){
    // our implementation
    if (count == 1) { // only one, remove it so that there is 0
        head = nullptr;
        tail = nullptr;
    }
    else if (p == head) { // move the head to the right
        head = p->next;
        head->prev = nullptr;
    }
    else if (p == tail) { // move the head to the left
        tail = p->prev;
        tail->next = nullptr;
    }
    else {
        p->next->prev = p->prev; // remove the item from somewhere in the middle
        p->prev->next = p->next;
    }

    /* discussed implementation
    if (!p) return;
    if (p != head) {
        p->prev->next = p->next; // not the head, previous item must jump over this
    } else {
        head = p->next; // it is the head, set the new head
    }
    if (p != tail) {
        p->next->prev = p->prev; // not the tail, next item must jump over this
    } else {
        tail = p->prev;
    } */

    count--;
    std::cout << p.use_count() << std::endl;
}
