#include <algorithm>
#include <functional>
#include "carray.hpp"
#include "print1.hpp"
using namespace std;

int main() {
    carray<int, 10> a;

    for (unsigned i = 0; i < a.size(); ++i) {
        a[i] = i + 1;
    }

    PRINT_ELEMENTS(a);

    reverse(a.begin(), a.end());

    PRINT_ELEMENTS(a);

    transform(a.begin(), a.end(),      // Source
              a.begin(),               // Destination
              negate<int>());         // Operation

    PRINT_ELEMENTS(a);

    return 0;
}
