#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    string line;
    vector<int> arr;

    cout << "������ �Է��ϼ���\:" << endl;
    getline(cin, line);

    istringstream iss(line);
    int num;
    while (iss >> num) {
        arr.push_back(num);
    }

    if (!arr.empty()) {
        cout << "�ִ���: " << getMax(arr) << endl;
    }
    else {
        cout << "�Էµ� ���ڰ� �����ϴ�." << endl;
    }

    return 0;
}
