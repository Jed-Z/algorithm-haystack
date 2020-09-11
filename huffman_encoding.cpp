#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Node {
    char data;
    int weight;
    Node *left, *right;

    Node(char data, int weight = 0, Node* left = nullptr, Node* right = nullptr)
        : data(data), weight(weight), left(left), right(right) {}
};

Node* merge_two(Node* left, Node* right) {
    // Node data equals to '0' means this is an internal node in the huffman tree.
    return new Node('\0', left->weight + right->weight, left, right);
}

void build_recursive(Node* subRoot, map<char, string>& table, string code) {
    if (subRoot != nullptr) {
        if (subRoot->left == nullptr && subRoot->right == nullptr) {  // If this is a leaf,
            table[subRoot->data] = code;                              // insert it into the table.
        } else {                                                      // If this is an internal node.
            build_recursive(subRoot->left, table, code + '0');        // Left:  0;
            build_recursive(subRoot->right, table, code + '1');       // Right: 1.
        }
    }
}

Node* build_huffman_tree(vector<Node*>& forest) {
    while (forest.size() > 1) {
        sort(forest.begin(), forest.end(), [](const Node* lhs, const Node* rhs) { return lhs->weight < rhs->weight; });
        forest[1] = merge_two(forest[0], forest[1]);
        forest.erase(forest.begin());
    }
    return forest[0];
}

map<char, string> build_encoding_table(Node* root) {
    map<char, string> result;
    build_recursive(root, result, "");  // Call recursive function with an empty string.
    return result;
}

map<char, int> build_frequency(vector<Node*>& forest) {
    map<char, int> result;
    for (int i = 0, len = forest.size(); i < len; i++) {
        result[forest[i]->data] = forest[i]->weight;
    }
    return result;
}

string encode(const string& origin, map<char, string>& table) {
    string result;
    for (char c : origin) {
        result += table[c];
    }
    return result;
}

// void DEBUG_printmap1(map<char, string> themap) {
//	for (auto it = themap.begin(); it != themap.end(); it++) {
//		cout << it->first << " " << it->second << endl;
//	}
//}
//
// void DEBUG_printmap2(map<char, int> themap) {
//	for (auto it = themap.begin(); it != themap.end(); it++) {
//		cout << it->first << " " << it->second << endl;
//	}
//}

void print_encode_ins() {
    cout << "*** Huffman Encoding ***" << endl;
    cout << "Caution: Only support English pure text files." << endl;
    cout << endl;
}

int main() {
    print_encode_ins();

    ifstream infile;
    string infileName;
    cout << "Input file name: ";
    cin >> infileName;
    infile.open(infileName);
    if (!infile.is_open()) {
        cerr << "ERROR OPEN FILE! EXITING..." << endl;
        system("pause");
        exit(1);
    }

    string text((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

    int buckets[256] = {0};
    for (char c : text) {
        ++buckets[int(c)];
    }

    vector<Node*> forest;
    for (int i = 0; i < 256; i++) {
        if (buckets[i] != 0) {
            forest.emplace_back(new Node(char(i), buckets[i]));
        }
    }

    map<char, int> frequency = build_frequency(forest);

    Node* huffmanRoot = build_huffman_tree(forest);
    map<char, string> encodingTable = build_encoding_table(huffmanRoot);
    string encodeText = encode(text, encodingTable);

    //	DEBUG_printmap2(frequency);
    //	cout << "************************" << endl;
    //	DEBUG_printmap1(encodingTable);
    //	cout << "************************" << endl;
    //	cout << encodeText << endl;

    /* Begin writing into binary file. */
    ofstream outfile;
    string outfileName;
    cout << "Output file name (better end with .huf): ";
    cin >> outfileName;
    outfile.open(outfileName, ios::binary);
    if (!outfile.is_open()) {
        cerr << "ERROR OPEN FILE! EXITING..." << endl;
        system("pause");
        exit(1);
    }

    char header[4] = {char(0xde), char(0xad), char(0xbe), char(0xef)};  // This is a file header.
    outfile.write(header, 4);

    int charNum = frequency.size(), encodeNum = encodeText.length();
    outfile.write((char*)&charNum, sizeof(charNum));
    outfile.write((char*)&encodeNum, sizeof(encodeNum));

    for (auto it = frequency.begin(); it != frequency.end(); it++) {
        char currentChar = it->first;
        int currentFreq = it->second;
        outfile.write((char*)&currentChar, sizeof(currentChar));
        outfile.write((char*)&currentFreq, sizeof(currentFreq));
    }

    if (encodeNum % 8 != 0) {
        encodeText += string(8 - encodeNum % 8, '0');
    }

    for (int i = 0; i < encodeText.length(); i += 8) {
        char currentByte = stoi(encodeText.substr(i, 8), nullptr, 2);
        outfile.write((char*)&currentByte, sizeof(currentByte));
    }

    outfile.close();
    cout << "Encoding finished! See \"" << outfileName << "\"." << endl;
    system("pause");
    return 0;
}
