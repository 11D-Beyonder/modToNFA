#pragma once
#include"FANode.h"
#include<set>
#include<vector>
#include<map>
#include<iostream>
class FA {
private:
	/*
		初态集
		终态集
		状态集
		NFA状态转移
		DFA状态转移
		NFA对应DFA的结点
		正规式
	*/
	
	/// <summary>
	/// 开始状态集
	/// </summary>
	std::set<FANode> startSet;
	/// <summary>
	/// 终止状态集
	/// </summary>
	std::set<FANode> endSet;
	/// <summary>
	/// 状态集（包含所有状态）
	/// </summary>
	std::set<FANode> states;
	/// <summary>
	/// NFA的状态转移
	/// 一个状态经过一个字符转移到多个状态（状态集）
	/// </summary>
	std::map<FANode, std::map<char, std::set<FANode>>> transNFA;
	std::map<FANode, std::map<char, FANode>> transDFA;
	/// <summary>
	/// 正规表达式
	/// </summary>
	std::string stringMod;
	void modifyToDFA();
	void minimizeDFA();
	/// <summary>
	/// NFA结点数目
	/// </summary>
	int nodeCount = 0;
public:
	FA(std::string stringMod) {
		this->stringMod = stringMod;
		//创建自动机 确定化 最小化
		//分别对应任务 1，2 ，3
	}
	/// <summary>
	/// 输出NFA的状态转移（图上的边）
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
	/// 创建NFA
	/// </summary>
	/// <returns>NFA的起点和终点</returns>
	std::pair<FANode, FANode> creatNFA();
	//检验是否接受字符串 任务4
	bool check(std::string in);
	/// <summary>
	/// 创建区间内的NFA
	/// </summary>
	/// <param name="l">正规式开始扫描的位置</param>
	/// <returns>区间内NFA的起点和终点（遇到右括号或正规式扫描完返回）</returns>
	std::pair<FANode, FANode> creatNFA(int& l);
};