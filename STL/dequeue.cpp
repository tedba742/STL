#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    // Create empty deque of strings
    deque<string> coll;
    
    // Insert several elements
    coll.assign(3, string("string"));
    coll.push_back("last string");
    coll.push_front("first string");
    
    // Print elements separated by newlines
    copy(coll.begin(), coll.end(),
         ostream_iterator<string>(cout,"\n"));
    cout << endl;
    
    // Remove first and last element
    coll.pop_front();
    coll.pop_back();
    
    // Insert ''another'' into every element but the first
    for (int i = 1; i < coll.size(); ++i) {
        coll[i] = "another " + coll[i];
    }
    
    // Change size to four elements
    coll.resize(4, "resized string");
    
    // Print elements separated by newlines
    copy(coll.begin(), coll.end(),
         ostream_iterator<string>(cout,"\n"));
    
    return 0;
}
