#include"reflect.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
char* argv[3] = { "aaa","input_name","非同义突变.txt" };
int argc = 3;
int main() {
	string outlog = argv[1];
	outlog.erase(outlog.find('.'));
	outlog += ".log";
	ofstream log(outlog);
	if (argc != 3) {
		log << "输入参数数量有误，程序退出。" << endl;
		cout << "输入参数数量有误，程序退出。" << endl;
		exit(EXIT_FAILURE);
	}
	ifstream inlib(argv[1]);
	if (inlib.is_open()) {
		log << "文件" << argv[1] << "打开失败，程序退出";
		cout << "文件" << argv[1] << "打开失败，程序退出";
		exit(EXIT_FAILURE);
	}
	ifstream in(argv[2]);
	if (in.is_open()) {
		log << "文件" << argv[2] << "打开失败，程序退出";
		cout << "文件" << argv[2] << "打开失败，程序退出";
		exit(EXIT_FAILURE);
	}
	vector<pro> list_pro;
	in >> list_pro;
	ProIndexMap table;
	fill_hash(list_pro, table);//
}
