#include "pch.h"
#include "QuickSortStepper.h"

namespace Core {
    QuickSortStepper::QuickSortStepper() {
        m_result.Name = "Quick Sort";
    }

    void QuickSortStepper::Initialize(const std::vector<int>& inputData) {
        m_result.Data = inputData;
        m_result.Comparisons = 0;
        m_result.Swaps = 0;

        while (!m_stack.empty()) m_stack.pop(); // Clear stack
        m_isFinished = (inputData.size() <= 1);

        if (!m_isFinished) {
            m_stack.push({ 0, inputData.size() - 1 });
            m_state = 0;
        }
    }

    bool QuickSortStepper::Step() {
        if (m_isFinished) return false;

        switch (m_state) {
        case 0: // Lấy mảng con từ Stack
            if (m_stack.empty()) {
                m_isFinished = true;
                return false;
            }
            m_left = m_stack.top().first;
            m_right = m_stack.top().second;
            m_stack.pop();

            m_i = m_left;
            m_j = m_right;
            m_pivot = m_result.Data[(m_left + m_right) / 2];
            m_state = 1;
            return true;

        case 1: // Di chuyển i
            m_result.Comparisons++;
            if (m_result.Data[m_i] < m_pivot) {
                m_i++;
                return true;
            }
            m_state = 2; // Chuyển sang tìm j
            return true;

        case 2: // Di chuyển j
            m_result.Comparisons++;
            if (m_result.Data[m_j] > m_pivot) {
                m_j--;
                return true;
            }
            m_state = 3; // Chuyển sang kiểm tra đổi chỗ
            return true;

        case 3: // Kiểm tra và đổi chỗ
            if (m_i <= m_j) {
                int temp = m_result.Data[m_i];
                m_result.Data[m_i] = m_result.Data[m_j];
                m_result.Data[m_j] = temp;
                m_result.Swaps++;
                m_i++;
                m_j--;
            }

            if (m_i <= m_j) {
                m_state = 1; // Tiếp tục vòng lặp partition
            }
            else {
                // Partition xong, đẩy mảng con vào stack
                if (m_left < m_j) m_stack.push({ m_left, m_j });
                if (m_i < m_right) m_stack.push({ m_i, m_right });
                m_state = 0; // Quay lại lấy mảng con mới
            }
            return true;
        }
        return true;
    }

    void QuickSortStepper::Run() { while (Step()) {} }
    SortResult QuickSortStepper::GetResult() const { return m_result; }
}