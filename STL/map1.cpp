#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    /* Create map/associative array
     * - Keys are strings
     * - Values are floats
     */
    typedef map<string, float> StringFloatMap;
    StringFloatMap stocks; // Create empty container
    
    // Insert some elements
    stocks["BASF"] = 369.50;
    stocks["VW"] = 413.50;
    stocks["Daimler"] = 819.00;
    stocks["BMW"] = 834.00;
    stocks["Siemens"] = 842.20;
    
    // Print all elements
    StringFloatMap::iterator pos;
    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock: " << pos->first << "\t"
             << "price: " << pos->second << endl;
    }
    cout << endl;
    
    // Boom (all prices doubled)
    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        pos->second *= 2;
    }
    
    // Print all elements
    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock: " << pos->first << "\t"
             << "price: " << pos->second << endl;
    }
    cout << endl;
    
    /* Rename key from "VW" to "Volkswagen"
     * - Only provided by exchanging element
     */
    stocks["Volkswagen"] = stocks["VW"];
    stocks.erase("VW");
    
    // Print all elements
    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock: " << pos->first << "\t"
             << "price: " << pos->second << endl;
    }

    return 0;
}
