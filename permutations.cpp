#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> Permutations(string word) {
  if (word.length() == 1)
  {
    vector<string> perm {word};
    return perm;
  }

  vector<string> perms = Permutations(word.substr(1));
  vector<string> result;
  for (vector<string>::iterator iter = perms.begin(); iter != perms.end(); iter++) {
    string str = *iter;
    for (int i = 0; i <= str.length(); i++)
      result.push_back(str.substr(0, i) + word.substr(0, 1) + str.substr(i));
  }
  return result;
}

int main() {
  string word = "LSE";
  vector<string> result = Permutations(word);
  for (vector<string>::iterator iter = result.begin(); iter != result.end(); iter++) {
    cout << *iter << endl;
  }
  return 0;
}    
