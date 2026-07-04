#include "pch.h"
#include "AnalyticsChartControl.xaml.h"
#if __has_include("AnalyticsChartControl.g.cpp")
#include "AnalyticsChartControl.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Media;
using namespace std;

namespace winrt::Algorithm_Benchmark_Tool::implementation
{
    AnalyticsChartControl::AnalyticsChartControl()
    {
        InitializeComponent();
        ClearCharts();
    }

    void AnalyticsChartControl::ClearCharts()
    {
        m_maxTicks = 1;
        m_maxSwaps = 1;
        m_timeTicks.clear();
        m_currentSwaps.clear();
        UpdateBarCharts();
    }

    void AnalyticsChartControl::UpdateData(hstring const& algoTag, bool isRunning, int32_t swaps)
    {
        // Mỗi lần UI timer giật 1 tick (50ms), nếu thuật toán còn chạy thì cộng thêm thời gian
        if (isRunning) {
            m_timeTicks[algoTag]++;
            if (m_timeTicks[algoTag] > m_maxTicks) m_maxTicks = m_timeTicks[algoTag];
        }

        m_currentSwaps[algoTag] = swaps;
        if (swaps > m_maxSwaps) m_maxSwaps = swaps;
    }

    void AnalyticsChartControl::AdvanceStep()
    {
        UpdateBarCharts();
    }

    void AnalyticsChartControl::UpdateBarCharts()
    {
        // Tính độ dài an toàn cho cột bên trái (Trừ đi text 80px + 45px)
        double maxTimeWidth = TimeChartGrid().ActualWidth() - 125;
        if (maxTimeWidth <= 0) maxTimeWidth = 100;

        // Tính độ dài an toàn cho cột bên phải (Trừ đi text 80px + 35px)
        double maxSwapWidth = BarChartGrid().ActualWidth() - 115;
        if (maxSwapWidth <= 0) maxSwapWidth = 100;

        // Lambda update Cột Thời Gian
        auto updateTimeBar = [&](hstring const& tag, Shapes::Rectangle const& bar, Controls::TextBlock const& textBlock) {
            int32_t ticks = m_timeTicks[tag];
            double seconds = ticks * 0.05; // 50ms = 0.05s

            wchar_t buffer[32];
            swprintf_s(buffer, L"%.2f s", seconds);
            textBlock.Text(buffer);

            double width = m_maxTicks > 0 ? (static_cast<double>(ticks) / m_maxTicks) * maxTimeWidth : 0;
            bar.Width(width);
            };

        // Lambda update Cột Swaps
        auto updateSwapBar = [&](hstring const& tag, Shapes::Rectangle const& bar, Controls::TextBlock const& textBlock) {
            int32_t swaps = m_currentSwaps[tag];
            textBlock.Text(to_hstring(swaps));
            double width = m_maxSwaps > 0 ? (static_cast<double>(swaps) / m_maxSwaps) * maxSwapWidth : 0;
            bar.Width(width);
            };

        updateTimeBar(L"BubbleSort", TimeBarBubble(), TimeTextBubble());
        updateTimeBar(L"InsertionSort", TimeBarInsertion(), TimeTextInsertion());
        updateTimeBar(L"QuickSort", TimeBarQuick(), TimeTextQuick());
        updateTimeBar(L"MergeSort", TimeBarMerge(), TimeTextMerge());
        updateTimeBar(L"ShellSort", TimeBarShell(), TimeTextShell());

        updateSwapBar(L"BubbleSort", BarBubble(), TextBubble());
        updateSwapBar(L"InsertionSort", BarInsertion(), TextInsertion());
        updateSwapBar(L"QuickSort", BarQuick(), TextQuick());
        updateSwapBar(L"MergeSort", BarMerge(), TextMerge());
        updateSwapBar(L"ShellSort", BarShell(), TextShell());
    }

    void AnalyticsChartControl::TimeChartGrid_SizeChanged(IInspectable const&, SizeChangedEventArgs const&)
    {
        UpdateBarCharts();
    }

    void AnalyticsChartControl::BarChartGrid_SizeChanged(IInspectable const&, SizeChangedEventArgs const&)
    {
        UpdateBarCharts();
    }
}