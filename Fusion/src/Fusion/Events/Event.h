#pragma once

#include <string>
#include <functional>

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
		virtual ~Event() = default;

		[[nodiscard]] virtual EventType GetEventType() const = 0;
#ifdef FN_DEBUG
		[[nodiscard]] virtual const char* GetName() const = 0;
		[[nodiscard]] virtual std::string ToString() const { return GetName(); }
#endif

	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		template<EventType Type, typename ParamType>
		static bool CaptureAndDispatch(Event& Captured, EventFn<ParamType> Callbackfunction)
		{
			if (Captured.GetEventType() == Type)
			{
				Captured.m_Handled = Callbackfunction(Captured);
				return true;
			}
			return false;
		}
	};

}