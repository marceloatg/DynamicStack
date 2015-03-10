#pragma once
#include <iostream>

///  This class stores the node information and a pointer to the previous
/// element in the stack.
template <class Element>
class DynamicStackNode
{
public:
	/// Class constructor.
	DynamicStackNode();

	/// Class destructor.
	~DynamicStackNode();

	/// Element to be stored.
	Element data;

	/// Pointer to previous element.
	DynamicStackNode* link;
};

#pragma region "DynamicStackNode implementation"
template <class Element>
DynamicStackNode<Element>::DynamicStackNode()
{
	link = NULL;
}

template <class Element>
DynamicStackNode<Element>::~DynamicStackNode()
{
}

#pragma endregion

///  This class manages the DynamicStackNode objects in order to create a dynamic 
/// heap, with add, get and remove operations concerning to the nodes.
template <class Element>
class DynamicStack
{
public:
	/// Class constructor.
	DynamicStack();

	/// Class destructor.
	~DynamicStack();

	/// Add an element to the top of the stack.
	///
	/// <param element> The Element to be added.
	void add(Element element);

	/// Remove an element from the top of the stack.
	void remove(void);

	/// Get the top element of the stack.
	///
	/// <returns> Returns DynamicStackNode<Element> *top.
	Element get(void);

	/// Get the size of the stack (aka quantity of nodes).
	///
	/// <returns> Returns int size.
	inline int getSize(void);

	/// Prints all elements of the stack in order using cout. 
	void print(void);

private:
	/// Top node pointer.
	DynamicStackNode<Element> *top;

	/// Size of the stack.
	int size;
};

#pragma region "Dynamic stack implementation"
template <class Element>
DynamicStack<Element>::DynamicStack()
{
	// Initializing variables.
	this->top = NULL;
	this->size = 0;
}

template <class Element>
DynamicStack<Element>::~DynamicStack()
{
	if (top) delete top;
}

template <class Element>
void DynamicStack<Element>::add(Element element)
{
	// Creating auxiliar DynamicStackNode.
	DynamicStackNode<Element>* aux = new DynamicStackNode<Element>();

	// aux receives the element data and becames the top of the stack.
	aux->data = element;
	aux->link = this->top;
	this->top = aux;

	// Increment stack size and return.
	this->size++;
	return;
}

template <class Element>
void DynamicStack<Element>::remove(void)
{
	// If the stack is empty, return.
	if (this->top == NULL)
	{
		return;
	}

	// Creating auxiliar DynamicStackNode.
	DynamicStackNode<Element>* aux = this->top->link;

	// Delete top node.
	delete top;
	top = aux;

	// Decrement stack size and return.
	this->size--;
	return;
}

template <class Element>
Element DynamicStack<Element>::get(void)
{
	return this->top->data;
}

template <class Element>
inline int DynamicStack<Element>::getSize(void)
{
	return this->size;
}

template <class Element>
void DynamicStack<Element>::print(void)
{
	if (size == 0)
	{
		cout << "Stack is empty." << endl;
	}
	else
	{
		int counter = 0;
		DynamicStackNode<Element>* aux = this->top;
		while (true)
		{
			cout << "Element " << counter++ << " : " << aux->data << endl;
			if ((aux = aux->link) == NULL) break;
		}
	}

	return;
}
#pragma endregion