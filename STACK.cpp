#include "STACK.h"
#include<iostream>
using namespace std;
template <class Type>
void Stack<Type>::push(Type var) //put number on stack 
{
	resize(1);//Calling resize to check if the stack is full we can increase it by 2
	stack[++top] = var;//Increase the top and than store the value
}
template <class Type>
Type Stack<Type>::pop() //take number off stack 
{
	if (isempty())//It gives true when stack is empty
	{
		cout << "Stack is empty\n";
	}
	else
	{
		resize(2);//Calling resize and reducing the size py 2 times
		return stack[top--];//returnig the value and decreasing the top
	}

}
template <class Type>
Type Stack<Type>::peek()
{
	return stack[top];//It just simply return top value
}
template <class Type>
bool Stack<Type>::isfull()
{
	if ((top + 1) - size == 0)//If Top+1 and size have same vlaue means stack is full 
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <class Type>
bool Stack<Type>::isempty()
{
	if (top == -1)//If top goes back to -1 means stack is empty
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <class Type>
void Stack<Type>::resize(int check)
{
	if ((top + 1) - size == 0 && check == 1)//When Stack is full and check is 1 (push condition) this condition is ture
	{
		size = size * 2;//We increase the size by 2 time
		Type* RS = stack;
		stack = new Type[size];//Making a new array of new size
		for (int i = 0; i <= top; i++)
		{
			stack[i] = RS[i];
		}
		
	}
	if ((top * 4) < size && check == 2)//When stack is empty and check is 2 (pop condition) this condition is ture
	{
		size = size / 2;//We decrease the size by 2 time
		Type* RS = stack;
		stack = new Type[size];//Making a new array of new size
		for (int i = 0; i <= top; i++)
		{
			stack[i] = RS[i];
		}
	}
}
template <class Type>
void Stack<Type>::print()
{
	for (int i = 0; i <= top; i++)//Printing the stack uptill top value
	{
		cout << stack[i] << "\n";
	}
}
template <class Type>
int Stack<Type>::gettop()
{
	return top;
}