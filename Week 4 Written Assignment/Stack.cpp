#include <iostream>
#include <istream>
#include "Stack.h"

using namespace std;
template<class ItemType>
class Stack {

	bool isEmpty() {
		if (this.head == NULL)
			return true;
		else
			return false;
	}

	void push(ItemType& newEntry) {
		
		node* temp = new node;

		if (head == NULL) {
			head == new node;
			head == newEntry;
			head->next == NULL;
		}
		else (head != NULL) {
			temp == head;
			head == new node;
			head == newEntry;
			head->next == temp;
			temp == NULL;
		}
	}

	ItemType pop() {
		
		ItemType tempVal = head->value;
		node *temp == head;
		head == temp->next;
		temp->next == NULL;
		delete(temp);
		return tempVal;
	}

	ItemType peek() {
		return head->value;
	}

	void destroy() {

		while (head != NULL) {
			this.pop();
		}
	}
};
