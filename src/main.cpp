#include "../include/stdafx.h"
#include "../include/MyHeader.h"

int main() {
    std::vector<int> arr = {1, 5, 6, 1, 3, 9, 2, 0, 7};
    
    auto _pSort = new SelectSort();
    _pSort->ArrySort(arr);
}
