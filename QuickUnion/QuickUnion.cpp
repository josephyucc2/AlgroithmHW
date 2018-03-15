// hw1.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include"fstream"

using namespace std;

class quickUnion
{
public:
	int*id;
	quickUnion();
	quickUnion(int n);
	int root(int i);
	bool connected(int p, int q);
	void Union(int p, int q);
};

quickUnion::quickUnion()
{
	id = new int[0];
}
quickUnion::quickUnion(int n)
{
	id = new int[n];

	for (int i = 0; i < n; i++)
	{
		id[i] = i;
	}
}
int quickUnion::root(int i)
{
	while (i != id[i])
	{
		i = id[i];
	}
	return i;
}
bool quickUnion::connected(int p, int q)
{
	return (root(p) == root(q));
}
void quickUnion::Union(int p, int q)
{
	if (connected(p, q))
	{
		cout << "Connect." << endl;
		return;
	}
	else
	{
		int i = root(p);
		int j = root(q);
		id[i] = j;
	}
}
void output(quickUnion node)
{

}
int main()
{

	int dataNum;
	int runtime;
	while (cin >> dataNum)
	{
		quickUnion node(dataNum);
		cout << "value  ";
		for (int i = 0; i < dataNum; i++)
		{

			if (i == dataNum - 1)
			{
				cout << i << endl;
			}
			else
				cout << i << " ";
		}
		cout << "father  ";
		for (int i = 0; i < dataNum; i++)
		{

			if (i == dataNum - 1)
			{
				cout << node.id[i];
				cout << endl;
			}
			else
				cout << node.id[i] << " ";
		}
		cin >> runtime;

		for (int i = 0; i < runtime; i++)
		{
			int p, q;
			cin >> p >> q;
			node.Union(p, q);
			cout << "value  ";
			for (int i = 0; i < dataNum; i++)
			{

				if (i == dataNum - 1)
				{
					cout << i << endl;
				}
				else
					cout << i << " ";
			}
			cout << "father  ";
			for (int i = 0; i < dataNum; i++)
			{

				if (i == dataNum - 1)
				{
					cout << node.id[i];
					cout << endl;
				}
				else
					cout << node.id[i] << " ";
			}
		}
	}

	return 0;
}

