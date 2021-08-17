void merge(int arr[], int l, int m, int r)
{
    // Your code here
    int subone = m - l + 1;
    int subtwo = r - m;
    int left[subone];
    int right[subtwo];
    for (int i = 0; i < subone; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < subtwo; j++)
        right[j] = arr[m + j + 1];
    int idx_one = 0;
    int idx_two = 0;
    int idx = l;
    while (idx_one < subone && idx_two < subtwo)
    {
        if (left[idx_one] < right[idx_two])
        {
            arr[idx] = left[idx_one];
            idx_one++;
        }
        else
        {
            arr[idx] = right[idx_two];
            idx_two++;
        }
        idx++;
    }
    while (idx_one < subone)
    {
        arr[idx++] = left[idx_one++];
    }
    while (idx_one < subtwo)
    {
        arr[idx++] = right[idx_two++];
    }
}
void mergeSort(int arr[], int l, int r)
{
    //code here
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}