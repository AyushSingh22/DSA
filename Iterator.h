#pragma once
#include "Node.h"
template<typename Element>
class Iterator
{
public:
	Node<Element>* current;
public:
	Iterator() :current(NULL) {};	//initializer
	Iterator(Node<Element>* c) :current(c) {};	//initializing iterator pointing to node
	Iterator(const Iterator<Element>& it)	
	{
		this->current = it.current;
	};
	bool operator!=(const Iterator<Element>& it)	//checking if two iterators are different
	{
		return this->current != it.current;
	}
	bool operator==(const Iterator<Element>& it)	//checking if 2 iterators are equal
	{
		return this->current == it.current;
	}
	Iterator<Element>& operator=(const Iterator<Element>& it)	
	{
		this->current = it.current;
		return *this;
	}

	Iterator<Element>& operator++()	//going to next element ++element
	{

		current = current->next;
		return *this;
	}

	Iterator<Element> operator++(int)	//going to next element element++
	{
		Iterator<Element> tmp(*this);
		operator++();
		return tmp;
	}

	Element element() { return current->element; }	//getting the element


};

