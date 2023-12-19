#ifndef BLINK_LOG_H
#define BLINK_LOG_H

#include <memory>

#include "Core.h"

#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)

namespace Blink {

	class BLINK_API Log {
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};

}

// core log macros
#define BLINK_CORE_TRACE(...)    ::Blink::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BLINK_CORE_INFO(...)     ::Blink::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BLINK_CORE_WARN(...)     ::Blink::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BLINK_CORE_ERROR(...)    ::Blink::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BLINK_CORE_CRITICAL(...) ::Blink::Log::GetCoreLogger()->critical(__VA_ARGS__)

// client log macros
#define BLINK_TRACE(...)	     ::Blink::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BLINK_INFO(...)          ::Blink::Log::GetClientLogger()->info(__VA_ARGS__)
#define BLINK_WARN(...)          ::Blink::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BLINK_ERROR(...)         ::Blink::Log::GetClientLogger()->error(__VA_ARGS__)
#define BLINK_CORE_CRITICAL(...) ::Blink::Log::GetClientLogger()->critical(__VA_ARGS__)

#endif // BLINK_LOG_H
