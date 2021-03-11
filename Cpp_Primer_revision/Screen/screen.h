#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>
#include <iostream>

class Screen;

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};

class Screen {
	friend void Window_mgr::clear(Window_mgr::ScreenIndex);
public:
	typedef std::string::size_type pos;
	Screen () = default;
	Screen (pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
	
	Screen& set(char);
	Screen& set(pos, pos, char);
	char get() const { return contents[cursor]; }
	Screen& move (pos, pos);
	Screen& display (std::ostream &os);
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;	
};

void Window_mgr::clear(ScreenIndex i) 
{
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos row, pos col, char c)
{
	contents[width * row + col] = c;
	return *this;
}

inline Screen& Screen::move (pos r, pos c)
{
	cursor = r*width + c;
	return *this;
}

Screen& Screen::display (std::ostream &os) {
	for (int i = 0; i < height; ++i){
		for (int j = 0; j < width; ++j){
			os << contents[i * width + j];
		}
		os << "\n";
	}
	
	return *this;
}

#endif

