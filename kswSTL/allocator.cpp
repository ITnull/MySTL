// allocator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "kswAlloc.h"
#include <vector>
#include <iostream>
using namespace::std;

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[5] = { 0, 1, 2, 3, 4 };
	//unsigned int i;
	KSW::allocator<int> test;
	KSW::allocator<int> test1;

	vector<int, KSW::allocator<int>>iv(arr, arr + 5);
	for (int i = 0; i < iv.size(); i++){
		cout << iv[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}
