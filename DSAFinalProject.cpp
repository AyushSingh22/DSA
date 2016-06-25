// DSAFinalProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SortedList.h"
#include "BST.h"
#include "SLList.h"
#include "Meteorite.h"
#include "UI.h"
#include <fstream>
#include <iostream>
#include <assert.h>
using namespace std;

void testBST()
{
	//test for BST
	BST<int> testree{};
	assert(testree.size() == 0);
	int k1 = 1,k2=2;
	testree.insert(k1);
	assert(testree.size() == 1);
	testree.insert(k2);
	assert(testree.size() == 2);
	IteratorBST<int> it = testree.begin();
	int k3 = it.current->element;
	it++;
	int k4 = it.current->element;
	assert(k3 == 1);
	assert(k4 == 2);
	testree.erase(k2);
	assert(testree.size() == 1);
}



void testLL()
{
	//test for Linked List
	SLList<int> test{};
	assert(test.size() == 0);
	int k1 = 1, k2 = 2;
	test.insert(k1);
	assert(test.size() == 1);
	test.insert(k2);
	assert(test.size() == 2);
	Iterator<int> it = test.begin();
	int k3 = it.current->element;
	it++;
	int k4 = it.current->element;
	assert(k3 == 1);
	assert(k4 == 2);
	test.erase(k2);
	assert(test.size() == 1);
}


int main()
{
	testBST();//running the tests
	testLL();//before the application starts
	UI ui;
	ui.run();



	return 0;
}

