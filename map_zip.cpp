// map_zip.cpp - Mark Redekopp
//
// Another example usage of maps:  sparse arrays
//  A sparse array is one where only a few indicides
//  are used but the range of index values is large

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm> // needed for built-in sort and count
using namespace std;

bool zip_comp(const pair<int,int> &lhs, const pair<int,int> &rhs)
{ return lhs.first < rhs.first; }
bool occ_comp(const pair<int,int> &lhs, const pair<int,int> &rhs)
{ return lhs.second < rhs.second; }

int main(int argc, char *argv[])
{
  if(argc < 2){
    cerr << "Usage: ./map_zip zipcode_filename" << endl;
    return -1;
  }
  ifstream zipfile(argv[1]);
  if(!zipfile.good()){
    cerr << "Unable to open file" << argv[1] << endl;
  }
  vector<int> all_zips;

  int zipCode;
  zipfile >> zipCode;
  while(!zipfile.fail()){
    all_zips.push_back(zipCode);
    zipfile >> zipCode;
  }
  zipfile.close();

    // Key = zipcode, Value = Num. of Occurrences
    // Iterate through all the zip codes in 'all_zips' and 
    // create a map of zipcode to number of occurrences
    map<int, int> occurrences;
    map<int, int>::iterator map_it;
    vector<int>::iterator vector_it;

    for(vector_it = all_zips.begin(); vector_it != all_zips.end(); vector_it++){
        map_it = occurrences.find(*vector_it);
        if (map_it == occurrences.end()){
            occurrences.insert(make_pair(*vector_it,1));
        }
        else {
            map_it->second++;
        }
    }

    cout << "Zip code, occurrence table" << endl;
    // Print table of the zip codes with occurrences
    for (map_it = occurrences.begin(); map_it != occurrences.end(); map_it++) {
        cout << "Zip: " << map_it->first << " (Occurrences: " << map_it->second << ")" << endl;
    }

    // sort the zip codes
    sort(all_zips.begin(), all_zips.end());
 
    // figure out the number of occurrences of the first zip code in sorted order 
    //without using the map
    int count = 0;
    vector_it = all_zips.begin();
    while (*vector_it == all_zips[0]) {
        count++;
        vector_it++;
    }
    cout << "occurrences of zip code " << all_zips[0]  << " : " << count << endl;
    // can also get count with "count(all_zips.begin(), all_zips.end(), all_zips[0]"

    return 0;
  
}
