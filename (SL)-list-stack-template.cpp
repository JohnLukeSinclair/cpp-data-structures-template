#include <iostream>

struct Node {
	int data;
	Node* next;
};

class Stack {
private:
	Node* head;
	int stackSize;
public:
	Stack() {
		head = NULL;
		stackSize = 0;
	}

	// adds node to top of stack
	void push(int data) {
		Node* newNode = new Node;
		if (!newNode) {
			std::cerr << "memory wansn't allocated successfully" << std::endl;
			return;
		}
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		stackSize++;
	}

	// removes node from top of stack and returns its data
	int pop() {
		if (!head) {
			std::cerr << "Stack is empty. Unable to pop." << std::endl;
			return -1;
		}
		Node* temp = head;

		head = head->next;

		int value = temp->data;

		delete temp;
		stackSize--;

		return value;
	}

	// returns the top node->data
	int top() {
		if (!head) {
			std::cerr << "Stack is empty." << std::endl;
			return -1;
		}
		return head->data;
	}

	// returns true if the stack is empty
	bool isEmpty() {
		return !head;
	}

	// returns number of nodes in stack
	int size() {
		return stackSize;
	}

	// clears all nodes in stack
	void clear() {
		while (head) {
			pop();
		}
	}

	// prints all node->data in the stack
	void printStack() {
		Node* temp = head;

		while (temp) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}

	// destructor
	~Stack() {
		clear();
	}
};

int main()
{
}
