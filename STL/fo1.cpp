#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include <ostream>
using namespace std;

int main() {
    set<int, greater<int>> coll1;
    deque<int> coll2;

    // Insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i) {
        coll1.insert(i);
    }
    
    // Print initialized set
    cout << "initialized: ";
    for (const auto& elem : coll1) {
        cout << elem << " ";
    }
    cout << endl;

    // Transform all elements into coll2 by multiplying by 10
    transform(coll1.begin(), coll1.end(),                  // source
              back_inserter(coll2),                        // destination
              (multiplies<int>(), 10));             // operation
    // Print transformed deque
    cout << "transformed: ";
    for (const auto& elem : coll2) {
        cout << elem << " ";
    }
    cout << endl;

    // Replace value equal to 70 with 42
    replace_if(coll2.begin(), coll2.end(),                 // range
               (equal_to<int>(), 70),               // replace criterion
               42);                                        // new value
    // Print replaced deque
    cout << "replaced: ";
    for (const auto& elem : coll2) {
        cout << elem << " ";
    }
    cout << endl;

    // Remove all elements with values less than 50
    coll2.erase(remove_if(coll2.begin(), coll2.end(),     // range
                           (less<int>(), 50)),      // remove criterion
                coll2.end());
    // Print removed deque
    cout << "removed: ";
    for (const auto& elem : coll2) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
