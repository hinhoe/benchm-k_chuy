#pragma once

#include "SidebarControl.g.h"
#include <vector>
using namespace std;
namespace winrt::Algorithm_Benchmark_Tool::implementation
{
    struct SidebarControl : SidebarControlT<SidebarControl>
    {
        SidebarControl();

        winrt::event_token AlgorithmVisibilityChanged(Algorithm_Benchmark_Tool::AlgorithmVisibilityHandler const& handler);
        void AlgorithmVisibilityChanged(winrt::event_token const& token) noexcept;
        void ToggleCheckBox_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void ToggleCheckBox_Unchecked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void btnRandomData_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        winrt::hstring GetInputText();
        winrt::hstring GetInputSize();
    private:
        winrt::event<Algorithm_Benchmark_Tool::AlgorithmVisibilityHandler> m_algorithmVisibilityChanged;
    };
};

namespace winrt::Algorithm_Benchmark_Tool::factory_implementation
{
    struct SidebarControl : SidebarControlT<SidebarControl, implementation::SidebarControl>
    {
    };
}
