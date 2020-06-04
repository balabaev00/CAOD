#pragma once

#include "pch.h"
# include <iostream>
# include <map>
# include <vector>
# include <string>
# include <queue>

using namespace std;

class BorNode;
typedef map<const char, BorNode *> LinksMap;

class BorNode {
public:
	LinksMap links;
	BorNode *fail;  // ���������� ��������� ��� ������� ������. ������ ��� root ����� NULL.
	BorNode *term; // ��������� ������������ ���������. ���� ������������ - NULL
	int out;

public:
	BorNode(BorNode *fail_node = NULL)
		: fail(fail_node)
		, term(NULL)
		, out(-1)
	{ }

	BorNode* getLink(const char c) const
	{
		LinksMap::const_iterator iter = links.find(c);
		if (iter != links.cend()) {
			return iter->second;
		}
		else {
			return NULL;
		}
	}

	bool isTerminal() const
	{
		return (out >= 0);
	}
};
