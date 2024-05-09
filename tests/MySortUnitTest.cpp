#include "MySortUnitTest.h"

bool RunAllSortTests()
{
    std::vector<int> arr = {1, 5, 6, 1, 3, 9, 2, 0, 7};
    
    auto _pSort = new SelectSort();
    _pSort->ArrySort(arr);
    
    return true;
}