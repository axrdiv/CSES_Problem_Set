#include<iostream>
#include<vector>
using namespace std;
int k, n, tmp;
vector<int> vec;

int partition(vector<int> &arr, int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int randomPartition(vector<int> &arr, int l, int r)
{
    int n = r - l + 1;
    int pivot =  (rand() % 100 + 1) % n;
    swap(arr[l + pivot], arr[r]);
    return partition(arr, l, r);
}


// This function returns k'th smallest
// element in arr[l..r] using
// QuickSort based method. ASSUMPTION:
// ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(vector<int> &arr, int l,
        int r, int k)
{

    // If k is smaller than number
    // of elements in array
    if (k > 0 && k <= r - l + 1)
    {

        // Partition the array around last
        // element and get position of pivot
        // element in sorted array
        int pos = randomPartition(arr, l, r);

        // If position is same as k
        if (pos - l == k - 1)
        {
            return arr[pos];
        }

        // If position is more, recur
        // for left subarray
        if (pos - l > k - 1)
        {
            return kthSmallest(arr, l, pos - 1, k);
        }

        // Else recur for right subarray
        return kthSmallest(arr, pos + 1, r,
                k - pos + l - 1);
    }

    // If k is more than number of
    // elements in array
    return -1;
}

// int partition(int l, int r, vector<int> &vec) {
//     int x = vec[r-1], i = l;
//     for(int j = l; j <= r-2; j++) {
//         if(vec[j] <= x) swap(vec[i++], vec[j]);
//     }
//     swap(vec[i], vec[r-1]);
//     return i;
// }
//
// int randomPartition(int l, int r, vector<int> &vec) {
//     int pivot = rand() % (r - l);
//     swap(vec[l + pivot], vec[r-1]);
//     return partition(l, r, vec);
// }
//
// int findk(int l, int r, int k, vector<int> &vec) {
//     cout << l << " " << r << " " << k << endl;
//     if(k >= 0 && k <= r - l) {
//         int pos = partition(l, r, vec);
//         if(pos - l == k) return vec[pos];
//         if(pos - l > k) return findk(l, pos-1, k, vec);
//         if(pos - l < k) return findk(pos+1, r, k - pos + l - 1, vec);
//     }
//     return -1;
// }

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    // cout << findk(0, n, n/2) << endl;

    // vector<int> subv = vector<int>({4 ,3 ,5});
    // cout << findk(0, 3, 3/2, subv) << endl;
    for(int i = 0; i <= n-k; i++) {
        vector<int> subv(&vec[i], &vec[i+k]);
        cout << kthSmallest(subv, 0, k-1, (k+1)/2) << (i == n-k ? "\n" : " ");
    }

    return 0;
}
