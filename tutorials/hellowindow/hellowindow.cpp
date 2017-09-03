#include "hellowindow.h"

HelloWindow::HelloWindow(std::string name, int w, int h) :
	application(name, w, h)
{
}

int main()
{
	HelloWindow win("hello window");
}

