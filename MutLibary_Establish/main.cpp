#include"reflect.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
char* argv[3] = { "aaa","input_name","��ͬ��ͻ��.txt" };
int argc = 3;
int main() {
	string outlog = argv[1];
	outlog.erase(outlog.find('.'));
	outlog += ".log";
	ofstream log(outlog);
	if (argc != 3) {
		log << "��������������󣬳����˳���" << endl;
		cout << "��������������󣬳����˳���" << endl;
		exit(EXIT_FAILURE);
	}
	ifstream inlib(argv[1]);
	if (inlib.is_open()) {
		log << "�ļ�" << argv[1] << "��ʧ�ܣ������˳�";
		cout << "�ļ�" << argv[1] << "��ʧ�ܣ������˳�";
		exit(EXIT_FAILURE);
	}
	ifstream in(argv[2]);
	if (in.is_open()) {
		log << "�ļ�" << argv[2] << "��ʧ�ܣ������˳�";
		cout << "�ļ�" << argv[2] << "��ʧ�ܣ������˳�";
		exit(EXIT_FAILURE);
	}
	vector<pro> list_pro;
	in >> list_pro;
	ProIndexMap table;
	fill_hash(list_pro, table);//
}
