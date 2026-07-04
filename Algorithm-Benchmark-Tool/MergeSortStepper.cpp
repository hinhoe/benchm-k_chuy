#include "pch.h"
#include "MergeSortStepper.h"
#include <algorithm>

namespace Core {
    MergeSortStepper::MergeSortStepper() {
        m_result.Name = "Merge Sort";
    }

    void MergeSortStepper::Initialize(const std::vector<int>& inputData) {
        m_result.Data = inputData;
        m_result.Comparisons = 0;
        m_result.Swaps = 0;
        m_tempArray = inputData; // Mảng phụ cùng kích thước

        m_currSize = 1;
        m_leftStart = 0;
        m_state = 0;
        m_isFinished = (inputData.size() <= 1);
    }

    bool MergeSortStepper::Step() {
        if (m_isFinished) return false;
        int n = m_result.Data.size();

        if (m_state == 0) {
            if (m_currSize >= n) {
                m_isFinished = true;
                return false;
            }
            if (m_leftStart >= n - 1) {
                // Tăng gấp đôi size và bắt đầu lại từ đầu mảng
                m_currSize *= 2;
                m_leftStart = 0;
                return true;
            }

            // Xác định giới hạn của 2 mảng con cần trộn
            m_mid = (std::min)(m_leftStart + m_currSize - 1, n - 1);
            m_rightEnd = (std::min)(m_leftStart + 2 * m_currSize - 1, n - 1);

            m_i = m_leftStart;
            m_j = m_mid + 1;
            m_k = m_leftStart;
            m_state = 1; // Bắt đầu trộn
            return true;
        }

        if (m_state == 1) { // Đang trộn 2 mảng
            if (m_i <= m_mid && m_j <= m_rightEnd) {
                m_result.Comparisons++;
                if (m_result.Data[m_i] <= m_result.Data[m_j]) {
                    m_tempArray[m_k++] = m_result.Data[m_i++];
                }
                else {
                    m_tempArray[m_k++] = m_result.Data[m_j++];
                }
                return true; // Dừng để UI cập nhật hiệu ứng (nếu lấy data từ tempArray)
            }
            m_state = 2; // Chuyển sang copy phần dư
            return true;
        }

        if (m_state == 2) { // Chép phần dư
            if (m_i <= m_mid) {
                m_tempArray[m_k++] = m_result.Data[m_i++];
                return true;
            }
            if (m_j <= m_rightEnd) {
                m_tempArray[m_k++] = m_result.Data[m_j++];
                return true;
            }
            m_k = m_leftStart; // Reset k để chép lại
            m_state = 3;
            return true;
        }

        if (m_state == 3) { // Chép từ mảng tạm về mảng gốc
            if (m_k <= m_rightEnd) {
                m_result.Data[m_k] = m_tempArray[m_k];
                m_result.Swaps++; // Tính là 1 lần hạ phần tử
                m_k++;
                return true;
            }

            // Đã trộn xong đoạn hiện tại, tiến tới đoạn tiếp theo
            m_leftStart += 2 * m_currSize;
            m_state = 0;
            return true;
        }

        return true;
    }

    void MergeSortStepper::Run() { while (Step()) {} }
    SortResult MergeSortStepper::GetResult() const { return m_result; }
}