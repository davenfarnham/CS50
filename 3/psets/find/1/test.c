/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Set values for the top and the bottom of the search
    int lower = 0;
    int upper = n - 1;

    // Binary search
    while (lower <= upper)
    {
        int middle = (upper + lower) / 2;

        if (values[middle] == value)
            return true;
        else if (values[middle] < value)
            lower = middle + 1;
        else if (values[middle] > value)
            upper = middle - 1;
    }

    return false;
}

