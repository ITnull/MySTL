/*******************************************************************
*  Copyright(c) 2016 Ke Shanwu
*  All rights reserved.
*
*  chengonghao@yeah.net
*
*  ����:kswAllocator�ռ���������ʵ�ִ���
******************************************************************/

/*------------------allocator�е�kswAlloc.h------------------------------
#ifndef _KSW_ALLOC
#define _KSW_ALLOC

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>

namespace KSW
{
template<class T>
inline T* _allocate(ptrdiff_t size, T*)
{
set_new_handler(0);
T* tmp = (T*)(::operator new((size_t)(size * sizeof(T)))); // size���������Ԫ������sizeof(T)ÿ��Ԫ�صĴ�С
if (tmp == 0)
{
cerr << "out of memory" << endl;
exit(1);
}
return tmp;
}

template<class T>
inline void _deallocate(T* buffer)
{
::operator delete(buffer);
}

template<class T1, class  T2>
inline void _construct(T1* p, const T2& value)
{
new(p)T1(value); // ����placement new����ָ�����ڴ�λ��p����ʼ��T1���󣬳�ʼ��T1����ʱ����T1�ĸ��ƹ��캯��
}

template<class T>
inline void _destroy(T* ptr)
{
ptr->~T();
}

template<class T>
class allocator
{
public:
typedef T			value_type;
typedef T*			pointer;
typedef const T*	const_pointer;
typedef T&			reference;
typedef const T&	const_reference;
typedef size_t		size_type;
typedef ptrdiff_t	difference_type;

template<class U>
struct rebind
{
typedef allocator<U> other;
};

pointer allocate(size_type n, const void* hint = 0)
{
return _allocate((difference_type)n, (pointer)0);
}

void deallocate(pointer p, size_type n)
{
_deallocate(p);
}

void construct(pointer p, const T& value)
{
_construct(p, value);
}

void destroy(pointer p)
{
_destroy(p);
}

pointer address(reference x)
{
return (pointer)&x;
}

const_pointer const_address(const_reference x)
{
return (const_pointer)&x;
}

size_type max_size() const
{
return size_type(UINT_MAX / sizeof(T));
}
};
}

#endif
*/


/*------------------------------vector�е�kswAlloc.h-----------------------
#ifndef _KSW_ALLOC_
#define _KSW_ALLOC_

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>


namespace KSW
{
	#pragma region �ڴ������ͷź�����Ԫ�صĹ������������
	// �ڴ����
	template<class T>
	inline T* _allocate(ptrdiff_t size, T*)
	{
		set_new_handler(0);
		T* tmp = (T*)(::operator new((size_t)(size * sizeof(T))));
		if (tmp == 0)
		{
			std::cerr << "out of memory" << std::endl;
			exit(1);
		}
		return tmp;
	}

	// �ڴ��ͷ�
	template<class T>
	inline void _deallocate(T* buffer)
	{
		::operator delete(buffer);
	}

	// Ԫ�ع���
	template<class T1, class  T2>
	inline void _construct(T1* p, const T2& value)
	{
		new(p)T1(value);
	}

	// Ԫ������
	template<class T>
	inline void _destroy(T* ptr)
	{
		ptr->~T();
	}
	#pragma endregion

	#pragma region kswAllocator�ռ���������ʵ��
	template<class T>
	class kswAllocator
	{
	public:
		typedef T			value_type;
		typedef T*			pointer;
		typedef const T*	const_pointer;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef size_t		size_type;
		typedef ptrdiff_t	difference_type;

		template<class U>
		struct rebind
		{
			typedef kswAllocator<U> other;
		};

		static pointer allocate(size_type n, const void* hint = 0)
		{
			return _allocate((difference_type)n, (pointer)0);
		}

		static void deallocate(pointer p, size_type n)
		{
			_deallocate(p);
		}

		void construct(pointer p, const T& value)
		{
			_construct(p, value);
		}

		void destroy(pointer p)
		{
			_destroy(p);
		}

		pointer address(reference x)
		{
			return (pointer)&x;
		}

		const_pointer const_address(const_reference x)
		{
			return (const_pointer)&x;
		}

		size_type max_size() const
		{
			return size_type(UINT_MAX / sizeof(T));
		}
	};
	#pragma endregion

	#pragma region ��װSTL��׼�Ŀռ��������ӿ�
	template<class T, class Alloc = kswAllocator<T>>
	class simple_alloc
	{
	public:
		static T* allocate(size_t n)
		{
			return 0 == n ? 0 : (T*)Alloc::allocate(n*sizeof(T));
		}

		static T* allocate(void)
		{
			return (T*)Alloc::allocate(sizeof(T));
		}

		static void deallocate(T* p, size_t n)
		{
			if (0 != n)Alloc::deallocate(p, n*sizeof(T));
		}

		static void deallocate(T* p)
		{
			Alloc::deallocate(p, sizeof(T));
		}
	};
#pragma endregion
}

#endif
*/



/*-------------------------list�е�kswAlloc.h--------------------*/

#ifndef _KSW_ALLOC_
#define _KSW_ALLOC_

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>


namespace KSW
{
	#pragma region �ڴ������ͷź�����Ԫ�صĹ������������
	// �ڴ����
	template<class T>
	inline T* _allocate(ptrdiff_t size, T*)
	{
		set_new_handler(0);
		T* tmp = (T*)(::operator new((size_t)(size * sizeof(T))));
		if (tmp == 0)
		{
			std::cerr << "out of memory" << std::endl;
			exit(1);
		}
		return tmp;
	}

	// �ڴ��ͷ�
	template<class T>
	inline void _deallocate(T* buffer)
	{
		::operator delete(buffer);
	}

	// Ԫ�ع���
	template<class T1, class  T2>
	inline void _construct(T1* p, const T2& value)
	{
		new(p)T1(value);
	}

	// Ԫ������
	template<class T>
	inline void _destroy(T* ptr)
	{
		ptr->~T();
	}
#pragma endregion

#pragma region kswAllocator�ռ���������ʵ��
	template<class T>
	class kswAllocator
	{
	public:
		typedef T		value_type;
		typedef T*		pointer;
		typedef const T*	const_pointer;
		typedef T&		reference;
		typedef const T&	const_reference;
		typedef size_t		size_type;
		typedef ptrdiff_t	difference_type;

		template<class U>
		struct rebind
		{
			typedef kswAllocator<U> other;
		};

		static pointer allocate(size_type n, const void* hint = 0)
		{
			return _allocate((difference_type)n, (pointer)0);
		}

		static void deallocate(pointer p, size_type n)
		{
			_deallocate(p);
		}

		static void deallocate(void* p)
		{
			_deallocate(p);
		}

		void construct(pointer p, const T& value)
		{
			_construct(p, value);
		}

		void destroy(pointer p)
		{
			_destroy(p);
		}

		pointer address(reference x)
		{
			return (pointer)&x;
		}

		const_pointer const_address(const_reference x)
		{
			return (const_pointer)&x;
		}

		size_type max_size() const
		{
			return size_type(UINT_MAX / sizeof(T));
		}
	};
#pragma endregion

#pragma region ��װSTL��׼�Ŀռ��������ӿ�
	template<class T, class Alloc = kswAllocator<T>>
	class simple_alloc
	{
	public:
		static T* allocate(size_t n)
		{
			return 0 == n ? 0 : (T*)Alloc::allocate(n*sizeof(T));
		}

		static T* allocate(void)
		{
			return (T*)Alloc::allocate(sizeof(T));
		}

		static void deallocate(T* p, size_t n)
		{
			if (0 != n)Alloc::deallocate(p, n*sizeof(T));
		}

		static void deallocate(void* p)
		{
			Alloc::deallocate(p);
		}
	};
#pragma endregion
}

#endif

