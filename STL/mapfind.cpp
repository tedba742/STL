#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

/* Function object to check the value of a map element */
template <class K, class V>
class value_equals {
private:
    V value;

public:
    // Constructor (initialize value to compare with)
    value_equals(const V& v) : value(v) {}

    // Comparison
    bool operator() (const pair<const K, V>& elem) const {
        return elem.second == value;
    }
};

int main() {
    typedef map<float, float> FloatFloatMap;
    FloatFloatMap coll;
    FloatFloatMap::iterator pos;

    // Fill container
    coll[1] = 7;
    coll[2] = 4;
    coll[3] = 2;
    coll[4] = 3;
    coll[5] = 6;
    coll[6] = 1;
    coll[7] = 3;

    // Search an element with key 3.0
    pos = coll.find(3.0); // Logarithmic complexity
    if (pos != coll.end()) {
        cout << pos->first << ": " << pos->second << endl;
    }

    // Search an element with value 3.0
    pos = find_if(coll.begin(), coll.end(), value_equals<float, float>(3.0)); // Linear complexity
    if (pos != coll.end()) {
        cout << pos->first << ": " << pos->second << endl;
    }

    return 0;
}
