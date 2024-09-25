#include <stack>
#include <iostream>

#include <string>
#include <cctype>
using namespace std;

int prec(char c) {
     return (c == '+' c == '-') ? 1 : (c == '*' c == '/') ? 2
                                                                        : -1; }

void infixToPostfix(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (isalnum(c))
            cout << c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (st.top() != '(')
                cout << st.top(), st.pop();
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(c) <= prec(st.top()))
                cout << st.top(), st.pop();
            st.push(c);
        }
    }
    while (!st.empty())
        cout << st.top(), st.pop();
}

int main()
{
    string exp = "a+b(c^d-e)^(f+gh)-i";
    infixToPostfix(exp);
    return 0;
}