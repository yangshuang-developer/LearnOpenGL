#include "hellowindow.h"

HelloWindow::HelloWindow(std::string name, int width, int height) :
	Application(name, width, height)
{
	Application::init();
}

int main()
{
	HelloWindow win("hello window");
}

