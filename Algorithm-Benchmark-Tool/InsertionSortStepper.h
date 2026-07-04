#pragma once
#include "ISortStepper.h"

namespace Core {
    class InsertionSortStepper : public ISortStepper {
    private:
        SortResult m_result;
        int m_i;
        int m_j;
        int m_x;
        int m_state; // 0: Chuẩn bị phần tử mới, 1: Đang lùi j để so sánh
        bool m_isFinished;

    public:
        InsertionSortStepper();
        void Initialize(const std::vector<int>& inputData) override;
        bool Step() override;
        void Run() override;
        SortResult GetResult() const override;
    };
}