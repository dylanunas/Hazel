#ifndef HAZEL_KEYEVENT_H
#define HAZEL_KEYEVENT_H

#include "Event.h"

namespace Hazel {

	class HAZEL_API KeyEvent : public Event {
	protected:
		int m_keyCode { 0 };
		
		// default constructor
		KeyEvent(int keyCode)
			: m_keyCode{ keyCode } {}

	public:

		/**
		 * @brief  - get the key code from the key event
		 * @return - the key code of the KeyEvent object
		 */
		inline int getKeyCode() const { return m_keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	};
	
	class HAZEL_API KeyPressedEvent : public KeyEvent {
	private:
		int m_repeatCount;

	public:
		// default constructor
		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent{ keyCode }, m_repeatCount{ repeatCount } {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class HAZEL_API KeyReleasedEvent : public KeyEvent {
	public:
		// default constructor
		KeyReleasedEvent(int keyCode)
			: KeyEvent{ keyCode } {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}

#endif // HAZEL_KEYEVENT_H