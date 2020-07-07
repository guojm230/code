#pragma once
#include <iostream>
#include <cstring>

/**
 * 输入的值比较大，所以用字符串来接收输入的字符
 * 但最终运算的结果并不大，直接相加然后分解数位输出对应的数字便可，
 * 为了最后输出方便，自己实现了一个加法运算，并用数组保存，便于输出。
 */
namespace PAT_5_Spell_It_Right {
	using namespace std;
	string words[]{"zero","one","two","three","four","five","six","seven","eight","nine"};
	char* str = new char[101];
	int len,nlen = 1,temp;
	int num[4]{ 0,0,0,0 };

	void sum(int position, int number);

	int main() {
		std::iostream::sync_with_stdio(false);
		cin >> str;
		len = strlen(str);
		for (int i = 0; i < len;i++) {
			sum(0,str[i] - 48);
		}

		if (num[0] == 0&&nlen==1) {
			cout << words[0];
			return 0;
		}

		for (temp = nlen-1; temp >0;temp--) {
			cout << words[num[temp]]<<" ";
		}
		cout << words[num[0]] << endl;
		return 0;
	}

	void sum(int position,int number) {
		if ((temp = num[position] + number) >= 10) {
			if (num[position + 1] == 0 && position+1 == nlen) {
				nlen++;
			}
			num[position] = temp - 10;
			sum(position + 1,1);
		}
		else {
			num[position] += number;
		}
	}
}