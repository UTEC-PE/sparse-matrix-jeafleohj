#ifndef NODE_H
#define NODE_H

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
		: pos(p)
	{
		nextValue = nullptr;
		nextNode = nullptr;
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
	NodeHeader(int r, int c)
		: rows(r), cols(c)
	{
		//hColumns = nullptr;
		//	insertNode(hColumns);
	}
private:
	void insertNode(NodeLine<T>* & nodo){
		if(nodo == nullptr){
			//nodo = new NodeLine<T>(0);
		}
	}
};

#endif
