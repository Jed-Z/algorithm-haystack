#include <iostream>
#include <sstream>
#include <vector>
#include "List.hpp"
using namespace std;
// Constructors and destructor
list::list() :head(nullptr), tail(nullptr), _size(0) {}
list::list(const data_type arr[], int length) : head(nullptr), tail(nullptr), _size(0) {
	assign(arr, length);
}
list::list(const list& that) : head(nullptr), tail(nullptr), _size(0) {
	*this = that;
}
list& list::operator=(const list& that) {
	clear();
	node* nowptr = that.head;
	while (nowptr) {
		push_back(nowptr->data);
		nowptr = nowptr->next;
	}
	return *this;
}
list::~list() { clear(); }

// Capacity
bool list::empty(void) const { return _size == 0; }
list::size_type list::size(void) const { return _size; }
// Element access
list::data_type& list::front(void) const { return head->data; }
list::data_type& list::back(void) const { return tail->data; }

// Modifiers
void list::assign(const list& that) {
	*this = that;
}
void list::assign(const data_type arr[], int length) {
	clear();
	for (int i = 0; i < length; i++) {
		push_back(arr[i]);
	}
}

void list::push_front(const data_type& ele) {
	if (head == nullptr) {
		node* temp = new node(ele);
		head = temp;
		tail = temp;
	}
	else {
		node* temp = new node(ele, head, nullptr);
		head->prev = temp;
		head = temp;
	}
	_size++;
}
void list::push_back(const data_type& ele) {
	if (tail == nullptr) {
		node* temp = new node(ele);
		tail = temp;
		head = temp;
	}
	else {
		node* temp = new node(ele, nullptr, tail);
		tail->next = temp;
		tail = temp;
	}
	_size++;
}
void list::pop_front(void) {
	if (_size > 1) {
		node* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
		_size--;
	}
	else {
		delete head;
		head = nullptr;
		tail = nullptr;
		_size = 0;
	}
}
void list::pop_back(void) {
	if (_size > 1) {
		node* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
		_size--;
	}
	else {
		delete tail;
		head = nullptr;
		tail = nullptr;
		_size = 0;
	}
}

void list::insert(int pos, const data_type& ele) {
	if (pos < 0 || pos > _size) { return; }
	if (pos == 0) { push_front(ele); }
	else if (pos == _size) { push_back(ele); }
	else {
		node* nowptr = head;
		for (int i = 0; i < pos; i++) {
			nowptr = nowptr->next;
		}
		node* temp = new node(ele, nowptr, nowptr->prev);
		nowptr->prev->next = temp;
		nowptr->prev = temp;
		_size++;
	}
}
void list::erase(int pos) {
	if (pos<0 || pos>_size) { return; }
	if (pos == 0) { pop_front(); }
	else if (pos == _size - 1) { pop_back(); }
	else {
		node* nowptr = head;
		for (int i = 0; i < pos; i++) {
			nowptr = nowptr->next;
		}
		nowptr->prev->next = nowptr->next;
		nowptr->next->prev = nowptr->prev;
		delete nowptr;
		_size--;
	}

}
void list::clear(void) {
	while (_size != 0) {
		pop_back();
	}
}

// Operators
list::data_type& list::operator[](int index) {
	node* nowptr = head;
	for (int i = 0; i < index; i++) {
		nowptr = nowptr->next;
	}
	return nowptr->data;
}
list& list::operator+=(const list& rhs) {
	node* nowptr = rhs.head;
	while (nowptr) {
		push_back(nowptr->data);
		nowptr = nowptr->next;
	}
	return *this;
}
ostream& operator<<(ostream& os, const list& li) {
	os << li.toString();
	return os;
}

// Output
string list::toString(void) const {
	ostringstream ss;
	ss << "NULL";
	if (head != nullptr) {
		ss << "<-";
		node* nowptr = head;
		while (nowptr->next) {
			ss << nowptr->data << "<->";
			nowptr = nowptr->next;
		}
		ss << nowptr->data << "->NULL";
	}
	return ss.str();
}

// Operations
void list::split(int pos, list* des1, list* des2) {
	if (pos < 0 || pos > _size) { return; }
	des1->clear();
	des2->clear();
	for (int i = 0; i < pos; i++) {
		des1->push_back((*this)[i]);
	}
	for (int i = pos; i < _size; i++) {
		des2->push_back((*this)[i]);
	}
}
list& list::merge(const list& src1, const list& src2) {
	list result;
	node* nowptr = src1.head;
	while (nowptr) {
		result.push_back(nowptr->data);
		nowptr = nowptr->next;
	}
	nowptr = src2.head;
	while (nowptr) {
		result.push_back(nowptr->data);
		nowptr = nowptr->next;
	}
	*this = result;
	return *this;
}
list& list::unique(void) {
	if (empty()) { return *this; }
	vector<data_type> vec;
	node* nowptr = head;
	while (nowptr) {
		bool isrepeat = false;
		for (int i = 0; i < vec.size(); i++) {
			if (nowptr->data == vec[i]) {
				isrepeat = true;
				break;
			}
		}
		if (!isrepeat) {
			vec.push_back(nowptr->data);
		}
		nowptr = nowptr->next;
	}
	clear();
	for (int i = 0; i < vec.size(); i++) {
		this->push_back(vec[i]);
	}
	return *this;
}
list& list::reverse(void) {
	if (empty()) { return *this; }
	vector<data_type> vec;
	node* nowptr = tail;
	while (nowptr) {
		vec.push_back(nowptr->data);
		nowptr = nowptr->prev;
	}
	clear();
	for (int i = 0; i < vec.size(); i++) {
		this->push_back(vec[i]);
	}
	return *this;
}
list& list::remove_if(bool(*condition)(listPointer)) {
	node* nowptr = head;
	while (nowptr) {
		node* temp = nowptr->next;
		bool isbad = (*condition)(nowptr);
		if (isbad) {
			if (nowptr == head) {
				erase(0);
			}
			else if (nowptr == tail) {
				erase(size() - 1);
			}
			else {
				nowptr->prev->next = nowptr->next;
				nowptr->next->prev = nowptr->prev;
				delete nowptr;
				_size--;
			}
		}
		nowptr = temp;
	}
	return *this;
}