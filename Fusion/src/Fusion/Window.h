#pragma once

#include "Events/Event.h"

namespace Fusion
{

    struct WindowData
    {
        std::string Title;
        uint16_t Width;
        uint16_t Height;

        explicit WindowData(const std::string& Title = "No Title", const uint16_t Width = 1280, const uint16_t Height = 720):
    		Title(Title), Width(Width), Height(Height) {}
    };

    class Window
    {
    public:
        virtual ~Window() = default;

        // This is the function for the OnEvent(Event& e) that will be called
        using EventCallbackFn = std::function<void(Event&)>;

        virtual void OnUpdate() = 0;
        [[nodiscard]] virtual uint16_t GetWidth() const = 0;
        [[nodiscard]] virtual uint16_t GetHeight() const = 0;

        virtual void SetEventCallbackFunction(const EventCallbackFn& Callback) = 0;
        virtual void SetVsync(bool Enabled) = 0;
        [[nodiscard]] virtual bool IsVsync() const = 0;

        // This is implemented per platform
        static Window* Create(const WindowData& Data = WindowData());
    };

}