
#ifndef _KSW_LIST_ITEM_
#define _KSW_LIST_ITEM_

template<typename T>
class ListItem
{
public:
	ListItem(T value):_value(value),_next(NULL){ }

	ListItem* next(){
		return _next;
	}

	T value(){
		return _value;
	}

	~ListItem(){ }

public:
	ListItem *_next;
	T _value;
};

#endif