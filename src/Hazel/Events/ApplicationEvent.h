#pragma once

#include "Event.h"

namespace Hazel
{

    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(EventType::WindowClose)

        EVENT_CLASS_CATEGORY(EventCategory::Application)
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height)
        {
        }

        inline unsigned int GetWidth() const { return m_Width; }
        inline unsigned int GetHeight() const { return m_Height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::WindowResize)

        EVENT_CLASS_CATEGORY(EventCategory::Application)

    private:
        unsigned int m_Width,
            m_Height;
    };

    class AppTickEvent : public Event
    {
    public:
        AppTickEvent() {}

        EVENT_CLASS_TYPE(EventType::AppTick)

        EVENT_CLASS_CATEGORY(EventCategory::Application)
    };

    class AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}

        EVENT_CLASS_TYPE(EventType::AppUpdate)

        EVENT_CLASS_CATEGORY(EventCategory::Application)
    };

    class AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(EventType::AppRender)

        EVENT_CLASS_CATEGORY(EventCategory::Application)
    };

} // namespace Hazel
