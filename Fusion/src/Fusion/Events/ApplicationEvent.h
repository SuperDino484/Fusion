#pragma once

#include "Event.h"

namespace Fusion {

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(const uint16_t Width, const uint16_t Height) :
            m_Width(Width), m_Height(Height) {}

        virtual EventType GetEventType() const override { return EventType::WindowResize; }
        virtual const char* GetName() const override { return "WindowResizeEvent"; }

        [[nodiscard]] inline uint16_t GetWidth() const { return m_Width; }
        [[nodiscard]] inline uint16_t GetHeight() const { return m_Height; }

    private:
        uint16_t m_Width, m_Height;
    };

    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;

        virtual EventType GetEventType() const override { return EventType::WindowClose; }
        virtual const char* GetName() const override { return "WindowCloseEvent"; }
    };

}