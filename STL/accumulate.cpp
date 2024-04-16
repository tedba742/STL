#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <functional> // for std::multiplies

using namespace std;

int main() {
    vector<int> coll;

    // Populate the vector with some values
    for (int i = 1; i <= 5; ++i) {
        coll.push_back(i);
    }

    // Process sum of elements
    cout << "Sum: "
         << accumulate(coll.begin(), coll.end(), 0) // initial value
         << endl;

    // Process sum of elements less 100
    cout << "Sum less 100: "
         << accumulate(coll.begin(), coll.end(), -100) // initial value
         << endl;

    // Process product of elements
    cout << "Product: "
         << accumulate(coll.begin(), coll.end(), 1, multiplies<int>()) // operation
         << endl;

    // Process product of elements (use 0 as initial value)
    cout << "Product with initial 0: "
         << accumulate(coll.begin(), coll.end(), 0, multiplies<int>()) // operation
         << endl;

    return 0;
}
