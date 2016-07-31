
#ifndef _KSW_ITERATOR_
#define _KSW_ITERATOR_

template<typename Item>
struct ListIter : public std::iterator<std::forward_iterator_tag, Item>
{
	Item *ptr;								// �������������Ŧ��

	ListIter(Item *p = 0) :ptr(p) { }		// ���캯������ʼ��ptrָ��
	Item &operator*() const { return *ptr; } // ��������������Ϊ�����Ľڵ�����
	Item *operator->() const { return ptr; } // ��������������Ϊ�����Ľڵ��ַ

	//  ָ������������Ϊ��������һ���ڵ㣬i++
	ListIter &operator++(){
		ptr = ptr->next();
		return *this;
	}

	//  ָ������������Ϊ��������һ���ڵ㣬++i
	ListIter &operator++(int){
		ListIter tmp = *this;
		++*this;
		return tmp;
	}

	//�ж����ڵ��Ƿ���ȣ�Ҳ�����ж����ڵ�ĵ�ַ�Ƿ���ͬ
	bool operator == (const ListIter& i) const{
		return ptr == i.ptr;
	}

	//�ж����ڵ��Ƿ���ȣ�Ҳ�����ж����ڵ�ĵ�ַ�Ƿ���ͬ
	bool operator != (const ListIter& i) const{
		return ptr != i.ptr;
	}
};

#endif