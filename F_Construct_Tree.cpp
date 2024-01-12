#include <iostream>
#include <vector>

using namespace std;

bool canConstructTree(const vector<int> &lengths, int d)
{
    int n = lengths.size();
    int totalLength = 0; // Replace accumulate with a manual sum

    // Condition 1: Calculate the sum of lengths manually
    for (int length : lengths)
    {
        totalLength += length;
    }
    if (totalLength != d)
    {
        return false;
    }

    // Condition 2: Find the maximum length using a loop
    int maxEdge = 0;
    for (int length : lengths)
    {
        maxEdge = max(maxEdge, length);
    }
    if (maxEdge > d)
    {
        return false;
    }

    // Condition 3: Count long edges using a loop
    int longEdges = 0;
    for (int length : lengths)
    {
        if (length >= d / 2)
        {
            longEdges++;
            if (longEdges > 2)
            {
                return false;
            }
        }
    }

    return true;
}

// Rest of the code remains the same
