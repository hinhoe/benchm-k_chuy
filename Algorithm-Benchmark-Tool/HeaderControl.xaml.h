#pragma once

#include "HeaderControl.g.h"

namespace winrt::Algorithm_Benchmark_Tool::implementation
{
    struct HeaderControl : HeaderControlT<HeaderControl>
    {
        HeaderControl();

        // Các hàm xử lý sự kiện click từ giao diện
        void btnStart_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void btnPause_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void btnStop_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void btnStep_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void btnBack_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        // Các token public để MainWindow có thể đăng ký sự kiện
        winrt::event_token StartRequested(winrt::Microsoft::UI::Xaml::RoutedEventHandler const& handler);
        void StartRequested(winrt::event_token const& token) noexcept;

        winrt::event_token PauseRequested(winrt::Microsoft::UI::Xaml::RoutedEventHandler const& handler);
        void PauseRequested(winrt::event_token const& token) noexcept;

        winrt::event_token StopRequested(winrt::Microsoft::UI::Xaml::RoutedEventHandler const& handler);
        void StopRequested(winrt::event_token const& token) noexcept;

        winrt::event_token StepRequested(winrt::Microsoft::UI::Xaml::RoutedEventHandler const& handler);
        void StepRequested(winrt::event_token const& token) noexcept;

        winrt::event_token BackRequested(winrt::Microsoft::UI::Xaml::RoutedEventHandler const& handler);
        void BackRequested(winrt::event_token const& token) noexcept;

    private:
        // Các biến chứa sự kiện nội bộ
        winrt::event<Microsoft::UI::Xaml::RoutedEventHandler> m_startRequestedEvent;
        winrt::event<Microsoft::UI::Xaml::RoutedEventHandler> m_pauseRequestedEvent;
        winrt::event<Microsoft::UI::Xaml::RoutedEventHandler> m_stopRequestedEvent;
        winrt::event<Microsoft::UI::Xaml::RoutedEventHandler> m_stepRequestedEvent;
		winrt::event<Microsoft::UI::Xaml::RoutedEventHandler> m_backRequestedEvent; 
    };
}

namespace winrt::Algorithm_Benchmark_Tool::factory_implementation
{
    struct HeaderControl : HeaderControlT<HeaderControl, implementation::HeaderControl>
    {
    };
}