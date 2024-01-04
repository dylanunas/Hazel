#ifndef HAZEL_MOUSE_EVENT_H
#define HAZEL_MOUSE_EVENT_H

#include "Event.h"

namespace Hazel {

	class HAZEL_API MouseEvent : public Event {
	private:
		double m_mouseX{};
		double m_mouseY{};
	
	public:
		MouseEvent(const double mouseX, const double mouseY)
			: m_mouseX{ mouseX }, m_mouseY{ mouseY } {}
		/**
		 * @brief  - gets the x axis location of the mouse
		 * @return - the x axis location of the mouse
		 */
		inline double getX() const { return m_mouseX; }

		/**
		 * @brief  - gets the y axis location of the mouse
		 * @return - the y axis location of the mouse
		 */
		inline double gety() const { return m_mouseY; }
		
		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class HAZEL_API MouseScrolledEvent : public Event {
	private:
		double m_offsetX{};
		double m_offsetY{};

	public:
		MouseScrolledEvent(const double offsetX, const double offsetY)
			: m_offsetX{ offsetX }, m_offsetY{ offsetY } {}
		/**
		 * @brief  - get the x axis offset
		 * @return - x axis offset
		 */
		inline double getXoffset() const { return m_offsetX; }

		/**
		 * @brief  - get the y axis offset
		 * @return - y axis offset
		 */
		inline double getYoffset() const { return m_offsetY; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << getXoffset() << ", " << getYoffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};
	
	class HAZEL_API MouseButtonEvent : public Event {
	protected:
		int m_button{};
		MouseButtonEvent(int button)
			: m_button{ button } {}

	public:
		/**
		 * @brief  - get the mouse button value
		 * @return - the mouse button
		 */
		int getMouseButton() const { return m_button; }
		
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton | EventCategoryInput)
	};
	
	class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(const double button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(const double button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}

#endif // HAZEL_MOUSE_EVENT_H
