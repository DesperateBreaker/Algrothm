#include "../include/MySort.h"

// 两个 vector 是否相等
bool IsEqual(const std::vector<int>& vec1, const std::vector<int>& vec2);

// 生成一个随机数
int GenerateRandomInteger(int min_value, int max_value);

// 对数器比较，传入排序算法指针
template <typename T>
bool ComparativeTest(Sort<T>* pSort);

bool RunAllSortTests();