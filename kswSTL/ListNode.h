/*******************************************************************
*  Copyright(c) 2016 Ke Shanwu
*  All rights reserved.
*
*  1209016337@qq.com
*
*  功能:_kswList中元素的实现代码
******************************************************************/

#ifndef _KSW_LIST_NODE_
#define _KSW_LIST_NODE_

namespace KSW{
	// 定义双向链表节点类型
	template<typename T>
	struct __list_node
	{
		typedef void* void_pointer;
		void_pointer prev; // 指向前一个节点
		void_pointer next; // 指向后一个节点
		T data; // 节点的数据域
	};
}

#endif