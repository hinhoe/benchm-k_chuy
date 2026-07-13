#include "pch.h"
#include "AlgorithmCardControl.xaml.h"
#if __has_include("AlgorithmCardControl.g.cpp")
#include "AlgorithmCardControl.g.cpp"
#endif
#include <cmath>
using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Algorithm_Benchmark_Tool::implementation
{
    DependencyProperty AlgorithmCardControl::m_algorithmNameProperty =
        DependencyProperty::Register(
            L"AlgorithmName",
            xaml_typename<winrt::hstring>(),
            xaml_typename<Algorithm_Benchmark_Tool::AlgorithmCardControl>(),
            PropertyMetadata{ winrt::box_value(L"") }
        );

    DependencyProperty AlgorithmCardControl::m_complexityProperty =
        DependencyProperty::Register(
            L"Complexity",
            xaml_typename<winrt::hstring>(),
            xaml_typename<Algorithm_Benchmark_Tool::AlgorithmCardControl>(),
            PropertyMetadata{ winrt::box_value(L"") }
        );
    DependencyProperty AlgorithmCardControl::m_BestProperty =
        DependencyProperty::Register(
            L"Best",
            xaml_typename<winrt::hstring>(),
            xaml_typename<Algorithm_Benchmark_Tool::AlgorithmCardControl>(),
            PropertyMetadata{ winrt::box_value(L"") }
        );
    DependencyProperty AlgorithmCardControl::m_AvgProperty =
        DependencyProperty::Register(
            L"Avg",
            xaml_typename<winrt::hstring>(),
            xaml_typename<Algorithm_Benchmark_Tool::AlgorithmCardControl>(),
            PropertyMetadata{ winrt::box_value(L"") }
        );
    DependencyProperty AlgorithmCardControl::m_WorstProperty =
        DependencyProperty::Register(
            L"Worst",
            xaml_typename<winrt::hstring>(),
            xaml_typename<Algorithm_Benchmark_Tool::AlgorithmCardControl>(),
            PropertyMetadata{ winrt::box_value(L"") }
        );
    DependencyProperty AlgorithmCardControl::m_SpaceProperty =
        DependencyProperty::Register(
            L"Space",
            xaml_typename<winrt::hstring>(),
            xaml_typename<Algorithm_Benchmark_Tool::AlgorithmCardControl>(),
            PropertyMetadata{ winrt::box_value(L"") }
        );
    DependencyProperty AlgorithmCardControl::m_ComparisonsProperty =
        DependencyProperty::Register(
            L"Comparisons",
            xaml_typename<winrt::hstring>(),
            xaml_typename<Algorithm_Benchmark_Tool::AlgorithmCardControl>(),
            PropertyMetadata{ winrt::box_value(L"0") }
        );
    DependencyProperty AlgorithmCardControl::m_SwapsProperty =
        DependencyProperty::Register(
            L"Swaps",
            xaml_typename<winrt::hstring>(),
            xaml_typename<Algorithm_Benchmark_Tool::AlgorithmCardControl>(),
            PropertyMetadata{ winrt::box_value(L"0") }
        );
    DependencyProperty AlgorithmCardControl::m_StatusProperty =
        DependencyProperty::Register(
            L"Status",
            xaml_typename<winrt::hstring>(),
            xaml_typename<Algorithm_Benchmark_Tool::AlgorithmCardControl>(),
            PropertyMetadata{ winrt::box_value(L"Idle") }
        );
    DependencyProperty AlgorithmCardControl::m_ElapsedMsProperty =
        DependencyProperty::Register(
            L"ElapsedMs",
            xaml_typename<winrt::hstring>(),
            xaml_typename<Algorithm_Benchmark_Tool::AlgorithmCardControl>(),
            PropertyMetadata{ winrt::box_value(L"") }
        );

    AlgorithmCardControl::AlgorithmCardControl()
    {
        InitializeComponent();
    }

    winrt::hstring AlgorithmCardControl::AlgorithmName()
    {
        return unbox_value<winrt::hstring>(GetValue(m_algorithmNameProperty));
    }
    void AlgorithmCardControl::AlgorithmName(winrt::hstring const& value)
    {
        SetValue(m_algorithmNameProperty, box_value(value));
    }
    DependencyProperty AlgorithmCardControl::AlgorithmNameProperty()
    {
        return m_algorithmNameProperty;
    }

    winrt::hstring AlgorithmCardControl::Complexity()
    {
        return unbox_value<winrt::hstring>(GetValue(m_complexityProperty));
    }
    void AlgorithmCardControl::Complexity(winrt::hstring const& value)
    {
        SetValue(m_complexityProperty, box_value(value));
    }
    DependencyProperty AlgorithmCardControl::ComplexityProperty()
    {
        return m_complexityProperty;
    }

    winrt::hstring AlgorithmCardControl::Best()
    {
        return unbox_value<winrt::hstring>(GetValue(m_BestProperty));
    }
    void AlgorithmCardControl::Best(winrt::hstring const& value)
    {
        SetValue(m_BestProperty, box_value(value));
    }
    DependencyProperty AlgorithmCardControl::BestProperty()
    {
        return m_BestProperty;
    }

    winrt::hstring AlgorithmCardControl::Avg()
    {
        return unbox_value<winrt::hstring>(GetValue(m_AvgProperty));
    }
    void AlgorithmCardControl::Avg(winrt::hstring const& value)
    {
        SetValue(m_AvgProperty, box_value(value));
    }
    DependencyProperty AlgorithmCardControl::AvgProperty()
    {
        return m_AvgProperty;
    }

    winrt::hstring AlgorithmCardControl::Worst()
    {
        return unbox_value<winrt::hstring>(GetValue(m_WorstProperty));
    }
    void AlgorithmCardControl::Worst(winrt::hstring const& value)
    {
        SetValue(m_WorstProperty, box_value(value));
    }
    DependencyProperty AlgorithmCardControl::WorstProperty()
    {
        return m_WorstProperty;
    }

    winrt::hstring AlgorithmCardControl::Space()
    {
        return unbox_value<winrt::hstring>(GetValue(m_SpaceProperty));
    }
    void AlgorithmCardControl::Space(winrt::hstring const& value)
    {
        SetValue(m_SpaceProperty, box_value(value));
    }
    DependencyProperty AlgorithmCardControl::SpaceProperty()
    {
        return m_SpaceProperty;
    }
    winrt::hstring AlgorithmCardControl::Comparisons()
    {
        return unbox_value<winrt::hstring>(GetValue(m_ComparisonsProperty));
    }
    void AlgorithmCardControl::Comparisons(winrt::hstring const& value)
    {
        SetValue(m_ComparisonsProperty, box_value(value));
    }
    DependencyProperty AlgorithmCardControl::ComparisonsProperty()
    {
        return m_ComparisonsProperty;
    }

    winrt::hstring AlgorithmCardControl::Swaps()
    {
        return unbox_value<winrt::hstring>(GetValue(m_SwapsProperty));
    }
    void AlgorithmCardControl::Swaps(winrt::hstring const& value)
    {
        SetValue(m_SwapsProperty, box_value(value));
    }
    DependencyProperty AlgorithmCardControl::SwapsProperty()
    {
        return m_SwapsProperty;
    }

    winrt::hstring AlgorithmCardControl::Status()
    {
        return unbox_value<winrt::hstring>(GetValue(m_StatusProperty));
    }
    void AlgorithmCardControl::Status(winrt::hstring const& value)
    {
        SetValue(m_StatusProperty, box_value(value));
    }
    DependencyProperty AlgorithmCardControl::StatusProperty()
    {
        return m_StatusProperty;
    }

    winrt::hstring AlgorithmCardControl::ElapsedMs()
    {
        return unbox_value<winrt::hstring>(GetValue(m_ElapsedMsProperty));
    }
    void AlgorithmCardControl::ElapsedMs(winrt::hstring const& value)
    {
        SetValue(m_ElapsedMsProperty, box_value(value));
    }
    DependencyProperty AlgorithmCardControl::ElapsedMsProperty()
    {
        return m_ElapsedMsProperty;
    }

    void AlgorithmCardControl::SetStatus(winrt::hstring const& status, int32_t elapsedMs)
    {
        Status(status);
        ElapsedMs(winrt::hstring(std::to_wstring(elapsedMs) + L"ms"));
    }

    // ==========================================================
    // VẼ BIỂU ĐỒ CỘT LÊN CANVAS — gọi mỗi khi có 1 bước mới
    // ==========================================================
    void AlgorithmCardControl::UpdateBars(winrt::array_view<int32_t const> data, int32_t index1, int32_t index2)
    {
        SortingCanvas().Children().Clear();

        int32_t n = (int32_t)data.size();
        if (n == 0) return;

        double canvasWidth = SortingCanvas().ActualWidth();
        double canvasHeight = SortingCanvas().ActualHeight();
        if (canvasWidth <= 0 || canvasHeight <= 0) return;

        int32_t maxVal = 0;
        for (int32_t v : data) maxVal = (std::max)(maxVal, v);
        if (maxVal == 0) maxVal = 1;

        double gap = 1.0;
        double barWidth = (canvasWidth - gap * (n - 1)) / n;
        if (barWidth < 1.0) barWidth = 1.0;

        for (int32_t i = 0; i < n; i++)
        {
            double barHeight = ((double)data[i] / maxVal) * canvasHeight;
            Microsoft::UI::Xaml::Shapes::Rectangle rect;
            rect.Width(barWidth);
            rect.Height(barHeight);

            bool isActive = (i == index1 || i == index2);
            Microsoft::UI::Xaml::Media::SolidColorBrush brush(
                isActive ? Windows::UI::Colors::OrangeRed() : Microsoft::UI::Colors::DeepSkyBlue());
            rect.Fill(brush);

            double x = i * (barWidth + gap);
            double y = canvasHeight - barHeight;

            Microsoft::UI::Xaml::Controls::Canvas::SetLeft(rect, x);
            Microsoft::UI::Xaml::Controls::Canvas::SetTop(rect, y);

            SortingCanvas().Children().Append(rect);
        }
    }
    void AlgorithmCardControl::BtnExpand_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        // Lấy nút bấm và icon bên trong nó
        auto btn = sender.as<winrt::Microsoft::UI::Xaml::Controls::Button>();
        auto icon = btn.Content().as<winrt::Microsoft::UI::Xaml::Controls::FontIcon>();

        if (!m_isExpanded)
        {
            // TRẠNG THÁI: PHÓNG TO
            // Bạn có thể chỉnh con số 800 và 600 này cho vừa mắt
            this->Width(800);
            this->Height(600);

            // Đổi sang icon Thu nhỏ (BackToWindow)
            icon.Glyph(L"\xE73F");
            m_isExpanded = true;
        }
        else
        {
            // TRẠNG THÁI: THU NHỎ VỀ BAN ĐẦU
                // Trả Width và Height về Auto (NAN trong C++ tương đương Auto trong XAML)
            this->Width(std::nan(""));
            this->Height(std::nan(""));

            // Đổi lại icon Phóng to (FullScreen)
            icon.Glyph(L"\xE740");
            m_isExpanded = false;
        }


    }









}
