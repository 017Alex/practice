/*
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	string a = "hello world";
	string b = a;
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else 
		cout << "false" << endl;
	string c = b;
	c = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else 
		cout << "false" << endl;
	a = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else 
		cout << "false" << endl;
	return 0;

}
*/

#include<stdio.h>

void main()
{
	int i = 0;
	while (i < 10)
	{
		if (i < 1) continue;
		if (i == 5) break;
		i++;
	}
}