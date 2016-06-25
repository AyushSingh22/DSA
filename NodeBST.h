#pragma once

template<typename Element>
class NodeBST
{

public:
	Element element;
	NodeBST<Element>* parent;
	NodeBST<Element>* left;
	NodeBST<Element>* right;
	NodeBST() :left(0), right(0) {};
	NodeBST(Element el, NodeBST<Element>*p = 0, NodeBST<Element>*l = 0, NodeBST<Element>*r = 0) :element(el), parent(p), left(l), right(r) {};
	NodeBST(const NodeBST<Element>& n)
	{
		this->element = n->element;
		this->parent = n->parent;
		this->left = n->left;
		this->right = n->right;
	}
	NodeBST<Element>& operator=(const NodeBST<Element>& n)
	{
		this->element = n->element;
		this->parent = n->parent;
		this->left = n->left;
		this->right = n->right;
		return *this;
	}


};


