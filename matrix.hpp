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
void Matrix<T>::set(int x, int y, T data){
	
}
template<typename T>
T Matrix<T>::operator()(int x, int y){

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
~Matrix();

#endif
