#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T value;
	Node<T>* next;
	Node() :value(0), next(nullptr) {}
	Node(T value, Node* next = nullptr) :value(value), next(next) {}
};

template <typename T>
class Queue {
protected:
	Node<T> * front, *rear;
	int count;
public:
	Queue() :front(nullptr), rear(nullptr), count(0) {}
	Queue(const Queue& that) {
		*this = that;
	}
	~Queue() {
		clear();
	}

	T getfront() const {
		return front->value;
	}
	T getrear() const {
		return rear->value;
	}
	int size() const { return count; }
	bool empty() const { return size() == 0; }
	void append(const T& item) {
		Node<T> *new_node = new Node<T>(item);
		if (empty()) {
			front = rear = new_node;
		}
		else {
			rear->next = new_node;
			rear = new_node;
		}
		++count;
	}
	void serve() {
		if (!empty()) {
			Node<T> *old_front = front;
			front = front->next;
			if (front == nullptr) { rear = nullptr; }
			delete old_front;
		}
		--count;
	}
	void clear() {
		while (!empty()) {
			serve();
		}
	}

	Queue& operator=(const Queue& rhs) {
		Node<T> *new_front, *new_rear;
		if (rhs.empty()) {
			new_front = new_rear = nullptr;
		}
		else {
			Node<T> *new_node = new Node<T>(rhs.front->value);
			new_front = new_node;
			Node<T> *currentPtr = rhs.front;
			while (currentPtr->next) {
				currentPtr = currentPtr->next;
				new_node->next = new Node<T>(currentPtr->value);
				new_node = new_node->next;
			}
			new_rear = currentPtr;

			clear();
			front = new_front;
			rear = new_rear;
			count = rhs.size();
		}
		return *this;
	}
};

int main()
{
	system("pause");
	return 0;
}