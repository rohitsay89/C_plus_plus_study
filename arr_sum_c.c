#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n = 0;
    int sum = 0;
    int i = 0;
    scanf("%d", &n);
    int arr[n];
    //int arr[6] = {1,2,3,4,10,11};
    for(i = 0; i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0;i<n;i++){
        sum = sum + arr[i];
    }
    printf("%d",sum);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
