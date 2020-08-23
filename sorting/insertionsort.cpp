/* *************************
* FileName: InsertionSort_LinkedList.cpp
* Author: Jed Zhang
* Site: 
* Date: 2018.11.21
* Description: 链表（非STL）的插入排序算法。 
**************************/
#include <iostream>
using namespace std;

struct Node {
	Node(int value, Node* next = nullptr) :value(value), next(next) {}
	int value;
	Node* next;
};
void print(Node* head) {
	while (head) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}

void insertion_sort(Node* &head) {
	if (head != nullptr) {
		Node* last_sorted = head;
		Node* first_unsorted = head->next;
		while (first_unsorted) {
			if (first_unsorted->value < head->value) {
				last_sorted->next = first_unsorted->next;
				first_unsorted->next = head;
				head = first_unsorted;
			}
			else {
				Node* prevPtr = head;
				while (prevPtr->next->value < first_unsorted->value) {
					prevPtr = prevPtr->next;
				}
				if (prevPtr->next == first_unsorted) {
					last_sorted = first_unsorted;
				}
				else {
					last_sorted->next = first_unsorted->next;
					first_unsorted->next = prevPtr->next;
					prevPtr->next = first_unsorted;
				}
			}
			first_unsorted = first_unsorted->next;
		}

	}
}
int main()
{
	Node* node7 = new Node(3);
	Node* node6 = new Node(5, node7);
	Node* node5 = new Node(2, node6);
	Node* node4 = new Node(1, node5);
	Node* node3 = new Node(9, node4);
	Node* node2 = new Node(6, node3);
	Node* node1 = new Node(7, node2);
	Node* node0 = new Node(4, node1);
	print(node0);
	insertion_sort(node0);
	print(node0);

	system("pause");
	return 0;
}
