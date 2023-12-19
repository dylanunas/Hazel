#include <iostream>
#include "Application.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace Blink {

	Application::Application() {}
	Application::~Application() {}

	void Application::run() {
		WindowResizeEvent e(1280, 720);

		std::cout << "Enter a letter then enter to continue.\n";
		std::cin.ignore();
	}
}