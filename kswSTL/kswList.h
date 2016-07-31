
#include "ListItem.h"
#include<iostream>

using namespace std;

template < class T>
class kswList
{
public:
	kswList() :_end(NULL), _front(NULL),_size(0) { }         // 构造函数，初始化头指针、尾指针  
	void insert_front(T value);			            //插入节点到链表头部
	void insert_end(T value);		            	//插入节点到链表尾部
	ListItem<T>*front()const{ return _front; }      // 返回头指针  
	ListItem<T>*end()const{ return _end; }          // 返回尾指针  
	void display(std::ostream& os = std::cout)const;	//从头到尾打印链表

	~kswList(){ }

private:
	ListItem<T> *_front;
	ListItem<T> *_end;
	long _size;						//链表长度
};


/*---模板的定义和模板的声明必须放在同一个*.h文件中---*/

// 插入节点到链表头部
template<typename T>
void kswList<T>::insert_front(T value){
	kswList<T>::_size++;
	ListItem<T> *tmp = new ListItem<T>(value);
	if (typename kswList<T>::_front == NULL) {
		typename kswList<T>::_front = tmp;
		typename kswList<T>::_end = tmp;
	}
	else{
		tmp->_next = _front;
		_front = tmp;
	}
}

// 插入节点到链表尾部
template<typename T>
void kswList<T>::insert_end(T value){
	kswList<T>::_size++;
	ListItem<T>*tmp = new ListItem<T>(value);
	if (typename kswList<T>::_front == NULL) {
		typename kswList<T>::_front = tmp;
		typename kswList<T>::_end = tmp;
	}
	else{
		typename kswList<T>::_end->_next = tmp;
		typename kswList<T>::_end = typename kswList<T>::_end->_next;
	}
}

//从头到尾打印链表
template<typename T>
void kswList<T>::display(std::ostream &os = std::cout)const{
	if (typename kswList<T>::_front == NULL || typename kswList<T>::_end == NULL){
		return;
	}
	ListItem<T> *tmp = typename kswList<T>::_front;
	while (tmp != NULL){
		std::cout << tmp->_value << std::endl;
		tmp = tmp->_next;
	}
}