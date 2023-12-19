#ifndef BLINK_APPLICATION_EVENT_H
#define BLINK_APPLICATION_EVENT_H

#include "Event.h"

namespace Blink {

	class BLINK_API WindowResizeEvent : public Event {
	private:
		size_t m_width{};
		size_t m_height{};

	public:
		WindowResizeEvent(const size_t width, const size_t height)
			: m_width{ width }, m_height{ height } {}

		/**
		 * @ brief  - get the new width for the resize 
		 * @ return - the new width of the screen
		 */
		inline size_t getWidth() const { return m_width; }

		/**
		 * @ brief  - get the new height for the resize 
		 * @ return - the new height of the screen
		 */
		inline size_t getHeight() const { return m_height; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_width << ", " << m_height;
			return ss.str();
		}

		void print() const {
			std::cout << "WindowResizeEvent: " << m_width << ", " << m_height << std::endl;
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class BLINK_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class BLINK_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class BLINK_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class BLINK_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}

#endif // BLINK_APPLICATION_EVENT_H