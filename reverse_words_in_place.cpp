#include <string>
#include <algorithm>
#include <iostream>
#include <assert.h>

using namespace std;

void reverse_string(string& s, int low, int high, int offset = 0) {
    assert(high < s.size());
    assert(offset >= 0);
    
    low = low - offset;
    while (low < high) {
        swap(s[low], s[high]);
        ++low;
        --high;
    }
}

void reverse_words(string& s) {
    int read = 0;
    int write = 0;
    int low = 0;
    int high = 0;
    int offset = 0;

    while (read < s.size()) {
        if (s[read] != ' ') {
            low = read;
            for (; read < s.size() && s[read] != ' '; read++);
            high = read - 1;
            offset = low - write;
            
            reverse_string(s, low, high, offset);
            
            write += read - low + 1;
        }
        read++;
    }
}

void trim(string& s) {
    int i = s.size() - 1;
    while (s[i] == ' ') {
        s.pop_back();
        i--;
    }
}

int main() {
    string s = "Hello Wily  world ";
    cout << "Original: " << s << endl;
    
    int low = 0;
    int high = s.size() - 1;
    reverse_string(s, low, high);
    reverse_words(s);
    trim(s);
    
    cout << "Reversed: " << s << endl;
}