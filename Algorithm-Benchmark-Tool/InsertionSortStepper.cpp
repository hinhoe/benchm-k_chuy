#include "pch.h"
#include "InsertionSortStepper.h"

namespace Core {
    InsertionSortStepper::InsertionSortStepper() {
        m_result.Name = "Insertion Sort";
    }

    void InsertionSortStepper::Initialize(const std::vector<int>& inputData) {
        m_result.Data = inputData;
        m_result.Comparisons = 0;
        m_result.Swaps = 0;
        m_i = 1;
        m_state = 0;
        m_isFinished = (inputData.size() <= 1);
    }

    bool InsertionSortStepper::Step() {
        if (m_isFinished) return false;

        if (m_state == 0) {
            m_x = m_result.Data[m_i];
            m_j = m_i - 1;
            m_state = 1; // Chuyển sang trạng thái so sánh
            return true;
        }

        if (m_state == 1) {
            if (m_j >= 0) {
                m_result.Comparisons++;
                if (m_result.Data[m_j] > m_x) {
                    m_result.Data[m_j + 1] = m_result.Data[m_j]; // Dịch chuyển
                    m_result.Swaps++;
                    m_j--;
                    return true; // Dừng 1 nhịp ở đây để UI vẽ
                }
            }
            // Nếu không thỏa mãn (hoặc j < 0), chèn x vào vị trí tìm được
            m_result.Data[m_j + 1] = m_x;
            m_i++;

            if (m_i >= m_result.Data.size()) {
                m_isFinished = true; // Đã chạy xong mảng
            }
            else {
                m_state = 0; // Quay lại lấy phần tử tiếp theo
            }
        }
        return true;
    }

    void InsertionSortStepper::Run() {
        while (Step()) {}
    }

    SortResult InsertionSortStepper::GetResult() const {
        return m_result;
    }
}