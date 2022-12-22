
#pragma once


#include "Event.h"

namespace Fusion {


    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(const float X, const float Y) :
            m_MouseX(X), m_MouseY(Y) {}

        virtual EventType GetEventType() const override { return EventType::MouseButtonPressed; }
        virtual const char* GetName() const override { return "MouseMovedEvent"; }
        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << "(x:" << GetMouseX() << " y:" << GetMouseY() << ")";
            return ss.str();
        }

        [[nodiscard]] inline float GetMouseX() const { return m_MouseX; }
        [[nodiscard]] inline float GetMouseY() const { return m_MouseY; }

    private:
        float m_MouseX;
        float m_MouseY;
    };

    class MouseButtonPressedEvent : public Event
    {
    public:
	    explicit MouseButtonPressedEvent(const int Button) :
            m_Button(Button) {}

        virtual EventType GetEventType() const override { return EventType::MouseButtonPressed; }
        virtual const char* GetName() const override { return "MouseButtonPressedEvent"; }
        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << "(Button:" << GetButton() << ")";
            return ss.str();
        }

        [[nodiscard]] inline int GetButton() const { return m_Button; }

    private:
        int m_Button;
    };

    class MouseButtonReleasedEvent : public Event
    {
    public:
	    explicit MouseButtonReleasedEvent(const int Button) :
            m_Button(Button) {}

        virtual EventType GetEventType() const override { return EventType::MouseButtonReleased; }
        virtual const char* GetName() const override { return "MouseButtonReleasedEvent"; }
        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << "(Button:" << GetButton() << ")";
            return ss.str();
        }

        [[nodiscard]] inline int GetButton() const { return m_Button; }

    private:
        int m_Button;
    };

    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(const float XOffset, const float YOffset) :
            m_XOffset(XOffset), m_YOffset(YOffset) {}


        virtual EventType GetEventType() const override { return EventType::MouseScrolled; }
        virtual const char* GetName() const override { return "MouseScrolledEvent"; }
        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << "(xOffset:" << GetXOffset() << " y:" << GetYOffset() << ")";
            return ss.str();
        }

        [[nodiscard]] inline float GetXOffset() const { return m_XOffset; }
        [[nodiscard]] inline float GetYOffset() const { return m_YOffset; }

    private:
        float m_XOffset;
        float m_YOffset;
    };

}