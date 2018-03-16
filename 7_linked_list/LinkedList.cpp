#include <iostream>
#include <iterator>
#include <memory>

using namespace std;

template <typename T>
struct ListNode {
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> SearchList(shared_ptr<ListNode<int>> L, int key) {
	while (L && L->data != key) {
		L = L->next;
	}
	return L;
}

void InsertAfter(const shared_ptr<ListNode<int>>& node, const shared_ptr<ListNode<int>>& new_node) {
	new_node->next = node->next;
	node->next = new_node;
}

void DeleteAfter(const shared_ptr<ListNode<int>>& node) {
	node->next = node->next->next;
}

void PrintList(shared_ptr<ListNode<int>> L) {
	while (L) {
		cout << L->data << " -> ";
		L = L->next;
	}
	cout << "nullptr" << endl;
}


int main(int argc, char **argv) {
	ListNode<int> tail = {24, nullptr};
	ListNode<int> C = {3, make_shared<ListNode<int>>(tail)};
	ListNode<int> B = {65, make_shared<ListNode<int>>(C)};
	ListNode<int> A = {23, make_shared<ListNode<int>>(B)};
	shared_ptr<ListNode<int>> head = make_shared<ListNode<int>>(A);

	PrintList(head);
}
