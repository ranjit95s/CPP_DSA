#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
// ? default functions
void print_Array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_VArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_2DArray(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
    cout << "\n";
}

/* !
! |----------------------------- SUB_main_Func start -----------------------------|
*/

void swapTwoNum_Func(int *a, int *b)
{ //1
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void reverse_Func1(int *arr, int n)
{ //2.1
    // start-end algo
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        // swap(arr[s],arr[e]);
        arr[s] = arr[s] + arr[e];
        arr[e] = arr[s] - arr[e];
        arr[s] = arr[s] - arr[e];
        s++;
        e--;
    }
}

void reverse_Func2(int *arr, int n)
{ //2.2
    // in-place algo
    for (int i = 0; i < n / 2; i++)
    {
        arr[i] = arr[i] + arr[n - i - 1];
        arr[n - i - 1] = arr[i] - arr[n - i - 1];
        arr[i] = arr[i] - arr[n - i - 1];
    }
}

void reverse_Func3(int *arr, int start, int end)
{ // 2.3
    if (start >= end)
        return;
    arr[start] = arr[start] + arr[end];
    arr[end] = arr[start] - arr[end];
    arr[start] = arr[start] - arr[end];
    reverse_Func3(arr, start + 1, end - 1);
}

void minMax_Main_Func(int *arr, int n)
{ // 3
    pair<int, int> minmax;

    if (n == 1)
    {
        int min = minmax.first = arr[0];
        int max = minmax.second = arr[0];
        cout << "min : " << min << " max : " << max;
        return;
    }

    int i;
    if (arr[0] > arr[1])
    {
        minmax.first = arr[1];
        minmax.second = arr[0];
    }
    else
    {
        minmax.first = arr[0];
        minmax.second = arr[1];
    }

    for (i = 1; i < n; i++)
    {
        int min = minmax.first;
        int max = minmax.second;
        if (arr[i] > max)
            minmax.second = arr[i];
        if (arr[i] < min)
            minmax.first = arr[i];
    }
    int min = minmax.first;
    int max = minmax.second;
    cout << "min : " << min << " max : " << max;
}

void kthSmall_Main_Func(int *arr, int n, int k)
{ // 4
    // priority Queues
    priority_queue<int> kSmall;

    for (int i = 0; i < n; i++)
    {
        kSmall.push(arr[i]);
        if (kSmall.size() > k)
            kSmall.pop();
    }
    cout << "kth smallest elem : " << kSmall.top() << endl;
}

void sort012_Main_Func1(int *arr, int n)
{ // 5.1
    // low - mid - high
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid++], arr[low++]);
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high--]);
        }
    }
}

void sort012_Main_Func2(int *arr, int n)
{ // 5.2
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else if (arr[i] == 2)
            cnt2++;
    }
    for (int i = 0; i < n; i++)
    {
        if (cnt0 > 0)
        {
            arr[i] = 0;
            cnt0--;
        }
        else if (cnt1 > 0)
        {
            arr[i] = 1;
            cnt1--;
        }
        else if (cnt2 > 0)
        {
            arr[i] = 2;
            cnt2--;
        }
    }
}

void moveNegative_Main_Func1(int *arr, int n)
{ // 6.1
    int place_ve = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            if (i != place_ve)
                swap(arr[i], arr[place_ve++]);
    }
}

void moveNegative_Main_Func2(int *arr, int left, int right)
{ // 6.2
    while (left <= right)
    {
        if (arr[left] < 0 && arr[right] < 0)
            left++;
        else if (arr[left] > 0 && arr[right] > 0)
            right--;
        else if (arr[left] > 0 && arr[right] < 0)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        else if (arr[left] < 0 && arr[right] > 0)
        {
            left++;
            right--;
        }
    }
}

void uniIntersec_Main_Func(int *arr0, int *arr1, int n0, int n1)
{ // 7
    unordered_set<int> set;
    for (int i = 0; i < n0; i++)
        set.insert(arr0[i]);
    for (int i = 0; i < n1; i++)
        set.insert(arr1[i]);
    cout << "union and intersection of 2 sorted arrays is : " << set.size() << endl;
}

void cyclically_rotate_Main_Func(int *arr, int n)
{                          // 8
    int last = arr[n - 1]; // 5
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
        // 1 2 3 4
    }
    arr[0] = last;
    // 5 1 2 3 4
}

void findContiSubArr_Main_Func(int *arr, int n)
{ // 9
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum > maxSum)
            maxSum = currSum;
        if (currSum < 0)
            currSum = 0;
    }
    cout << "maxSum is : " << maxSum << endl;
}

void singleNumber_Main_Func(int *arr, int n)
{ // MISC 1
    sort(arr, arr + n);
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] != arr[i - 1])
        {
            cout << "Single Number is : " << arr[i - 1] << endl;
            return;
        }
    }
    cout << "Single Number is : " << arr[n - 1] << endl;
}

int getLessCount(vector<int> arr, int midNum)
{ // 12.1.1
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= midNum)
            cnt++;
    }
    return cnt;
}
void duplicate_In_Array_Main_Func1(vector<int> arr, int n)
{ // 12.0.1
    //? Using Binary Search
    // ! ( Contain BUGS )
    int start = 1;
    int end = arr.size() - 1;
    int ans = 0;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (getLessCount(arr, mid) > mid)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << "Duplicate is : " << mid << endl;
}

void duplicate_In_Array_Main_Func2(vector<int> arr, int n)
{ // 12.2
    // ? TWO POINTER ALGO
    int slow = 0;
    int fast = 0;
    int i = 0;

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
        cout << slow << " (1) " << fast << "\n";
    } while (slow != fast);

    slow = 0;
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
        cout << slow << " (2) " << fast << "\n";
    }

    cout << "Duplicate is : " << slow << endl;
}

void merge_wo_es_Main_Func(int *arr0, int *arr1, int n0, int n1)
{ // 13

    /* 
        !if sorted arrays is not given 
            ?sort(arr0, arr0+n0);
            ?sort(arr1, arr1+n1);
    */
    int elemX = 0;
    for (int i = n0 - 1; i >= 0; i--)
    {
        if (arr0[i] > arr1[elemX] && elemX < n1)
        {
            //*swap
            arr0[i] = arr0[i] + arr1[elemX];
            arr1[elemX] = arr0[i] - arr1[elemX];
            arr0[i] = arr0[i] - arr1[elemX];
            elemX++;
        }
        else
        {
            break;
        }
    }
    //* Sort after swaping !
    sort(arr0, arr0 + n0);
    sort(arr1, arr1 + n1);
}

void merge_Intervals_Main_Func(vector<vector<int>> interval)
{ // 14
    int n = interval.size();

    // * SORT THE VECTOR SUCH THAT INTERVAL[i][0]  WILL BE IN DECREASING ORDER &
    //*    INTERVAL[i][1] WILL BE IN INCREASING ORDER
    sort(interval.begin(), interval.end(), [&](const vector<int> &a, vector<int> &b)
         {
             if (a[0] != b[0])
             {
                 return a[0] < b[0];
             }
             else
             {
                 return a[1] > b[1];
             }
             /*
        ! example,        [ [1,2],[3,6],[1,7] ] 
        ? after sort,    [ [1,7],[1,2],[3,6] ]
    */
         });

    // *after sort
    cout << "Interval after sort Sort : "
         << "\n";
    print_2DArray(interval);

    int start = interval[0][0];
    int end = interval[0][1];

    vector<vector<int>> ans;

    for (int i = 1; i < n; i++)
    {
        if (interval[i][0] > end)
        {
            ans.push_back({start, end});
            start = interval[i][0];
            end = interval[i][1];
        }
        else if (interval[i][1] > end)
        {
            end = interval[i][1];
        }
    }
    ans.push_back({start, end});

    cout << "\n";
    cout << "Merged intervals : "
         << "\n";
    print_2DArray(ans);
}

void next_Permutation_Main_Func(vector<int> &arr, int n)
{ // 15
    /*
!Algorithm :

*step 1: Linearly traverse given array from the end and 
        *find a number that is less than its adjacent nums[i] < nums[i+1]. 
        *Store the index of smaller number in breakPoint variable. 
        *If there is no such element, reverse entire array and return.

*step 2: Linearly traverse from the end and 
        *this time find a number larger than nums[breakPoint]. 
        *Let's call it nums[i].

*step 3: Swap nums[i] and nums[breakPoint] / i.

*step 4: Reverse the array from index breakPoint + 1 to nums.size().
*/

    int i, j;

    for (i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
            break;
    }
    if (i < 0)
    {
        reverse(arr.begin(), arr.end());
        return;
    }
    for (j = n - 1; j > i; j--)
    {
        if (arr[j] > arr[i])
            break;
    }
    swap(arr[i], arr[j]);
    reverse(arr.begin() + i + 1, arr.end());
}

void count_Inversion_Main_Func1(int *arr, int n)
{ // 16.1
    //!Traverse Approch
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;
    cout << "count_Inversion : " << inv_count << "\n";
}

int merge_INV(int *arr, int *temp, int left, int mid, int right)
{ // 16.2.1
    int _left, _right, _tempArrayIndex;
    int inv_cnt = 0;

    _left = left;           //? _left is index for left subarray
    _right = mid;           //? _right is index for right subarray
    _tempArrayIndex = left; //? _tempArrayIndex is index for resultant merged subarray

    while ((_left <= mid - 1) && (_right <= right))
    {
        if (arr[_left] < arr[_right])
            temp[_tempArrayIndex++] = arr[_left++];
        else
        {
            temp[_tempArrayIndex++] = arr[_right++];
            /*
    In merge process, let _left is used for indexing left sub-array and 
    j for right sub-array. At any step in merge(), 
    if a[_left] is greater than a[_right], then there are (mid – _left) inversions. 
    because left and right subarrays are sorted, 
    so all the remaining elements in left-subarray 
    (a[_left+1], a[_left+2] … a[mid]) will be greater than a[_right]
        */
            inv_cnt += (mid - _left);
        }
    }

    while (_left <= mid - 1)
        temp[_tempArrayIndex++] = arr[_left++];
    while (_right <= right)
        temp[_tempArrayIndex++] = arr[_right++];
    for (int i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_cnt;
}

int count_Inversion_Main_Func2(int *arr, int *temp, int left, int right)
{ // 16.2.0
    //! MergeSort Approch
    int mid;
    int inv_cnt = 0;
    if (right > left)
    {
        mid = left + (right - left) / 2;

        inv_cnt += count_Inversion_Main_Func2(arr, temp, left, mid);
        inv_cnt += count_Inversion_Main_Func2(arr, temp, mid + 1, right);

        inv_cnt += merge_INV(arr, temp, left, mid + 1, right);
    }
    return inv_cnt;
}

void best_Time_to_Buy_N_Sell_Stock_Main_Func1(int *prices, int n)
{ // 17.1
    // ! least_Most
    int leastPrice = INT_MAX;
    int maxPrice = 0;
    int leastMaxPrice = 0;
    for (int i = 0; i < n; i++)
    {
        if (prices[i] < leastPrice)
            leastPrice = prices[i];
        leastMaxPrice = prices[i] - leastPrice;
        if (leastMaxPrice > maxPrice)
            maxPrice = leastMaxPrice;
    }
    cout << "maximum profit : " << maxPrice << "\n";
}
void best_Time_to_Buy_N_Sell_Stock_Main_Func2(int *prices, int n)
{ // 17.2
    int maxPrice = 0;
    int currPrice = prices[0];
    for (int i = 1; i < n; i++)
    {
        currPrice = min(prices[i], currPrice);
        maxPrice = max(maxPrice, (prices[i] - currPrice));
    }
    cout << "maximum profit : " << maxPrice << "\n";
}

void common_Elements_Main_Func(vector<int> arr0, vector<int> arr1, vector<int> arr2)
{ // 19
    int i = 0, j = 0, k = 0;
    vector<int> ans;
    int N = arr0.size();
    int M = arr1.size();
    int O = arr2.size();

    while (i < N && j < M && k < O)
    {
        if (arr0[i] == arr1[j] && arr1[j] == arr2[k])
        {
            ans.push_back(arr0[i]);
            // ! given sorted arrays if any duplicate value find skip it
            while (arr0[i] == arr0[i + 1])
                i++;
            while (arr1[j] == arr1[j + 1])
                j++;
            while (arr2[k] == arr2[k + 1])
                k++;
            i++;
            j++;
            k++;
        }
        else if (arr0[i] <= arr1[j] && arr0[i] <= arr2[k])
        {
            i++;
        }
        else if (arr1[j] <= arr0[i] && arr1[j] <= arr2[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    print_VArray(ans, ans.size());
}

void alt_posNeg_Main_Func1(int *arr, int n)
{ // 20.1
    // ! with O(N) Time
    // ! with O(N) Space

    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
        else
        {
            pos.push_back(arr[i]);
        }
    }
    int f = pos.size();
    int s = neg.size();
    int i = 0;
    int point = 0;
    int point0 = 0;
    while (point < f && point0 < s)
    {
        arr[i] = neg[point0];
        i++;
        point0++;
        arr[i] = pos[point];
        i++;
        point++;
    }
    while (point0 < s)
    {
        arr[i] = neg[point0];
        i++;
        point0++;
    }
    while (point < f)
    {
        arr[i] = pos[point];
        i++;
        point++;
    }
    print_Array(arr, n);
}
void rightrotate(int *arr, int n, int wi, int i)
{ // 20.2.1
    char index = arr[i];
    for (int j = i; j > wi; j--)
        arr[j] = arr[j - 1];
    arr[wi] = index;
}
void alt_posNeg_Main_Func2(int *arr, int n)
{ // 20.2
    int wrongIndex = -1;
    for (int index = 0; index < n; index++)
    {

        if (wrongIndex >= 0)
        {
            if (((arr[index] >= 0) && (arr[wrongIndex] < 0)) || ((arr[index] < 0) && (arr[wrongIndex] >= 0)))
            {
                rightrotate(arr, n, wrongIndex, index);
                if (index - wrongIndex >= 2)
                {
                    wrongIndex = wrongIndex + 2;
                }
                else
                {
                    wrongIndex = -1;
                }
            }
        }
        if (wrongIndex == -1)
        {
            if (((arr[index] >= 0) && (!(index & 0x01))) || ((arr[index] < 0) && (index & 0x01)))
            {
                wrongIndex = index;
            }
        }
    }
    print_Array(arr, n);
}
/* 
! |----------------------------- SUB_main_Func end -----------------------------|
*/
/*
! |----------------------------- SUB_main start -----------------------------| 
*/

void alt_posNeg_Main()
{ // 20
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);
    // output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}
    cout << "\n";
    // alt_posNeg_Main_Func1(arr, n);
    alt_posNeg_Main_Func2(arr, n);
    cout << "\n";
}

void common_Elements_Main()
{ // 19
    vector<int> arr0{1, 5, 10, 20, 40, 80};
    vector<int> arr1{6, 7, 20, 80, 100};
    vector<int> arr2{3, 4, 15, 20, 30, 70, 80, 120};
    cout << "\n";
    common_Elements_Main_Func(arr0, arr1, arr2);
    cout << "\n";
}

void best_Time_to_Buy_N_Sell_Stock_Main()
{ // 17
    /* 
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation:Buy on day 2 (price = 1) and 
            sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed 
because you must buy before you sell.
    */
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = 6;
    // cout << "\n";
    // best_Time_to_Buy_N_Sell_Stock_Main_Func1(arr,n);
    cout << "\n";
    best_Time_to_Buy_N_Sell_Stock_Main_Func2(arr, n);
    cout << "\n";
}

void count_Inversion_Main()
{ // 16
    int arr[] = {1, 20, 6, 4, 5};
    int n = 5;
    cout << "\n";
    // count_Inversion_Main_Func1(arr,n);

    int temp[n];

    auto start = high_resolution_clock::now();
    int invCount = count_Inversion_Main_Func2(arr, temp, 0, n - 1);
    print_Array(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    cout << "Inversion Count : " << invCount << "\n";
    cout << "\n";
}

void next_Permutation_Main()
{ // 15
    vector<int> arr = {3, 2, 1};
    int n = 3;

    cout << endl;
    next_Permutation_Main_Func(arr, n);
    print_VArray(arr, n);
    cout << endl;
}

void merge_Intervals_Main()
{ // 14
    vector<vector<int>> interval = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    //*OUTPUT : [[1,6],[8,10],[15,18]]
    cout << endl;
    merge_Intervals_Main_Func(interval);
    cout << endl;
}

void merge_wo_es_Main()
{ // 13
    int arr0[] = {1, 3, 5, 7};
    int arr1[] = {0, 2, 6, 8, 9};
    int n0 = 4, n1 = 5;
    cout << "\n";
    merge_wo_es_Main_Func(arr0, arr1, n0, n1);
    print_Array(arr0, n0);
    print_Array(arr1, n1);
    cout << "\n";
}

void duplicate_In_Array_Main()
{ // 12
    vector<int> arr = {1, 3, 4, 2, 2};
    int n = 5;

    cout << endl;
    // duplicate_In_Array_Main_Func1(arr,n);
    duplicate_In_Array_Main_Func2(arr, n);
    cout << endl;
}

void singleNumber_Main()
{ //MISC 1
    int arr[] = {9, 8, 8, 5, 5};
    int n = 5;

    cout << endl;
    singleNumber_Main_Func(arr, n);
    cout << endl;
}

void findContiSubArr_Main()
{ // 9
    // *KADANE'S Algo
    int arr[] = {1, 2, 3, -2, 5};
    int n = 5;

    cout << endl;
    findContiSubArr_Main_Func(arr, n);
    cout << endl;
}

void cyclically_rotate_Main()
{ // 8
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << endl;
    cyclically_rotate_Main_Func(arr, n);
    print_Array(arr, n);
    cout << endl;
}

void uniIntersec_Main()
{ // 7
    int arr0[] = {1, 2, 3, 4, 5};
    int arr1[] = {1, 3, 5};

    int n0 = 5;
    int n1 = 3;
    cout << endl;
    uniIntersec_Main_Func(arr0, arr1, n0, n1);
    cout << endl;
}

void moveNegative_Main()
{ // 6
    int arr[] = {-2, 26, -6, 63, -59, 25};
    int n = 6;
    cout << endl;
    moveNegative_Main_Func1(arr, n);
    print_Array(arr, n);
    cout << endl;
    // moveNegative_Main_Func2(arr, 0, n);
    // print_Array(arr, n);
    // cout << endl;
}

void sort012_Main()
{ // 5
    int arr[] = {2, 1, 0, 0, 2, 1};
    int n = 6;

    cout << endl;
    cout << "Output From 1st function : " << endl;
    sort012_Main_Func1(arr, n);
    print_Array(arr, n);
    cout << endl;

    cout << "Output From 2nd function : " << endl;
    sort012_Main_Func2(arr, n);
    print_Array(arr, n);
    cout << endl;
}

void kthSmall_Main()
{ // 4
    int arr[] = {100, 656, 942, 10, 125, 30};
    int n = 6;
    cout << endl;
    kthSmall_Main_Func(arr, n, 3);
    cout << endl;
}

void minMax_Main()
{ // 3
    int arr[] = {100, 656, 942, 10, 125, 30};
    int n = 6;
    cout << endl;
    minMax_Main_Func(arr, n);
    cout << endl;
}

void reverse_Main()
{ // 2
    int arr[] = {1, 6, 9, 10, 25, 30};
    int n = 6;

    cout << endl;
    cout << "Output From 1st function : " << endl;
    reverse_Func1(arr, n);
    print_Array(arr, n);
    cout << endl;

    cout << "Output From 2nd function :"
         << "\n(Arrays Modifion Happend, reverse to original)" << endl;
    reverse_Func2(arr, n);
    print_Array(arr, n);
    cout << endl;

    cout << "Output From 3rd function : " << endl;
    reverse_Func3(arr, 0, n - 1);
    print_Array(arr, n);
    cout << endl;
}

void swapTwoNum_Main()
{ // 1
    int a = 10;
    int b = 20;
    swapTwoNum_Func(&a, &b);
    cout << endl;
    cout << "a : " << a << " b : " << b;
    cout << endl;
}

/* 
! |----------------------------- SUB_main end -----------------------------|
*/

int main()
{ // main body

    // ! : total number of Arrays question - 15 / 36

    /*
     *sub-main functions
     */

    /*
    *1. SWAP TWO NUMBER WITHOUT USING 3RD VARIABLE
    */
    // swapTwoNum_Main();

    /*
    *2. reverse the arrays (3M)
    */
    // reverse_Main();

    /*
    *3. Maximum and minimum of an array using minimum number of comparisons 
    */
    // minMax_Main();

    /* 
    *4. Find kth smallest element in array 
    */
    // kthSmall_Main();

    /*
    *5. Sort 0, 1, 2 (2M) 
    */
    // sort012_Main();

    /* 
    *6. move all negative to one side of array (2M) 
    */
    // moveNegative_Main();

    /* 
    *7. find(count) intersection of 2 sorted array 
    */
    // uniIntersec_Main();

    /* 
    *8. write program to cyclically rotate array by one 
    */
    // cyclically_rotate_Main();

    /*
    *9. Find the contiguous sub-array (kadane's algo)
    */
    // findContiSubArr_Main();

    /* 
    *MISC 1. Find Single Number
    */
    // singleNumber_Main();

    /*
    * 10. Minimize the Heights II (Minimize the Maximum difference between height) 
    */
    //!Greedy Topic
    // TODO : minimize_Heights_Main();

    /*
    * 11. Minimum number of jumps
    */
    //! Dynamic Programming Topic
    // TODO : minimum_Number_Of_Jumps_Main();

    /*
    *12. Find Duplicate Number in Array (2M)
    */
    // duplicate_In_Array_Main();

    /*
    *13. Merge Without extra Space (Modifify existing Array)
    */
    // merge_wo_es_Main();

    /*
    *14.Merge Intervals */
    // merge_Intervals_Main();

    /*
    *15. Next Permutation
    */
    // next_Permutation_Main();

    /*
    *16. Count Inversion (2M)
    */
    // count_Inversion_Main();

    /*
    *17. Best Time to Buy and Sell Stock (2M)
    */
    // best_Time_to_Buy_N_Sell_Stock_Main();

    /*
    * 18. Count pairs with given sum
    */
    // ! Heaps
    //  TODO : countPairSum_Main();

    /*
    *19. Common elements
    */
    // common_Elements_Main();

    /*
    *20.Rearrange array in alternating 
    *positive & negative items with O(1) extra space
    */
    alt_posNeg_Main();
}
