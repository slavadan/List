#pragma once
#include <iostream>


template<class T>
struct Node
{
	Node(T data = T()) :
		data(data)
	{}

	T data;
	
};

template<class T>
struct DirectedNode : public Node<T>
{
	DirectedNode(T data = T()) : Node<T>(data)
	{}

	std::shared_ptr<DirectedNode> p_next = nullptr;
};


template<class T>
struct UndirectedNode : public Node<T>
{
	UndirectedNode(T data = T()) : Node<T>(data)
	{}

	std::shared_ptr<UndirectedNode> p_next = nullptr;
	std::shared_ptr<UndirectedNode> p_prev = nullptr;

};


template<class T, class TypeNode = DirectedNode<T>>
class directed_list
{
public:


	virtual void push_back(T data);
	virtual bool find(const T& data);

	virtual void remove(const T& data);
	virtual void emplace_front();

protected:

	std::shared_ptr<TypeNode> head;

};

template<class T, class TypeNode>
inline void directed_list<T, TypeNode>::push_back(T data)
{
	
	auto new_element = std::make_shared<TypeNode>(data);

	if (head == nullptr)
		head = new_element;
	else
	{

		std::shared_ptr<TypeNode> current_pointer = head;

		while (current_pointer->p_next != nullptr)
			current_pointer = current_pointer->p_next;

		current_pointer->p_next = new_element;
	}
}

template<class T, class TypeNode>
inline bool directed_list<T, TypeNode>::find(const T& data)
{

	TypeNode* pointer = head.get();

	while (pointer != nullptr)
	{
		if (pointer->data == data)
			return true;

		pointer = pointer->p_next.get();
	}

	return false;
}

template<class T, class TypeNode>
inline void directed_list<T, TypeNode>::remove(const T& data)
{
	if (head == nullptr)
		return;

	std::shared_ptr<TypeNode> current_shared_pointer = head;
	std::shared_ptr<TypeNode> prev_shared_pointer = head;

	TypeNode* current_pointer = head.get();

	while (current_pointer != nullptr)
	{

		if (current_pointer->data == data && current_shared_pointer == head)
		{
			head = current_pointer->p_next;
			return;
		}

		if (current_pointer->data == data)
		{
			prev_shared_pointer->p_next = move(current_pointer->p_next);
			return;
		}


		prev_shared_pointer = current_shared_pointer;
		current_shared_pointer = current_pointer->p_next;
		current_pointer = current_pointer->p_next.get();

		
	}
	
}

template<class T, class TypeNode>
inline void directed_list<T, TypeNode>::emplace_front()
{
	TypeNode* head_pointer = head.get();
	head = head_pointer->p_next;
}

