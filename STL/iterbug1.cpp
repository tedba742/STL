#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> coll1; // empty collection
    vector<int> coll2; // empty collection

    /* RUNTIME ERROR:
     * - beginning is behind the end of the range
     */
    vector<int>::iterator pos = coll1.begin();
    reverse(++pos, coll1.end());

    // Insert elements from 1 to 9 into coll2
    for (int i = 1; i <= 9; ++i) {
        coll2.push_back(i);
    }

    /* RUNTIME ERROR:
     * - overwriting nonexisting elements
     */
    copy(coll2.begin(), coll2.end(),     // source
         coll1.begin());                 // destination

    /* RUNTIME ERROR:
     * - collections mistaken
     * - begin() and end() mistaken
     */
    copy(coll1.begin(), coll2.end(),     // source
         coll1.end());                   // destination

    return 0;
}
