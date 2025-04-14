#pragma once
#include <stdio.h>
#include <vector>

#define MAX_DEGREE 101  // ���׽��� ó�� ������ �ִ� ���� + 1

class SparsePoly {
    int numTerms;                        // ���׽� ���� ����
    std::vector<int> exponents;         // �� ���� ���� ���� ����
    std::vector<float> coefficients;    // �� ���� ��� ���� ����

public:
    SparsePoly() { numTerms = 0; }

    // ���׽� �Է� �Լ�
    void read() {
        printf("���� ������ �Է��ϼ���: ");
        scanf_s("%d", &numTerms);
        for (int i = 0; i < numTerms; ++i) {
            float coeff;
            int exp;
            printf("%d��° ���� ����� ������ �Է��ϼ��� (��:��� ����): ", i + 1);
            scanf_s("%f %d", &coeff, &exp);
            coefficients.push_back(coeff);
            exponents.push_back(exp);
        }
    }

    // ���׽� ��� �Լ�
    void display(const char* str) {
        printf("%s", str);
        for (int i = 0; i < numTerms; ++i) {
            printf("%.1fx^%d", coefficients[i], exponents[i]);
            if (i != numTerms - 1) printf(" + ");
        }
        printf("\n");
    }

    // ���׽� ���� �Լ�
    void add(SparsePoly a, SparsePoly b) {
        int i = 0, j = 0;
        while (i < a.numTerms && j < b.numTerms) {
            if (a.exponents[i] == b.exponents[j]) {
                // ������ ���� ���
                float sumCoeff = a.coefficients[i] + b.coefficients[j];
                if (sumCoeff != 0) {
                    exponents.push_back(a.exponents[i]);
                    coefficients.push_back(sumCoeff);
                }
                ++i; ++j;
            }
            else if (a.exponents[i] > b.exponents[j]) {
                // a�� ���� ������ ū ���
                exponents.push_back(a.exponents[i]);
                coefficients.push_back(a.coefficients[i]);
                ++i;
            }
            else {
                // b�� ���� ������ ū ���
                exponents.push_back(b.exponents[j]);
                coefficients.push_back(b.coefficients[j]);
                ++j;
            }
        }

        // ���� �׵� �߰�
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

