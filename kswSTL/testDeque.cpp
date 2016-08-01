/*******************************************************************
*  Copyright(c) 2016 Ke Shanwu
*  All rights reserved.
*
*  1209016337@qq.com
*
*  �ļ�����:kswDeque�����Ĳ��Դ���
******************************************************************/

#include "stdafx.h"
#include "kswVector.h"
#include "kswDeque.h"
using namespace::std;

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace::KSW;



	/***************************************************************************************/
	/***************************************************************************************/
	std::cout << "************************��ʼ����ǰ�塢������************************" << endl;
	std::cout << endl;
	kswDeque<int> test(1, 1); // ��ʼ��
	test.push_back(2); // ���
	test.push_back(3); // ���
	test.push_back(4); // ���
	test.push_front(0); // ǰ��
	test.push_front(-1); // ǰ��

	std::cout << "��ǰԪ�أ�";
	for (kswDeque<int>::iterator iter = test.begin(); iter != test.end(); ++iter){
		std::cout << *iter << ",";
	}
	std::cout << endl;
	std::cout << endl;
	std::cout << "���ȣ�" << test.size() << endl;
	std::cout << endl;




	/***************************************************************************************/
	/***************************************************************************************/
	std::cout << "************************ǰɾ����ɾ����************************" << endl;
	std::cout << endl;
	test.pop_front(); // ǰɾ
	test.pop_back(); // ��ɾ
	std::cout << "��ǰԪ�أ�";
	for (kswDeque<int>::iterator iter = test.begin(); iter != test.end(); ++iter){
		std::cout << *iter << ",";
	}
	std::cout << endl;
	std::cout << endl;
	std::cout << "���ȣ�" << test.size() << endl;
	std::cout << endl;




	/***************************************************************************************/
	/***************************************************************************************/
	std::cout << "************************��ղ���************************" << endl;
	std::cout << endl;
	test.clear(); // ǰɾ
	std::cout << "��ǰԪ�أ�";
	for (kswDeque<int>::iterator iter = test.begin(); iter != test.end(); ++iter){
		std::cout << *iter << ",";
	}
	std::cout << endl;
	std::cout << endl;
	std::cout << "���ȣ�" << test.size() << endl;
	std::cout << endl;




	/***************************************************************************************/
	/***************************************************************************************/
	std::cout << "************************�����ؽڵ������************************" << endl;
	std::cout << endl;
	std::cout << "������Ĭ�ϴ�СΪ512�ֽڣ�һ��intռ4�ֽڣ�512 / 4 = 128" << endl << endl;
	std::cout << "�������Ԫ���� > 128 ʱ�ͻ�����ؽڵ�" << endl;
	std::cout << endl;
	test.clear(); // ǰɾ
	for (int i = 0; i < 150; i++){
		test.push_back(i);
	}
	std::cout << "��ǰԪ�أ�";
	for (kswDeque<int>::iterator iter = test.begin(); iter != test.end(); ++iter){
		std::cout << *iter << ",";
	}
	std::cout << endl;
	std::cout << endl;
	std::cout << "���ȣ�" << test.size() << endl;
	std::cout << endl;




	/***************************************************************************************/
	/***************************************************************************************/
	std::cout << "************************�����ؽڵ�ǰ�����************************" << endl;
	std::cout << endl;
	std::cout << "������Ĭ�ϴ�СΪ512�ֽڣ�һ��intռ4�ֽڣ�512 / 4 = 128" << endl << endl;
	std::cout << "�������Ԫ���� > 128 ʱ�ͻ�����ؽڵ�" << endl;
	std::cout << endl;
	test.clear(); // ǰɾ
	for (int i = 0; i < 150; i++){
		test.push_front(i);
	}
	std::cout << "��ǰԪ�أ�";
	for (kswDeque<int>::iterator iter = test.begin(); iter != test.end(); ++iter){
		std::cout << *iter << ",";
	}
	std::cout << endl;
	std::cout << endl;
	std::cout << "���ȣ�" << test.size() << endl;
	std::cout << endl;

	std::cout << "************************���Խ���************************" << endl;
	std::cout << endl;
	system("pause");
	return 0;
}
