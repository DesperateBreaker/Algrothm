// 排序算法类
#include "stdafx.h"

// --------------------------- MySort.h--------------------------- //

// 接口类
template <typename T>
class Sort
{
public:
    // 使用默认构造/析构函数
    // Sort();
    // virtual ~Sort();
    virtual void ArrySort(std::vector<T>& arr) = 0;
};

// 选择排序
template <typename T>
class SelectSort : public Sort<T>
{
public:
    virtual void ArrySort(std::vector<T>& arr);
};

//　冒泡排序
template <typename T>
class BubbleSort : public Sort<T>
{
public:
    virtual void ArrySort(std::vector<T>& arr);
};

// 插入排序
template <typename T>
class InsertSort : public Sort<T>
{
public:
    virtual void ArrySort(std::vector<T>& arr);
};

// 归并排序
template <typename T>
class MergeSort : public Sort<T>
{
public:
    virtual void ArrySort(std::vector<T>& arr);
};

// 快速排序
template <typename T>
class FastSort : public Sort<T>
{
public:
    virtual void ArrySort(std::vector<T>& arr);
};

// 堆排序
template <typename T>
class HeapSort : public Sort<T>
{
public:
    virtual void ArrySort(std::vector<T>& arr);
};


// -------------------------------------- //
// 下列是一些辅助函数

// 交换数组中的值
template <typename T>
void Swap(std::vector<T>& arr, int index1, int index2);



// --------------------------- MySort.cpp--------------------------- //
// It is best to implement template classes in the header file.

template <typename T>
void SelectSort<T>::ArrySort(std::vector<T>& arr)
{
    std::cout << "This is SelectSort!\n";
    int nSize = arr.size();

    for (int i = 0; i < nSize; i++)
    {
        int nMinIndex = i;
        for (int j = i; j < nSize; j++)
        {
            if (arr[j] < arr[nMinIndex])
                nMinIndex = j;
        }

        Swap(arr, nMinIndex, i);
    }
}

template <typename T>
void BubbleSort<T>::ArrySort(std::vector<T>& arr)
{
    std::cout << "This is BubbleSort!\n";
}

template <typename T>
void InsertSort<T>::ArrySort(std::vector<T>& arr)
{
    std::cout << "This is InsertSort!\n";
}

template <typename T>
void MergeSort<T>::ArrySort(std::vector<T>& arr)
{
    std::cout << "This is MergeSort!\n";
}

template <typename T>
void FastSort<T>::ArrySort(std::vector<T>& arr)
{
    std::cout << "This is FastSort!\n";
}

template <typename T>
void HeapSort<T>::ArrySort(std::vector<T>& arr)
{
    std::cout << "This is HeapSort!\n";
}

template <typename T>
void Swap(std::vector<T>& arr, int index1, int index2)
{
    int size = arr.size();

    if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size)
        std::swap(arr[index1], arr[index2]);
}
