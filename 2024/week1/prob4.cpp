#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    if (s.size() % 2 != 0)
    {
        return false;
    }
    stack<char> myStack;

    for (size_t i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '{':
        case '[':
        case '(':
            myStack.push(s[i]);
            break;
        case '}':
            if(myStack.empty()){
                return false;
            }
            if (myStack.top() == '{')
            {
                myStack.pop();
            }
            else
            {
                return false;
            }
            break;
        case ']':
        if(myStack.empty()){
                return false;
            }
            if (myStack.top() == '[')
            {
                myStack.pop();
            }
            else
            {
                return false;
            }
            break;
        case ')':
        if(myStack.empty()){
                return false;
            }
            if (myStack.top() == '(')
            {
                myStack.pop();
            }
            else
            {
                return false;
            }
            break;
        default:
            return false;
            break;
        }
    }
    return myStack.empty();
}

int main(int argc, char const *argv[])
{
    string s = "()[]{}";
    bool x = isValid(s);
    cout << x << endl;
    return 0;
}
