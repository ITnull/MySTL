/*******************************************************************
*  Copyright(c) 2016 Ke Shanwu
*  All rights reserved.
*
*  1209016337@qq.com
*
*  ����:_kswList��Ԫ�ص�ʵ�ִ���
******************************************************************/

#ifndef _KSW_LIST_NODE_
#define _KSW_LIST_NODE_

namespace KSW{
	// ����˫������ڵ�����
	template<typename T>
	struct __list_node
	{
		typedef void* void_pointer;
		void_pointer prev; // ָ��ǰһ���ڵ�
		void_pointer next; // ָ���һ���ڵ�
		T data; // �ڵ��������
	};
}

#endif