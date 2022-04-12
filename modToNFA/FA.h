#pragma once
#include"FANode.h"
#include<set>
#include<vector>
#include<map>
#include<iostream>
class FA {
private:
	/*
		��̬��
		��̬��
		״̬��
		NFA״̬ת��
		DFA״̬ת��
		NFA��ӦDFA�Ľ��
		����ʽ
	*/
	
	/// <summary>
	/// ��ʼ״̬��
	/// </summary>
	std::set<FANode> startSet;
	/// <summary>
	/// ��ֹ״̬��
	/// </summary>
	std::set<FANode> endSet;
	/// <summary>
	/// ״̬������������״̬��
	/// </summary>
	std::set<FANode> states;
	/// <summary>
	/// NFA��״̬ת��
	/// һ��״̬����һ���ַ�ת�Ƶ����״̬��״̬����
	/// </summary>
	std::map<FANode, std::map<char, std::set<FANode>>> transNFA;
	std::map<FANode, std::map<char, FANode>> transDFA;
	/// <summary>
	/// ������ʽ
	/// </summary>
	std::string stringMod;
	void modifyToDFA();
	void minimizeDFA();
	/// <summary>
	/// NFA�����Ŀ
	/// </summary>
	int nodeCount = 0;
public:
	FA(std::string stringMod) {
		this->stringMod = stringMod;
		//�����Զ��� ȷ���� ��С��
		//�ֱ��Ӧ���� 1��2 ��3
	}
	/// <summary>
	/// ���NFA��״̬ת�ƣ�ͼ�ϵıߣ�
	/// </summary>
	void printEdge() {
		for (const auto& from : transNFA) {
			for (const auto& e : from.second) {
				std::cout << "from " << from.first.getID() << ' ';
				std::cout << "through (" << e.first << ") to ";
				for (const auto& to : e.second) {
					std::cout << to.getID()<<' ';
				}
				std::cout << std::endl;
			}
		}
	}
	/// <summary>
	/// ����NFA
	/// </summary>
	/// <returns>NFA�������յ�</returns>
	std::pair<FANode, FANode> creatNFA();
	//�����Ƿ�����ַ��� ����4
	bool check(std::string in);
	/// <summary>
	/// ���������ڵ�NFA
	/// </summary>
	/// <param name="l">����ʽ��ʼɨ���λ��</param>
	/// <returns>������NFA�������յ㣨���������Ż�����ʽɨ���귵�أ�</returns>
	std::pair<FANode, FANode> creatNFA(int& l);
};