// 排序算法类
#include "stdafx.h"

// 接口类
class Sort 
{
public:
    // 使用默认构造/析构函数
    // Sort();
    // virtual ~Sort();
    virtual void ArrySort(std::vector<int>& arr) = 0;
};

// 选择排序
class SelectSort : public Sort
{
public:
    virtual void ArrySort(std::vector<int>& arr);
};

//　冒泡排序
class BubbleSort : public Sort
{
public:
    virtual void ArrySort(std::vector<int>& arr);
};

// 插入排序
class InsertSort : public Sort
{
public:
    virtual void ArrySort(std::vector<int>& arr);
};

// 归并排序
class MergeSort : public Sort
{
public:
    virtual void ArrySort(std::vector<int>& arr);
};

// 快速排序
class FastSort : public Sort
{
public:
    virtual void ArrySort(std::vector<int>& arr);
};

// 堆排序
class HeapSort : public Sort
{
public:
    virtual void ArrySort(std::vector<int>& arr);
};