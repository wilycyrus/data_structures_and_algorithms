//
// Balanced Parentheses
//
    
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool balance(const string& s) {
    stack<char> stack_;
    
    unordered_map<char, char> pairs = {
        {'(', ')'}, {'[', ']'}, {'{', '}'}
    };
    
    // Extract values from the dictionary
    vector<char> close;
    close.reserve(pairs.size());
    for (auto item: pairs) {
        close.push_back(item.second);
    }
    
    for (int i = s.length() - 1; i >= 0; --i) {
        char c = s[i];

        vector<char>::iterator it =
            find(close.begin(), close.end(), c);
        
        if (it != close.end()) {
            cout << "pushing " << c << " to stack" << endl;
            stack_.push(c);
        } else if (!stack_.empty() && stack_.top() == pairs[c]) {
            cout << "poping " << stack_.top() << " from stack" << endl;
            stack_.pop();
        } else {
            return false;
        }
    }
    
    if (stack_.empty())
        return true;
    else
        return false;
}

int main() {
    string s = "([{})";
    if (balance(s))
        cout << "balanced" << endl;
    else
        cout << "unbalanced" << endl;
    return 0;
}
