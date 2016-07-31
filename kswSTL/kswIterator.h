
#ifndef _KSW_ITERATOR_
#define _KSW_ITERATOR_

template<typename Item>
struct ListIter : public std::iterator<std::forward_iterator_tag, Item>
{
	Item *ptr;								  // 容器与迭代器的纽带

	ListIter(Item *p = 0) :ptr(p) { }		  // 构造函数，初始化ptr指针
	Item &operator*() const { return *ptr; }  // 返回容器（本例为链表）的节点引用
	Item *operator->() const { return ptr; }  // 返回容器（本例为链表）的节点地址

	//  指向容器（本例为链表）的下一个节点，i++
	ListIter &operator++(){
		ptr = ptr->next();
		return *this;
	}

	//  指向容器（本例为链表）的下一个节点，++i
	ListIter &operator++(int){
		ListIter tmp = *this;
		++*this;
		return tmp;
	}

	//判断两节点是否相等，也就是判断两节点的地址是否相同
	bool operator == (const ListIter& i) const{
		return ptr == i.ptr;
	}

	//判断两节点是否不相等，也就是判断两节点的地址是否不相同
	bool operator != (const ListIter& i) const{
		return ptr != i.ptr;
	}
};

#endif