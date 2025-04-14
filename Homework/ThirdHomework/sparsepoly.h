#pragma once
#include <stdio.h>
#include <vector>

#define MAX_DEGREE 101  // 다항식의 처리 가능한 최대 차수 + 1

class SparsePoly {
    int numTerms;                        // 다항식 항의 개수
    std::vector<int> exponents;         // 각 항의 차수 저장 벡터
    std::vector<float> coefficients;    // 각 항의 계수 저장 벡터

public:
    SparsePoly() { numTerms = 0; }

    // 다항식 입력 함수
    void read() {
        printf("항의 개수를 입력하세요: ");
        scanf_s("%d", &numTerms);
        for (int i = 0; i < numTerms; ++i) {
            float coeff;
            int exp;
            printf("%d번째 항의 계수와 차수를 입력하세요 (예:계수 차수): ", i + 1);
            scanf_s("%f %d", &coeff, &exp);
            coefficients.push_back(coeff);
            exponents.push_back(exp);
        }
    }

    // 다항식 출력 함수
    void display(const char* str) {
        printf("%s", str);
        for (int i = 0; i < numTerms; ++i) {
            printf("%.1fx^%d", coefficients[i], exponents[i]);
            if (i != numTerms - 1) printf(" + ");
        }
        printf("\n");
    }

    // 다항식 덧셈 함수
    void add(SparsePoly a, SparsePoly b) {
        int i = 0, j = 0;
        while (i < a.numTerms && j < b.numTerms) {
            if (a.exponents[i] == b.exponents[j]) {
                // 차수가 같은 경우
                float sumCoeff = a.coefficients[i] + b.coefficients[j];
                if (sumCoeff != 0) {
                    exponents.push_back(a.exponents[i]);
                    coefficients.push_back(sumCoeff);
                }
                ++i; ++j;
            }
            else if (a.exponents[i] > b.exponents[j]) {
                // a의 항이 차수가 큰 경우
                exponents.push_back(a.exponents[i]);
                coefficients.push_back(a.coefficients[i]);
                ++i;
            }
            else {
                // b의 항이 차수가 큰 경우
                exponents.push_back(b.exponents[j]);
                coefficients.push_back(b.coefficients[j]);
                ++j;
            }
        }

        // 남은 항들 추가
        while (i < a.numTerms) {
            exponents.push_back(a.exponents[i]);
            coefficients.push_back(a.coefficients[i]);
            ++i;
        }

        while (j < b.numTerms) {
            exponents.push_back(b.exponents[j]);
            coefficients.push_back(b.coefficients[j]);
            ++j;
        }

        numTerms = exponents.size();
    }
};

