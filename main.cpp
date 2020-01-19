#include <iostream>
#include <fstream>
#include "test.h"

using namespace std;

// declares header file
typing_test test;


// starting display
int main(){
	cout << "Typing Test\n";
	cout << "Press Enter to Continue";
	cin.ignore();
	test.start();
}
