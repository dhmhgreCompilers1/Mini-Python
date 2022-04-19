#pragma once

#include <fstream>
#include <string>;
#include <list>;

#include "STNodeTypes.h"

using namespace std;

class  STNode abstract {
public:
	void addChild(STNode*);
	void setParent(STNode*);

	STNode* getChild(int index); //(int index = 0); default parameter if not given = 0
	STNode* getParent() { return m_parent; }
	NodeType getNodeType() { return m_type; }
	string getLabel() { return m_label; }
	list<STNode*>* getChildList() { return m_children; }

	virtual void vistiSyntaxTreePrinter(ofstream* dotFile, STNode* parent);
	virtual int visitEval();

protected:
	STNode(NodeType);
	virtual ~STNode(); //destructor

	static int ms_serial_counter;
	int m_serial;

	string m_label; //Graphviz label
	NodeType m_type;

	STNode* m_parent;
	list<STNode*>* m_children;

	static int ms_returned_value;

	static bool ms_breakVisit;
	static bool ms_continueVisit;
};

extern STNode* g_root;