#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<unordered_map>
using namespace std;
const int MAX = 10;
typedef unordered_map<string, vector<int>> ProIndexMap;
struct pro {
	std::string ensp="";
	char origaa;
	char mutataa;
	int pos;
	std::string hseq="";
};
istream& operator>>(istream& is, vector<pro>& list);
bool sortbyensp(pro& a, pro& b);
void fillhseq(istream& is,vector<pro>& list);
void fill_hash(const vector<pro>& list, ProIndexMap& table);