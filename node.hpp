#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T>
struct NodeValue{
	int x,y;
	T data;
	NodeValue* next;
	NodeValue* down;
	NodeValue(int _x, int _y, T d)
		: x(_x), y(_y), data(d)
	{}
};

template <typename T>
struct NodeLine{
	int pos;
	NodeLine* nextNode;
	NodeValue<T>* nextValue;
	NodeLine(int p)
		: pos(p), nextValue(nullptr), nextNode(nullptr)
	{}

	NodeLine* operator[](int index){
		NodeLine* tmp = this;
		for(int i = 0; i<index; ++i) {
			tmp = tmp->nextNode;
		}
		//cout << "asd" << "\n";
		return tmp;
	}
};

template <typename T>
struct NodeHeader{
	int rows, cols;
	NodeLine<T>* hColumns;
	NodeLine<T>* hRows;
	NodeHeader(){
		hColumns = hRows = nullptr;
		rows = cols = 0;
	}
	NodeHeader(int x, int y)
		: rows(x), cols(y)
	{
		hColumns = hRows = nullptr;
		insertNodes(hRows, x);
		insertNodes(hColumns, y);
	}
private:
	void insertNodes(NodeLine<T>* & nodo, int count){
		for(int i = count-1; i>=0; i--) {
			insertNode(nodo, i);
		}
	}
	void insertNode(NodeLine<T>* & nodo, int pos=0){
		NodeLine<T>* tmp = new NodeLine<T>(pos);
		if(nodo == nullptr){
			nodo = tmp;
			return;
		}
		tmp->nextNode = nodo;
		nodo = tmp;
	}
};

#endif
