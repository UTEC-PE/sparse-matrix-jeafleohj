#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "node.hpp"

using namespace std;

template <typename T>
class Matrix {
private:
	NodeHeader<T> matrix;

public:
	Matrix()
		: matrix()
	{}

	Matrix(int sizeX, int sizeY)
		: matrix(sizeX, sizeY)
	{

	}

	void set(int x, int y, T data);
	T operator()(int x, int y);
	Matrix<T> operator*(Matrix<T> other);
	Matrix<T> operator*(T scalar);
	Matrix<T> operator+(Matrix<T> other);
	Matrix<T> operator-(Matrix<T> other);
	Matrix<T> transposed();
	Matrix<T> operator=(Matrix<T> other);
	~Matrix();
};

template<typename T>
void Matrix<T>::set(int r, int c, T data){
	if( -1 < c && c < matrix.cols &&
		-1 < r && r < matrix.rows){
		NodeValue<T>* nnode = new NodeValue<T>(c,r,data);
		if( (*matrix.hColumns)[c]->nextValue == nullptr ){
			(*matrix.hColumns)[c]->nextValue = nnode;
		}else{
			NodeValue<T>* it = (*matrix.hColumns)[c]->nextValue;
			if( y < it->y ){
				(*matrix.hRows)[x]->nextValue = nnode;
				nnode->down = it;

			}else{
				while( it && it->y < y){
					if(it->down == nullptr){
						it->down = nnode;
					}else if( it->down && y < it->down->y ){
						nnode= it->down;
						it->down = nnode;
					}
					it = it->down;
				}				
			}
		}
	}else{
		throw std::out_of_range ("Index Error");
	}
}

template<typename T>
T Matrix<T>::operator()(int x, int y){
	if( (*matrix.hColumns)[x]->nextValue != nullptr ){
		NodeValue<T>* it = (*matrix.hColumns)[x]->nextValue;
		while(it && it->y <= y){
			if(it->y == y){
				return it->data;
			}
			it = it->down;
		}
	}
	return 0;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> other){

}

template<typename T>
Matrix<T> Matrix<T>::operator*(T scalar){

}

template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> other){

}

template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> other){

}

template<typename T>
Matrix<T> Matrix<T>::transposed(){
}

template<typename T>
Matrix<T> Matrix<T>::operator=(Matrix<T> other){
	
}

template<typename T>
Matrix<T>::~Matrix(){
	
}

#endif
