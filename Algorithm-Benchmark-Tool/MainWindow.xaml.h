#pragma once

#include "MainWindow.g.h"
#include <winrt/Microsoft.UI.Xaml.h>
#include <vector>
#include <string>
#include <sstream>

#include "BubbleSortStepper.h"
#include "InsertionSortStepper.h"
#include "QuickSortStepper.h"
#include "MergeSortStepper.h"
#include "ShellSortStepper.h"

namespace winrt::Algorithm_Benchmark_Tool::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        void Sidebar_AlgorithmVisibilityChanged(winrt::hstring const& algoTag, bool isVisible);
        void AppHeader_StartRequested(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void AppHeader_PauseRequested(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void AppHeader_StepRequested(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void AppHeader_StopRequested(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void AppHeader_BackRequested(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        // ==========================================
        // BIẾN TRẠNG THÁI MỚI THÊM VÀO DƯỚI ĐÂY
        // ==========================================
        bool m_isPaused{ false };

        winrt::Microsoft::UI::Xaml::DispatcherTimer m_timer{ nullptr };

        // Dùng namespace Core:: để khai báo
        Core::BubbleSortStepper m_bubbleStepper;
        Core::InsertionSortStepper m_insertionStepper;
        Core::QuickSortStepper m_quickStepper;
        Core::MergeSortStepper m_mergeStepper;
        Core::ShellSortStepper m_shellStepper;

        // Lịch sử trạng thái của từng thuật toán
        std::vector<Core::BubbleSortStepper> m_bubbleHistory;
        std::vector<Core::InsertionSortStepper> m_insertionHistory;
        std::vector<Core::QuickSortStepper> m_quickHistory;
        std::vector<Core::MergeSortStepper> m_mergeHistory;
        std::vector<Core::ShellSortStepper> m_shellHistory;

        void SetupTimer();
        void ExecuteSingleStep();
        std::vector<int> ParseInputData(winrt::hstring const& input);
        void InitializeAlgorithms(std::vector<int> const& data);
        void ResetUI();
    };
}

namespace winrt::Algorithm_Benchmark_Tool::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}