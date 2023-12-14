#include <iostream>
#include "Application.h"

namespace Blink {

	Application::Application() {}
	Application::~Application() {}

	void Application::run() {
		std::cout << "Enter a letter then enter to continue.\n";
		std::cin.ignore();
	}
}