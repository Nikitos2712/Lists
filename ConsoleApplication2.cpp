#include <iostream>
using namespace std;

struct list {
	int val;
	list* next;
};

// Считывание списка:
void read_list(int n, list* head) {
	list* cur = head;
	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			cin >> cur->val;
			cur->next = new list;
			cur = cur->next;
		}
		else {
			cin >> cur->val;
			cur->next = NULL;
		}
	}
}

// Вывод всего списка:
void print_list(list* head) {
	list* cur = head;
	while (cur != NULL) {
		cout << cur->val << " ";
		cur = cur->next;
	}
}

// Функция добавления элемента на место k:
void add_val(int val, int k, list* head) {
	list* cur = head;
	int cnt = 0;
	if (k == 0) {
		list* NEW = new list;
		NEW->val = head->val;
		NEW->next = head->next;
		head->val = val;
		head->next = NEW;
	}
	else {
		while (cnt != k - 1) {
			cur = cur->next;
			cnt = cnt + 1;
		}
		list* NEW = new list;
		NEW->val = val;
		NEW->next = cur->next;
		cur->next = NEW;
	}
}

// Функцию добавления элемента в конец списка:
void pushBack(int val, list* head) {
	list* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	list* NEW = new list;
	NEW->val = val;
	NEW->next = cur->next;
	cur->next = NEW;
}

// Функция удаления элемента с места ind:
void del_Ind(int ind, list* head) {
	if (ind != 0) {
		list* cur = head;
		int cnt = 0;
		while (cnt != ind - 1) {
			cur = cur->next;
			cnt = cnt + 1;
		}
		cur->next = cur->next->next;
	}
	else {
		head->val = head->next->val;
		head->next = head->next->next;
	}
}

// Функция удаления первого элемента со значением val:
void del_Val(int val, list* head) {
	if (head->val != val) {
		list* cur = head;
		while (cur->next->val != val) {
			cur = cur->next;
		}
		cur->next = cur->next->next;
	}
	else {
		head->val = head->next->val;
		head->next = head->next->next;
	}
}


int main() {
	int n;
	cin >> n;
	list* head = NULL;
	head = new list;

	// Записываем в список:
	read_list(n, head);

	add_val(9, 2, head);
	pushBack(9, head);
	pushBack(9, head);
	del_Val(9, head);

	// Выводим список:
	print_list(head);
}