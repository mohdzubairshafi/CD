#include <iostream>
#include <cctype>
using namespace std;
struct Node
{
    char data;
    Node *left;
    Node *right;
};
// Function to create a new node
Node *createNode(char data)
{
    Node *newNode = new Node();
    if (newNode)
    {
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
    }
    return newNode;
}
// Recursive function to construct the parse tree
Node *parseExpression(string expression, int &index)
{
    if (index >= expression.length())
        return nullptr;
    // Create a new node with the current character
    Node *newNode = createNode(expression[index]);
    // Move to the next character in the expression
    index++;
    // Check if the current character is an operator
    if (index < expression.length() && expression[index] == '+' || expression[index] == '-' ||
        expression[index] == '*' || expression[index] == '/')
    {
        // Recursively construct the left and right subtrees
        newNode->left = parseExpression(expression, index);
        newNode->right = parseExpression(expression, index);
    }
    return newNode;
}
// Function to perform an in-order traversal of the parse tree
void inorderTraversal(Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
// Function to delete the parse tree
void deleteParseTree(Node *root)
{
    if (root)
    {
        deleteParseTree(root->left);
        deleteParseTree(root->right);
        delete root;
    }
}
int main()
{
    string expression;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expression);
    int index = 0;
    Node *root = parseExpression(expression, index);
    cout << "In-order traversal of the parse tree: ";
    inorderTraversal(root);
    cout << endl;
    deleteParseTree(root);
    return 0;
}
