#include "pch.h"
#include "BubbleSortStepper.h"

namespace Core {

    BubbleSortStepper::BubbleSortStepper() {
        m_result.Name = "Bubble Sort";
    }

    void BubbleSortStepper::Initialize(const std::vector<int>& inputData) {
        m_result.Data = inputData;
        m_result.Comparisons = 0;
        m_result.Swaps = 0;

        // Khởi tạo trạng thái vòng lặp cho Bubble Sort
        m_i = 0;
        m_j = inputData.size() - 1;
        m_isFinished = (inputData.size() <= 1);
    }

    bool BubbleSortStepper::Step() {
        if (m_isFinished) return false;

        int n = m_result.Data.size();

        // Thực hiện 1 bước so sánh
        m_result.Comparisons++;
        if (m_result.Data[m_j] < m_result.Data[m_j - 1]) {
            int t = m_result.Data[m_j];
            m_result.Data[m_j] = m_result.Data[m_j - 1];
            m_result.Data[m_j - 1] = t;
            m_result.Swaps++;
        }

        // Cập nhật biến đếm cho bước tiếp theo (mô phỏng vòng lặp for)
        m_j--;
        if (m_j <= m_i) {
            m_i++;
            m_j = n - 1;
        }

        // Kiểm tra điều kiện kết thúc
        if (m_i >= n - 1) {
            m_isFinished = true;
            return false; // Đã xong
        }

        return true; // Vẫn còn bước tiếp theo
    }

    void BubbleSortStepper::Run() {
        // Run giờ đây chỉ đơn giản là gọi Step liên tục cho đến khi xong
        while (Step()) {}
    }

    SortResult BubbleSortStepper::GetResult() const {
        return m_result;
    }
}