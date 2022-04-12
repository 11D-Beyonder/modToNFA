#include "FA.h"
bool FA::check(std::string in) {
	return false;
}
std::pair<FANode,FANode> FA::creatNFA() {
	int l = 0;
	auto StEd = creatNFA(l);
	startSet.emplace(StEd.first);
	endSet.emplace(StEd.second);
	return StEd;
}
std::pair<FANode, FANode> FA::creatNFA(int& l) {
	FANode p(nodeCount++);
	//设置起点
	FANode st = p;
	//设置终点
	FANode ed(nodeCount++);
	states.emplace(st);
	states.emplace(ed);
	for (int i = l; i < stringMod.size(); i++) {
		char c = stringMod[i];
		if (stringMod[i] == '(') {
			//进入下一层递归 得到()内的自动机的起点和终点
			l = i + 1;
			auto StEd = creatNFA(l);
			i = l;
			transNFA[p][' '].insert(StEd.first);
			p = StEd.second;
		} else if(stringMod[i]==')'){
			//返回上一层
			l = i+1;
			transNFA[p][' '].insert(ed);
			return std::make_pair(st, ed);
		} else if (isalpha(stringMod[i])||isdigit(stringMod[i])) {
			FANode newNode(nodeCount++);
			states.emplace(newNode);
			if (i + 1 < stringMod.size() && stringMod[i + 1] == '+') {
				//正闭包
				transNFA[newNode][' '].insert(p);
				transNFA[p][c].insert(newNode);
				p = newNode;
			} else if (i + 1 <stringMod.size() && stringMod[i + 1] == '*') {
				//一个指针通过 c 指向newNode
				//但是这个c因为是*也可以没有
				//所以在搞一个newNodenew，用空串指向它
				transNFA[newNode][' '].insert(p);
				FANode newNodeNew(nodeCount++);
				transNFA[p][' '].insert(newNodeNew);
				transNFA[newNode][' '].insert(newNodeNew);
				transNFA[p][c].insert(newNode);
				p = newNodeNew;
				states.emplace(newNodeNew);
			} else {
				transNFA[p][c].insert(newNode);
				p = newNode;
			}
		} else if(c=='|'){
			transNFA[p][' '].insert(ed);
			p = st;
		}
	}
	transNFA[p][' '].insert(ed);
	return std::make_pair(st, ed);
}
void FA::modifyToDFA() {

}
void FA::minimizeDFA() {

}
