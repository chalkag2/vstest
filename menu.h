#ifndef MENU_H_
#define MENU_H_
class BaseMenu {
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}

	std::string get_title() { return title; }
	virtual ~BaseMenu() {}
	virtual void command() = 0;
};

class PopupMenu :public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	void add(BaseMenu* p) { v.push_back(p); }
	void command();

};

class MenuItem :public BaseMenu
{
	int id;
	using HANDLER = std::function<void()>;
	std::function<void()> handler;	//메뉴 선택시 호출될 함수
public:
	MenuItem(const std::string& s, int n, HANDLER h = nullptr) : BaseMenu(s), id(n), handler(h) {}

	void command() { if (handler != nullptr) handler(); }
};

void foo();
void goo();
void hoo(int id);
#endif