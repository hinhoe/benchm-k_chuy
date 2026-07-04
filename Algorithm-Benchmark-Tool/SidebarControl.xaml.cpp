#include "pch.h"
#include "SidebarControl.xaml.h"

#include "Algorithms.h"
#include <vector>
#include <sstream>
#include <string>

#include <random>

#if __has_include("SidebarControl.g.cpp")
#include "SidebarControl.g.cpp"
#endif

using namespace winrt;
using namespace std;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Algorithm_Benchmark_Tool::implementation
{
    SidebarControl::SidebarControl()
    {
        InitializeComponent();
    }

    winrt::event_token SidebarControl::AlgorithmVisibilityChanged(Algorithm_Benchmark_Tool::AlgorithmVisibilityHandler const& handler)
    {
        return m_algorithmVisibilityChanged.add(handler);
    }
    void SidebarControl::AlgorithmVisibilityChanged(winrt::event_token const& token) noexcept
    {
        m_algorithmVisibilityChanged.remove(token);
    }
    void SidebarControl::ToggleCheckBox_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        auto cb = sender.as<Microsoft::UI::Xaml::Controls::CheckBox>();
        m_algorithmVisibilityChanged(winrt::unbox_value<winrt::hstring>(cb.Tag()), true);
    }
    void SidebarControl::ToggleCheckBox_Unchecked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        auto cb = sender.as<Microsoft::UI::Xaml::Controls::CheckBox>();
        m_algorithmVisibilityChanged(winrt::unbox_value<winrt::hstring>(cb.Tag()), false);
    }

    winrt::hstring SidebarControl::GetInputText()
    {
        return numberInput().Text();
    }
    hstring SidebarControl::GetInputSize()
    {
        return sizeInput().Text();
    }
    std::vector<int> randomData(int size)
    {
        std::vector<int> data(size);
        // Sử dụng bộ sinh số ngẫu nhiên chuẩn C++11
        std::random_device rd;
        std::mt19937 gen(rd());

        // Giới hạn giá trị các số ngẫu nhiên (ví dụ: từ 1 đến 100)
        // Bạn có thể thay đổi khoảng này tùy ý đồ bài toán
        std::uniform_int_distribution<> distrib(1, 100);

        for (int i = 0; i < size; ++i)
        {
            data[i] = distrib(gen);
        }
        return data;
    }
    void SidebarControl::btnRandomData_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        numberInput().Text(L"");
        int size = 10;
        hstring numberSizeInput = sizeInput().Text();
        if (!numberSizeInput.empty()) {
            try {
                size = stoi(numberSizeInput.c_str());
                if (size <= 0) {
                    sizeInput().Text(L"10");
                    size = 10;
                }
            }
            catch (invalid_argument const&) {
                size = 10;
            }
            catch (out_of_range const&) {
                size = 10;
            }
        }
        vector<int>dataNumber = randomData(size);
        wstringstream wss;
        for (int i = 0; i < dataNumber.size(); i++) {
            wss << dataNumber[i];
            if (i < dataNumber.size() - 1) {
                wss << L", ";
            }
        }
        numberInput().Text(wss.str());
    }
}
