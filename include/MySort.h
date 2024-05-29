// 排序算法类
#include "stdafx.h"
#include <utility>
#include <vector>

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
    void MergeSortProcess(std::vector<T>& arr, std::vector<T>& assistArr, int nL, int nR);              // 归并排序的递归过程
    void Merge(std::vector<T>& arr, std::vector<T>& tempArr, int nL, int nMid, int nR);                 // 归并排序的合并过程
};

// 快速排序
template <typename T>
class QuickSort : public Sort<T>
{
public:
    virtual void ArrySort(std::vector<T>& arr);
private:
    void QuickSortProcess(std::vector<T>& arr, int nLow, int nHigh);                                    // 快速排序的递归过程
    std::pair<int, int> Partition(std::vector<T>& arr, int nLow, int nHigh);                            // 快速排序的 Patition
};

// 堆排序
template <typename T>
class HeapSort : public Sort<T>
{
public:
    virtual void ArrySort(std::vector<T>& arr);
private:
    void heapfyDown(std::vector<T>& arr, int nIndex, int nSize);                                        // heapfydown 操作 nSize: 调整至什么位置结束
};


// -------------------------------------- //
// 下列是一些辅助函数

// 交换数组中的值
template <typename T>
void Swap(std::vector<T>& arr, int nIndex1, int nIndex2);



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
    if (nSize < 2)
        return;
    
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
    if (nSize < 2)
        return;

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
    if (nSize < 2)
        return;

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

// 快速排序
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
void QuickSort<T>::QuickSortProcess(std::vector<T>& arr, int nLow, int nHigh)
{
    if (nHigh <= nLow)
        return;

    auto [leftIndex, rightIndex] = Partition(arr, nLow, nHigh);

    // 递归排序左半部分
    QuickSortProcess(arr, nLow, leftIndex - 1);

    // 递归排序右半部分
    QuickSortProcess(arr, rightIndex + 1, nHigh);  
}

// 快速排序辅助函数： Partition 过程
template <typename T>
std::pair<int, int> QuickSort<T>::Partition(std::vector<T>& arr, int nLow, int nHigh)
{
    // 选择基准元素 (理论上随机选较好、这里取最后一个元素)
    T basic_elem = arr[nHigh];

    int lessAreaIndex  = nLow;       // 小于区域索引(包含)
    int greaterAreaIndex = nHigh;    // 大于区域索引(包含)

    int nNowIndex = nLow;

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

// 堆排序
// 思想：构建堆 -> 最大值位于堆顶，除去最大值重新构建堆，重复执行 
// 时间复杂度：O(NLogN)
// 空间复杂度：O（1）
// 稳定性：不稳定
template <typename T>
void HeapSort<T>::ArrySort(std::vector<T>& arr)
{
    std::cout << "This is HeapSort!\n";
    int nSize = arr.size();
    if (nSize < 2)
        return;

    // 将 arr 调整为大根堆形式、调整完之后最大值位于堆顶
    for (int i = (nSize >> 1) - 1; i >= 0; i--)
    {
        heapfyDown(arr, i, nSize);
    }

    // 将最大值交换至尾部，剩下元素重新调整为大根堆(堆顶元素向下一次 heapfyDown 操作)
    for (int i = nSize - 1; i >= 1; i--)
    {
        std::swap(arr[0], arr[i]);
        heapfyDown(arr, 0, i);
    }

    return;
}

// 堆排序辅助函数
template <typename T>
void HeapSort<T>::heapfyDown(std::vector<T>& arr, int nCurIndex, int nSize)
{
    int leftIndex = 2 * nCurIndex + 1;      // 左子节点
    int rightIndex = 2 * nCurIndex + 2;     // 右子节点

    int largestIndex = nCurIndex;           // 较大节点

    if (leftIndex < nSize && arr[leftIndex] > arr[largestIndex])
        largestIndex = leftIndex;

    if (rightIndex < nSize && arr[rightIndex] > arr[largestIndex])
        largestIndex = rightIndex;

    if (largestIndex != nCurIndex)
    {
        std::swap(arr[largestIndex], arr[nCurIndex]);
        heapfyDown(arr, largestIndex, nSize);
    }

    return;
}

template <typename T>
void Swap(std::vector<T>& arr, int nIndex1, int nIndex2)
{
    int size = arr.size();

    if (nIndex1 >= 0 && nIndex1 < size && nIndex2 >= 0 && nIndex2 < size)
        std::swap(arr[nIndex1], arr[nIndex2]);
}
