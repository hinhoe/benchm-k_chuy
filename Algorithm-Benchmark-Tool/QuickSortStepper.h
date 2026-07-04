#pragma once
#include "ISortStepper.h"
#include <stack>
#include <utility>

namespace Core {
    class QuickSortStepper : public ISortStepper {
    private:
        SortResult m_result;
        std::stack<std::pair<int, int>> m_stack;
        int m_left, m_right, m_i, m_j, m_pivot;
        int m_state; // 0: Lấy từ stack, 1: Lặp i, 2: Lặp j, 3: Đổi chỗ
        bool m_isFinished;

    public:
        QuickSortStepper();
        void Initialize(const std::vector<int>& inputData) override;
        bool Step() override;
        void Run() override;
        SortResult GetResult() const override;
    };
}