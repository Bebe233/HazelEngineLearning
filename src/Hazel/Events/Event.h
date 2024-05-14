#pragma once

#include "hzpch.h"
#include "Hazel/Core.h"

namespace Hazel
{

    enum class EventType
    {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        KeyPressed,
        KeyReleased,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum class EventCategory
    {
        None = 0,
        Application = BIT(1),
        Input = BIT(2),
        Keyboard = BIT(3),
        Mouse = BIT(4),
        MouseButton = BIT(5)
    };

#define EVENT_CLASS_TYPE(type)                                                  \
    static EventType GetStaticType() { return type; }                           \
    virtual EventType GetEventType() const override { return GetStaticType(); } \
    virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
    virtual int GetCategoryFlags() const override { return (int)category; }

    class Event
    {
        friend class EventDispatcher;

    public:
        virtual EventType GetEventType() const = 0;
        virtual const char *GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & (int)category;
        }

    protected:
        bool m_Handled = false;
    };

    class EventDispatcher
    {

        template <typename T>
        using EventFn = std::function<bool(T &)>;

    public:
        EventDispatcher(Event &event) : m_Event(event)
        {
        }

        template <typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_Handled = func(*(T *)&m_Event);
                return true;
            }
            return false;
        }

    private:
        Event &m_Event;
    };

    // override operator <<
    inline std::ostream &operator<<(std::ostream &os, const Event &e)
    {
        return os << e.ToString();
    }
}