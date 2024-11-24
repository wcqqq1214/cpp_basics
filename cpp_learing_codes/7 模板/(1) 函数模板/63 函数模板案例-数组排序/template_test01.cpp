#include <iostream>
using namespace std;

//模板-函数模板案例-数组排序


//利用选择排序，对数组进行从大到小的排序
template<typename T>
void mySort(T arr[], int len) {

    for (int i = 0; i < len; i++) {

        int max = i;    //认定最大值的下标
        for (int j = i + 1; j < len; j++) {
            //认定的最大值 比 遍历出的数值 要小，说明 j下标的元素才是真正的最大值
            if (arr[max] < arr[j]) {

                max = j;    //更新最大值下标
            }
        }

        if (i != max) {
            //交换 max 和 i 的元素
            swap(arr[i], arr[max]);
        }
    }
}

//提供打印数组模板
template<typename T>
void printArray(T arr[], int len) {

    for (int i = 0; i < len; i ++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

//int数组测试
void test01() {

    int intArr[] = {2, 4, 1, 3, 5};

    int len = sizeof(intArr) / sizeof(int);

    mySort(intArr, len);

    printArray(intArr, len);
}

//char数组测试
void test02() {

    char charArr[] = "badcfe";

    int len = sizeof(charArr) / sizeof(char);

    mySort(charArr, len);

    printArray(charArr, len);
}

int main() {

    test01();

    test02();

    system("pause");

    return 0;
}