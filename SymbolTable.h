#ifndef SYMBOLTABLE_
#define SYMBOLTABLE_

#include <map>
#include <optional>
#include <string>

using namespace std;

class CIDENTIFIER;
class CSTNode;
class Symbol {
public:
	string m_text;
	double value;
	CIDENTIFIER* Idnode;
	CSTNode* syntaxNode;
};


class SymbolTable {
	map<string, Symbol*>* m_symbolTable;
public:
	SymbolTable() {
		m_symbolTable = new map<string, Symbol*>();
	}
	virtual ~SymbolTable() {}

	Symbol * GetSymbol(string);
};

extern SymbolTable g_symbolTable;



#endif
