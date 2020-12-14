#pragma once
#include "list.h"

template<class T, class TypeNode = UndirectedNode<T>>
class undirected_list : public directed_list<T, TypeNode>
{
public:

	virtual void push_back(T data) override;

	virtual void remove(const T& data) override;
	virtual void emplace_front() override;

private:

};

template<class T, class TypeNode>
inline void undirected_list<T, TypeNode>::push_back(T data)
{

	auto new_element = std::make_shared<TypeNode>(data);

	if (this->head == nullptr)
		this->head = new_element;
	else
	{

		std::shared_ptr<TypeNode> current_pointer = this->head;

		while (current_pointer->p_next != nullptr)
		{
			current_pointer = current_pointer->p_next;
		}

		current_pointer->p_next = new_element;
		current_pointer->p_next->p_prev = current_pointer;
		
	}
	
}

template<class T, class TypeNode>
inline void undirected_list<T, TypeNode>::remove(const T& data)
{
	if (this->head == nullptr)
		return;

	std::shared_ptr<TypeNode> current_shared_pointer = this->head;
	std::shared_ptr<TypeNode> prev_shared_pointer = this->head;

	TypeNode* current_pointer = this->head.get();

	while (current_pointer != nullptr)
	{

		if (current_pointer->data == data && current_shared_pointer == this->head)
		{
			this->head = current_pointer->p_next;
			current_pointer->p_next->p_prev.reset();
			return;
		}

		if (current_pointer->data == data)
		{
			prev_shared_pointer->p_next = move(current_pointer->p_next);
			
			if (current_pointer->p_next == nullptr)
				return;

			current_pointer->p_next->p_prev = prev_shared_pointer;

			return;
		}


		prev_shared_pointer = current_shared_pointer;
		current_shared_pointer = current_pointer->p_next;
		current_pointer = current_pointer->p_next.get();


	}
}

template<class T, class TypeNode>
inline void undirected_list<T, TypeNode>::emplace_front()
{
	directed_list<T, TypeNode>::emplace_front();

	TypeNode* head_pointer = this->head.get();
	head_pointer->p_prev.reset();
}
