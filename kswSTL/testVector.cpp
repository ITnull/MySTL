/*******************************************************************
*  Copyright(c) 2016 Ke Shanwu
*  All rights reserved.
*
*  1209016337@qq.com
*
*  文件名称:kswVector容器的测试代码
******************************************************************/

#include "stdafx.h"
#include "kswAlloc.h"
#include "globalConstruct.h"
#include "kswVector.h"
using namespace::std;

/*
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace::KSW;

	kswVector<int> test(2, 2);
	cout << "size = " << test.size() << "\t";
	cout << "capacity = " << test.capacity() << endl;

	test.push_back(1);
	cout << "size = " << test.size() << "\t";
	cout << "capacity = " << test.capacity() << endl;

	test.push_back(2);
	cout << "size = " << test.size() << "\t";
	cout << "capacity = " << test.capacity() << endl;

	test.push_back(3);
	cout << "size = " << test.size() << "\t";
	cout << "capacity = " << test.capacity() << endl;

	test.pop_back();
	cout << "size = " << test.size() << "\t";
	cout << "capacity = " << test.capacity() << endl;

	std::cout << test[2] << endl;// 返回指定位置处的元素，这里体现了vector迭代器的随机访问性质（random access iterators）

	test.erase(test.begin() + 1, test.begin() + 2);
	test.erase(test.begin());
	for (kswVector<int>::iterator it = test.begin(); it != test.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	system("pause");
	return 0;
}
*/