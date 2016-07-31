/*******************************************************************
*  Copyright(c) 2016 Ke Shanwu
*  All rights reserved.
*
*  1209016337@qq.com
*
*  ����:kswVector������ʵ�ִ���
******************************************************************/

#ifndef _KSW_VECTOR_
#define _KSW_VECTOR_

#include "globalConstruct.h"
#include "kswAlloc.h"
#include <memory>

namespace KSW
{
	template<class T, class Alloc = kswAllocator<T>>
	class kswVector
	{
	public:
		typedef T				value_type;
		typedef value_type*		pointer;
		typedef value_type*		iterator;
		typedef value_type&		reference;
		typedef size_t			size_type;
		typedef ptrdiff_t		difference_type;

		//typedef __false_type	has_trivial_default_constructor;
		//typedef __false_type	has_trivial_copy_destructor;
		//typedef __false_type	has_trivial_assignment_operator;
		//typedef __false_type	has_trivial_destructor;
		//typedef __false_type	is_POD_type;

	protected:
		typedef simple_alloc<value_type, Alloc> data_allocator; // ����ռ�������
		iterator start;
		iterator finish;
		iterator end_of_storage;

		void insert_aux(iterator position, const T& value)
		{
			if (finish != end_of_storage)
			{
				construct(finish, *(finish - 1));
				++finish;
				T x_copy = value;
				std::copy_backward(position, finish - 2, finish - 1);
				*position = x_copy;
			}
			else
			{
				ptrdiff_t old_size = size();
				const size_type len = old_size != 0 ? 2 * old_size : 1;
				/*
				����ԭ�����ԭ��СΪ0��������1��Ԫ�ش�С
				���ԭ��С��Ϊ0��������ԭ��С������
				*/
				iterator new_start = data_allocator::allocate(len);
				iterator new_finish = new_start;
				try
				{
					// �� start �� position ����ڴ濽���� new_start ��,���� new_finish = new_start + ( position - start )
					new_finish = std::uninitialized_copy(start, position, new_start);
					construct(new_finish, value); // �� new_finish ��������Ԫ��
					++new_finish;
					//new_finish = std::uninitialized_copy(position, finish, new_finish);
				}
				catch (std::exception ex)
				{
					// ���ִ��ʧ�ܾ�Ҫ�ع�
					destroy(new_start, new_finish);
					data_allocator::deallocate(new_start, len);
					throw;
				}
				destroy(begin(), end());
				deallocate();
				start = new_start;
				finish = new_finish;
				end_of_storage = new_start + len;
			}
		}

		#pragma region �ͷ��ڴ������Ԫ��
		void deallocate()
		{
			if (start)
			{
				data_allocator::deallocate(start, end_of_storage - start);
			}
		}
		#pragma endregion

		#pragma region �����ڴ�͹���Ԫ��
		/*
		*	fill_initialize��allocate_and_fill��kswVector�ĳ�ʼ����Ϊ��������
		*	1.fill_initialize��ְ���Ƿ���һ���ڴ�
		*	2.fill_initialize����allocate_and_fill���ڷ�����ڴ��е��ù��캯������kswVector��Ԫ��
		*/
		void fill_initialize(size_type n, const T& value)
		{
			start = allocate_and_fill(n, value);
			finish = start + n;
			end_of_storage = finish;
		}

		iterator allocate_and_fill(size_type n, const T& x)
		{
			iterator result = data_allocator::allocate(n);
			iterator cur = result;
			for (; n > 0; --n, ++cur)
			{
				construct(&*cur, x);
			}
			return result;
		}
		#pragma endregion
	public:
		#pragma region ��kswVector�Ķ�����
		iterator begin(){ return start; } // ����kswVectorͷԪ�صĵ�ַ
		iterator end(){ return finish; } // ����kswVectorβԪ�صĵ�ַ
		size_type size(){ return size_type(int(end() - begin())); } // kswVector�ĳ��� = βԪ�ص�ַ - ͷԪ�ص�ַ
		size_type capacity()const{ return size_type(end_of_storage - start); } // kswVector������ = ���������ַ - ͷԪ�ص�ַ
		bool empty()const { return begin() == end(); } // kswVector�Ƿ�Ϊ�գ�ͷԪ�ص�ַ �Ƿ���� βԪ�ص�ַ
		reference operator[](size_type n){ return *(begin() + n); } // ����ָ��λ�õ�Ԫ������
		reference front(){ return *begin(); } // ���ͷԪ��λְ
		reference back(){ return *(end() - 1); } // ���βԪ��λ��
		#pragma endregion

		#pragma region ���캯��
		kswVector() :start(0), finish(0), end_of_storage(0) { } // ��ʼ���յ�kswVector
		kswVector(size_type n, const T& value){ fill_initialize(n, value); } // ��ʼ������n��ֵΪvalue��kswVector
		kswVector(int n, const T& value){ fill_initialize(n, value); } // ͬ��
		kswVector(long n, const T& value){ fill_initialize(n, value); } // ͬ��
		explicit kswVector(size_type n){ fill_initialize(n, T()); } // ��ʼ��kswVector�ĳ���Ϊn
		#pragma endregion 

		#pragma region ��������
		~kswVector()
		{
			destroy(start, finish); // �ȵ���kswVector��Ԫ�ص���������
			deallocate(); // ���ͷ�kswVectorռ�õ��ڴ�
		}
		#pragma endregion

		#pragma region ��kswVector��д����
		/**
		*  ����βԪ��
		*/
		void pop_back()
		{
			--finish;
			destroy(finish);
		}

		/**
		*  ��kswVectorĩβ����һ��Ԫ��
		*/
		void push_back(const T& x)
		{
			// �ж�kswVector�������Ƿ����ˣ����û������ֱ�������е��ڴ������Ϲ���Ԫ��
			if (finish != end_of_storage)
			{
				construct(finish, x);
				++finish;
			}
			else // ����������Ǿ�Ҫ���·����ڴ沢���¹��캯��
			{
				insert_aux(end(), x);
			}
		}

		/**
		*  ���[first, last)�����ڵ�Ԫ��
		*/
		iterator erase(iterator first, iterator last)
		{
			// ��last��finish���Ԫ�ؿ�����first��Ϊ��ʼ�����ڴ�ռ䣬����first + ( finish - last ) �ĵ�ַ
			iterator i = std::copy(last, finish, first);
			destroy(i, finish); // ����(first + ( finish - last ), finish]����ڴ�
			finish = finish - (last - first); // ��������finish
			return first;
		}

		/**
		*  ���ĳ��λ���ϵ�Ԫ��
		*/
		iterator erase(iterator position)
		{
			if (position + 1 != end())
			{
				copy(position + 1, finish, position);
			}
			--finish;
			destroy(finish);
			return position;
		}
		#pragma endregion
	};
}

#endif