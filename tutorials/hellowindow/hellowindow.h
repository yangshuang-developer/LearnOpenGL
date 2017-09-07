#pragma once
#include <application.h>

using namespace core;

class HelloWindow:Application{
public:
	HelloWindow(std::string name, int width = 800, int height = 600);
};