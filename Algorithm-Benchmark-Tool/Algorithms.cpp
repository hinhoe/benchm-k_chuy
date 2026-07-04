#include "pch.h"
#include "Algorithms.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

vector<int>randomData(int n) {
    srand(time(0));
    vector<int>vecData;
    vecData.reserve(n);
    for (int i = 0; i < n; i++) {
        int randomNumber = rand() % 1000 + 1;
        vecData.push_back(randomNumber);
    }
    return vecData;
}

void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

