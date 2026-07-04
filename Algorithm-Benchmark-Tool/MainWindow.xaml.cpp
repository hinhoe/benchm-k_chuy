#include "pch.h"
#include "MainWindow.xaml.h"
#include "AlgorithmCardControl.xaml.h"
#include "AnalyticsChartControl.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace std;

namespace winrt::Algorithm_Benchmark_Tool::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        SetupTimer();
    }

    // ==========================================
    // LOGIC GIAO DIỆN XẾP THẺ
    // ==========================================
    void MainWindow::Sidebar_AlgorithmVisibilityChanged(winrt::hstring const& algoTag, bool isVisible)
    {
        auto visibility = isVisible ? Visibility::Visible : Visibility::Collapsed;
        if (algoTag == L"BubbleSort" && CardBubbleSort()) CardBubbleSort().Visibility(visibility);
        else if (algoTag == L"InsertionSort" && CardInsertionSort()) CardInsertionSort().Visibility(visibility);
        else if (algoTag == L"QuickSort" && CardQuickSort()) CardQuickSort().Visibility(visibility);
        else if (algoTag == L"MergeSort" && CardMergeSort()) CardMergeSort().Visibility(visibility);
        else if (algoTag == L"ShellSort" && CardShellSort()) CardShellSort().Visibility(visibility);

        vector<FrameworkElement> visibleCards;
        if (CardBubbleSort() && CardBubbleSort().Visibility() == Visibility::Visible) visibleCards.push_back(CardBubbleSort());
        if (CardInsertionSort() && CardInsertionSort().Visibility() == Visibility::Visible) visibleCards.push_back(CardInsertionSort());
        if (CardQuickSort() && CardQuickSort().Visibility() == Visibility::Visible) visibleCards.push_back(CardQuickSort());
        if (CardMergeSort() && CardMergeSort().Visibility() == Visibility::Visible) visibleCards.push_back(CardMergeSort());
        if (CardShellSort() && CardShellSort().Visibility() == Visibility::Visible) visibleCards.push_back(CardShellSort());

        for (size_t i = 0; i < visibleCards.size(); ++i)
        {
            Controls::Grid::SetRow(visibleCards[i], static_cast<int>(i / 2));
            Controls::Grid::SetColumn(visibleCards[i], static_cast<int>(i % 2));
        }
    }

    // ==========================================
    // CHUYỂN CHUỖI TỪ SIDEBAR THÀNH MẢNG INT
    // ==========================================
    vector<int> MainWindow::ParseInputData(winrt::hstring const& input)
    {
        vector<int> result;
        wstring ws(input.c_str());
        wstringstream wss(ws);
        wstring token;
        while (getline(wss, token, L','))
        {
            try {
                result.push_back(stoi(token));
            }
            catch (...) { /* Bỏ qua nếu lỗi format */ }
        }
        return result;
    }

    // ==========================================
    // CÀI ĐẶT TIMER
    // ==========================================
    void MainWindow::SetupTimer()
    {
        m_timer = DispatcherTimer();
        m_timer.Interval(std::chrono::milliseconds(50));
        m_timer.Tick([this](auto const&, auto const&)
            {
                ExecuteSingleStep();
            });
    }

    void MainWindow::InitializeAlgorithms(vector<int> const& data)
    {
        if (data.empty()) return;

        // Truyền mảng từ UI xuống các class trong thư mục core/
        if (CardBubbleSort().Visibility() == Visibility::Visible) {
            m_bubbleStepper.Initialize(data);
            CardBubbleSort().Status(L"Running...");
        }
        if (CardInsertionSort().Visibility() == Visibility::Visible) {
            m_insertionStepper.Initialize(data);
            CardInsertionSort().Status(L"Running...");
        }
        if (CardQuickSort().Visibility() == Visibility::Visible) {
            m_quickStepper.Initialize(data);
            CardQuickSort().Status(L"Running...");
        }
        if (CardMergeSort().Visibility() == Visibility::Visible) {
            m_mergeStepper.Initialize(data);
            CardMergeSort().Status(L"Running...");
        }
        if (CardShellSort().Visibility() == Visibility::Visible) {
            m_shellStepper.Initialize(data);
            CardShellSort().Status(L"Running...");
        }
        // Thêm tương tự cho QuickSort, MergeSort, ShellSort nếu bạn bật...
    }

    void MainWindow::ExecuteSingleStep()
    {
        bool isAnyRunning = false;

        // --- BUBBLE SORT ---
        if (CardBubbleSort().Visibility() == Visibility::Visible) {
            auto card = winrt::get_self<implementation::AlgorithmCardControl>(CardBubbleSort());
            m_bubbleHistory.push_back(m_bubbleStepper);
            bool isRunning = m_bubbleStepper.Step();
            Core::SortResult res = m_bubbleStepper.GetResult();

            if (isRunning) {
                card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
                CardBubbleSort().Comparisons(to_hstring(res.Comparisons));
                CardBubbleSort().Swaps(to_hstring(res.Swaps));
                isAnyRunning = true;
            }
            else {
                CardBubbleSort().Status(L"Completed");
                card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
            }

            // TRUYỀN BIẾN isRunning ĐỂ ĐẾM THỜI GIAN
            AppChart().UpdateData(L"BubbleSort", isRunning, res.Swaps);
        }

        // --- INSERTION SORT ---
        if (CardInsertionSort().Visibility() == Visibility::Visible) {
            auto card = winrt::get_self<implementation::AlgorithmCardControl>(CardInsertionSort());
            m_insertionHistory.push_back(m_insertionStepper);
            bool isRunning = m_insertionStepper.Step();
            Core::SortResult res = m_insertionStepper.GetResult();

            if (isRunning) {
                card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
                CardInsertionSort().Comparisons(to_hstring(res.Comparisons));
                CardInsertionSort().Swaps(to_hstring(res.Swaps));
                isAnyRunning = true;
            }
            else {
                CardInsertionSort().Status(L"Completed");
                card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
            }

            AppChart().UpdateData(L"InsertionSort", isRunning, res.Swaps);
        }

        // --- QUICK SORT ---
        if (CardQuickSort().Visibility() == Visibility::Visible) {
            auto card = winrt::get_self<implementation::AlgorithmCardControl>(CardQuickSort());
            m_quickHistory.push_back(m_quickStepper);
            bool isRunning = m_quickStepper.Step();
            Core::SortResult res = m_quickStepper.GetResult();

            if (isRunning) {
                card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
                CardQuickSort().Comparisons(to_hstring(res.Comparisons));
                CardQuickSort().Swaps(to_hstring(res.Swaps));
                isAnyRunning = true;
            }
            else {
                CardQuickSort().Status(L"Completed");
                card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
            }

            AppChart().UpdateData(L"QuickSort", isRunning, res.Swaps);
        }

        // --- MERGE SORT ---
        if (CardMergeSort().Visibility() == Visibility::Visible) {
            auto card = winrt::get_self<implementation::AlgorithmCardControl>(CardMergeSort());
            m_mergeHistory.push_back(m_mergeStepper);
            bool isRunning = m_mergeStepper.Step();
            Core::SortResult res = m_mergeStepper.GetResult();

            if (isRunning) {
                card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
                CardMergeSort().Comparisons(to_hstring(res.Comparisons));
                CardMergeSort().Swaps(to_hstring(res.Swaps));
                isAnyRunning = true;
            }
            else {
                CardMergeSort().Status(L"Completed");
                card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
            }

            AppChart().UpdateData(L"MergeSort", isRunning, res.Swaps);
        }

        // --- SHELL SORT ---
        if (CardShellSort().Visibility() == Visibility::Visible) {
            auto card = winrt::get_self<implementation::AlgorithmCardControl>(CardShellSort());
            m_shellHistory.push_back(m_shellStepper);
            bool isRunning = m_shellStepper.Step();
            Core::SortResult res = m_shellStepper.GetResult();

            if (isRunning) {
                card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
                CardShellSort().Comparisons(to_hstring(res.Comparisons));
                CardShellSort().Swaps(to_hstring(res.Swaps));
                isAnyRunning = true;
            }
            else {
                CardShellSort().Status(L"Completed");
                card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
            }

            AppChart().UpdateData(L"ShellSort", isRunning, res.Swaps);
        }

        // CHỐT LẠI SAU KHI ĐÃ CẬP NHẬT TẤT CẢ THUẬT TOÁN
        if (isAnyRunning) {
            // Yêu cầu biểu đồ vẽ tiến lên 1 nhịp
            AppChart().AdvanceStep();
        }
        else {
            m_timer.Stop();
        }
    }
    // ==========================================
    // XỬ LÝ 4 NÚT BẤM (START, PAUSE, STEP, STOP)
    // ==========================================
    void MainWindow::AppHeader_StartRequested(IInspectable const&, RoutedEventArgs const&)
    {
        hstring inputText = AppSidebar().GetInputText();
        vector<int> data = ParseInputData(inputText);

        InitializeAlgorithms(data);
        m_timer.Start();
    }

    void MainWindow::AppHeader_PauseRequested(IInspectable const&, RoutedEventArgs const&)
    {
        m_timer.Stop();
    }

    void MainWindow::AppHeader_StepRequested(IInspectable const&, RoutedEventArgs const&)
    {
        m_timer.Stop();

        // SỬA LỖI Ở DÒNG NÀY: Dùng GetResult() để truy cập Data
        if (m_bubbleStepper.GetResult().Data.empty()) {
            vector<int> data = ParseInputData(AppSidebar().GetInputText());
            InitializeAlgorithms(data);
        }

        ExecuteSingleStep();
    }

    void MainWindow::AppHeader_StopRequested(IInspectable const&, RoutedEventArgs const&)
    {
        m_timer.Stop();
        ResetUI();
    }

    // ==========================================
    // XỬ LÝ NÚT BACK (LÙI 1 BƯỚC)
    // ==========================================
    void MainWindow::AppHeader_BackRequested(IInspectable const&, RoutedEventArgs const&)
    {
        m_timer.Stop(); // Tạm dừng nếu đang chạy tự động

        // --- LÙI BUBBLE SORT ---
        if (CardBubbleSort().Visibility() == Visibility::Visible && !m_bubbleHistory.empty()) {
            m_bubbleStepper = m_bubbleHistory.back(); // Phục hồi trạng thái cũ
            m_bubbleHistory.pop_back();               // Xóa trạng thái đó khỏi lịch sử

            Core::SortResult res = m_bubbleStepper.GetResult();
            auto card = winrt::get_self<implementation::AlgorithmCardControl>(CardBubbleSort());
            card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
            CardBubbleSort().Comparisons(to_hstring(res.Comparisons));
            CardBubbleSort().Swaps(to_hstring(res.Swaps));
            CardBubbleSort().Status(L"Paused");
        }

        // --- LÙI INSERTION SORT ---
        if (CardInsertionSort().Visibility() == Visibility::Visible && !m_insertionHistory.empty()) {
            m_insertionStepper = m_insertionHistory.back();
            m_insertionHistory.pop_back();

            Core::SortResult res = m_insertionStepper.GetResult();
            auto card = winrt::get_self<implementation::AlgorithmCardControl>(CardInsertionSort());
            card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
            CardInsertionSort().Comparisons(to_hstring(res.Comparisons));
            CardInsertionSort().Swaps(to_hstring(res.Swaps));
            CardInsertionSort().Status(L"Paused");
        }

        // --- LÙI QUICK SORT ---
        if (CardQuickSort().Visibility() == Visibility::Visible && !m_quickHistory.empty()) {
            m_quickStepper = m_quickHistory.back();
            m_quickHistory.pop_back();

            Core::SortResult res = m_quickStepper.GetResult();
            auto card = winrt::get_self<implementation::AlgorithmCardControl>(CardQuickSort());
            card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
            CardQuickSort().Comparisons(to_hstring(res.Comparisons));
            CardQuickSort().Swaps(to_hstring(res.Swaps));
            CardQuickSort().Status(L"Paused");
        }

        // --- LÙI MERGE SORT ---
        if (CardMergeSort().Visibility() == Visibility::Visible && !m_mergeHistory.empty()) {
            m_mergeStepper = m_mergeHistory.back();
            m_mergeHistory.pop_back();

            Core::SortResult res = m_mergeStepper.GetResult();
            auto card = winrt::get_self<implementation::AlgorithmCardControl>(CardMergeSort());
            card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
            CardMergeSort().Comparisons(to_hstring(res.Comparisons));
            CardMergeSort().Swaps(to_hstring(res.Swaps));
            CardMergeSort().Status(L"Paused");
        }

        // --- LÙI SHELL SORT ---
        if (CardShellSort().Visibility() == Visibility::Visible && !m_shellHistory.empty()) {
            m_shellStepper = m_shellHistory.back();
            m_shellHistory.pop_back();

            Core::SortResult res = m_shellStepper.GetResult();
            auto card = winrt::get_self<implementation::AlgorithmCardControl>(CardShellSort());
            card->UpdateBars(winrt::array_view<int32_t const>(res.Data.data(), res.Data.size()), -1, -1);
            CardShellSort().Comparisons(to_hstring(res.Comparisons));
            CardShellSort().Swaps(to_hstring(res.Swaps));
            CardShellSort().Status(L"Paused");
        }
    }

    void MainWindow::ResetUI()
    {
        // Lấy con trỏ thực sự của các thẻ Card
        auto cardBubble = winrt::get_self<implementation::AlgorithmCardControl>(CardBubbleSort());
        auto cardInsertion = winrt::get_self<implementation::AlgorithmCardControl>(CardInsertionSort());
        auto cardQuick = winrt::get_self<implementation::AlgorithmCardControl>(CardQuickSort());
        auto cardMerge = winrt::get_self<implementation::AlgorithmCardControl>(CardMergeSort());
        auto cardShell = winrt::get_self<implementation::AlgorithmCardControl>(CardShellSort());

        // Khôi phục trạng thái thẻ Bubble Sort
        CardBubbleSort().Status(L"Idle");
        CardBubbleSort().Comparisons(L"0");
        CardBubbleSort().Swaps(L"0");
        cardBubble->UpdateBars({}, -1, -1); // Đã dùng con trỏ

        // Khôi phục trạng thái thẻ Insertion Sort
        CardInsertionSort().Status(L"Idle");
        CardInsertionSort().Comparisons(L"0");
        CardInsertionSort().Swaps(L"0");
        cardInsertion->UpdateBars({}, -1, -1);

        // Khôi phục trạng thái thẻ Quick Sort
        CardQuickSort().Status(L"Idle");
        CardQuickSort().Comparisons(L"0");
        CardQuickSort().Swaps(L"0");
        cardQuick->UpdateBars({}, -1, -1);

        // Khôi phục trạng thái thẻ Merge Sort
        CardMergeSort().Status(L"Idle");
        CardMergeSort().Comparisons(L"0");
        CardMergeSort().Swaps(L"0");
        cardMerge->UpdateBars({}, -1, -1);

        // Khôi phục trạng thái thẻ Shell Sort
        CardShellSort().Status(L"Idle");
        CardShellSort().Comparisons(L"0");
        CardShellSort().Swaps(L"0");
        cardShell->UpdateBars({}, -1, -1);

        // Xóa data bên trong các object để sẵn sàng cho mảng mới

        m_bubbleStepper.Initialize({});
        m_insertionStepper.Initialize({});
        m_quickStepper.Initialize({});
        m_mergeStepper.Initialize({});
        m_shellStepper.Initialize({});

        // Xóa các trạng thái đã lưu trước đó
        m_bubbleHistory.clear();
        m_insertionHistory.clear();
        m_quickHistory.clear();
        m_mergeHistory.clear();
        m_shellHistory.clear();

        // Xóa sạch biểu đồ
        AppChart().ClearCharts();
    }
    
}