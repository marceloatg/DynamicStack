#pragma once
#include <iostream>

///  This class stores the node information and a pointer to the previous
/// element in the stack.
template <class Element>
class StackNode
{
public:
	/// Class constructor.
	StackNode();

	/// Class destructor.
	~StackNode();

	/// Element to be stored.
	Element data;

	/// Pointer to previous element.
	StackNode* link;
};

#pragma region "StackNode implementation"
template <class Element>
StackNode<Element>::StackNode()
{
	link = NULL;
}

template <class Element>
StackNode<Element>::~StackNode()
{
}

#pragma endregion

///  This class manages the StackNode objects in order to create a dynamic 
/// heap, with add, get and remove operations concerning to the nodes.
template <class Element>
class Stack
{
public:
	/// Class constructor.
	Stack();

	/// Class destructor.
	~Stack();

	/// Add an element to the top of the stack.
	///
	/// <param element> The Element to be added.
	void add(Element element);

	/// Remove an element from the top of the stack.
	void remove(void);

	/// Get the top element of the stack.
	///
	/// <returns> Returns StackNode<Element> *top.
	Element get(void);

	/// Get the size of the stack (aka quantity of nodes).
	///
	/// <returns> Returns int size.
	inline int getSize(void);

	/// Prints all elements of the stack in order using cout. 
	void printStack(void);

private:
	/// Top node pointer.
	StackNode<Element> *top;

	/// Size of the stack.
	int size;
};

#pragma region "Stack implementation"
template <class Element>
Stack<Element>::Stack()
{
	// Initializing variables.
	this->top = NULL;
	this->size = 0;
}

template <class Element>
Stack<Element>::~Stack()
{
	if (top) delete top;
}

template <class Element>
void Stack<Element>::add(Element element)
{
	// Creating auxiliar StackNode.
	StackNode<Element>* aux = new StackNode<Element>();

	// aux receives the element data and becames the top of the stack.
	aux->data = element;
	aux->link = this->top;
	this->top = aux;

	// Increment stack size and return.
	this->size++;
	return;
}

template <class Element>
void Stack<Element>::remove(void)
{
	// If the stack is empty, return.
	if (this->top == NULL)
	{
		return;
	}

	// Creating auxiliar StackNode.
	StackNode<Element>* aux = this->top->link;

	// Delete top node.
	delete top;
	top = aux;

	// Decrement stack size and return.
	this->size--;
	return;
}

template <class Element>
Element Stack<Element>::get(void)
{
	return this->top->data;
}

template <class Element>
inline int Stack<Element>::getSize(void)
{
	return this->size;
}

template <class Element>
void Stack<Element>::printStack(void)
{
	if (size == 0)
	{
		cout << "Stack is empty." << endl;
	}
	else
	{
		int counter = 0;
		StackNode<Element>* aux = this->top;
		while (true)
		{
			cout << "Element " << counter++ << " : " << aux->data << endl;
			if ((aux = aux->link) == NULL) break;
		}
	}

	return;
}
#pragma endregion