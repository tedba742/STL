#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator> // Include the header for ostream_iterator
using namespace std;

int main() {
    // Create empty vector for strings
    vector<string> sentence;
    
    // Reserve memory for five elements to avoid reallocation
    sentence.reserve(5);
    
    // Append some elements
    sentence.push_back("Hello,");
    sentence.push_back("how");
    sentence.push_back("are");
    sentence.push_back("you");
    sentence.push_back("?");
    
    // Print elements separated with spaces
    copy(sentence.begin(), sentence.end(),
         ostream_iterator<string>(cout, " "));
    cout << endl;
    
    // Print ''technical data''
    cout << "max_size(): " << sentence.max_size() << endl;
    cout << "size(): " << sentence.size() << endl;
    cout << "capacity(): " << sentence.capacity() << endl;
    
    // Swap second and fourth element
    swap(sentence[1], sentence[3]);
    
    // Insert element "always" before element "?"
    sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");
    
    // Assign "!" to the last element
    sentence.back() = "!";
    
    // Print elements separated with spaces
    copy(sentence.begin(), sentence.end(),
         ostream_iterator<string>(cout, " "));
    cout << endl;
    
    // Print "technical data" again
    cout << "max_size(): " << sentence.max_size() << endl;
    cout << "size(): " << sentence.size() << endl;
    cout << "capacity(): " << sentence.capacity() << endl;

    return 0;
}
