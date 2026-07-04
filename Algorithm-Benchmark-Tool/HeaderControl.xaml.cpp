#include "pch.h"
#include "HeaderControl.xaml.h"
#if __has_include("HeaderControl.g.cpp")
#include "HeaderControl.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Algorithm_Benchmark_Tool::implementation
{
    HeaderControl::HeaderControl()
    {
        InitializeComponent();
    }
        //  TOKEN ĐĂNG KÝ SỰ KIỆN

    winrt::event_token HeaderControl::StartRequested(winrt::Microsoft::UI::Xaml::RoutedEventHandler const& handler) {
        return m_startRequestedEvent.add(handler);
    }
    void HeaderControl::StartRequested(winrt::event_token const& token) noexcept {
        m_startRequestedEvent.remove(token);
    }

    winrt::event_token HeaderControl::PauseRequested(winrt::Microsoft::UI::Xaml::RoutedEventHandler const& handler) {
        return m_pauseRequestedEvent.add(handler);
    }
    void HeaderControl::PauseRequested(winrt::event_token const& token) noexcept {
        m_pauseRequestedEvent.remove(token);
    }

    winrt::event_token HeaderControl::StopRequested(winrt::Microsoft::UI::Xaml::RoutedEventHandler const& handler) {
        return m_stopRequestedEvent.add(handler);
    }
    void HeaderControl::StopRequested(winrt::event_token const& token) noexcept {
        m_stopRequestedEvent.remove(token);
    }

    winrt::event_token HeaderControl::StepRequested(winrt::Microsoft::UI::Xaml::RoutedEventHandler const& handler) {
        return m_stepRequestedEvent.add(handler);
    }
    void HeaderControl::StepRequested(winrt::event_token const& token) noexcept {
        m_stepRequestedEvent.remove(token);
    }
    winrt::event_token HeaderControl::BackRequested(winrt::Microsoft::UI::Xaml::RoutedEventHandler const& handler) {
        return m_backRequestedEvent.add(handler);
    }
    void HeaderControl::BackRequested(winrt::event_token const& token) noexcept {
        m_backRequestedEvent.remove(token);
    }

    // DỪNG SỰ KIỆN 


    void HeaderControl::btnStart_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        m_startRequestedEvent(*this, e);
    }
    void HeaderControl::btnPause_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        m_pauseRequestedEvent(*this, e);
    }
    void HeaderControl::btnStop_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        m_stopRequestedEvent(*this, e);
    }
    void HeaderControl::btnStep_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        m_stepRequestedEvent(*this, e);
    }
    void HeaderControl::btnBack_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& e) {
        m_backRequestedEvent(*this, e);
    }
}
