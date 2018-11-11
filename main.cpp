#include <iostream>
#include "matrix.hpp"

using namespace std;

int main(){
//int main(int argc, char *argv[]) {
    Matrix<int> a(4, 7);
	a.set(0,5, 3);
	a.set(0,6, 2);
	a.set(0,0, 7);
	
	a.set(1,6, 2);
	//a.set(2,5, 8);
	//a.set(4,6, 1);
	//a.set(5,5, 7);	
	//a.set(3,6, 5);
	//	a.set(2,5, 9);
	//a.set(0,2, 1);
	//a.set(2,3, 6);
	//a.set(0,3, 8);
	//a.set(5,6, -1);
	//a.set(0,5, 5);

	for(int i = 0; i<4;i++){//rows
		for(int j = 0; j<7; ++j) {//cols
			cout << a(j,i) << " ";
		}
		cout << "\n";
	}
    //system("PAUSE");
    return EXIT_SUCCESS;
}
