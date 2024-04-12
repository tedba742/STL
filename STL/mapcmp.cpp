#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip> // Added for setw
using namespace std;

/* Function object to compare strings
 * - Allows you to set the comparison criterion at runtime
 * - Allows you to compare case insensitive
 */
class RuntimeStringCmp {
public:
    // Constants for the comparison criterion
    enum cmp_mode { normal, nocase };

private:
    // Actual comparison mode
    const cmp_mode mode;

    // Auxiliary function to compare case insensitive
    static bool nocase_compare(char c1, char c2) {
        return toupper(c1) < toupper(c2);
    }

public:
    // Constructor: initializes the comparison criterion
    RuntimeStringCmp(cmp_mode m = normal) : mode(m) {}

    // The comparison
    bool operator() (const string& s1, const string& s2) const {
        if (mode == normal) {
            return s1 < s2;
        }
        else {
            return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), nocase_compare);
        }
    }
};

/* Container type:
 * - Map with
 *   - String keys
 *   - String values
 *   - The special comparison object type
 */
typedef map<string, string, RuntimeStringCmp> StringStringMap;

// Function that fills and prints such containers
void fillAndPrint(StringStringMap& coll);

int main() {
    // Create a container with the default comparison criterion
    StringStringMap coll1;
    fillAndPrint(coll1);

    // Create an object for case-insensitive comparisons
    RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);

    // Create a container with the case-insensitive comparisons criterion
    StringStringMap coll2(ignorecase);
    fillAndPrint(coll2);

    return 0;
}

void fillAndPrint(StringStringMap& coll) {
    // Fill insert elements in random order
    coll["Deutschland"] = "Germany";
    coll["deutsch"] = "German";
    coll["Haken"] = "snag";
    coll["arbeiten"] = "work";
    coll["Hund"] = "dog";
    coll["gehen"] = "go";
    coll["Unternehmen"] = "enterprise";
    coll["unternehmen"] = "undertake";
    coll["gehen"] = "walk";
    coll["Bestatter"] = "undertaker";

    // Print elements
    StringStringMap::iterator pos;
    cout.setf(ios::left, ios::adjustfield);
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << setw(15) << pos->first << " " << pos->second << endl;
    }
    cout << endl;
}
