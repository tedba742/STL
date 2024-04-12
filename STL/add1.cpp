#include <iostream>
#include <vector> 
#include <set>
#include <algorithm>
#include "print1.hpp"

int square(int value) {
    return value * value;
}

int main() {
    
    std::vector<int> coll2;
    std::set<int, std::greater<int>> coll1;  // sorted set in reverse order 9,8,7,6,5,4,3,2,1
    // Insert elements from 1 to 9 into coll1
    for (int i = 1; i <= 9; ++i) {
        coll1.insert(i);
    }
    PRINT_ELEMENTS(coll1, "initialized: ");

    // Transform each element from coll1 to coll2
    // - square transformed values
    std::transform(coll1.begin(), coll1.end(),        // source
                   std::back_inserter(coll2),          // destination
                   square);                            // operation

    PRINT_ELEMENTS(coll2, "squared: ");

    return 0;
}
