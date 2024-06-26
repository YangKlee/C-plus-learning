#include <iostream>
#include <climits>
using namespace std;

// Hàm tìm tổng đoạn con lớn nhất chứa phần tử giữa và lưu lại chỉ số
int maxCrossingSum(int arr[], int left, int mid, int right, int &cross_start, int &cross_end) {
    int sum = 0;
    int left_sum = INT_MIN;
    int temp_start = mid;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            cross_start = i;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;
    int temp_end = mid + 1;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
            cross_end = i;
        }
    }

    return left_sum + right_sum;
}

// Hàm tìm tổng đoạn con lớn nhất sử dụng chia để trị và lưu lại chỉ số
int maxSubArraySum(int arr[], int left, int right, int &start, int &end) {
    if (left == right) {
        start = left;
        end = left;
        return arr[left];
    }

    int mid = (left + right) / 2;

    int left_start, left_end;
    int right_start, right_end;
    int cross_start = mid, cross_end = mid + 1;

    int left_sum = maxSubArraySum(arr, left, mid, left_start, left_end);
    int right_sum = maxSubArraySum(arr, mid + 1, right, right_start, right_end);
    int cross_sum = maxCrossingSum(arr, left, mid, right, cross_start, cross_end);

    if (left_sum >= right_sum && left_sum >= cross_sum) {
        start = left_start;
        end = left_end;
        return left_sum;
    } else if (right_sum >= left_sum && right_sum >= cross_sum) {
        start = right_start;
        end = right_end;
        return right_sum;
    } else {
        start = cross_start;
        end = cross_end;
        return cross_sum;
    }
}

int main() {
    int arr[] = {-1 ,5, -3, 6 ,9 ,4, -7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start, end;
    int max_sum = maxSubArraySum(arr, 0, n - 1, start, end);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    cout << "The subarray with the maximum sum is: [";
    for (int i = start; i <= end; i++) {
        cout << arr[i];
        if (i < end) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}
