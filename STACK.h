#pragma once
template <class Type>
class Stack
{
private:
	Type* stack;	//stack: array of any type int top; 					   
	int top;		//number of top of stack
	int size;		//Size of stack
public:
	Stack() //constructor 
	{
		size = 5;
		top = -1;
		stack = new Type[size];
	}
	~Stack()
	{
		delete[] stack;
 	}
	void push(Type); //put number on stack 
	Type pop(); //take number off stack 
	Type peek();//check the top vlaue
	bool isfull();//To check if stack is full or not
	bool isempty();//To check if stack is empty
	void resize(int);//To increase or decrease the size
	void print();//To print the whole stack
	int gettop();
};