#include <Blink.h>

class Sandbox : public Blink::Application {
private:

public:
	Sandbox() {}
	~Sandbox() {}
};

Blink::Application* Blink::createApplication() {
	return new Sandbox();
}
