
#include "ListItem.h"
#include<iostream>

using namespace std;

template < class T>
class kswList
{
public:
	kswList() :_end(NULL), _front(NULL) { }         // ���캯������ʼ��ͷָ�롢βָ��  
	void insert_front(T value);			            //����ڵ㵽����ͷ��
	void insert_end(T value);		            	//����ڵ㵽����β��
	ListItem<T>*front()const{ return _front; }      // ����ͷָ��  
	ListItem<T>*end()const{ return _end; }          // ����βָ��  
	void display(std::ostream& os = std::cout)const;	//��ͷ��β��ӡ����

	~kswList(){ }

private:
	ListItem<T> *_front;
	ListItem<T> *_end;
	long _size;						//������
};


/*---ģ��Ķ����ģ��������������ͬһ��*.h�ļ���---*/

// ����ڵ㵽����ͷ��
template<typename T>
void kswList<T>::insert_front(T value){
	kswList<T>::_size++;
	ListItem<T>*tmp = new ListItem<T>(value);
	if (typename kswList<T>::_front == NULL) {
		typename kswList<T>::_front = tmp;
		typename kswList<T>::_end = tmp;
	}
	else{
		tmp->_next = _front;
		_front = tmp;
	}
}

// ����ڵ㵽����β��
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

//��ͷ��β��ӡ����
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