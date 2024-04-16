#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> coll;

    // Insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i) {
        coll.push_back(i);
    }

    // Find position of element with value 5
    vector<int>::iterator pos;
    pos = find(coll.begin(), coll.end(), 5);

    // Print value to which iterator pos refers
    cout << "pos: " << *pos << endl;

    // Convert iterator to reverse iterator rpos
    vector<int>::reverse_iterator rpos(pos);

    // Print value to which reverse iterator rpos refers
    cout << "rpos: " << *rpos << endl;

    return 0;
}
