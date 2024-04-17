#include <iostream>
#include <string>
using namespace std;

void printAllSequences(string str, string sequence = "", int index = 0) {
    if (index == str.length()) {
        cout << sequence << endl;
        return;
    }

    printAllSequences(str, sequence, index + 1);
    
    printAllSequences(str, sequence + str[index], index + 1);
}

int main() {
    string str = "abc";
    cout << "All sequences of string \"" << str << "\":" << endl;
    printAllSequences(str);
    return 0;
}
