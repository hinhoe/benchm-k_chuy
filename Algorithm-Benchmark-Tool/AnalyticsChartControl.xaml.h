#pragma once
#include "AnalyticsChartControl.g.h"
#include <map>

namespace winrt::Algorithm_Benchmark_Tool::implementation
{
    struct AnalyticsChartControl : AnalyticsChartControlT<AnalyticsChartControl>
    {
        AnalyticsChartControl();

        void ClearCharts();
        void UpdateData(hstring const& algoTag, bool isRunning, int32_t swaps);
        void AdvanceStep();

        void TimeChartGrid_SizeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::SizeChangedEventArgs const& e);
        void BarChartGrid_SizeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::SizeChangedEventArgs const& e);

    private:
        int32_t m_maxTicks = 1;
        int32_t m_maxSwaps = 1;

        std::map<hstring, int32_t> m_timeTicks;
        std::map<hstring, int32_t> m_currentSwaps;

        void UpdateBarCharts();
    };
}
namespace winrt::Algorithm_Benchmark_Tool::factory_implementation
{
    struct AnalyticsChartControl : AnalyticsChartControlT<AnalyticsChartControl, implementation::AnalyticsChartControl>
    {
    };
}