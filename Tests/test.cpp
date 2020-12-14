#include "pch.h"
#include "../List3/queue.h"

TEST(directedList, Test1)
{
	directed_list<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);

	for (int i = 01; i <= 7; ++i)
		ASSERT_TRUE(list.find(i));

	list.remove(5);

	ASSERT_FALSE(list.find(5));

	list.emplace_front();

	ASSERT_FALSE(list.find(1));

}

TEST(undirectedList, Test2)
{
	undirected_list<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);

	for (int i = 01; i <= 7; ++i)
		ASSERT_TRUE(list.find(i));

	list.remove(5);

	ASSERT_FALSE(list.find(5));

	list.emplace_front();

	ASSERT_FALSE(list.find(1));

}

TEST(queue, test1)
{
	Queue<int> test_queue;

	test_queue.push(1);
	test_queue.push(2);
	test_queue.push(3);
	test_queue.push(4);
	test_queue.push(5);
	test_queue.push(6);

	for (int i = 1; i <= 6; ++i)
		ASSERT_TRUE(test_queue.find(i));

	test_queue.pop();
	test_queue.pop();

	ASSERT_FALSE(test_queue.find(1));
	ASSERT_FALSE(test_queue.find(2));
}

TEST(queue, test2)
{
	Queue<int, undirected_list<int>> test_queue;

	test_queue.push(1);
	test_queue.push(2);
	test_queue.push(3);
	test_queue.push(4);
	test_queue.push(5);
	test_queue.push(6);

	for (int i = 1; i <= 6; ++i)
		ASSERT_TRUE(test_queue.find(i));

	test_queue.pop();
	test_queue.pop();

	ASSERT_FALSE(test_queue.find(1));
	ASSERT_FALSE(test_queue.find(2));
}