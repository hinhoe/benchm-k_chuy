#pragma once
#include "ISortStepper.h"
#include <vector>

namespace Core {
    class MergeSortStepper : public ISortStepper {
    private:
        SortResult m_result;
        std::vector<int> m_tempArray; // Mảng tạm để gộp
        int m_currSize; // Kích thước mảng con đang gộp (1, 2, 4, 8...)
        int m_leftStart; // Vị trí bắt đầu mảng trái

        // Trạng thái trộn (Merge)
        int m_mid, m_rightEnd, m_i, m_j, m_k;
        int m_state; // 0: Tìm khoảng trộn, 1: Đang so sánh và trộn, 2: Chép phần dư, 3: Chép lại vào mảng gốc
        bool m_isFinished;

    public:
        MergeSortStepper();
        void Initialize(const std::vector<int>& inputData) override;
        bool Step() override;
        void Run() override;
        SortResult GetResult() const override;
    };
}