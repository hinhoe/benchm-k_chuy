#pragma once
#include "ISortStepper.h"

namespace Core {
    class BubbleSortStepper : public ISortStepper {
    private:
        SortResult m_result;
        int m_i; // Biến lưu trạng thái vòng lặp ngoài
        int m_j; // Biến lưu trạng thái vòng lặp trong
        bool m_isFinished;

    public:
        BubbleSortStepper();
        void Initialize(const std::vector<int>& inputData) override;
        bool Step() override;
        void Run() override;
        SortResult GetResult() const override;
    };
}