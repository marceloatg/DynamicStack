#include <iostream>
#include "DynamicStack.h"

using namespace std;

void main(void)
{
	DynamicStack<float> stack;

	cout << "TESTING STACK___________________________________________________________________" << endl;

	cout << "Add 100, add 200, add 250, add 50." << endl << endl;
	stack.add(100.0f);
	stack.add(200.0f);
	stack.add(250.0f);
	stack.add(50.0f);

	cout << "size of stack: " << stack.getSize() << endl;
	stack.print();

	cout << endl << "Remove top." << endl;
	stack.remove();

	cout << endl << "size of stack: " << stack.getSize() << endl;
	stack.print();

	cout << endl << "Remove 4 times." << endl;
	stack.remove();
	stack.remove();
	stack.remove();
	stack.remove();

	cout << endl << "size of stack: " << stack.getSize() << endl;
	stack.print();

	cout << endl << "Add 750, add 960." << endl << endl;
	stack.add(750.0f);
	stack.add(960.0f);
	cout << "Remove top." << endl;
	stack.remove();
	cout << "Add 1250." << endl;
	stack.add(1250.0f);
	
	cout << endl << "size of stack: " << stack.getSize() << endl;
	stack.print();

	cout << "________________________________________________________________________________" << endl;
	system("pause");
	return;
}