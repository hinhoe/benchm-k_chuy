#pragma once

#include "AlgorithmCardControl.g.h"

namespace winrt::Algorithm_Benchmark_Tool::implementation
{
    struct AlgorithmCardControl : AlgorithmCardControlT<AlgorithmCardControl>
    {
        AlgorithmCardControl();;

        winrt::hstring AlgorithmName();
        void AlgorithmName(winrt::hstring const& value);
        static Microsoft::UI::Xaml::DependencyProperty AlgorithmNameProperty();
        winrt::hstring Complexity();
        void Complexity(winrt::hstring const& value);
        static Microsoft::UI::Xaml::DependencyProperty ComplexityProperty();
        winrt::hstring Best();
        void Best(winrt::hstring const& value);
        static Microsoft::UI::Xaml::DependencyProperty BestProperty();
        winrt::hstring Avg();
        void Avg(winrt::hstring const& value);
        static Microsoft::UI::Xaml::DependencyProperty AvgProperty();
        winrt::hstring Worst();
        void Worst(winrt::hstring const& value);
        static Microsoft::UI::Xaml::DependencyProperty WorstProperty();
        winrt::hstring Space();
        void Space(winrt::hstring const& value);
        static Microsoft::UI::Xaml::DependencyProperty SpaceProperty();
        // --- Bổ sung ---
        winrt::hstring Comparisons();
        void Comparisons(winrt::hstring const& value);
        static Microsoft::UI::Xaml::DependencyProperty ComparisonsProperty();

        winrt::hstring Swaps();
        void Swaps(winrt::hstring const& value);
        static Microsoft::UI::Xaml::DependencyProperty SwapsProperty();

        winrt::hstring Status();
        void Status(winrt::hstring const& value);
        static Microsoft::UI::Xaml::DependencyProperty StatusProperty();

        winrt::hstring ElapsedMs();
        void ElapsedMs(winrt::hstring const& value);
        static Microsoft::UI::Xaml::DependencyProperty ElapsedMsProperty();

        void UpdateBars(winrt::array_view<int32_t const> data, int32_t index1, int32_t index2);
        void SetStatus(winrt::hstring const& status, int32_t elapsedMs);

        void BtnExpand_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        static Microsoft::UI::Xaml::DependencyProperty m_algorithmNameProperty;
        static Microsoft::UI::Xaml::DependencyProperty m_complexityProperty;
        static Microsoft::UI::Xaml::DependencyProperty m_BestProperty;
        static Microsoft::UI::Xaml::DependencyProperty m_AvgProperty;
        static Microsoft::UI::Xaml::DependencyProperty m_WorstProperty;
        static Microsoft::UI::Xaml::DependencyProperty m_SpaceProperty;

        static Microsoft::UI::Xaml::DependencyProperty m_ComparisonsProperty;
        static Microsoft::UI::Xaml::DependencyProperty m_SwapsProperty;
        static Microsoft::UI::Xaml::DependencyProperty m_StatusProperty;
        static Microsoft::UI::Xaml::DependencyProperty m_ElapsedMsProperty;

        bool m_isExpanded{ false };
    };
}

namespace winrt::Algorithm_Benchmark_Tool::factory_implementation
{
    struct AlgorithmCardControl : AlgorithmCardControlT<AlgorithmCardControl, implementation::AlgorithmCardControl>
    {
    };
}
