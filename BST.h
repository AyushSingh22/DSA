#pragma once
#include "SortedList.h"
using namespace std;

template<typename Element>
class BST 
{
private:
	int length;
	IteratorBST<Element>* iter;
public:
	NodeBST<Element>* root;

	BST() :root(0), length(0) { iter = new IteratorBST<Element>(); };

	IteratorBST<Element> begin()	//used for iterating through the elements
	{
		IteratorBST<Element> it(this->root);
		return  it;
	}

	IteratorBST<Element> end()	//used for iterating through the elements
	{
		IteratorBST<Element> it(this->root);
		while (it.q.size() != 0)
			it++;
		return  it;
	}

	NodeBST<Element>* leftMost(NodeBST<Element>* node)	//the minimum number from a subtree
	{
		while (node->left != NULL)
			node = node->left;
		return node;
	}

	bool empty()	//checking if empty
	{
		if (length == 0)
			return true;
		return false;
	}

	int size() { return this->length; }	//returns the number of elements

	void* find(Element& k) //checks if an element is in our tree; if it is, it returns 
	{						//an iterator pointing to it;otherwise it returns NULL
		IteratorBST<Element> *it = new IteratorBST<Element>();
		for ((*it) = this->begin(); (*it) != this->end(); (*it)++)
			if (it->element() == k)
				return (void*)it;
		return NULL;
	}

	bool insert(Element el)	//function for inserting elements into our tree
	{
		IteratorBST<Element> *it = new IteratorBST<Element>();
		it = (IteratorBST<Element>*)this->find(el);
		if (it != NULL)
		{
			return false;
		}

		NodeBST<Element>* node = this->root;
		if (node != NULL)
		{
			while (node != NULL)
			{
				if (node->element>=el)
					if (node->left == NULL)
					{
						node->left = new NodeBST<Element>(el, node, NULL, NULL);
						this->length++;
						return true;
					}
					else
						node = node->left;

				else
					if (node->right == NULL)
					{
						node->right = new NodeBST<Element>(el, node, NULL, NULL);
						this->length++;
						return true;
					}
					else
						node = node->right;
			}
		}
		else
		{
			this->root = new NodeBST<Element>(el, NULL, NULL, NULL);
			this->length++;
			return true;
		}
		return true;
	}

	void erase(Element& e) //function for deleting an element from our tree
	{
		IteratorBST<Element> *it = new IteratorBST<Element>();
		it = (IteratorBST<Element>*)this->find(e);
		if (it == NULL)
		{
			return;
		}
		NodeBST<Element> *z, *y, *x, *q;
		z = it->current;
		if (z->left != NULL && z->right != NULL)
		{
			y = this->leftMost(z->right);
		}
		else
		{
			y = z;
		}
		if (y->left != NULL)
		{
			x = y->left;
		}
		else
		{
			x = y->right;
		}
		q = y->parent;
		if (y != z)
		{
			z->element = y->element;
		}
		if (x != NULL)
		{
			x->parent = q;
		}
		if (q != NULL)
		{
			if (q->left == y)
			{
				q->left = x;
			}
			else
			{
				q->right = x;
			}
		}
		else
		{
			this->root = x;
		}
		this->length--;
	}
	void clear()	//emptying the tree
	{
		IteratorBST<Element> it;
		IteratorBST<Element> it2;
		it = this->begin();
		while (it.current != NULL)
		{
			it2 = it;
			delete(it.current);
			it = it2;
			it++;
		}
		this->root = 0;
		this->length = 0;
	}





};

