#pragma once

#ifndef _STACK
#define _STACK
template<class ItemType>
class Stack
{
public:
	struct node {
		ItemType value;
		node* next;
	};

	node* head;

	bool isEmpty();
	void push(ItemType& newEntry);
	ItemType pop();
	ItemType peek();
	void destroy();
};
#endif