#pragma once

#include "fnpch.h"
#include "Fusion/Log.h"

namespace Fusion {

	enum class EventType : unsigned char
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	
	class Event
	{
		friend class EventDispatcher;
	public:
		[[nodiscard]] virtual EventType GetEventType() const = 0;
		[[nodiscard]] virtual const char* GetName() const = 0;
		[[nodiscard]] virtual std::string ToString() const { return GetName(); }

		bool IsHandled() const { return m_Handled; }

	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

		template<typename T>
		using EventType = T;
	public:
		explicit EventDispatcher(Event& Event):
			m_Event(Event) {}

		template<typename T>
		bool Dispatch(EventFn<T> Callbackfunction)
		{
			if (T::StaticEventType() == m_Event.GetEventType())
			{
				m_Event.m_Handled = Callbackfunction(*static_cast<T*>(&m_Event));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

}