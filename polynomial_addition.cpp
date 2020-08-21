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
	Queue(const Queue& that) : front(nullptr), rear(nullptr), count(0) {
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
			delete[] old_front;
			--count;
		}
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

struct Term {
	double coefficient;
	int index;
	Term(double coefficient = 0, int index = 0) :coefficient(coefficient), index(index) {}
};
class Polynomial : private Queue<Term> {
public:
	Polynomial() : Queue<Term>() {}

	int degree() const {
		if (empty()) { return -1; }
		return getfront().index;
	}
	int terms() const {
		return size();
	}
	friend ostream& operator<<(ostream& os, const Polynomial& data);
	void print() const {
		Node<Term> *print_node = front;
		while (print_node)
		{
			cout << (print_node->value).coefficient << " " << (print_node->value).index << endl;
			print_node = print_node->next;
		}
	}
	void read() {	// ????????????
		clear();
		int num_of_terms;
		cin >> num_of_terms;
		for (int i = 0; i < num_of_terms; i++) {
			double co;
			int exp;
			cin >> co >> exp;
			Term currentTerm(co, exp);
			append(currentTerm);
		}

	}
	Polynomial operator+(Polynomial rhs) const {
		Polynomial result, lhs = *this;
		while (!lhs.empty() || !rhs.empty()) {
			if (lhs.degree() > rhs.degree()) {
				result.append(lhs.getfront());
				lhs.serve();
			}
			else if (lhs.degree() < rhs.degree()) {
				result.append(rhs.getfront());
				rhs.serve();
			}
			else {
				Term left_term = lhs.getfront(), right_term = rhs.getfront();
				if (left_term.coefficient + right_term.coefficient != 0) {
					Term result_term(left_term.coefficient + right_term.coefficient, lhs.degree());
					result.append(result_term);
				}
				lhs.serve();
				rhs.serve();
			}
		}
		return result;
	}
};
ostream& operator<<(ostream& os, const Polynomial& data) {
	Node<Term> *print_node = data.front;
	if (print_node == nullptr) {
		os << "0";
	}
	while (print_node)
	{
		os << (print_node->value).coefficient;
		os << "x^";
		os << (print_node->value).index;
		os << " ";
		print_node = print_node->next;
	}
	return os;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		Polynomial p, q;
		p.read();
		q.read();
		Polynomial result = p + q;

		cout << result.terms() << endl;
		result.print();
	}
	system("pause");
	return 0;
}
