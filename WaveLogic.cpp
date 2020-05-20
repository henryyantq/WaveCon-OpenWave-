#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

void lapse(double duration) {
	time_t start, end;
	start = clock();
	end = clock();
	while(1) {
		if ((end - start) / CLOCKS_PER_SEC >= duration)
			break;
		end = clock();
	}
}

inline double inputFunc_t(double t) {
	return 1;
}

inline double inputFunc_s(double s) {
	return 1;
}

inline double outputFunc_t(double t) {
	return 0;
}

inline double outputFunc_s(double s) {
	return 0;
}

inline double sysFunc_t(double t) {
	return 0;
}

inline double sysFunc_s(double s) {
	return 0;
}

int main () {
	int choice;
	lapse(1);
	cout << "WaveLogic(OpenALSA)" << endl;
	lapse(1);
	cout << "简体中文，版本 0.1b" << endl << endl;
	lapse(1);
	cout << "正在检测（可能需要一些时间，取决于函数复杂度和设备部分性能）..." << endl;
	int label[6] = {0};
	for (double i = -5000; i < 5000; i += 0.01) {
		if (inputFunc_t(i) != 0 && label[0] != 1) {
			cout << endl << "您定义了输入函数：时域连续；";
			label[0] = 1;
		}
		if (inputFunc_s(i) != 0 && label[3] != 1) {
			cout << endl << "您定义了输入函数：频域连续；";
			label[3] = 1;
		}
		if (outputFunc_t(i) != 0 && label[1] != 1) {
			cout << endl << "您定义了输出函数：时域连续；";
			label[1] = 1;
		}
		if (outputFunc_s(i) != 0 && label[4] != 1) {
			cout << endl << "您定义了输出函数：频域连续；";
			label[4] = 1;
		}
		if (sysFunc_t(i) != 0 && label[2] != 1) {
			cout << endl << "您定义了系统函数：时域连续；";
			label[2] = 1;
		}
		if (sysFunc_s(i) != 0 && label[5] != 1) {
			cout << endl << "您定义了系统函数：频域连续；";
			label[5] = 1;
		}
	}
	char str[3][30] = {"输入函数", "输出函数", "系统函数"};
	int definedFunc = 0;
	for(int i = 0; i < 6; i++)
		definedFunc += label[i];
	if (definedFunc >= 3) {
		cout << endl << endl << "输入、输出和系统函数只能预先定义最多2项。\n请按Enter键退出重新修改...";
		cin.get();
		exit(0);
	}
	for(int i = 0; i < 3; i++)
		if (label[i] == label[i + 3]) {
			cout << endl << endl << "您重复定义了" << str[i] << "的时域和频域。这是不被允许的。\n请按Enter键退出重新修改...";
			cin.get();
			exit(0);
		}
	if (definedFunc == 0) {
		cout << endl << endl << "您没有定义任何连续函数信号。是否直接进入菜单？\n1. 好的\n2. 退出以进行定义\n--> ";
		cin >> choice;
		if (choice == 2) exit(0);
	}
	else if (definedFunc == 1) {
		cout << endl << endl << "您定义了单个环节的函数信号。是否直接进入菜单？\n1. 好的\n2. 退出以添加另一个环节的函数信号定义\n--> ";
		cin >> choice;
		if (choice == 2) exit(0);
	}
}
