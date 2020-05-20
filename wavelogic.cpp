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
	cout << "�������ģ��汾 0.1b" << endl << endl;
	lapse(1);
	cout << "���ڼ�⣨������ҪһЩʱ�䣬ȡ���ں������ӶȺ��豸�������ܣ�..." << endl;
	int label[6] = {0};
	for (double i = -5000; i < 5000; i += 0.01) {
		if (inputFunc_t(i) != 0 && label[0] != 1) {
			cout << endl << "�����������뺯����ʱ��������";
			label[0] = 1;
		}
		if (inputFunc_s(i) != 0 && label[3] != 1) {
			cout << endl << "�����������뺯����Ƶ��������";
			label[3] = 1;
		}
		if (outputFunc_t(i) != 0 && label[1] != 1) {
			cout << endl << "�����������������ʱ��������";
			label[1] = 1;
		}
		if (outputFunc_s(i) != 0 && label[4] != 1) {
			cout << endl << "�����������������Ƶ��������";
			label[4] = 1;
		}
		if (sysFunc_t(i) != 0 && label[2] != 1) {
			cout << endl << "��������ϵͳ������ʱ��������";
			label[2] = 1;
		}
		if (sysFunc_s(i) != 0 && label[5] != 1) {
			cout << endl << "��������ϵͳ������Ƶ��������";
			label[5] = 1;
		}
	}
	char str[3][30] = {"���뺯��", "�������", "ϵͳ����"};
	int definedFunc = 0;
	for(int i = 0; i < 6; i++)
		definedFunc += label[i];
	if (definedFunc >= 3) {
		cout << endl << endl << "���롢�����ϵͳ����ֻ��Ԥ�ȶ������2�\n�밴Enter���˳������޸�...";
		cin.get();
		exit(0);
	}
	for(int i = 0; i < 3; i++)
		if (label[i] == label[i + 3]) {
			cout << endl << endl << "���ظ�������" << str[i] << "��ʱ���Ƶ�����ǲ�������ġ�\n�밴Enter���˳������޸�...";
			cin.get();
			exit(0);
		}
	if (definedFunc == 0) {
		cout << endl << endl << "��û�ж����κ����������źš��Ƿ�ֱ�ӽ���˵���\n1. �õ�\n2. �˳��Խ��ж���\n--> ";
		cin >> choice;
		if (choice == 2) exit(0);
	}
	else if (definedFunc == 1) {
		cout << endl << endl << "�������˵������ڵĺ����źš��Ƿ�ֱ�ӽ���˵���\n1. �õ�\n2. �˳��������һ�����ڵĺ����źŶ���\n--> ";
		cin >> choice;
		if (choice == 2) exit(0);
	}
}