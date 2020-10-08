#include<iostream>
#include <memory>
#include <algorithm>
using namespace std;

template <typename T>
struct Item {    
    T val;    
    shared_ptr<Item<T>> left;    
    shared_ptr<Item<T>> right;      
    shared_ptr<Item<T>> parent;    
  };
  
  // Bin. Search Tree
  template <typename T>
  class BinTree {    
        public:    
        BinTree()= default;    
        ~BinTree()= default; // Yes, there are memory leaks now    
        // Add is provided for you and adds node to tree with value v
        void add(const T& v) ;    
        // Implement count recursively to return the number of nodes in the tree
        int count();    
        // Implement height recursively to return the height of the tree
        int height();
        private:   
        int count_help(shared_ptr<Item<T>> root);
        int height_help(shared_ptr<Item<T>> root);
        shared_ptr<Item<T>> root;   
        // You may add private data members and functions
  };

template <typename T>
int BinTree<T>::count() {
    return count_help(root);
}
template <typename T>
int BinTree<T>::count_help(shared_ptr<Item<T>> root) {
    if (root == nullptr) return 0;
    return 1 + count_help(root->left) + count_help(root->right);
}

template <typename T>
int BinTree<T>::height() {
    return height_help(root);
}
template <typename T>
int BinTree<T>::height_help(shared_ptr<Item<T>> root) {
    if (root == nullptr) return 0;
    return 1 + max(height_help(root->left), height_help(root->right));
}    
 
   
   int main(){    
       BinTree<int> b1;    
       b1.add(4);    
       b1.add(5);    
       b1.add(3);    
       b1.add(9);    
       b1.add(7);    
       cout << "num of nodes " << b1.count() << endl;    
       cout << "height " << b1.height() << endl;    
       return 0;
   }

// Provided for you
 template <typename T>
 void BinTree<T>::add(const T& v) {        
        if (root == nullptr){            
            root = make_shared<Item<T>>();            
            root->val = v;        
         } else {                        
            shared_ptr<Item<T>> temp = root;                
            while (temp != nullptr){                
                if (v <= temp->val){                    
                   if (temp->left == nullptr){                        
                       temp->left = make_shared<Item<T>>();                        
                       temp->left->val =v;                        
                       temp->left->parent = temp;                        
                       return;                    
                    }                    
                    temp = temp->left;                
                } else {                    
                     if (temp->right==nullptr){                       
                         temp->right = make_shared<Item<T>>();                        
                         temp->right->val = v;                        
                         temp->right->parent = temp;                        
                         return;                   
                      }                    
                      temp = temp->right;                
                 }            
             }        
          }    
             
   }