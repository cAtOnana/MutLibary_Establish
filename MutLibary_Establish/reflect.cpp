#include "reflect.h"
#include<algorithm>
#include<unordered_map>
struct str_hash {//自定义hash函数
	size_t operator() (const string& str) const {
		unsigned long _h = 0;
		for (int i = 0; i < str.size(); i++)
			_h = _h * 2 + str[i] - 49;
		return size_t(_h);
	}
};
struct str_compare {
	bool operator()(const string& a1, const string& a2) const {
		return a1 == a2;
	}
};
typedef unordered_map<string, string> NmEnspMap,EnspHseqMap;
istream & operator>>(istream & is, vector<pro>& list)
{
	pro temp;
	string waste;
	getline(is, waste);
	getline(is, waste);
	while (is >> waste) {
		for (int i = 0; i < 12; i++)
			is >> waste;
		is >> temp.ensp;
		is >> temp.origaa;
		is >> temp.mutataa;
		is >> temp.pos;
		getline(is,waste);
		list.push_back(temp);
	}
	return is;
}
bool sortbyensp(const pro& a,const  pro& b) {
	return a.ensp < b.ensp;
}
void fillhseq(istream & is, vector<pro>& list)
{
	EnspHseqMap ehmap;
	string ensp, hseq;
	while (is) {//填表
		while (is.get() != '>'&&is)//找'>'
			continue;
		is >> ensp >> hseq;
		ehmap[ensp] = hseq;
	}
	for (int i = 0; i < list.size(); i++) {
		if (ehmap.find(list[i].ensp) != ehmap.end())
			list[i].hseq = ehmap[list[i].ensp];
	}
}
bool comparestr(const pro& a, const pro& b) {
	return a.ensp < b.ensp;
}
void fill_hash(vector<pro>& list_pro, ProIndexMap & pimap)
{
	sort(list_pro.begin(), list_pro.end(), comparestr);
	string ensp = list_pro[0].ensp;
	vector<int> index;
	for (int i = 0; i < list_pro.size(); i++) {//填表
		index.push_back(i);
		if (i == list_pro.size() - 1) {
			pimap[ensp] = index;
		}
		if (list_pro[i].ensp != list_pro[i + 1].ensp) {
			pimap[ensp] = index;
			ensp = list_pro[i + 1].ensp;
			index.clear();
		}
	}
}//
