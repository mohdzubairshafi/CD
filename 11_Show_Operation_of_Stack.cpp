#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<string> symbolStack;
    // Push symbols onto the stack
    symbolStack.push("int");
    symbolStack.push("=");
    symbolStack.push("10");
    symbolStack.push("+");
    symbolStack.push("5");
    // Display the contents of the stack
    cout << "Stack Contents: ";
    while (!symbolStack.empty())
    {
        cout << symbolStack.top() << " ";
        symbolStack.pop();
    }
    cout << endl;
    return 0;
}
