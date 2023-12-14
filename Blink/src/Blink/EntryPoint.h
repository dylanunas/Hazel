#ifndef BLINK_ENTRYPOINT_H
#define BLINK_ENTRYPOINT_H

#ifdef BLINK_PLATFORM_WINDOWS

extern Blink::Application* Blink::createApplication();

int main(int argc, char** argv) {
	Blink::Log::Init();
	BLINK_CORE_WARN("Initialized Log!");
	int a = 5;
	BLINK_INFO("Hello! Var={0}", a);

	auto app = Blink::createApplication();
	app->run();
	delete app;

	return 0;
}

#endif // BLINK_PLATFORM_WINDOWS

#endif // BLINK_ENTRYPOINT_H