#include <iostream>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

inline double func(double t) {
	return sin(t) * cos(2 * t) * log(t); 
}

void lapse(double secs) {
	time_t start, end;
	start = clock();
	while (1) {
		end = clock();
		if ((end - start) / CLOCKS_PER_SEC >= secs)
			break;
	}
}

int main() {
	int choice;
	double f;
	lapse(1);
	cout << endl << "--WaveCon--" << endl << "版本 0.1b";
	lapse(1);
	cout << endl << endl << "是否开始转换时域波形为复频域幅频特性波形？\nEnter键继续...";
	cin.get();
option1:
	cout << "\n第一步 - 请设定采样率：";
	cin >> f;
	if (f <= 0) {
		cout << "采样率不得小于或等于0，请重新设置！\n";
		goto option1;
	}
	double epsilon = 1 / f;
	double t0;
option2:
	cout << "\n第二步 - 波形转换模拟器无法得知因果信号的响应终点（信号响应终点），请给出一个大于0的时刻，以秒为单位：";
	cin >> t0;
	if (t0 <= 0) {
		cout << "响应时长不得小于或等于0，请重新设置！\n";
		goto option2;
	}
	int i = t0 / epsilon;
	cout << "\n开始使用方波信号逼近原信号（WaveCon测试版为了便于开发者调试，会输出方波拟合结果）..." << endl;
	lapse(1);
	cout << "准备输出强度序列..." << endl;
	lapse(1);
	double *a = new double[i];
	for (double k = 0; k < i; k++) {
		a[(int)k] = func(k * epsilon);
		cout << "阶跃强度" << k + 1 << " = " << a[(int)k] << endl;
	}
	lapse(1);
	cout << "\n输出方波线性近似信号表达式：x(t)=";
	for (double k = 0; k < i; k++) {
		cout << a[(int)k] << "[u(t-" << k * epsilon << ")-u(t-" << (k + 1) * epsilon << ")]";
		if (k != i - 1)
			cout << '+';
	}
	cout << endl << endl;
	cout << "准备转换，即将输出复频域工程学近似表达式..." << endl << endl;
	lapse(1);
	cout << "X(s)=";
	for (double k = 0; k < i; k++) {
		cout << a[(int)k] << "*e^(-" << k * epsilon << "s)/s*[1-e^(-" << epsilon << "s)]";
		if (k != i - 1)
			cout << '+';
	}
	cin.get();
	cout << "\n\n转换完毕！";
select:
	cout << "\n1、输出相频近似表达式\n2、输出幅频近似表达式\n--> ";
	cin >> choice;
	cout << endl << "令 s=p+jq，此时有：" << endl;
	if (choice == 1) {
		cout << "Ψ(p+jq)=-" << t0 / epsilon << "arccos{[e^(-" << epsilon << "p)-cos(" << epsilon << "q)]/[1+e^(-" << 2 * epsilon << "p)-2e^(-" << epsilon << "p)cos(" << epsilon << "q)]^0.5}";
	}	//相频近似表达式
	else if (choice == 2) {
		cout << "H(p+jq)=";
		for (double k = 0; k < i; k++) {
			cout << a[(int)k] << "e^(-" << k * epsilon << "p)/(p^2+q^2)^0.5*[1+e^(-" << 2 * epsilon << "p)-2e^(-" << epsilon << "p)cos(" << epsilon << "q)]^0.5";
			if (k != i - 1)
				cout << " + ";
		}
	}	//幅频近似表达式
	cout << endl;
	goto select;
}