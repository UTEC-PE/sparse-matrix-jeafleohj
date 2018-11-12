#include <iostream>
#include "matrix.hpp"

using namespace std;

int main(){
//int main(int argc, char *argv[]) {
    Matrix<int> a(4, 7), b;
	a.set(0,5, 3);
	a.set(0,6, 2);
	a.set(0,0, 7);
	a.set(0,1, 1);	
	a.set(0,2, 1);
	a.set(0,3, 8);
	a.set(1,6, 7);
	a.set(2,6, 8);
	a.set(3,0,0);
	b= a;
	b = b * a.transposed();
	cout << "RES: " << "\n";
	cout << b <<endl;
	cout << a ;
    return EXIT_SUCCESS;
}
