#ifndef BLINK_EVENT_H
#define BLINK_EVENT_H

#include "BlinkPCH.h"
#include "../Core.h"

namespace Blink {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

// macros so all derived event classes won't have to redefine all functions listed below
#define EVENT_CLASS_TYPE(type) static  EventType   getStaticType() { return EventType::type; }\
							   virtual EventType   getEventType() const override { return getStaticType(); }\
						   	   virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class BLINK_API Event {
	protected:

		bool m_isHandled{ false };

	public:

		/**
		 * @brief  - get the type of the event
		 * @return - the type of the Event object
		 */
		virtual EventType getEventType() const = 0;

		/**
		 * @brief  - get the name of the event
		 * @return - the name of the Event object
		 */
		virtual const char* getName() const = 0;

		/*
		 * @brief  - get the event category of the Event object
		 * @return - the EventCategory flag of the Event object
		 */
		virtual int getCategoryFlags() const = 0;

		/**
		 * @brief  - returns the name of the event as a std::string type
		 * @return - std::string version of getName();
		 */
		virtual std::string toString() const { return getName(); }

		/**
		 * @brief  -
		 * @return -
		 */
		inline bool isInCategory(EventCategory category) {
			return getCategoryFlags() & category;
		}
	};

	class EventDispatcher {
		template <typename T>
		using eventFn = std::function<bool(T&)>;

	private:
		Event& m_event;

	public:
		// default constructor
		EventDispatcher(Event& event)
			: m_event(event) {}

		template <typename T>
		bool dispatch(eventFn<T> func) {
			if (m_event.getEventType() == T::getStaticType()) {
				m_event.m_isHandled = func(*(T*)&m_event);
				return true;
			}
			else {
				return false;
			}
		}
	};

}

#endif // BLINK_EVENT_H
