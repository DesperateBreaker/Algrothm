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


// 选择排序
// 思想：依次在未排序区域选择最小值，放至已排序区末尾
// 时间复杂度：O(N^2)
// 空间复杂度：O（1）
// 稳定性：稳定
template <typename T>
void SelectSort<T>::ArrySort(std::vector<T>& arr)
{
    std::cout << "This is SelectSort!\n";
    int nSize = arr.size();
    
    // 外层循环：已排序区域
    for (int i = 0; i < nSize; i++)
    {
        int nMinIndex = i;
        
        // 内层循环：未排序区域
        for (int j = i; j < nSize; j++)
        {
            if (arr[j] < arr[nMinIndex])
                nMinIndex = j;
        }

        Swap(arr, nMinIndex, i);
    }
}

// 冒泡排序
// 思想：依次将未排序区的最大值，冒泡至已排序区前
// 时间复杂度：O(N^2)
// 空间复杂度：O（1）
// 稳定性：稳定
template <typename T>
void BubbleSort<T>::ArrySort(std::vector<T>& arr)
{
    std::cout << "This is BubbleSort!\n";
    int nSize = arr.size();

    // 外层循环：排序的轮数
    for(int i = 0; i < nSize; i++)
    {
        // 内层循环：每一轮比较的次数
        for (int j = 0; j < nSize - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(arr, j, j + 1);
            }
        }
    }
}

// 插入排序
// 思想：依次将未排序区的元素，插入至已排序区
// 时间复杂度：O(N)~O(N^2)
// 空间复杂度：O（1）
// 稳定性：稳定
template <typename T>
void InsertSort<T>::ArrySort(std::vector<T>& arr)
{
    std::cout << "This is InsertSort!\n";
    int nSize = arr.size();

    // 外层循环：已排序区域(0 位置已经有序)
    for (int i = 1; i < nSize; i++)
    {
        T curElement = arr[i];

        int j = i - 1;

        // 将 arr[0..i-1] 中大于 key 的元素向后移动
        while(j >= 0 && arr[j] > curElement)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // 插入当前元素到正确位置
        arr[j + 1] = curElement;
    }
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
