// 排序算法类
#include "stdafx.h"
#include <utility>
#include <vector>

// --------------------------- MySort.h--------------------------- //

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
private:
    void MergeSortProcess(std::vector<T>& arr, std::vector<T>& assistArr, int nL, int nR);
    void Merge(std::vector<T>& arr, std::vector<T>& tempArr, int nL, int nMid, int nR);
};

// 快速排序
template <typename T>
class QuickSort : public Sort<T>
{
public:
    virtual void ArrySort(std::vector<T>& arr);
private:
    void QuickSortProcess(std::vector<T>& arr, int low, int high);
    std::pair<int, int> Partition(std::vector<T>& arr, int low, int high);
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

// 归并排序
// 思想：分治思想
// 时间复杂度：O(NLogN)
// 空间复杂度：O（N）
// 稳定性：稳定
template <typename T>
void MergeSort<T>::ArrySort(std::vector<T>& arr)
{
    std::cout << "This is MergeSort!\n";
    int nSize = arr.size();
    if (nSize < 2)
        return;

    // 辅助数组，避免频繁的内存分配
    std::vector<T> assistArr(nSize);
    
    MergeSortProcess(arr, assistArr, 0, nSize - 1);
}

// 归并排序辅助函数： 递归过程
template <typename T>
void MergeSort<T>::MergeSortProcess(std::vector<T>& arr, std::vector<T>& assistArr, int nL, int nR)
{
    std::vector<T> result;
    
    if (nL == nR)
        return;

    int nMid = nL + ((nR - nL) >> 1);
    MergeSortProcess(arr, assistArr, nL, nMid);
    MergeSortProcess(arr, assistArr, nMid + 1, nR);

    Merge(arr, assistArr, nL, nMid, nR);

    return;
}

// 归并排序辅助函数：合并过程
template <typename T>
void MergeSort<T>::Merge(std::vector<T>& arr, std::vector<T>& assistArr, int nL, int nMid, int nR)
{
    int pLeft = nL;
    int pRight = nMid + 1;

    int pTemp = nL;

    std::vector<T> result;
    while(pLeft <= nMid && pRight <= nR)
    {
        // attention: 要想保持稳定性，相等时应先拷贝左边元素
        // 但对于小和问题、逆序对问题时，有可能要先拷贝右侧元素，这样势必会破坏该算法的稳定性
        assistArr[pTemp++] = arr[pLeft] <= arr[pRight] ? arr[pLeft++] : arr[pRight++];
    }

    // 左侧还有剩余
    while(pLeft <= nMid)
        assistArr[pTemp++] = arr[pLeft++];

    // 右侧还有剩余
    while(pRight <= nR)
        assistArr[pTemp++] = arr[pRight++];

    // 将局部排序结果拷贝至原数组
    for (int i = nL; i <= nR; ++i)
        arr[i] = assistArr[i];

    return;
}

// 快速序
// 思想：分治思想、基准分类思想
// 时间复杂度：O(NLogN)
// 空间复杂度：O（LogN）
// 稳定性：不稳定
template <typename T>
void QuickSort<T>::ArrySort(std::vector<T>& arr)
{
    std::cout << "This is QuickSort!\n";
    int nSize = arr.size();
    if (nSize < 2)
        return;

    // 排序过程
    QuickSortProcess(arr, 0, nSize - 1);
}

// 快速排序辅助函数： 递归过程
template <typename T>
void QuickSort<T>::QuickSortProcess(std::vector<T>& arr, int low, int high)
{
    if (high <= low)
        return;

    auto [leftIndex, rightIndex] = Partition(arr, low, high);

    // 递归排序左半部分
    QuickSortProcess(arr, low, leftIndex - 1);

    // 递归排序右半部分
    QuickSortProcess(arr, rightIndex + 1, high);  
}

// 快速排序辅助函数： Partition 过程
template <typename T>
std::pair<int, int> QuickSort<T>::Partition(std::vector<T>& arr, int low, int high)
{
    // 选择基准元素 (理论上随机选较好、这里取最后一个元素)
    T basic_elem = arr[high];

    int lessAreaIndex  = low;       // 小于区域索引(包含)
    int greaterAreaIndex = high;    // 大于区域索引(包含)

    int nNowIndex = low;

    while (nNowIndex <= greaterAreaIndex)
    {
        // 如果小于基准值，当前元素与小于区域后一个元素交换，小于区域向右扩展
        if (arr[nNowIndex] < basic_elem)
        {
            std::swap(arr[lessAreaIndex], arr[nNowIndex]);
            lessAreaIndex++;
            nNowIndex++;
        }
        else if (arr[nNowIndex] == basic_elem)
        {
            nNowIndex++;
        }
        else
        {
            std::swap(arr[greaterAreaIndex], arr[nNowIndex]);
            greaterAreaIndex--;
        }
    }

    return std::make_pair(lessAreaIndex, greaterAreaIndex);
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
