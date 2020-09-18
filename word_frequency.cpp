#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Word {
    string content;
    int count;
    Word(string content) : content(content), count(1) {}
    void increase() { ++count; }
    bool operator==(const Word& rhs) { return content == rhs.content; }
};

bool comp1(const Word& w1, const Word& w2) { return w1.content < w2.content; }
bool comp2(const Word& w1, const Word& w2) { return w1.count > w2.count; }
int main() {
    vector<Word> vec;
    string s;
    while (cin >> s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        while (s[0] == '(') {
            s.erase(0, 1);
        }
        while (s[s.size() - 1] == ',' || s[s.size() - 1] == '.' || s[s.size() - 1] == '?' || s[s.size() - 1] == ':' ||
               s[s.size() - 1] == ')') {
            s.erase(s.size() - 1, 1);
        }

        Word currentWord(s);
        auto wordPtr = find(vec.begin(), vec.end(), currentWord);
        if (wordPtr != vec.end()) {
            wordPtr->increase();
        } else {
            vec.push_back(currentWord);
        }
    }
    stable_sort(vec.begin(), vec.end(), comp1);
    stable_sort(vec.begin(), vec.end(), comp2);

    cout << "------------" << vec.size() << endl;
    int i = 1;
    for (vector<Word>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << "#" << i++ << "  " << it->content << "   " << it->count << endl;
    }

    system("pause");
    return 0;
}