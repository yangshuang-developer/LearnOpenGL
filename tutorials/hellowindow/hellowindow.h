#pragma once
#include <application.h>

using namespace core;

class HelloWindow:application{
public:
	HelloWindow(std::string name, int w = 800, int h = 600);
};