#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <functional>
#include "menu.h"
using namespace std::placeholders;

void PopupMenu::command() {
	while (1) {
		system("cls");

		size_t sz = v.size();
		for (int i = 0; i < sz; i++) {
			std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
		}
		std::cout << sz + 1 << ". 종료\n";

		int cmd;
		std::cout << "메뉴를 선택하세요 >> ";
		std::cin >> cmd;

		if (cmd == sz + 1) break;
		if (cmd < 1 || cmd > sz + 1) continue;

		v[cmd - 1]->command();

	}
}

//메뉴 선택시 수행될 함수 만들기
void foo() { std::cout << "foo\n"; _getch(); }
void goo() { std::cout << "goo\n"; _getch(); }
void hoo(int id) { std::cout << "hoo" << id << "\n"; _getch(); }

