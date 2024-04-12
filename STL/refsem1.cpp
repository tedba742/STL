#include <iostream>
#include <list>
#include <deque>
#include <algorithm>
#include "countptr.hpp"

using namespace std;

void printCountedPtr(CountedPtr<int> elem) {
    cout << *elem << ' ';
}

int main() {
    // Array of integers (to share in different containers)
    static int values[] = {3, 5, 9, 1, 6, 4};

    // Two different collections
    typedef CountedPtr<int> IntPtr;
    deque<IntPtr> coll1;
    list<IntPtr> coll2;

    /* Insert shared objects into the collections
     * - Same order in coll1
     * - Reverse order in coll2
     */
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        IntPtr ptr(new int(values[i]));
        coll1.push_back(ptr);
        coll2.push_front(ptr);
    }

    // Print contents of both collections
    for_each(coll1.begin(), coll1.end(), printCountedPtr);
    cout << endl;
    for_each(coll2.begin(), coll2.end(), printCountedPtr);
    cout << endl << endl;

    /* Modify values at different places
     * - Square third value in coll1
     * - Negate first value in coll1
     * - Set first value in coll2 to 0
     */
    *coll1[2] *= *coll1[2];
    (**coll1.begin()) *= -1;
    (**coll2.begin()) = 0;

    // Print contents of both collections again
    for_each(coll1.begin(), coll1.end(), printCountedPtr);
    cout << endl;
    for_each(coll2.begin(), coll2.end(), printCountedPtr);
    cout << endl;

    return 0;
}
