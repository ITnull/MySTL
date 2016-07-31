/*******************************************************************
*  Copyright(c) 2016 Ke Shanwu
*  All rights reserved.
*
*  1209016337@qq.com
*
*  �ļ�����:_kswList�Ĳ��Դ���
******************************************************************/

#include "stdafx.h"
#include "kswAlloc.h"
#include "globalConstruct.h"
#include "_kswList.h"
using namespace::std;

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace::KSW;

	_kswList<int> list;
	int i = 0;
	list.push_back(1); // ��listβ������1
	list.push_back(2); // ��listβ������2
	list.push_back(2); // ��listβ������2
	list.push_back(2); // ��listβ������2
	list.push_front(3); // ��listͷ������1

	std::cout << "-----------------����Ԫ��----------------" << endl;
	std::cout << "��listβ�����β���1��2��2��2����listͷ������3" << endl;
	// ȡ��list�ĳ���
	std::cout << "list�ĳ��ȣ�" << list.size() << endl;
	// ����list
	for (_kswList<int>::iterator iter = list.begin(); iter != list.end(); iter++)
	{
		std::cout << "��" << i << "��Ԫ�أ�" << *iter << endl;
		i++;
	}

	std::cout << endl << endl << "-----------------ֵ����һ��ֵ����2��Ԫ��----------------" << endl;
	// ֵ����һ��ֵ����2��Ԫ��
	list.unique(2);
	// ȡ��list�ĳ���
	std::cout << "list�ĳ��ȣ�" << list.size() << endl;
	// ����list
	i = 0;
	for (_kswList<int>::iterator iter = list.begin(); iter != list.end(); iter++)
	{
		std::cout << "��" << i << "��Ԫ�أ�" << *iter << endl;
		i++;
	}

	std::cout << endl << endl << "-----------------ɾ��ֵ����2��Ԫ��----------------" << endl;
	list.remove(2);// ɾ��ֵ����2��Ԫ��
	// ȡ��list�ĳ���
	std::cout << "list�ĳ��ȣ�" << list.size() << endl;
	// ����list
	i = 0;
	for (_kswList<int>::iterator iter = list.begin(); iter != list.end(); iter++)
	{
		std::cout << "��" << i << "��Ԫ�أ�" << *iter << endl;
		i++;
	}

	std::cout << endl << endl << "-----------------���list----------------" << endl;
	list.clear(); // ���
	// ȡ��list�ĳ���
	std::cout << "list�ĳ��ȣ�" << list.size() << endl;
	// ����list
	i = 0;
	for (_kswList<int>::iterator iter = list.begin(); iter != list.end(); iter++)
	{
		std::cout << "��" << i << "��Ԫ�أ�" << *iter << endl;
		i++;
	}

	system("pause");
	return 0;
}