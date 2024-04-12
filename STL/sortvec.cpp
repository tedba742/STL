#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    /* Create a string vector
     * - Initialized by all words from standard input
     */
    vector<string> coll;
    string word;

    // Read input until end-of-file (EOF) or when the user presses enter
    while (getline(cin, word)) {
        if (word.empty()) // If the input is empty (user pressed enter), break the loop
            break;
        coll.push_back(word);
    }

    // Sort elements
    sort(coll.begin(), coll.end());

    // Print all elements ignoring subsequent duplicates
    unique_copy(coll.begin(), coll.end(),
                ostream_iterator<string>(cout, "\n"));

    return 0;
}
