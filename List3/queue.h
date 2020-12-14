#pragma once
#include "undirected_list.h"
#include <queue>

template<class T, class TypeList = directed_list<T>>
class Queue
{
public:

	
	void push(T data);
	void pop();
	bool find(const T& data);

private:

	std::shared_ptr<TypeList> list = std::make_shared<TypeList>();
	
};

template<class T, class TypeList>
inline void Queue<T, TypeList>::push(T data)
{
	TypeList* pointer = list.get();
	pointer->push_back(data);
}

template<class T, class TypeList>
inline void Queue<T, TypeList>::pop()
{
	TypeList* pointer = list.get();
	pointer->emplace_front();
}

template<class T, class TypeList>
inline bool Queue<T, TypeList>::find(const T& data)
{
	TypeList* pointer = list.get();
	return pointer->find(data);
}
