#pragma once
#include <iostream>
#include <cstdio>

/**
*����𰸻���˼·��ʹ�ö�ά������д���ָ����ϵ������ָ����ȵ��������ӣ�Ȼ�����������
*�����ʽ�Ŀӣ�
* 1.���ĩβ�����пո�
* 2.�����ϵ��Ϊ0����Ҫ��ȥ�������
* 3.�������Ϊ0��ֻ���0
*�����ӣ�
* 1.�Ƚϸ�������С����ֱ����==��Ҫ���þ������������
*/
class A_Plus_B_For_Polynomials_2 {
public:
	int main() {
		using namespace std;
		//read data from input
		int size1 = 0,size2 = 0, i = 0,j = 0, k = 0;
		double n1[10][2];
		double n2[10][2];
		cin >> size1;
		for (i = 0; i < size1;i++) {
			cin >> n1[i][0];
			cin >> n1[i][1];
		}
		cin >> size2;
		for (i = 0; i < size2; i++) {
			cin >> n2[i][0];
			cin >> n2[i][1];
		}
		//merge array,sum elements that have the same exponent to one element
		double result[20][2];
		for (i = 0; i < size1 ;i++) {
			for (j = 0; j < size2; j++) {
				if (n1[i][0] == n2[j][0]) {
					n1[i][1] += n2[j][1];
					n2[j][0] = -1;
				}
			}
			if (!de(n1[i][1],0)) {
				result[k][0] = n1[i][0];
				result[k][1] = n1[i][1];
				k++;
			}
		}
		for (i = 0; i < size2; i++) {
			if (!de(n2[i][0],-1) && !de(n2[i][1],0)) {
				result[k][0] = n2[i][0];
				result[k][1] = n2[i][1];
				k++;
			}
		}
		//order the result array by exponent and output all elements
		double temp[2]{ 0,0 };
		for (i = k; i > 0;i-- ) {
			for (j = 1; j < k; j++) {
				if (result[j][0] > result[j-1][0]) {
					temp[0] = result[j - 1][0];
					temp[1] = result[j - 1][1];
					result[j - 1][0] = result[j][0];
					result[j - 1][1] = result[j][1];
					result[j][0] = temp[0];
					result[j][1] = temp[1];
				}
			}
		}
		printf("%d", k);
		for (i = 0; i < k;i++) {
			printf(" %.0f ", result[i][0]);
			printf("%.1f", result[i][1]);
		}

		return 0;
	}

	//�ж�����double�Ƿ����
	inline bool de(double b1,double b2) {
		return (b1 - b2) > -0.0000001 && (b1 - b2) < 0.0000001;
	}

	void print(double a[][2],int len) {
		for (int i = 0; i < len; i++) {
			printf("%.1f  %.1f  ", a[i][0], a[i][1]);
		}
	}
};
