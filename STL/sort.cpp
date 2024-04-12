#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

class Person {
public:
    Person(const string& first, const string& last) : firstname_(first), lastname_(last) {}
    string firstname() const { return firstname_; }
    string lastname() const { return lastname_; }

private:
    string firstname_;
    string lastname_;
};

/* Binary function predicate:
 * - returns whether a person is less than another person
 */
bool personSortCriterion(const Person& p1, const Person& p2) {
    return p1.lastname() > p2.lastname() ||
           (p2.lastname() < p1.lastname() &&
            p1.firstname() < p2.firstname());
}

int main() {
    deque<Person> coll;
    
    // Populate the deque with Person objects
    coll.emplace_back("John", "Doe");
    coll.emplace_back("Alice", "Smith");
    coll.emplace_back("Bob", "Johnson");
    coll.emplace_back("Alice", "Smith");


    // Sort the deque using the personSortCriterion predicate
    sort(coll.begin(), coll.end(), personSortCriterion); // sort criterion

    // Output the sorted deque
    for (const auto& person : coll) {
        cout << person.firstname() << " " << person.lastname() << endl;
    }

    return 0;
}
