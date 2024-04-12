#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Simple function object that prints the passed argument
class PrintInt {
public:
    void operator() (int elem) const {
        cout << elem << ' ';
    }
};

int main() {
    vector<int> coll;

    // Insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i) {
        coll.push_back(i);
    }

    // Print all elements
    for_each(coll.begin(), coll.end(),    // range
             PrintInt());                  // operation
    cout << endl;

    return 0;
}
