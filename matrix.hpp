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
	{}

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
		if( data ){
			NodeValue<T>* nnode = new NodeValue<T>(c,r,data);
			if( (*matrix.hColumns)[c]->nextValue == nullptr ){
				(*matrix.hColumns)[c]->nextValue = nnode;
			}else{
				NodeValue<T>* it = (*matrix.hColumns)[c]->nextValue;
				if( r < it->y ){
					nnode->down = it;
					(*matrix.hColumns)[c]->nextValue = nnode;
				}else{
					while( it && it->y <= r){
						if(it->y == r){
							it->data = data;
							delete nnode;
							nnode = nullptr;
							break;
						}else if(it->down == nullptr){
							it->down = nnode;
							break;
						}else if(it->down->y > r){
							NodeValue<T>* down = it->down;
							it->down = nnode;
							nnode->down = down;
							break;
						} 
						it = it->down;
					}
				}
			}
			if( (*matrix.hRows)[r]->nextValue == nullptr ){
				(*matrix.hRows)[r]->nextValue = nnode;
			}else{
				NodeValue<T>* itr = (*matrix.hRows)[r]->nextValue;
				if( c < itr->x ){
					nnode->next = itr;
					(*matrix.hRows)[r]->nextValue = nnode;
				}else{
					while( itr && itr->x <= c){
					  	if(itr->x == c){

					  		itr->data = data;
					  		delete nnode;
					  		nnode = nullptr;
					  		break;
					  	}else if(itr->next == nullptr){
							itr->next = nnode;
					  		break;
					  	}else if(itr->next->x > c){
					 		NodeValue<T>* next = itr->next;
					 		itr->next = nnode;
					 		nnode->next = next;
					 		break;
					  	} 
					 	itr = itr->next;
					}
				}
			}
		}else{
			if( (*matrix.hColumns)[c]->nextValue ){
				NodeValue<T>* it = (*matrix.hColumns)[c]->nextValue;
				//no libero memoria.
				if( it->y == r){
					//(*matrix.hColumns)[c]->nextValue = it->down;
				}else{
					//falta testear esto
					while( it && it->down && it->y <= r ){
						if( it->y == r){
							//it->data = 0;
							it = nullptr;
						}
						it = it->down;
					}
				}

				it = (*matrix.hRows)[r]->nextValue;
				if( it->x == c){
					(*matrix.hRows)[r]->nextValue = it->next;
					delete it;
					it = nullptr;
				}else{
					while( it->next){
						cout << it->x<<" "<<it->y<<" "<<it->data <<" "<<c<< "\n";
						if( it->next->x == c){
							NodeValue<T>* node = it->next;
							it->next = node->next;
							delete node;
							node = nullptr;
							break;
						}
						it = it->next;
					}
				}

			}
		}
	}else{
		throw std::out_of_range ("Index Error");
	}
}

template<typename T>
T Matrix<T>::operator()(int x, int y){
	// if( (*matrix.hColumns)[x]->nextValue != nullptr ){
	// 	NodeValue<T>* it = (*matrix.hColumns)[x]->nextValue;
	// 	while(it && it->y <= y){
	// 		if(it->y == y){
	// 			return it->data;
	// 		}
	// 		it = it->down;
	// 	}
	// }
	if( (*matrix.hRows)[y]->nextValue != nullptr ){
		NodeValue<T>* it = (*matrix.hRows)[y]->nextValue;
		while(it && it->x <= x){
			if(it->x == x){
				return it->data;
			}
			it = it->next;
		}
	}
	return -1;
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
