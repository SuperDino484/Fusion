#pragma once


#include "Event.h"

namespace Fusion {

    class KeyPressedEvent : public Event
    {
    public:
        KeyPressedEvent(const int Keycode, const int RepeatCount) :
            m_KeyCode(Keycode), m_RepeatCount(RepeatCount) {}

        static EventType StaticEventType() { return EventType::KeyPressed; }
        virtual EventType GetEventType() const override { return EventType::KeyPressed; }
        virtual const char* GetName() const override { return "KeyPressedEvent"; }
        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << "(KeyCode:" << GetKeyCode() << " RepeatCount:" << GetRepeatCount() << ")";
            return ss.str();
        }

    	int GetKeyCode() const { return m_KeyCode; }
        int GetRepeatCount() const { return m_RepeatCount; }

    private:
        int m_KeyCode;
        int m_RepeatCount;
    };

    class KeyReleasedEvent : public Event
    {
    public:
	    explicit KeyReleasedEvent(const int Keycode) :
            m_KeyCode(Keycode) {}

        static EventType StaticEventType() { return EventType::KeyReleased; }
        virtual EventType GetEventType() const override { return EventType::KeyReleased; }
        virtual const char* GetName() const override { return "KeyReleasedEvent"; }
        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << "(KeyCode:" << GetKeyCode() << ")";
            return ss.str();
        }

        int GetKeyCode() const { return m_KeyCode; }

    private:
        int m_KeyCode;
    };

}