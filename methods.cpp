#include "methods.h"
using namespace std;

bool isValid(string exp)
{
	if (exp.length() == 0 || exp.length() == 1 || exp.length() == 2)
		return false;
	int j = exp.length() - 1;
	if (exp[j] == '+' || exp[j] == '-' || exp[j] == '*' || exp[j] == '/' || exp[j] == '%' || exp[j] == '^')
		return false;

	int operatorCount = 0;
	int operandCount = 0;

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%' || exp[i] == '^')
			operatorCount++;
		else if (exp[i] != ' ' && exp[i] != '\t')
			operandCount++;

		if (exp[i] == '(' || exp[i] == ')' || exp[i] == '[' || exp[i] == ']' || exp[i] == '{' || exp[i] == '}')
			return false;
	}

	if (operatorCount != operandCount - 1)
		return false;

	return true;
}

string prefixToPostfix(string prefix)
{
	if (!isValid(prefix))
		return " ";

	string postfix;
	stack<string> s;

	for (int i = prefix.length() - 1; i >= 0; i--)
	{
		if (prefix[i] != '+' && prefix[i] != '-' && prefix[i] != '*' && prefix[i] != '/' && prefix[i] != '%' && prefix[i] != '^' && prefix[i] != ' ' && prefix[i] != '\t')
		{
			string x(1, prefix[i]);
			s.push(x);
		}
		else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '%' || prefix[i] == '^')
		{
			if (s.empty())
				return " ";

			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();

			string exp = op1 + op2 + prefix[i];
			s.push(exp);
		}
	}

	while (!s.empty())
	{
		postfix += s.top();
		s.pop();
	}

	return postfix;
}