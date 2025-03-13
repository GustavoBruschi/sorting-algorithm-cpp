#include <iostream>
#include <vector>

void countSort(int upperBound, int lowerBound, std::vector<int> numbersToSort)
{
    int range = upperBound - lowerBound + 1; 
    std::vector<int> counts(range, 0);
    
    
    for (size_t i = 0; i < numbersToSort.size(); i++)
    {
        int index = numbersToSort[i] - lowerBound;
        counts[index] += 1; 
    }

    
    std::vector<int> sortedArray;
    for (int i = 0; i < range; i++)
    {
        while (counts[i] > 0)
        {
            sortedArray.push_back(i + lowerBound);
            counts[i]--;
        }
    }

    
    std::cout << "Sorted array: ";
    for (int num : sortedArray)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> numbers = {5, 3, 8, 6, 3, 2, 7, 4};
    int lowerBound = 2, upperBound = 8;
    countSort(upperBound, lowerBound, numbers);
    return 0;
}
