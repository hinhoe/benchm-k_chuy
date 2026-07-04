#include "pch.h"
#include "ShellSortStepper.h"

namespace Core {
    ShellSortStepper::ShellSortStepper() {
        m_result.Name = "Shell Sort";
        m_gaps = { 701, 301, 132, 57, 23, 10, 4, 1 }; // Dãy Knuth
    }

    void ShellSortStepper::Initialize(const std::vector<int>& inputData) {
        m_result.Data = inputData;
        m_result.Comparisons = 0;
        m_result.Swaps = 0;

        m_stepIdx = 0;
        // Bỏ qua các khoảng gap lớn hơn kích thước mảng
        while (m_stepIdx < m_gaps.size() && m_gaps[m_stepIdx] >= inputData.size()) {
            m_stepIdx++;
        }

        m_isFinished = (m_stepIdx >= m_gaps.size() || inputData.size() <= 1);
        if (!m_isFinished) {
            m_len = m_gaps[m_stepIdx];
            m_i = m_len;
            m_state = 0; // 0: Gán x, 1: So sánh và dịch
        }
    }

    bool ShellSortStepper::Step() {
        if (m_isFinished) return false;

        if (m_state == 0) {
            m_x = m_result.Data[m_i];
            m_j = m_i - m_len;
            m_state = 1;
            return true;
        }

        if (m_state == 1) {
            if (m_j >= 0) {
                m_result.Comparisons++;
                if (m_result.Data[m_j] > m_x) {
                    m_result.Data[m_j + m_len] = m_result.Data[m_j];
                    m_result.Swaps++;
                    m_j -= m_len;
                    return true;
                }
            }
            m_result.Data[m_j + m_len] = m_x;
            m_i++;

            if (m_i >= m_result.Data.size()) {
                m_stepIdx++; // Chuyển sang gap tiếp theo
                if (m_stepIdx >= m_gaps.size()) {
                    m_isFinished = true;
                }
                else {
                    m_len = m_gaps[m_stepIdx];
                    m_i = m_len;
                    m_state = 0;
                }
            }
            else {
                m_state = 0;
            }
        }
        return true;
    }

    void ShellSortStepper::Run() { while (Step()) {} }
    SortResult ShellSortStepper::GetResult() const { return m_result; }
}