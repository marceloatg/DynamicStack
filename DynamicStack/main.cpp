#include <iostream>
#include "Stack.h"

using namespace std;

void main(void)
{
	Stack<float> stack;

	stack.add(100.0f);
	stack.add(200.0f);
	stack.add(250.0f);
	stack.add(50.0f);

	cout << "TESTING STACK___________________________________________________________________" << endl;
	cout << "size of stack: " << stack.getSize() << endl;
	stack.printStack();

	stack.remove();

	cout << endl << "size of stack: " << stack.getSize() << endl;
	stack.printStack();

	stack.remove();
	stack.remove();
	stack.remove();
	stack.remove();

	cout << endl << "size of stack: " << stack.getSize() << endl;
	stack.printStack();

	stack.add(750.0f);
	stack.add(960.0f);
	stack.remove();
	stack.add(1250.0f);
	
	cout << endl << "size of stack: " << stack.getSize() << endl;
	stack.printStack();

	cout << "________________________________________________________________________________" << endl;
	system("pause");
	return;
}