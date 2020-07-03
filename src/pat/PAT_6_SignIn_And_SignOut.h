#pragma once
#include <iostream>
#include <cstring>
/**
 * 主要实现一个时间比对函数就行了，将日期字符串分解为三个部分，分别进行比对。
 * 然后对输入的数据进行比较，找出startTime的最小值和endTime的最大值，时间复杂度为O(N)
 */
namespace PAT_6_SignIn_And_SignOut{
	using namespace std;
	constexpr int HOUR = 0, MINUTE = 1, SECOND = 2;
	constexpr int ID_LEN = 15,TIME_LEN=8;

	int temp1, temp2,M;
	
	//compare two time strings
	//return 1,0,-1 represent great,equal and less respectively
	int compareTime(char* str1, char* str2);
	//extract certain part from time string
	int extract(char* str, int type);

	int main() {
		cin >> M;
		char unlockId[ID_LEN+1], startTime[TIME_LEN+1],
		     lockId[ID_LEN + 1], endTime[TIME_LEN + 1];
        char id[ID_LEN+1], st[TIME_LEN+1], et[TIME_LEN+1];
		if (M>=1) {
			cin >> unlockId >> startTime >> endTime;
			strncpy(lockId, unlockId, ID_LEN + 1);
		}

		for (int i = 1;i < M; i++)
		{
			cin >> id >> st >> et;
			if (compareTime(st,startTime) < 0) {
                strncpy(unlockId, id, ID_LEN + 1);
                strncpy(startTime, st, TIME_LEN + 1);
			}
			if (compareTime(et,endTime) > 0) {
                strncpy(lockId, id, ID_LEN + 1);
                strncpy(endTime, et, TIME_LEN + 1);
			}
		}

		cout << unlockId << " " << lockId<<endl;
		return 0;
	}

	//compare time,return 1,0,-1,fromat:HH:MM:SS
	int compareTime(char* str1, char* str2) {
		int t1 = 0;
		int t2 = 0;
		for (int i = 0; i < 3; i++)
		{
			t1 = extract(str1, i);
			t2 = extract(str2, i);
			if (t1 > t2) {
				return 1;
			}
			else if(t1 < t2) {
				return -1;
			}
		}
		return 0;
	}

	//extract
	int extract(char* str, int type) {
		if (type == HOUR) {
			return (str[0] - 48) * 10 + (str[1] - 48);
		}
		if (type == MINUTE) {
			return (str[3] - 48) * 10 + (str[4] - 48);
		}
		if (type == SECOND) {
			return (str[6] - 48) * 10 + (str[7] - 48);
		}
		return -1;
	}
	
}