#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define pb push_back
#define int long long
using namespace std;
 
//do elements repeat within a 'k' sized window?

/*

return true if an array consists of two equal elements 
which are not furhter than 'k' distance   
=> return (arr[i] == arr[j] && abs(i-j) < k)

*/


//brute-force

void bruteForce(vector<int> arr, int k) {       //O(n*k)


    if (k==1) {
        cout << "YES" << endl; return;
    }


    int n = arr.size();

    for (int i=0;i<n;i++) {
        for (int j=i+1;abs(i-j)<k && j < n;j++) {

            if (arr[i]==arr[j])
                {
                    cout << "YES" << endl;
                    return;
                }

        }
    }

    cout << "NO" << endl;


}


//fixed-size sliding window

void slidingWindow(vector<int> arr, int k) {

    if (k==1) {
        cout << "YES" << endl; return;
    }

    int n = arr.size();

    unordered_set<int> s;
    int l = 0;

    for (int i=0;i<n;i++) {


        if (s.size() >= k) {
            
            s.erase(arr[l]);
            l++;
        }

        if (s.count(arr[i])) {
            cout << "YES" << endl;
            return;
        }

        s.insert(arr[i]);



    }

    cout << "NO" << endl;

}


//--------------- variable sized sliding window ----------------------

//find the length of the longest subarray with every element equal

void slidingWindow(vector<int> arr) {

    int l = 0;
    int maxi = 1;
    for (int r=0;r<arr.size();r++) {
        if (arr[r] == arr[l]) {
            maxi = max(maxi, r - l + 1);
        }

        else {

            l = r;
        }

    }

    cout << maxi;

}


/*

length of smallest subarray where sum is
greater than or equal to the target

*/

void smSubArray(vector<int> arr, int target) {          //O(n)
    int n = arr.size();
    
    int l = 0, sum = 0;
    int mini = INT_MAX;

    for (int r=0;r<n;r++) {

        sum += arr[r];

        while (sum>=target) {
            mini = min(mini, r-l+1);
            sum -= arr[l];
            l++;
        }

    }

    if (mini==INT_MAX) 
        cout << "NO SUCH LENGTH" << endl;
    

    else
        cout << mini << endl;

}

 
int32_t main() {
    quick;
    vector<int> arr = {1,1,9,5,2,4};
    bruteForce(arr, 2);
    slidingWindow(arr, 2);

 
}