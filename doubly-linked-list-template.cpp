#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;
};

class NodeList {
private:
	Node* head;
	Node* tail;
public:
	NodeList() {
		head = NULL;
		tail = NULL;
	}

	// appends node to end of list
	void appendNode(int data) {
		Node* newNode = new Node;
		if (!newNode) {
			std::cerr << "Memory allocation error\n";
			return;
		}
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = tail;

		if (!head) {
			head = newNode;
			tail = head;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
		}
	}

	// inserts node at beginning of list
	void insertNode(int data) {
		Node* newNode = new Node;
		if (!newNode) {
			std::cerr << "Memory allocation error\n";
			return;
		}
		newNode->data = data;
		newNode->next = head;

		if (head) {
			head->prev = newNode;
		}
		head = newNode;
	}

	// updates node with data 'data' to 'newData'
	void updateNode(int data, int newData) {
		if (!head) {
			return;
		}

		Node* nodePtr = head;

		while (nodePtr) {
			if (nodePtr->data == data) {
				nodePtr->data = newData;
				return;
			}
			nodePtr = nodePtr->next;
		}

		std::cout << "Node " << data << " is not in list" << std::endl;
	}

	// deletes node with data 'data'
	void deleteNode(int data) {
		if (!head) {
			return;
		}

		Node* current = head;
		Node* prev = NULL;

		while (current && current->data != data) {
			prev = current;
			current = current->next;
		}

		if (current) {
			if (prev) {
				if (current == tail) {
					tail = prev;
				}
				prev->next = current->next;
				if (current->next) {
					current->next->prev = prev;
				}
				delete current;
			}
			else {
				if (head->next) {
					head->next->prev = NULL;
				}
				head = head->next;
				delete current;
			}
		}
		else {
			std::cout << "Node " << data << " is not in list" << std::endl;
		}
	}

	// deletes node at head of list
	void deleteHead() {
		if (!head) {
			return;
		}

		Node* temp = head;
		if (head->next) {
			head->next->prev = NULL;
		}
		head = head->next;
		delete temp;
	}

	// deletes node at tail of list
	void deleteTail() {
		if (!head) {
			return;
		}

		Node* temp = tail;
		if (tail->prev) {
			tail->prev->next = NULL;
		}
		else {
			head = NULL;
		}
		tail = tail->prev;
		delete temp;
	}

	// prints all elements in linked list
	void printList() {
		if (!head) {
			return;
		}

		Node* temp = head;

		while (temp) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}

	// destructor
	~NodeList() {
		while (head) {
			deleteHead();
		}
	}
};

int main()
{
}
