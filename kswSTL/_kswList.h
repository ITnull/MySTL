/*******************************************************************
*  Copyright(c) 2016 Ke Shanwu
*  All rights reserved.
*
*  1209016337@qq.com
*
*  ����:_kswList��ʵ�ִ���
******************************************************************/
#pragma once 
#ifndef _KSW_LIST_
#define _KSW_LIST_

#include "ListNode.h"
#include "kswAlloc.h"
#include "globalConstruct.h"
#include "ListIterator.h"

namespace KSW{
	template<class T, class Alloc = kswAllocator<T>>
	class _kswList{
	protected:
		typedef __list_node<T>				list_node;
	public:
		typedef list_node*				link_type;
		typedef size_t					size_type;
		typedef typename __list_iterator<T, T&, T*>::iterator	iterator;

		#pragma region �ڴ���ơ��ڵ㹹��������
	protected:
		link_type node; // _kswList��Ψһ�Ľڵ�ָ�룬ָ��_kswList��β��
		typedef simple_alloc<list_node, Alloc> list_node_allocator; // ����ռ�������
		link_type get_node(){ return list_node_allocator::allocate(); } // ����һ���ڵ���ڴ�ռ�
		void put_node(link_type p){ list_node_allocator::deallocate(p); } // �ͷ�һ���ڵ���ڴ�ռ�

		/*
		����һ���ڵ㣺
		1.����get_node����ڵ��ڴ�;
		2.����construct����ڵ�
		*/
		link_type create_node(const T& x)
		{
			link_type p = get_node();
			construct(&p->data, x);
			return p;
		}

		/*
		����һ���ڵ㣺
		1.����destroy�����ڵ�;
		2.����put_node�ͷ��ڴ�
		*/
		void destroy_node(link_type p)
		{
			destroy(&p->data);
			put_node(p);
		}

	public:
		/*
		���캯����
		����empty_initialize
		*/
		_kswList(){ empty_initialize(); }
	protected:
		/*
		����һ��������
		1.����һ���ڵ��ڴ�
		2.��ʼ��β�ڵ�
		*/
		void empty_initialize()
		{
			node = get_node();
			node->next = node;
			node->prev = node;
		}
		#pragma endregion 

	public:
		#pragma region ����Ĳ�ѯ����

		/*
		����ͷ�ڵ㣺
		_kswList�е�node��Ա���������������βָ��
		�����βָ�벻�������㣬����ʶ�����β
		*/
		iterator begin()const { return (link_type)((*node).next); }

		/*
		����β�ڵ㣺
		_kswList�е�node��Ա���������������βָ��
		�����βָ�벻�������㣬����ʶ�����β
		*/
		iterator end()const{ return node; }

		/*
		�ж������Ƿ�Ϊ�գ�
		_kswList�е�node��Ա���������������βָ��
		�����βָ�벻�������㣬����ʶ�����β
		*/
		bool empty() const{ return node->next == node; }

		/*
		���������ȣ�
		_kswList�е�node��Ա���������������βָ��
		�����βָ�벻�������㣬����ʶ�����β
		*/
		size_type size()	const
		{
			size_type result = 0;
			iterator first = begin();
			iterator last = end();
			while (first != last)
			{
				++first;
				++result;
			}
			return result;
		}

		#pragma endregion

		#pragma region ��������Ԫ�أ�����ͷ���β��

		/*
		���뵽����ͷ��
		*/
		void push_back(const T& x){ insert(end(), x); }

		/*
		���뵽����β��
		*/
		void push_front(const T& x){ insert(begin(), x); }

		/*
		ִ�о���Ĳ������
		*/
		iterator insert(iterator position, const T& x)
		{
			link_type tmp = create_node(x);
			tmp->next = position.node;
			tmp->prev = position.node->prev;
			(link_type(position.node->prev))->next = tmp;
			position.node->prev = tmp;
			return tmp;
		}

		#pragma endregion

		#pragma region ɾ������Ԫ��

		/*
		ɾ��ָ��λ�õ�����ڵ�
		*/
		iterator erase(iterator position)
		{
			link_type next_node = link_type(position.node->next);
			link_type prev_node = link_type(position.node->prev);
			prev_node->next = next_node;
			next_node->prev = prev_node;
			destroy_node(position.node);
			return iterator(next_node);
		}

		/*
		ɾ������ͷ�ڵ�
		*/
		void pop_front(){ erase(begin()); }

		/*
		ɾ������β�ڵ�
		*/
		void pop_back()
		{
			iterator tmp = end();
			erase(--tmp);
		}

		/*
		�����������
		*/
		void clear()
		{
			link_type cur = (link_type)node->next; //�õ�ͷ���
			while (cur != node)
			{
				iterator tmp = cur;
				cur = (link_type)cur->next;
				destroy_node(tmp.node);
			}
			node->next = node;
			node->prev = node;
		}

		/*
		�Ƴ��ڵ�ֵΪ value ������ڵ�
		*/
		void remove(const T& value)
		{
			iterator first = begin();
			iterator last = end();
			while (first != last)
			{
				iterator next = first;
				++next;
				if (*first == value)erase(first);
				first = next;
			}
		}

		/*
		���������������ŵ�����ͬ�ڵ�ֵ��Ԫ��
		*/
		void unique(const T& value)
		{
			iterator first = begin();
			iterator last = end();
			if (first == last)return;
			iterator next = first;
			while (++next != last)
			{
				if (*first == *next)
				{
					erase(next);
				}
				else
				{
					first = next;
				}
				next = first;
			}
		}

		#pragma endregion
	};
}

#endif
