#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void allProducts_helper(const vector<int>& primes, vector<int>& products, int currProd, size_t idx) {
    if (idx == primes.size()) {
        products.push_back(currProd);
    } else {
        // try a product w/o this prime
        allProducts_helper(primes, products, currProd, idx+1);
        // try one with this prime
        allProducts_helper(primes, products, currProd*primes[idx], idx+1);
    }
}

// Write a recursive function that returns all products of the subsets
// of set of primes in the vector primes
// You may use helper functions
// Trace your function on the set {2,3}
vector<int> allProducts(const vector<int>& primes) 
{
  vector<int> products;
  allProducts_helper(primes, products, 1, 0);
  return products;
}

void sortAndPrint(vector<int> nums){
   sort(nums.begin(), nums.end());
   for(unsigned int i=0; i < nums.size(); i++){
      cout << nums[i] << " ";  
   }
   cout << endl;

}

int main(int argc, char* argv[]) {
   // Answers go in this vector
   vector<int> products;
   
   vector<int> primes1;
   products = allProducts(primes1);
   sortAndPrint(products);
   
   products.clear();
   vector<int> primes2;
   primes2.push_back(2); primes2.push_back(5);
   products = allProducts(primes2);
   sortAndPrint(products);

   products.clear();
   vector<int> primes3;
   primes3.push_back(2); primes3.push_back(3); primes3.push_back(7); 
   products = allProducts(primes3);
   sortAndPrint(products);

   products.clear();
   vector<int> primes4;
   primes4.push_back(2); primes4.push_back(3); primes4.push_back(5); primes4.push_back(11);
   products = allProducts(primes4);
   sortAndPrint(products);

   return 0;   
}
