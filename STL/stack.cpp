#include <iostream>
#include "Stack.hpp" // use special stack class

using namespace std;

int main() {
    try {
        Stack<int> st;

        // push three elements into the stack
        st.push(1);
        st.push(2);
        st.push(3);

        // pop and print two elements from the stack
        cout << st.pop() << ' ';
        cout << st.pop() << ' ';

        // modify top element
        st.top() = 77;

        // push two new elements
        st.push(4);
        st.push(5);

        // pop one element without processing it
        st.pop();

        /* pop and print three elements
         * - ERROR: one element too many
         */
        cout << st.pop() << ' ';
        cout << st.pop() << endl;
        cout << st.pop() << endl;
    } catch (const exception& e) {
        cerr << "EXCEPTION: " << e.what() << endl;
    }

    return 0;
}
