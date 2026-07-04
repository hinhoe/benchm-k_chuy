#pragma once
#include <vector>
#include <string>

namespace Core {
    struct SortResult {
        std::string Name;
        long long Comparisons = 0;
        long long Swaps = 0;
        std::vector<int> Data;
    };

    class ISortStepper {
    public:
        virtual ~ISortStepper() = default;
        virtual void Initialize(const std::vector<int>& inputData) = 0;

        // Hàm chạy một bước duy nhất (Dùng cho UI có nút Step / Pause)
        // Trả về true nếu chưa xong, false nếu đã sắp xếp xong
        virtual bool Step() = 0;

        // Hàm chạy một mạch đến cuối (Dùng cho Benchmark lấy kết quả nhanh)
        virtual void Run() = 0;

        virtual SortResult GetResult() const = 0;
    };
}