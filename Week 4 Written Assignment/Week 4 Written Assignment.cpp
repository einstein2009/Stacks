// Week 4 Written Assignment.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <istream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Stack.h"

using namespace std;

void Calculator(string input);
void Execute(Stack<int> &i, Stack<char> &c);
int Precedence(char ch);
//bool IsNumeric(string input);
//bool IsOperator(string input);

void Calculator(string input) {
	Stack<int> valStack = Stack<int>();
	Stack<char> opStack = Stack<char>();
	int result = 0;

	for (int i = 0; i < input.length; i++) {

		switch (input[i]) {
			
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': valStack.push(input[i]);
			break;

		case '(':
			opStack.push(input[i]);
				break;

		case '+':
		case '-':
		case '*':
		case '/':
			if (opStack.isEmpty())
				opStack.push(input[i]);
			else if (Precedence(input[i]) > Precedence(opStack.peek()))
				opStack.push(input[i]);
			else {
				while (!opStack.isEmpty() && Precedence(input[i]) <= Precedence(opStack.peek()))
					Execute(valStack, opStack);
				opStack.push(input[i]);
			}
				break;

		case ')':

			while (opStack.peek() == '(')
				Execute(valStack, opStack);
			opStack.pop();
				break;
		}
	}
	while (!opStack.isEmpty()) {
		Execute(valStack, opStack);
		result = valStack.peek();
	}
};

void Execute(Stack<int> &i, Stack<char> &c) {
	Stack<int> valStack = i;
	Stack<char> opStack = c;
	int operand1 = 0;
	int operand2 = 0;
	int result = 0;
	char op = ' ';

	operand2 = valStack.pop();
	operand1 = valStack.pop();
	op = opStack.pop();
	
	switch (op)
	{
	case '+': result = operand1 + operand2;
		break;

	case '-': result = operand1 - operand2;
		break;

	case '/': result = operand1 / operand2;
		break;

	case '*': result = operand1 * operand2;
		break;
	};
	valStack.push(result);
}

int Precedence(char ch) {
	int paran = 1;
	int addsub = 3;
	int multdiv = 5;

	switch (ch) {

	case '+': return addsub;
		break;

	case '-': return addsub;
		break;

	case '/': return multdiv;
		break;

	case '*': return multdiv;
		break;

	case '(': return paran;
		break;

	case ')': return paran;
		break;
	}


	return;
}
/*
bool IsOperator(string input)
{
	bool verify = true;
	for (int i = 0; i < input.length(); i++)
	{
		char op = input[i];
		if (op == '+' || op == '-' || op == '/' || op == '*')
			verify = true;
		else
			verify = false;
	}
	return verify;
}

bool IsNumeric(string input)
{
	bool verify = true;
	for (int i = 0; i < input.length(); i++)
	{
		int numeric = input[i];

		if (numeric >= 0 || numeric <= 10)
			verify = true;
		else
			verify = false;
	}
	return verify;
}
*/

int main()
{
	string answer = " ";

	cout << "Enter the equation you would like solved. ";
	cin.getline >> answer;

	Calculator(answer);
	


    return 0;
}