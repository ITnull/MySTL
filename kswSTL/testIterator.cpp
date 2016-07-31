// testIterator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "kswList.h"
#include "kswIterator.h"
#include "ListItem.h"
#include<iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	kswList<int>myList; //  定义容器

	//往容器中加入节点
	for (int i = 0; i < 8; i++){
		myList.insert_front(i);
	}

	//从前向后打印节点
	//myList.display();

	for (ListIter<ListItem<int>> iter = myList.front(); iter != myList.end(); iter++){
		std::cout << iter->_value << std::endl;
	}
	system("pause");
	return 0;
}