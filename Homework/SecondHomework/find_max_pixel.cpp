#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    // 이미지 파일 읽기 (그레이스케일)
    Mat image = imread("Lenna.png", IMREAD_GRAYSCALE);

    if (image.empty()) {
        cout << "이미지를 불러올 수 없습니다." << endl;
        return -1;
    }

    double minVal, maxVal;
    Point minLoc, maxLoc;

    // 최소/최대 밝기값 계산
    minMaxLoc(image, &minVal, &maxVal, &minLoc, &maxLoc);

    cout << "최대 밝기 값: " << static_cast<int>(maxVal) << endl;

    return 0;
}