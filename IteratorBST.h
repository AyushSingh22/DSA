#pragma once
#include <queue>
#include"NodeBST.h"
using namespace std;
template<typename Element>
class IteratorBST
{
public:
	queue<NodeBST<Element>*> q;
	NodeBST<Element>* current;

	IteratorBST() :current(0) {};	//initializer for iterator
	IteratorBST(NodeBST<Element>* r)	//initializing iterator with node
	{
		this->inOrderQueue(r);
		q.push(NULL);
		this->current = this->q.front();
		this->q.pop();
	};
	void inOrderQueue(NodeBST<Element>* node)	//putting the next elements into queue
	{
		if (node == NULL)
		{
			return;
		}
		inOrderQueue(node->left);
		this->q.push(node);
		inOrderQueue(node->right);
	}

	IteratorBST(const IteratorBST<Element>& it)
	{
		this->current = it.current;
		this->q = it.q;
	};
	bool operator!=(const IteratorBST<Element>& it)	//checks if the iterators are pointing to same node
	{
		return this->current != it.current;
	}
	bool operator==(const IteratorBST<Element>& it)	//checks if the iterators are pointing to same node
	{
		return this->current == it.current;
	}

	IteratorBST<Element>& operator=(const IteratorBST<Element>& it)	
	{
		this->current = it.current;
		this->q = it.q;
		return *this;
	}

	IteratorBST<Element>& operator++()	//going to next element ++element
	{

		this->current = this->q.front();
		this->q.pop();
		return *this;
	}

	IteratorBST<Element> operator++(int)	//going to next element element++
	{
		IteratorBST<Element> tmp(*this);
		operator++();
		return tmp;
	}

	Element element() { return current->element; }	//getting the element




};

