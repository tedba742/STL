#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib> // for abs()

using namespace std;

// Predicate, which returns whether an integer is a prime number
bool isPrime(int number) {
    // Ignore negative sign
    number = abs(number);
    // 0 and 1 are not prime numbers
    if (number == 0 || number == 1) {
        return false;
    }
    // Find divisor that divides without a remainder
    int divisor;
    for (divisor = number / 2; number % divisor != 0; --divisor) {
        ;
    }
    // If no divisor greater than 1 is found, it is a prime number
    return divisor == 1;
}

int main() {
    list<int> coll;

    // Insert elements from 24 to 30
    for (int i = 24; i <= 30; ++i) {
        coll.push_back(i);
    }

    // Search for prime number
    list<int>::iterator pos;
    pos = find_if(coll.begin(), coll.end(), // range
                   isPrime);               // predicate

    if (pos != coll.end()) {
        // Found
        cout << *pos << " is the first prime number found" << endl;
    } else {
        // Not found
        cout << "No prime number found" << endl;
    }

    return 0;
}
