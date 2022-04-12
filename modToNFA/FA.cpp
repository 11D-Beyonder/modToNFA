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
	//�������
	FANode st = p;
	//�����յ�
	FANode ed(nodeCount++);
	states.emplace(st);
	states.emplace(ed);
	for (int i = l; i < stringMod.size(); i++) {
		char c = stringMod[i];
		if (stringMod[i] == '(') {
			//������һ��ݹ� �õ�()�ڵ��Զ����������յ�
			l = i + 1;
			auto StEd = creatNFA(l);
			i = l;
			transNFA[p][' '].insert(StEd.first);
			p = StEd.second;
		} else if(stringMod[i]==')'){
			//������һ��
			l = i+1;
			transNFA[p][' '].insert(ed);
			return std::make_pair(st, ed);
		} else if (isalpha(stringMod[i])||isdigit(stringMod[i])) {
			FANode newNode(nodeCount++);
			states.emplace(newNode);
			if (i + 1 < stringMod.size() && stringMod[i + 1] == '+') {
				//���հ�
				transNFA[newNode][' '].insert(p);
				transNFA[p][c].insert(newNode);
				p = newNode;
			} else if (i + 1 <stringMod.size() && stringMod[i + 1] == '*') {
				//һ��ָ��ͨ�� c ָ��newNode
				//�������c��Ϊ��*Ҳ����û��
				//�����ڸ�һ��newNodenew���ÿմ�ָ����
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
