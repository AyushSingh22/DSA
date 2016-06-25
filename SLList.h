#pragma once
#include "SortedList.h"
using namespace std;
template<typename Element>
class SLList 
{
private:
	Node<Element>* first;	//pointing to the start of the linked list
	int length;	//number of elements
	Iterator<Element> *iter;	//iterator

public:
	SLList() :first(0), length(0) { iter = new Iterator<Element>(); };	//initializer

	Iterator<Element> begin() { return  Iterator<Element>(this->first); }	//used for iterating through the elements

	Iterator<Element> end() { return  Iterator<Element>(0); }	//used for iterating through the elements

	bool empty()	//checks if the linked list is empty
	{
		if (length == 0)
			return true;
		return false;
	}

	int size() { return this->length; }	//returns the size of the linked list

	void* find(Element& e)	//searches for an elements in the linked list; if it is in the list it returns
	{						//an iterator pointing to the element, otherwise it returns null
		Iterator<Element> *it = new Iterator<Element>();
		(*it) = this->begin();
		if (this->iter->current != NULL && this->iter->element()<e)
		{
			(*it) = *(this->iter);
		}
		//
		for (; (*it) != this->end(); (*it)++)
			if (it->element() == e)
				return (void*)it;
		delete(it);
		return NULL;
	}


	bool insert(Element el)	//inserting an element in the list
	{
		Iterator<Element> *prev = new Iterator<Element>();
		Iterator<Element> *it = new Iterator<Element>();
		it = (Iterator<Element>*)this->find(el);
		if (it != NULL)
		{
			delete(it);
			delete(prev);
			return false;

		}

		if (this->empty())
		{
			Node<Element> *n = new Node<Element>(el, 0);
			this->first = n;
			*(this->iter) = Iterator<Element>(this->first);
			this->length++;
			delete(it); delete(prev);
			return true;
		}
		Iterator<Element> *it2 = new Iterator<Element>();
		(*it2) = this->begin();

		if (this->iter->element()<el)
		{
			(*it2) = *(this->iter);
		}
		if (el < this->begin().current->element)
		{
			Node<Element>* t = new Node<Element>(el, this->begin().current);
			first = t;
			return true;
		}
		for (; (*it2) != this->end() && it2->element()<el; (*it2)++)
		{
			*prev = *it2;
			*(this->iter) = *it2;
		}
		prev->current->next = new Node<Element>(el, it2->current);
		this->length++;
		delete(it);
		delete(prev);
		return true;
	}

	void erase(Element& e)	//erasing an element from the list if it exists in the list
	{
		
		Node<Element>* actual = first;
		Node<Element>* prev;
		while (actual->element != e&&actual != NULL)
		{
			prev = actual;
			actual = actual->next;
		}
		if (actual == first)
		{
			first = actual->next;
			this->length--;
			return;
		}
		if (actual == NULL)
			return;
		prev->next = actual->next;
		this->length--;
		return;

	}
	void clear()	//emptying the linked list
	{
		Iterator<Element> *it = new Iterator<Element>();
		Node<Element>* next;
		(*it) = this->begin();
		while (it->current != NULL)
		{
			next = it->current->next;
			delete(it->current);
			it->current = next;
		}
		this->first = 0;
		this->length = 0;
		delete(it);
	}

};


