#include <iostream>
#include <vector>
using namespace std;

 //합계를 구하는 함수
int sum(vector<int> num) {
    int sumVar=0;
    for (int i = 0; i < num.size(); i++) {
        sumVar += num[i];
    }
    return sumVar;
}

//평균을 구하는 함수
float avg(vector<int> num) {
    float aveVar = sum(num) / (float)num.size();
    return aveVar;
}

//배열의 원소를 출력하는 함수
void printArr(vector <int> num) {
    cout << "현재 배열은 : ";
    for (int i = 0; i < num.size(); i++) {
        if (i == num.size() - 1) {
            cout << num[i] <<" 입니다.";
        }
        else { cout << num[i] << ", "; }
    }
}

//오름차순 정렬 알고리즘(퀵정렬)
void quickSort1(vector<int>& arr, int start, int end) {
    if (start >= end) return;
    int pivot = start;
    int i = start+1;
    int j = end;

    while (i <= j) {

        while (i <= end && arr[i] <= arr[pivot])
            i++;

        while (j > start && arr[j] >= arr[pivot])
            j--;

        if (i > j)
        {
            int temp = arr[j];
            arr[j] = arr[pivot];    
            arr[pivot] = temp;      
        }
        else {
            int temp = arr[j];
            arr[j] = arr[i];    
            arr[i] = temp;      
        }

        // 재귀 호출
        quickSort1(arr, start, j - 1);
        quickSort1(arr, j + 1, end);
    }
}


//내림차순 정렬 알고리즘
void quickSort2(vector<int>& arr, int start, int end) {
    if (start >= end) return;
    int pivot = start;
    int i = start + 1;
    int j = end;

    while (i <= j) {

        while (i <= end && arr[i] >= arr[pivot])
            i++;

        while (j > start && arr[j] <= arr[pivot])
            j--;

        if (i > j)
        {
            int temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }
        else {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }

        quickSort2(arr, start, j - 1);
        quickSort2(arr, j + 1, end);
    }
}

int main()
{
    std::cout << "Hello World!\n";

    int a, b, c, d, e, f;
    cout << "5개의 숫자를 입력하세요 (숫자 + Enter)\nnum1 : ";
    cin >> a;
    cout << "num2 : ";
    cin >> b;
    cout << "num3 : ";
    cin >> c;
    cout << "num4 : ";
    cin >> d;
    cout << "num5 : ";
    cin >> e;

    vector<int> arr = {a, b, c, d, e }; 
    cout << "숫자들의 합계 : " << sum(arr) << endl;
    cout << "숫자들의 평균 : " << avg(arr) << endl;
    //현재 배열 출력
    printArr(arr);
    cout << "\n오름차순 정렬 : 1\n내림차순 정렬 : 2\n입력 : ";
    cin >> f;
    if (f == 1) {
        quickSort1(arr,0,arr.size()-1);
        printArr(arr);
    }
    else if (f == 2) {
        quickSort2(arr, 0, arr.size() -1);
        printArr(arr);
    }
}
