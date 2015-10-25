#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n = 0;
    int sum = 0;
    int i = 0;
    cin >> n;
    int arr[n];
    for(i =0; i<n;i++){
        cin >> arr[i];
    }
    
    for(i = 0; i<n;i++){
        sum = sum +arr[i];
    }
    cout << sum << endl;
    return 0;
}
