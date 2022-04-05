#include<iostream>
#include<string>
#include"STACK.h"
#include"STACK.cpp"
using namespace std;

bool isbalanced(string brackets)
{
	Stack<char> s1, s2;
	int count = 0;
	for (int i = 0; i < brackets.size(); i++)
	{
		if (brackets[i]=='[' || brackets[i] == '{' || brackets[i] == '(' || brackets[i] == ')' || brackets[i] == '}' || brackets[i] == ']')
		{
			s1.push(brackets[i]);	//Entering whole string in Stack
			count++;
		}
	}
	int check1 = 0, check2 = 0, check3 = 0;
	char check;
	for (int i = 0; i < count; i++)
	{
		check = s1.pop();
		if (check == ')')//If closing bracket deteted than increase check
		{
			check1++;
		}
		if (check == '(')//If opeing comes than reduce the check at the end if some bracket is missing check will have its count
		{
			check1--;
		}
		if (check == '}')//If closing bracket deteted than increase check
		{
			check2++;
		}
		if (check == '{')//If opeing comes than reduce the check at the end if some bracket is missing check will have its count
		{
			check2--;
		}
		if (check == ']')//If closing bracket deteted than increase check
		{
			check3++;
		}
		if (check == '[')//If opeing comes than reduce the check at the end if some bracket is missing check will have its count
		{
			check3--;
		}
	}
	if (check1 < 0)//If the values of check is negatice make it positive
	{
		check1 = check1 * (-1);
	}
	if (check2 < 0)//If the values of check is negatice make it positive
	{
		check2 = check2 * (-1);
	}
	if (check3 < 0)//If the values of check is negatice make it positive
	{
		check3 = check3 * (-1);
	}
	if (check1+check2+check3==0)//If sum is zero means no bracket is needed hence valid
	{
		cout << "Equation is Valid\n";
		return 1;
	}
	else
	{
		cout << "Equation is InValid\n";
		return 0;
	}
}

void infixtopostfix(string expression)
{
	int brackets = 0;//It is used to check the count of brackets
	Stack<string>s1,s2,s3;
	string check;
	bool sign = true;//To just enter the sign in stack for first time
	bool Double = false;
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] >= 97 && expression[i] <= 122)//If it is some small letter than store it in stack
		{
			check = expression[i];
			s1.push(check);
		}
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || i + 1 == expression.size() || expression[i] == '(' || expression[i] == ')')
		{//To manage all the signs
			if (expression[i] == '(')//If opening bracket comes it increases the bracket
			{
				brackets++;
			}
			if (s2.isempty())//To just enter the first sign with out checking
			{
				string check3;
				check3 = expression[i];
				s2.push(check3);
			}
			else
			{
				if (expression[i] == ')')//If closing bracket comes we pop all the signs until opening brackets comes
				{
					while (s2.peek() != "(")
					{
						string check3;
						check3 = s2.pop();
						s1.push(check3);
					}
					s2.pop();//To pop opening also
					brackets--;//To reduce the number brackets after solving them
					continue;
				}
				if (expression[i] == '*' || expression[i] == '/')//If it is * or / and stack has + or - we pop it and replace them
				{
					if (s2.peek() == "+" || s2.peek() == "-")
					{
						string check1, check2;
						s2.push("a");
						s2.pop();
						check1 = s2.pop();
						check2 = expression[i];
						//Exchanging Signs according to precedence
						s2.push(check1);
						s2.push(check2);
						Double = true;//To pop two signs after two are pushed
					}
					else
					{
						if (Double == false)//If it is false we just pop only one sign
						{
							if (brackets == 0)//If there are not brackets then we pop otherwise just push
							{
								s2.push("a");
								s2.pop();
								s1.push(s2.pop());
								string check3;
								check3 = expression[i];
								s2.push(check3);
							}
							else
							{
								string check3;
								check3 = expression[i];
								s2.push(check3);
							}
						}
						else //Here we have two elements in sign stack
						{
							if (brackets == 0)
							{	//Here we again check the precedence
								if (expression[i]=='/' || expression[i] == '*')
								{
									string check4 = s2.pop();
									if (s2.peek() =="+" || s2.peek() == "-")
									{
										s2.push(check4);
										s1.push(s2.pop());
										string check1, check2;
										s2.push("a");
										s2.pop();
										check1 = s2.pop();
										check2 = expression[i];
										s2.push(check1);
										s2.push(check2);
										Double = true;
									}
								}
								else //If precednce is okay then just pop
								{
									s1.push(s2.pop());
									s1.push(s2.pop());
									string check3;
									check3 = expression[i];
									s2.push(check3);
									Double = false;
								}
							}
							else//Otherwise just push the element
							{
								string check3;
								check3 = expression[i];
								s2.push(check3);
								Double = false;
							}
						}
					}
				}
				else
				{
					if (Double == false)
					{
						if (brackets == 0)
						{
							s2.push("a");
							s2.pop();
							s1.push(s2.pop());
							string check3;
							check3 = expression[i];
							s2.push(check3);
						}
						else
						{
							string check3;
							check3 = expression[i];
							s2.push(check3);
						}
					}
					else //If predence is okay then we just check it and push and pop elements accordingly
					{
						if (brackets == 0)
						{//Here predence is checked
							if (expression[i] == '/' || expression[i] == '*')
							{
								string check4 = s2.pop();
								if (s2.peek() == "+" || s2.peek() == "-")
								{
									s2.push(check4);
									s1.push(s2.pop());
									string check1, check2;
									s2.push("a");
									s2.pop();
									check1 = s2.pop();
									check2 = expression[i];
									s2.push(check1);
									s2.push(check2);
									Double = true;
								}
							}
							else //In case precedene is okay we just pop and push
							{
								s1.push(s2.pop());
								s1.push(s2.pop());
								string check3;
								check3 = expression[i];
								s2.push(check3);
								Double = false;
							}
						}
						else //Ottherwise just push the sign
						{
							string check3;
							check3 = expression[i];
							s2.push(check3);
							Double = false;
						}
					}
				}
			}
		}
	}
	while (!(s1.isempty()))//Here we push total stack in another stack to invert it
	{
		s3.push(s1.pop());
	}
	while (!(s3.isempty()))//And finally print it
	{
		cout << s3.pop();
	}
}
void evaluate(string expression, int a)
{
	Stack<int> s1,s2;
	if (a==0)//Here we check if it is prefix or not
	{
		for (int i = 0; i < expression.size(); i++)
		{
			if (expression[i]=='/')//If we read / we pop two element and perfrom /
			{
				int a, b;
				b = s1.pop();
				a = s1.pop();
				s1.push(a / b);
			}
			else if (expression[i] == '*')//If we read * we pop two element and perfrom *
			{
				int a, b;
				b = s1.pop();
				a = s1.pop();
				s1.push(a * b);
			}
			else if (expression[i] == '+')//If we read + we pop two element and perfrom +
			{
				int a, b;
				b = s1.pop();
				a = s1.pop();
				s1.push(a + b);
			}
			else if (expression[i] == '-')//If we read - we pop two element and perfrom -
			{
				int a, b;
				b = s1.pop();
				a = s1.pop();
				s1.push(a - b);
			}
			else
			{
				s1.push(expression[i] - 48);//If it is some digit convert it from char to int by subtracting 48
			}
		}
		s1.print();
	}
	if (a==1)//To check postfix
	{
		reverse(expression.begin(), expression.end());//To simply reverse the string
		for (int i = 0; i < expression.size(); i++)
		{
			if (expression[i] == '/')//If we read / we pop two element and perfrom /
			{
				int a, b;
				b = s1.pop();
				a = s1.pop();
				s1.push(a / b);
			}
			else if (expression[i] == '*')//If we read * we pop two element and perfrom *
			{
				int a, b;
				b = s1.pop();
				a = s1.pop();
				s1.push(a * b);
			}
			else if (expression[i] == '+')//If we read + we pop two element and perfrom +
			{
				int a, b;
				b = s1.pop();
				a = s1.pop();
				s1.push(a + b);
			}
			else if (expression[i] == '-')//If we read - we pop two element and perfrom -
			{
				int a, b;
				b = s1.pop();
				a = s1.pop();
				s1.push(a - b);
			}
			else
			{
				s1.push(expression[i] - 48);//If it is some digit convert it from char to int by subtracting 48
			}
		}
		s1.print();
	}
}
int main()
{
	string expression;// String to be entered
	int number;//To check the pre or post fix
	cout << "Enter 1 if you want to Check the Balance of Expression\n";
	cout << "Enter 2 if you want to Convert Infix to Postifx(just use small letter)\n";
	cout << "Enter 3 if you want to Evluate a postfix or prefix notation\n";
	cin >> number;
	if (number==1)
	{
		cout << "Enter expression you want to check:";
		cin >> expression;
		isbalanced(expression);
	}
	if (number==2)
	{
		cout << "Enter Infix expression you want to convert in Postfix:";
		cin >> expression;
		infixtopostfix(expression);
	}
	if (number==3)
	{
		cout << "Enter Infix or Postifx expression to evaluate:";
		cin >> expression;
		cout << "Enter 0 if it is post fix and 1 if it is Prefix:";
		cin >> number;
		evaluate(expression, number);
	}
	return 0;
}