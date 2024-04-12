// iter/advance1.cpp
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<int> coll;

    // Insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i) {
        coll.push_back(i);
    }

    list<int>::iterator pos = coll.begin();

    // Print actual element
    cout << *pos << endl;

    // Step three elements forward
    advance(pos, 3);

    // Print actual element
    cout << *pos << endl;

    // Step three elements backward
    advance(pos, -1);

    // Print actual element
    cout << *pos << endl;

    return 0;
}
