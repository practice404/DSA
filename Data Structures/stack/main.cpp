#include<bits/stdc++.h>
#include "Stack.h"

void bracket_matching()
{
	std::string str;
	std::cin >> str;
	std::map<char, int> mp;
	mp['('] = 1;
	mp['{'] = 2;
	mp['['] = 3;
	mp[')'] = -1;
	mp['}'] = -2;
	mp[']'] = -3;

	Stack<char> st;
	for(auto i : str)
	{
		if(mp[i] > 0)
			st.push(i);
		else
		{
			if(st.isempty())
			{
				std::cout << "False";
				return;
			}

			else if(mp[st.top()] != -1*mp[i])
			{
				std::cout << "False";
				return;
			}

			st.pop();
		}
	}

	if(st.isempty())
		std::cout << "True";
	else
		std::cout << "False";
}

int postfix_eval()
{
	std::string s;
	std::cin >> s;
	Stack<int> st;

	auto is_operand = [](char c){ // lambda function
		if(c == '+' || c == '-' || c == '/' || c == '*')
			return false;
		return true;
	};

	auto operation = [](int a, int b, char op)
	{
		switch(op)
		{
			case '*' : return a*b; break;
			case '/' : return a/b; break;
			case '-' : return a-b; break;
			case '+' : return a+b; break;
		}

		return 0;
	};

	for(auto i : s)
	{
		if(is_operand(i))
		{
			int value = i - '0';
			st.push(value);
		}
		else
		{
			int v1 = st.pop();
			int v2 = st.pop();
			st.push(operation(v2, v1, i)); // v2 is left and v1 is right operand
		}
	}

	return st.pop();
}

int main()
{
	std::cout << postfix_eval();
}