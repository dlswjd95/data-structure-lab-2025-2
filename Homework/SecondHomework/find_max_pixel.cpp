#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    // �̹��� ���� �б� (�׷��̽�����)
    Mat image = imread("Lenna.png", IMREAD_GRAYSCALE);

    if (image.empty()) {
        cout << "�̹����� �ҷ��� �� �����ϴ�." << endl;
        return -1;
    }

    double minVal, maxVal;
    Point minLoc, maxLoc;

    // �ּ�/�ִ� ��Ⱚ ���
    minMaxLoc(image, &minVal, &maxVal, &minLoc, &maxLoc);

    cout << "�ִ� ��� ��: " << static_cast<int>(maxVal) << endl;

    return 0;
}