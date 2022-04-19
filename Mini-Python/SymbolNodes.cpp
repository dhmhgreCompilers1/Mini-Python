#pragma once

#include <iostream>

#include "SymbolNodes.h"
#include "SymbolTable.h"

C_Compile_Unit::C_Compile_Unit() : STNode(NT_COMPILE_UNIT) {}
C_Compile_Unit::~C_Compile_Unit() {} //destructor of father class will be called after this class destructor runs
void C_Compile_Unit::vistiSyntaxTreePrinter(ofstream* dotFile, STNode* parent) {
	list<STNode*>::iterator it;
	if (parent == nullptr) {
		(*dotFile) << "digraph G{ \n";
		for (it = m_children->begin(); it != m_children->end(); it++) {
			(*it)->vistiSyntaxTreePrinter(dotFile, this);
		}
		(*dotFile) << "}";
		dotFile->close();
	}
	else {
		STNode::vistiSyntaxTreePrinter(dotFile, parent);
	}
}

C_Statement::C_Statement() : STNode(NT_STATEMENT) {}
C_Statement::~C_Statement() {}
int C_Statement::visitEval() { return STNode::visitEval(); }

C_Statements::C_Statements() : STNode(NT_STATEMENTS) {}
C_Statements::~C_Statements() {}
int C_Statements::visitEval() {
	list<STNode*>::iterator it;
	for (it = m_children->begin(); it != m_children->end(); it++) {
		(*it)->visitEval();
		if (ms_breakVisit)
			break;
		if (ms_continueVisit)
			break;
	}
	return 0;
}

C_Compound_Statement::C_Compound_Statement() : STNode(NT_COMPOUND_STATEMENT) {}
C_Compound_Statement::~C_Compound_Statement() {}

C_NUMBER_INTEGER::C_NUMBER_INTEGER(int number) : STNode(T_NUMBER_INTEGER) {
	m_number = number;
	m_label.append("_" + to_string(getNumber()));
}
C_NUMBER_INTEGER::~C_NUMBER_INTEGER() {}
int C_NUMBER_INTEGER::visitEval() { return m_number; }

C_IDENTIFIER_INTEGER::C_IDENTIFIER_INTEGER(string text) : STNode(T_IDENTIFIER_INTEGER) {
	m_name = text;
	m_number = 0;
	m_root = nullptr;
	m_label.append("_" + m_name);
}
C_IDENTIFIER_INTEGER::~C_IDENTIFIER_INTEGER() {}
int C_IDENTIFIER_INTEGER::visitEval() { return m_number; }

C_Assignment_Expression::C_Assignment_Expression() : STNode(NT_ASSIGNMENT_EXPRESSION) {}
C_Assignment_Expression::~C_Assignment_Expression() {}
int C_Assignment_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	C_IDENTIFIER_INTEGER* id = dynamic_cast<C_IDENTIFIER_INTEGER*>(*it);
	advance(it, 1);
	id->m_number = (*it)->visitEval();
	cout << id->m_name << "=" << id->m_number << endl;
	return id->m_number;
}

// ARITHMETIC EXPRESSIONS //
C_Addition_Expression::C_Addition_Expression() : STNode(NT_EXPRESSION_ADDITION) {}
C_Addition_Expression::~C_Addition_Expression() {}
int C_Addition_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->visitEval();
	advance(it, 1);
	result += (*it)->visitEval();
	return result;
}

C_Subtraction_Expression::C_Subtraction_Expression() : STNode(NT_EXPRESSION_SUBTRACTION) {}
C_Subtraction_Expression::~C_Subtraction_Expression() {}
int C_Subtraction_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->visitEval();
	advance(it, 1);
	result -= (*it)->visitEval();
	return result;
}

C_Multiplication_Expression::C_Multiplication_Expression() : STNode(NT_EXPRESSION_MULTIPLICATION) {}
C_Multiplication_Expression::~C_Multiplication_Expression() {}
int C_Multiplication_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int result = (*it)->visitEval();
	advance(it, 1);
	result *= (*it)->visitEval();
	return result;
}

C_Division_Expression::C_Division_Expression() : STNode(NT_EXPRESSION_DIVISION) {}
C_Division_Expression::~C_Division_Expression() {}
int C_Division_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int left = (*it)->visitEval();
	advance(it, 1);
	int result;
	int right = (*it)->visitEval();
	if (right != 0) {
		result = (int)(((double)left) / right);
	}
	else throw runtime_error("Math error: Attempted to divide by Zero\n");

	return result;
}

C_SquareRoot_Expression::C_SquareRoot_Expression() : STNode(NT_EXPRESSION_SQUARE_ROOT) {}
C_SquareRoot_Expression::~C_SquareRoot_Expression() {}
int C_SquareRoot_Expression::visitEval() {
	return (int) sqrt(getChild(0)->visitEval());
}

C_Power_Expression::C_Power_Expression() : STNode(NT_EXPRESSION_POWER) {}
C_Power_Expression::~C_Power_Expression() {}
int C_Power_Expression::visitEval() {
	return (int) pow(getChild(0)->visitEval(), getChild(1)->visitEval());
}

// LOGICAL EXPRESSIONS //
C_Less_Expression::C_Less_Expression() : STNode(NT_LESS_EXPRESSION) {}
C_Less_Expression::~C_Less_Expression() {}
int C_Less_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int left = (*it)->visitEval();
	advance(it, 1);
	int right = (*it)->visitEval();
	return left < right;
}

C_Greater_Expression::C_Greater_Expression() : STNode(NT_GREATER_EXPRESSION) {}
C_Greater_Expression::~C_Greater_Expression() {}
int C_Greater_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int left = (*it)->visitEval();
	advance(it, 1);
	int right = (*it)->visitEval();
	return left > right;
}

C_LessEqual_Expression::C_LessEqual_Expression() : STNode(NT_LESS_EQUAL_EXPRESSION) {}
C_LessEqual_Expression::~C_LessEqual_Expression() {}
int C_LessEqual_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int left = (*it)->visitEval();
	advance(it, 1);
	int right = (*it)->visitEval();
	return left <= right;
}

C_GreaterEqual_Expression::C_GreaterEqual_Expression() : STNode(NT_GREATER_EQUAL_EXPRESSION) {}
C_GreaterEqual_Expression::~C_GreaterEqual_Expression() {}
int C_GreaterEqual_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int left = (*it)->visitEval();
	advance(it, 1);
	int right = (*it)->visitEval();
	return left >= right;
}

C_Equal_Expression::C_Equal_Expression() : STNode(NT_EQUAL_EXPRESSION) {}
C_Equal_Expression::~C_Equal_Expression() {}
int C_Equal_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int left = (*it)->visitEval();
	advance(it, 1);
	int right = (*it)->visitEval();
	return left == right;
}

C_NotEqual_Expression::C_NotEqual_Expression() : STNode(NT_NOT_EQUAL_EXPRESSION) {}
C_NotEqual_Expression::~C_NotEqual_Expression() {}
int C_NotEqual_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int left = (*it)->visitEval();
	advance(it, 1);
	int right = (*it)->visitEval();
	return left != right;
}

C_AND_Expression::C_AND_Expression() : STNode(NT_AND_EXPRESSION) {}
C_AND_Expression::~C_AND_Expression() {}
int C_AND_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int left = (*it)->visitEval();
	advance(it, 1);
	int right = (*it)->visitEval();
	return left && right;
}

C_OR_Expression::C_OR_Expression() : STNode(NT_OR_EXPRESSION) {}
C_OR_Expression::~C_OR_Expression() {}
int C_OR_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int left = (*it)->visitEval();
	advance(it, 1);
	int right = (*it)->visitEval();
	return left || right;
}

C_NOT_Expression::C_NOT_Expression() : STNode(NT_NOT_EXPRESSION) {}
C_NOT_Expression::~C_NOT_Expression() {}
int C_NOT_Expression::visitEval() {
	list<STNode*>::iterator it = m_children->begin();
	int expr = (*it)->visitEval();
	return !expr;
}

// FUNCTION //
C_Function_Definition::C_Function_Definition() :STNode(NT_FUNCTION_DEFINITION) {}
C_Function_Definition::~C_Function_Definition() {}
int C_Function_Definition::visitEval() { return 0; }

C_Function_Call_Expression::C_Function_Call_Expression() : STNode(NT_FUNCTION_CALL_EXPRESSION) {}
C_Function_Call_Expression::~C_Function_Call_Expression() {}
int C_Function_Call_Expression::visitEval() {
	//1. get access to the function identifier object to get m_root
	//*m_root gives access to function code
	string f_name = ((C_IDENTIFIER_INTEGER*)getChild(0))->m_name;
	C_IDENTIFIER_INTEGER* f_id = (C_IDENTIFIER_INTEGER*)g_symbolTable.getIdentifier(f_name);

	C_Function_Definition* fun_def = (C_Function_Definition*)f_id->m_root;

	if (fun_def->getChildList()->size() == 3) {
		//2. store actuall args in a list
		C_Actual_Args* f_a_args = (C_Actual_Args*)getChild(1);
		list<STNode*>* actualArgs = new list<STNode*>;
		getActualArguments(f_a_args, actualArgs);

		//3. store formal args in a list
		C_Formal_Args* f_f_args = (C_Formal_Args*)fun_def->getChild(1);
		list<STNode*>* formalArgs = new list<STNode*>;
		getFormalArguments(f_f_args, formalArgs);

		//4. map actuall args to formal args
		list<STNode*>::iterator formal_it;
		list<STNode*>::iterator actual_it;
		for (formal_it = formalArgs->begin(), actual_it = actualArgs->begin();
			formal_it != formalArgs->end(); formal_it++, actual_it++) {

			dynamic_cast<C_IDENTIFIER_INTEGER*>(*formal_it)->m_number = (*actual_it)->visitEval();
		}

		fun_def->getChild(2)->visitEval();
	}
	else { fun_def->getChild(1)->visitEval(); }

	ms_breakVisit = false;

	return STNode::ms_returned_value;
}

C_Formal_Args::C_Formal_Args() : STNode(NT_FORMAL_ARGUMENTS) {}
C_Formal_Args::~C_Formal_Args() {}
C_Actual_Args::C_Actual_Args() : STNode(NT_ACTUAL_ARGUMENTS) {}
C_Actual_Args::~C_Actual_Args() {}
int getActualArguments(C_Actual_Args* root, list<STNode*>* actualArgs) {
	if (dynamic_cast<C_Actual_Args*>(root->getChild(0)) != nullptr) {
		C_Actual_Args* next = dynamic_cast<C_Actual_Args*>(root->getChild(0));
		getActualArguments(next, actualArgs);
		actualArgs->push_back(root->getChild(1));
	}
	else {
		actualArgs->push_back(root->getChild(0));
	}
	return actualArgs->size();
}
int getFormalArguments(C_Formal_Args* root, list<STNode*>* formalArgs) {
	if (dynamic_cast<C_Formal_Args*>(root->getChild(0)) != nullptr) {
		C_Formal_Args* next = dynamic_cast<C_Formal_Args*>(root->getChild(0));
		getFormalArguments(next, formalArgs);
		formalArgs->push_back(root->getChild(1));
	}
	else {
		formalArgs->push_back(root->getChild(0));
	}
	return formalArgs->size();
}

C_RETURN_Statement::C_RETURN_Statement() : STNode(NT_RETURN_STATEMENT) {}
C_RETURN_Statement::~C_RETURN_Statement() {}
int C_RETURN_Statement::visitEval() {
	STNode* expr = getChild(0);
	ms_returned_value = expr->visitEval();
	ms_breakVisit = true;
	return ms_returned_value;
}

// LOOPS & CONDITIONS //
C_If_Statement::C_If_Statement() : STNode(NT_IF_STATEMENT) {}
C_If_Statement::~C_If_Statement() {}
int C_If_Statement::visitEval() {
	STNode* condition = getChild(0);
	STNode* true_body = getChild(1);
	STNode* false_body;
	if (condition->visitEval()) {
		true_body->visitEval();
	}
	else if (m_children->size() > 2) {
		false_body = getChild(2);
		false_body->visitEval();
	}

	return 0;
}

C_While_Statement::C_While_Statement() : STNode(NT_WHILE_STATEMENT) {}
C_While_Statement::~C_While_Statement() {}
int C_While_Statement::visitEval() {
	STNode* condition = getChild(0);
	STNode* body = getChild(1);
	while (condition->visitEval()) {
		body->visitEval();
		if (ms_breakVisit)
			break;
		if (ms_continueVisit)
			ms_continueVisit = false;
	}
	ms_breakVisit = false;
	return 0;
}

C_Continue_Statement::C_Continue_Statement() : STNode(NT_CONTINUE_STATEMENT) {}
C_Continue_Statement::~C_Continue_Statement() {}
int C_Continue_Statement::visitEval() {
	ms_continueVisit = true;
	return 0;
}

C_Break_Statement::C_Break_Statement() : STNode(NT_BREAK_STATEMENT) {}
C_Break_Statement::~C_Break_Statement() {}
int C_Break_Statement::visitEval() {
	ms_breakVisit = true;
	return 0;
}
