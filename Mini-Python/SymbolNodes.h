#pragma once

#include "STNode.h"

class C_Compile_Unit : public STNode {
public:
	C_Compile_Unit();
	virtual ~C_Compile_Unit();
	void vistiSyntaxTreePrinter(ofstream* dotFile, STNode* parent) override;
};

class C_Statement : public STNode {
public:
	C_Statement();
	virtual ~C_Statement();
	virtual int visitEval() override;
};
class C_Statements : public STNode {
public:
	C_Statements();
	virtual ~C_Statements();
	virtual int visitEval() override;
};

class C_Assignment_Expression : public STNode {
public:
	C_Assignment_Expression();
	virtual ~C_Assignment_Expression();
	virtual int visitEval() override;
};
class C_NUMBER_INTEGER : public STNode {
public:
	C_NUMBER_INTEGER(int);
	virtual ~C_NUMBER_INTEGER();
	int getNumber() { return m_number; }
	virtual int visitEval() override;

protected:
	int m_number;
};
class C_IDENTIFIER_INTEGER : public STNode {
public:
	int m_number;
	string m_name;
	char* m_name_c;
	STNode* m_root;

	C_IDENTIFIER_INTEGER(string text);
	virtual ~C_IDENTIFIER_INTEGER();
	virtual int visitEval() override;
};

// ARITHMETIC EXPRESSIONS //
class C_Addition_Expression : public STNode {
public:
	C_Addition_Expression();
	virtual ~C_Addition_Expression();
	virtual int visitEval() override;
};
class C_Subtraction_Expression : public STNode {
public:
	C_Subtraction_Expression();
	virtual ~C_Subtraction_Expression();
	virtual int visitEval() override;
};
class C_Multiplication_Expression : public STNode {
public:
	C_Multiplication_Expression();
	virtual ~C_Multiplication_Expression();
	virtual int visitEval() override;
};
class C_Division_Expression : public STNode {
public:
	C_Division_Expression();
	virtual ~C_Division_Expression();
	virtual int visitEval() override;
};
class C_SquareRoot_Expression : public STNode {
public:
	C_SquareRoot_Expression();
	virtual ~C_SquareRoot_Expression();
	virtual int visitEval() override;
};
class C_Power_Expression : public STNode {
public:
	C_Power_Expression();
	virtual ~C_Power_Expression();
	virtual int visitEval() override;
};

// LOGICAL EXPRESSIONS //
class C_Less_Expression : public STNode {
public:
	C_Less_Expression();
	virtual ~C_Less_Expression();
	virtual int visitEval() override;
};
class C_Greater_Expression : public STNode {
public:
	C_Greater_Expression();
	virtual ~C_Greater_Expression();
	virtual int visitEval() override;
};
class C_LessEqual_Expression : public STNode {
public:
	C_LessEqual_Expression();
	virtual ~C_LessEqual_Expression();
	virtual int visitEval() override;
};
class C_GreaterEqual_Expression : public STNode {
public:
	C_GreaterEqual_Expression();
	virtual ~C_GreaterEqual_Expression();
	virtual int visitEval() override;
};
class C_Equal_Expression : public STNode {
public:
	C_Equal_Expression();
	virtual ~C_Equal_Expression();
	virtual int visitEval() override;
};
class C_NotEqual_Expression : public STNode {
public:
	C_NotEqual_Expression();
	virtual ~C_NotEqual_Expression();
	virtual int visitEval() override;
};
class C_AND_Expression : public STNode {
public:
	C_AND_Expression();
	virtual ~C_AND_Expression();
	virtual int visitEval() override;
};
class C_OR_Expression : public STNode {
public:
	C_OR_Expression();
	virtual ~C_OR_Expression();
	virtual int visitEval() override;
};
class C_NOT_Expression : public STNode {
public:
	C_NOT_Expression();
	virtual ~C_NOT_Expression();
	virtual int visitEval() override;
};

// FUNCTION //
class C_Function_Definition : public STNode {
public:
	C_Function_Definition();
	virtual ~C_Function_Definition();
	virtual int visitEval() override;
};
class C_Function_Call_Expression : public STNode {
public:
	C_Function_Call_Expression();
	virtual ~C_Function_Call_Expression();
	virtual int visitEval() override;
};

class C_Formal_Args : public STNode {
public:
	C_Formal_Args();
	virtual ~C_Formal_Args();
};
class C_Actual_Args : public STNode {
public:
	C_Actual_Args();
	virtual ~C_Actual_Args();
};
int getFormalArguments(C_Formal_Args* root, list<STNode*>* formalArgs);
int getActualArguments(C_Actual_Args* root, list<STNode*>* actualArgs);

class C_RETURN_Statement : public STNode {
public:
	C_RETURN_Statement();
	virtual ~C_RETURN_Statement();
	virtual int visitEval() override;
};

// LOOPS & IF //
class C_If_Statement : public STNode {
public:
	C_If_Statement();
	virtual ~C_If_Statement();
	virtual int visitEval() override;
};

class C_While_Statement : public STNode {
public:
	C_While_Statement();
	virtual ~C_While_Statement();
	virtual int visitEval() override;
};
class C_Compound_Statement : public STNode {
public:
	C_Compound_Statement();
	virtual ~C_Compound_Statement();
};

class C_Continue_Statement : public STNode {
public:
	C_Continue_Statement();
	virtual ~C_Continue_Statement();
	virtual int visitEval() override;
};
class C_Break_Statement : public STNode {
public:
	C_Break_Statement();
	virtual ~C_Break_Statement();
	virtual int visitEval() override;
};