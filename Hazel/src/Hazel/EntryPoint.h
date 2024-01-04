#ifndef HAZEL_ENTRYPOINT_H
#define HAZEL_ENTRYPOINT_H

#ifdef HAZEL_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::createApplication();

int main(int argc, char** argv) {
	Hazel::Log::Init();

	auto app = Hazel::createApplication();
	app->run();
	delete app;

	return 0;
}

#endif // HAZEL_PLATFORM_WINDOWS

#endif // HAZEL_ENTRYPOINT_H