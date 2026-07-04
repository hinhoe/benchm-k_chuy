#pragma once
#include "ISortStepper.h"
#include <vector>

namespace Core {
    class ShellSortStepper : public ISortStepper {
    private:
        SortResult m_result;
        std::vector<int> m_gaps;
        int m_stepIdx, m_i, m_j, m_x, m_len;
        int m_state;
        bool m_isFinished;

    public:
        ShellSortStepper();
        void Initialize(const std::vector<int>& inputData) override;
        bool Step() override;
        void Run() override;
        SortResult GetResult() const override;
    };
}