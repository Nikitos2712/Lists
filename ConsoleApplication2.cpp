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
void write_list(list* head) {
	list* cur = head;
	while (cur != NULL) {
		cout << cur->val << " ";
		cur = cur->next;
	}
}

// Функция добавления элемента на место k со сдвигом вправа:
void add_el(int el, int k, list* head) {
	list* cur = head;
	int cnt = 0;
	if (k == 0) {
		list* NEW = new list;
		NEW->val = head->val;
		NEW->next = head->next;
		head->val = el;
		head->next = NEW;
	}
	else {
		while (cnt != k - 1) {
			cur = cur->next;
			cnt = cnt + 1;
		}
		list* NEW = new list;
		NEW->val = el;
		NEW->next = cur->next;
		cur->next = NEW;
	}
}

// Функция удаления элемента с места k со сдвигом влево:
void del_k(int k, list* head) {
	list* cur = head;
	int cnt = 0;
	while (cnt != k - 1) {
		cur = cur->next;
		cnt = cnt + 1;
	}
	list* NEW = new list;
	NEW->next = cur->next;
	cur->next = NEW;
}


int main(){
	int n;
	cin >> n;
	list* head = NULL;
	head = new list;

	// Записываем в список:
	read_list(n, head);
	
	add_el(9, 3, head);

	// Выводим список:
	write_list(head);
}