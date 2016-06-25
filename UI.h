#pragma once
#include "BST.h"
#include "SLList.h"
#include "Meteorite.h"
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

class UI
{
private:
	BST<Meteorite> tree{};
	SLList<Meteorite> list{};
	int n;
	Meteorite a[20];
	void loadFromFile()
	{
		clock_t startTime = clock();
		ifstream fin("m.txt"); //can pick m.txt , m2.txt or m3.txt for different inputs 
		fin >> n; //number of meteorites (at most 20)
		for (int i = 0; i < n; i++)
		{
			int c, d;
			fin >> c >> d;	//reading meteorites' coordinates
			a[i].setX1(c); a[i].setX2(d);
		}
		for (int i = 0; i < n; i++)
		{
			tree.insert(a[i]);
			list.insert(a[i]);
		}//inserting the meteorites
		cout << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
	}

	void printAll()	//printing all the initial meteorites in insertion order
	{
		cout << "All the meteorites \n";
		for (int i = 0; i < n; i++)
		{
			cout << a[i].getX1() << " " << a[i].getX2() << endl;
		}

	}
	void printTree()	//print all the elements from the tree
	{
		cout << "Printing the binary search tree\n";
		IteratorBST<Meteorite> it = tree.begin();
		for (; it != tree.end(); it++)
		{
			cout << it.current->element.getX1() << " " << it.current->element.getX2() << endl;

		}
	}

	void printList()	//print all the elements from the list
	{
		cout << "Printing the linked list\n";

		Iterator<Meteorite> it3 = list.begin();
		for (; it3 != list.end(); it3++)
		{
			cout << it3.current->element.getX1() << " " << it3.current->element.getX2() << endl;
		}

	}

	void solveTree()	//solve the problem using the tree
	{
		clock_t startTime = clock();

		int nr = 0;
		Meteorite met[200];


		for (IteratorBST<Meteorite> it = tree.begin(); it != tree.end();)
		{
			IteratorBST<Meteorite> it2 = it;

			it2++;
			for (IteratorBST<Meteorite> jt = it2; jt != tree.end();)
			{
				if (it.current->element.getX1() != jt.current->element.getX1() || it.current->element.getX2() != jt.current->element.getX2())	//we check if the meteorites are different
				{
					if ((it.current->element.getX1()<jt.current->element.getX2() && it.current->element.getX1()>jt.current->element.getX1()) || (it.current->element.getX2()<jt.current->element.getX2() && it.current->element.getX2()>jt.current->element.getX1()) || (jt.current->element.getX1()<it.current->element.getX2() && jt.current->element.getX1()>it.current->element.getX1()) || (jt.current->element.getX2()<it.current->element.getX2() && jt.current->element.getX2()>it.current->element.getX1()))
					{	//we check if the meteorites overlap
						//if they do we delete the second oneint exists = 0;
						int exists = 0;
						for (int r = 0; r < nr; r++)
						{
							if (met[r] == jt.current->element)exists = 1;
						}
						if (exists == 0) { met[nr] = jt.current->element; nr++; }
						jt++;
					}
					else
					{
						++jt;
					}


				}
				else
				{
					++jt;
				}
			}
			it++;

		}

		nr--;

		while (nr >= 0)
		{
			//cout << "Sterge"<<met[nr].getX1()<<" "<<met[nr].getX2()<<endl;
			tree.erase(met[nr]);
			nr--;

		}
		cout << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
		cout << "The elements from the binary search tree were updated!\n";
	}

	void solveList()	//solve the problem using the linked list
	{
		clock_t startTime = clock();
		int nr = 0;
		Meteorite met[200];

		for (Iterator<Meteorite> it = list.begin(); it != list.end();)
		{
			Iterator<Meteorite> it2 = it;

			//cout << it.current->element.getX1() << " " << it.current->element.getX2()<<"test2" << endl;
			it2++;
			Iterator<Meteorite> prev;
			for (Iterator<Meteorite> jt = it2; jt != list.end();)
			{
				if (it.current->element.getX1() != jt.current->element.getX1() || it.current->element.getX2() != jt.current->element.getX2())	//we check if the meteorites are different
				{
					if ((it.current->element.getX1()<jt.current->element.getX2() && it.current->element.getX1()>jt.current->element.getX1()) || (it.current->element.getX2()<jt.current->element.getX2() && it.current->element.getX2()>jt.current->element.getX1()) || (jt.current->element.getX1()<it.current->element.getX2() && jt.current->element.getX1()>it.current->element.getX1()) || (jt.current->element.getX2()<it.current->element.getX2() && jt.current->element.getX2()>it.current->element.getX1()))
					{	//we check if the meteorites overlap
						//if they do we delete the second one
						//cout << jt.current->element.getX1() << " "<<jt.current->element.getX2() << endl;
						int exists = 0;
						for (int r = 0; r < nr; r++)
						{
							if (met[r] == jt.current->element)exists = 1;
						}
						if (exists == 0) { met[nr] = jt.current->element; nr++; }
						Iterator<Meteorite> jt2 = jt;
						prev = jt;
						++jt;
						
						
					}
					else
					{
						prev = jt;
						++jt;
					}


				}
				else
				{
					prev = jt;
					++jt;
				}
			}
			it++;

		}
		nr--;
		
		while (nr >= 0)
		{
			//cout << "Sterge"<<met[nr].getX1()<<" "<<met[nr].getX2()<<endl;
			list.erase(met[nr]);
			nr--;

		}
		cout << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
		cout << "The elements from the linked list were updated!\n";
	}

public:
	UI() { loadFromFile(); }
	void printMenu()
	{
		cout << "Press:\n";
		cout << "1 see all the initial meteorites\n";
		cout << "2 see all the meteorites from the Binary Search Tree\n";
		cout << "3 see all the meteorites from the linked list\n";
		cout << "4 solve the problem using the binary search tree\n";
		cout << "5 solve the problem using the linked list\n";
		cout << "0 exit\n";

	}

	void run()
	{
		int command;
		while (true)
		{
			printMenu();
			cin >> command;
			switch (command)
			{
			case 1:
				printAll();
				break;
			case 2:
				printTree();
				break;
			case 3:
				printList();
				break;
			case 4:
				solveTree();
				break;
			case 5:
				solveList();
				break;
			case 0:
				exit(0);
			default:
				cout << "Something went wrong\n";

			}

		}

	}

};