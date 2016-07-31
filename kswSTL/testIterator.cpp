// testIterator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "kswList.h"
#include "kswIterator.h"
#include "ListItem.h"
#include<iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	kswList<int>myList; //  ��������

	//�������м���ڵ�
	for (int i = 0; i < 8; i++){
		myList.insert_front(i);
	}

	//��ǰ����ӡ�ڵ�
	//myList.display();

	for (ListIter<ListItem<int>> iter = myList.front(); iter != myList.end(); iter++){
		std::cout << iter->_value << std::endl;
	}
	system("pause");
	return 0;
}