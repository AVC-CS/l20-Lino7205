#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// Helper functions (inner loop only — one pass each)
// ============================================================

// Bubble: one pass through first N elements
// Compare adjacent pairs, swap if left > right
void bubble(vector<int>& numbers, int N)
{
    // TODO: Implement one pass over elements [0..N-1], swapping adjacent pairs if out of order
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] > numbers[i+1])
        {
            swap (numbers[i], numbers[i+1]);
        }
    }
}

// Selection: find index of minimum from index start to end of array
// Returns the index of the minimum value
int selection(vector<int>& numbers, int start, int N)
{
    // TODO: Find and return the index of the minimum element in [start..N-1]

    int minIdx = start;
    int startidx = 0;
    for (int i = start + 1; i < numbers.size(); i++){
        if (numbers[i] < numbers[minIdx]){
            minIdx = i;
        }
    } swap(numbers[startidx], numbers[minIdx]);
    

    return start;
}

// Insertion: insert element at index idx into sorted portion [0..idx-1]
// Shift larger elements right to make room
void insertion(vector<int>& numbers, int idx)
{
    // TODO: Insert numbers[idx] into its correct position in [0..idx-1]
    int key = numbers[idx];
    int j = idx - 1;
    while (j >= 0 && numbers[j] > key)
    {
        numbers[j + 1] = numbers[j];
        j--;
    }
    numbers[j+1] = key;
}

// ============================================================
// Utility
// ============================================================

void printNumbers(vector<int> numbers)
{
    for (int num : numbers)
        cout << num << " ";
    cout << endl;
}

// ============================================================
// Main — test each helper function (inner loop only)
// ============================================================

#ifndef TESTING
int main()
{
    // --- Test bubble() : one pass ---
    cout << "=== Bubble: One Pass ===" << endl;
    {
        vector<int> v = {40, 10, 30, 50, 20};
        cout << "Before:  ";
        printNumbers(v);

        bubble(v, 5);  // one pass over all 5 elements
        cout << "After bubble(v, 5):  ";
        printNumbers(v);
        // Expected: [10, 30, 40, 20, 50] — 50 bubbled to end

        bubble(v, 4);  // one pass over first 4 elements
        cout << "After bubble(v, 4):  ";
        printNumbers(v);
        // Expected: [10, 30, 20, 40, 50] — 40 bubbled to index 3
    }

    // --- Test selection() : find min index ---
    cout << "\n=== Selection: Find Min ===" << endl;
    {
        vector<int> v = {40, 10, 30, 50, 20};
        cout << "Array: ";
        printNumbers(v);

        int minIdx = selection(v, 0, 5);  // find min in [0..4]
        cout << "Min in [0..4]: index " << minIdx << " value " << v[minIdx] << endl;
        // Expected: index 1, value 10

        minIdx = selection(v, 2, 5);  // find min in [2..4]
        cout << "Min in [2..4]: index " << minIdx << " value " << v[minIdx] << endl;
        // Expected: index 4, value 20

        minIdx = selection(v, 1, 3);  // find min in [1..2]
        cout << "Min in [1..2]: index " << minIdx << " value " << v[minIdx] << endl;
        // Expected: index 1, value 10
    }

    // --- Test insertion() : insert one element ---
    cout << "\n=== Insertion: Insert One ===" << endl;
    {
        vector<int> v = {40, 10, 30, 50, 20};
        cout << "Before:  ";
        printNumbers(v);

        insertion(v, 1);  // insert v[1]=10 into sorted [0..0]
        cout << "After insertion(v, 1): ";
        printNumbers(v);
        // Expected: [10, 40, 30, 50, 20]

        insertion(v, 2);  // insert v[2]=30 into sorted [0..1]
        cout << "After insertion(v, 2): ";
        printNumbers(v);
        // Expected: [10, 30, 40, 50, 20]

        insertion(v, 3);  // insert v[3]=50 into sorted [0..2]
        cout << "After insertion(v, 3): ";
        printNumbers(v);
        // Expected: [10, 30, 40, 50, 20]

        insertion(v, 4);  // insert v[4]=20 into sorted [0..3]
        cout << "After insertion(v, 4): ";
        printNumbers(v);
        // Expected: [10, 20, 30, 40, 50]
    }

    return 0;
}
#endif
