#include <bits/stdc++.h>
using namespace std;
bool isValid(string str, int n)
{
    // If first character is invalid
    if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_'))
        return false;
    // Traverse the string for the rest of the characters
    for (int i = 1; i < str.length(); i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
            return false;
    }
    // String is a valid identifier
    return true;
}
// Driver code
int main()
{
    string str = "_This_is_Valid_Name123";
    cout << "String: " << str << endl;
    int n = str.length();
    if (isValid(str, n))
        cout << "Valid Identifier \n";
    else
        cout << "Invalid Identifier \n";
    string s = "1_not$Valid_name";
    cout << "-----------------------\n";
    cout << "String: " << s << endl;
    n = s.length();
    if (isValid(s, n))
        cout << "Valid Identifier \n";
    else
        cout << "Invalid Identifier \n";
    return 0;
}
