#include "MySortUnitTest.h"
#include <algorithm>
#include <vector>

bool IsEqual(const std::vector<int>& vec1, const std::vector<int>& vec2)
{
    if (vec1.size() != vec2.size()) {
        return false;  // Vectors have different sizes, so they can't be equal
    }

    return std::equal(vec1.begin(), vec1.end(), vec2.begin());
}

int GenerateRandomInteger(int min_value, int max_value) {
    // Initialize a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min_value, max_value);

    // Generate a random integer within the specified range
    return distribution(gen);
}

template <typename T>
bool ComparativeTest(Sort<T>* pSort)
{
    for (int i = 0; i < 50; i++)
    {
        // 生成一个随机数作为数组大小
        int nSize = GenerateRandomInteger(0, 50);
        
        // 生成一个随机的数组
        std::vector<int> arr1;
        for (int j = 0; j < nSize; j++)
        {
            int nTemp = GenerateRandomInteger(-10000, 10000);
            arr1.push_back(nTemp);
        }

        std::vector<int> arr2 = arr1;

        // arr1 使用系统标准排序函数
        std::sort(arr1.begin(), arr1.end());

        // arr2 使用自己的排序算法
        pSort->ArrySort(arr2);

        bool bEqual = IsEqual(arr1, arr2);
        if (!bEqual)
            return false;
    }

    return true;  
}


bool RunAllSortTests()
{
    bool bRet = true;
    
    // 选择排序测试
    SelectSort<int> selectSort;
    bRet &= ComparativeTest(&selectSort);

    // 冒泡排序测试
    BubbleSort<int> bubbleSort;
    bRet &= ComparativeTest(&bubbleSort);

    // 插补排序测试
    InsertSort<int> insertSort;
    bRet &= ComparativeTest(&insertSort);
    
    return bRet;
}