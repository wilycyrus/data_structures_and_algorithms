//
// Find the number of delete operations in order to make two string to anagrams
//

#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<char, int> build_map() {
    unordered_map<char, int> map;
    map.reserve(26);
    const string alphabets = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    for (auto letter: alphabets) {
        map[letter] = i;
        ++i;
    }
    return map;
}

vector<int> count_alphabets(const string& str, const unordered_map<char, int>& map) {
    vector<int> counts(26, 0);
    
    for (auto letter: str) {
        int index = 0;
        try {
            index = map.at(letter);
        } catch (out_of_range& ex)
        {
            cout << "\nOut of range exception caught.\n" << ex.what() << endl;
        }
        counts[index] += 1;
    }
    return counts;
}

int find_anagram(const string& str1, const string& str2) {
    unordered_map<char, int> map = build_map();
    
    // Count the occurence of each alphabet
    vector<int> counts1 = count_alphabets(str1, map);
    vector<int> counts2 = count_alphabets(str2, map);
    
    int diff_sum = 0;
    for (int i = 0; i < counts1.size(); ++i) {
        diff_sum += abs(counts1[i] - counts2[i]);
    }
    return diff_sum;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << find_anagram(str1, str2) << endl;
    return 0;
}
