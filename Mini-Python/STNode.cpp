#include "STNode.h"

STNode* g_root = nullptr;

int STNode::ms_serial_counter = 0;

int STNode::ms_returned_value = 0;

bool STNode::ms_breakVisit = false;
bool STNode::ms_continueVisit = false;

STNode::STNode(NodeType type) {
	m_serial = ms_serial_counter++;
	m_type = type;
	m_parent = nullptr;
	m_children = new list<STNode*>;
	m_label = g_nodeNames[type];
	m_label.append("_" + to_string(m_serial));
}
STNode::~STNode() {
	list<STNode*>::iterator it;
	for (it = m_children->begin(); it != m_children->end(); it++) {
		delete* it; //delete calls destructor for object *it before memory deallocation
	}
	delete m_children;
	delete m_parent;
}

void STNode::addChild(STNode* child) {
	m_children->push_back(child);
	child->setParent(this);
}

void STNode::setParent(STNode* parent) {
	m_parent = parent;
}

STNode* STNode::getChild(int index) {
	list<STNode*>::iterator it = m_children->begin();
	advance(it, index);
	return *it;
}

void STNode::vistiSyntaxTreePrinter(ofstream* dotFile, STNode* parent) {
	list<STNode*>::iterator it;

	(*dotFile) << "\"" << parent->getLabel() << "\"->\"" << getLabel() << "\";\n";

	for (it = m_children->begin(); it != m_children->end(); it++) {
		(*it)->vistiSyntaxTreePrinter(dotFile, this);
	}
}

int STNode::visitEval() {
	list<STNode*>::iterator it;
	for (it = m_children->begin(); it != m_children->end(); it++) {
		(*it)->visitEval();
	}
	return 0;
}