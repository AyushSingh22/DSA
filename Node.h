#pragma once
template< typename Element>
class Node
{
public:
	Element element;
	Node<Element>* next;
	Node() :next(0) {};
	Node(Element el, Node<Element>*n = 0) :element(el), next(n) {};
	Node(const Node<Element>& n)
	{
		this->element = n->element;
		this->next = n->next;
	}
};
