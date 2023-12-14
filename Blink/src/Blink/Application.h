#ifndef BLINK_APPLICATION_H
#define BLINK_APPLICATION_H

#include "Core.h"

namespace Blink {

	class BLINK_API Application {
	private:

	public:
		// constructors
		Application();

		// destructor
		virtual ~Application();

		// member functions
		void run();
	};
	
	// to be defined in the client (SandboxApp.cpp)
	Application* createApplication();

}

#endif // BLINK_APPLICATION_H
