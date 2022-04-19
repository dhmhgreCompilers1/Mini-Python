#include "SymbolTable.h"
#include "SymbolNodes.h"

SymbolTable g_symbolTable;

STNode* SymbolTable::getIdentifier(string name) {
	map<string, STNode*>::iterator it;
	STNode* node = NULL;

	it = m_symbolTable.find(name);
	if (it != m_symbolTable.end()) {
		node = m_symbolTable[name];
	}
	else {
		node = new C_IDENTIFIER_INTEGER(name);
		m_symbolTable[name] = node;
	}

	return node;
}