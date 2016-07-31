/*******************************************************************
*  Copyright(c) 2016 Ke Shanwu
*  All rights reserved.
*
*  1209016337@qq.com
*
*  ����:_kswList�ĵ�������ʵ�ִ���
******************************************************************/

#ifndef _KSW_LIST_ITERATOR_
#define _KSW_LIST_ITERATOR_

#include "ListNode.h"
#include <memory>

namespace KSW{
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_iterator<T, T&, T*>		iterator;
		typedef __list_iterator<T, Ref, Ptr>	self;

		typedef T					value_type;
		typedef Ptr					pointer;
		typedef Ref					reference;
		typedef __list_node<T>*		link_type;
		typedef size_t				size_type;
		typedef ptrdiff_t			difference_type;

		link_type node; // ��ϵ������������ڵ��Ŧ��

		#pragma region ���캯��

		__list_iterator(link_type x) : node(x){}
		__list_iterator(){}
		__list_iterator(const iterator& x) :node(x.node){}

		#pragma endregion

		#pragma region �������Ļ�������

		bool operator==(const self& x) const { return node == x.node; }
		bool operator!=(const self& x) const { return node != x.node; }
		reference operator*() const { return (*node).data; }
		reference operator->() const { return &(operator*()); }

		// ������ǰ��һ���ڵ�
		self& operator++()
		{
			node = (link_type)((*node).next);
			return *this;
		}
		self operator++(int)
		{
			self tmp = *this;
			++*this;
			return tmp;
		}

		// �������ݼ�1������һ���ڵ�
		self& operator--()
		{
			node = (link_type)((*node).prev);
			return *this;
		}
		self operator--(int)
		{
			self tmp = *this;
			--*this;
			return tmp;
		}

		#pragma endregion
	};
}
#endif