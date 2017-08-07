#include"reflect.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct fasta {
	string ensp;
	string seq;
};
char* argv[3] = { "aaa","LM3_ensembl.fasta","非同义突变.txt" };
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
	if (!inlib.is_open()) {
		log << "文件" << argv[1] << "打开失败，程序退出";
		cout << "文件" << argv[1] << "打开失败，程序退出";
		exit(EXIT_FAILURE);
	}
	ifstream in(argv[2]);
	if (!in.is_open()) {
		log << "文件" << argv[2] << "打开失败，程序退出";
		cout << "文件" << argv[2] << "打开失败，程序退出";
		exit(EXIT_FAILURE);
	}
	string output = string(argv[1]) + "multiple";
	ofstream out(output);

	vector<pro> list_pro;
	vector<fasta> list_fasta;
	in >> list_pro;
	ProIndexMap table;
	fill_hash(list_pro, table);
	while (inlib) {
		while (inlib.get() != '>'&&inlib)
			continue;
		fasta temp;
		inlib >> temp.ensp >> temp.seq;
		list_fasta.push_back(temp);
	}
	cout << "Done Read-in!" << endl;
	for (int j = 0; j < list_fasta.size();j++){
		out << '>' << list_fasta[j].ensp << endl
			<< list_fasta[j].seq<<endl << endl;//输出原序列
		if (table.find(list_fasta[j].ensp) != table.end()) {
			vector<int> tempindex = table[list_fasta[j].ensp];
			for (int i = 0; i < tempindex.size(); i++) {
				if (list_pro[tempindex[i]].mutataa == list_pro[tempindex[i]].origaa)
					continue;
				string tempseq = list_fasta[j].seq;
				if (tempseq[list_pro[tempindex[i]].pos] == list_pro[tempindex[i]].origaa) {
					tempseq.replace(list_pro[tempindex[i]].pos, 1, 1, list_pro[tempindex[i]].mutataa);
					out << '>' << list_fasta[j].ensp << "_SAP_" << i + 1
						<< tempseq<<endl<<endl;//输出突变序列
				}
				else
					log << "有不匹配的残基：" << list_fasta[j].ensp << endl
					<< list_fasta[j].seq << "第" << list_pro[tempindex[i]].pos + 1 << "位应为" << list_pro[tempindex[i]].origaa << "实际为" << tempseq[list_pro[tempindex[i]].pos]<< endl;
						
			}
		}
	}
}
