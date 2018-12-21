#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <bitset>
using namespace std;

struct Node {
	char data;
	int weight;
	Node *left, *right;

	Node(char data, int weight = 0, Node* left = nullptr, Node* right = nullptr) :
		data(data), weight(weight), left(left), right(right) {}
};

Node* merge_two(Node* left, Node* right) {
	// Node data equals to '0' means this is an internal node in the huffman tree.
	return new Node('\0', left->weight + right->weight, left, right);
}

Node* build_huffman_tree(vector<Node*> &forest) {
	while (forest.size() > 1) {
		sort(forest.begin(), forest.end(), [](const Node* lhs, const Node* rhs){return lhs->weight < rhs->weight;});
		forest[1] = merge_two(forest[0], forest[1]);
		forest.erase(forest.begin());
	}
	return forest[0];
}

string decode(Node* root, string encodeText) {
	string result;
	Node* currentPtr = root;
	for(char c : encodeText) {
		if(c=='0') {
			currentPtr = currentPtr->left;
		}
		else if(c=='1') {
			currentPtr = currentPtr->right;
		}
		if(currentPtr->left==nullptr && currentPtr->right==nullptr) {    // currentPtr points to a leaf.
			result += currentPtr->data;
			currentPtr = root;    // Restore currentPtr.
		}
	}
	return result;
}

void print_decode_ins() {
	cout << "*** Huffman Decoding ***" << endl;
	cout << "Warning: If the file you open was not generated by my HuffmanCoding.exe,\n         then I don't know what will happen! The program may die!" << endl;
	cout << endl;
}
int main()
{
	print_decode_ins();
	
	ifstream infile;
	string infileName;
	cout << "Input file name: ";
	cin >> infileName;
	infile.open(infileName);
	if(!infile.is_open()){
		cerr << "ERROR OPEN FILE! EXITING..." << endl;
		system("pause");
		exit(1);
	}
	
	char header[4];
	infile.read(header, 4);
	if(header[0]!=char(0xde) || header[1]!=char(0xad) || header[2]!=char(0xbe) || header[3]!=char(0xef)) {
		cerr << "[Fatal Error]: The file you input is not generated by the corresponding HuffmanCoding.exe! Exiting..." << endl;
		system("pause");
		exit(2);
		
	}
	
	int charNum, encodeNum;
	infile.read((char*)&charNum, sizeof(charNum));
	infile.read((char*)&encodeNum, sizeof(encodeNum));
	
	/* Make frequency map */
	map<char, int> frequency;
	for(int i = 0; i < charNum; i++){
		char currentChar;
		int currentFreq;
		infile.read((char*)&currentChar, sizeof(currentChar));
		infile.read((char*)&currentFreq, sizeof(currentFreq));
		frequency[currentChar] = currentFreq;
	}
	
	/* Make forest vector and build huffman tree */
	vector<Node*> forest;
	for(auto it = frequency.begin(); it != frequency.end(); it++) {
		forest.emplace_back(new Node(it->first, it->second));
	}
	Node* huffmanRoot = build_huffman_tree(forest);
	
	/* Get encoded text */
	string encodeText;
	char tempEncodeText[encodeNum/8+1];
	infile.read(tempEncodeText, encodeNum/8+1);
	for(int i = 0; i < encodeNum/8+1; i++) {
		encodeText += bitset<8>(int(tempEncodeText[i])).to_string();
	}
	encodeText = encodeText.substr(0, encodeNum);    // Discard spare zeros.
	
	/* Use huffman tree to decode */
	string originText = decode(huffmanRoot, encodeText);
	
	ofstream outfile;
	string outfileName;
	cout << "Output file name: ";
	cin >> outfileName;
	outfile.open(outfileName, ios::binary);
	if(!outfile.is_open()){
		cerr << "ERROR OPEN FILE! EXITING..." << endl;
		system("pause");
		exit(1);
	}
	outfile << originText;
	
	infile.close();
	cout << "Decoding finished! See \"" << outfileName << "\"." << endl;
	system("pause"); 
	return 0;
} 
