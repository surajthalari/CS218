#include <bits/stdc++.h>

using namespace std;

long long merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    long long count = 0;
 
    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            count = count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
 
    return count;
}
 

long long mergeSort(vector<int> &arr, vector<int> &temp, int left, int right)
{
    int mid;
    long long count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        count  = mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid+1, right);
        count += merge(arr, temp, left, mid+1, right);
    }
 
    return count;
}
 
long long solve(vector<int> &cars)
{
    int n = cars.size();
    vector<int> temp(n, 0);
    return mergeSort(cars, temp, 0, n - 1);
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> cars;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        cars.push_back(temp);
    }

    cout << solve(cars) << endl;
    return 0;
}