#pragma once

#include <map>
#include <string>

#include "STNode.h"

using namespace std;

class SymbolTable {
public:
	map<string, STNode*> m_symbolTable;
	STNode* getIdentifier(string name);
};

extern SymbolTable g_symbolTable;