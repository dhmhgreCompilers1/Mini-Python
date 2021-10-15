%language "C++"

%{
	#include <iostream>
	#include "Grammar.tab.h"
	#include "CompositeConcrete.h"
	using namespace std;
	extern int yylex(yy::parser::semantic_type *yylval ,yy::parser::location_type *yylloc);
	extern FILE *yyin;
%}

%verbose
%locations

%initial-action 
{
	// Filename for locations here
	@$.begin.filename = @$.end.filename = new std::string("test.txt");
}
%error-verbose

%code requires{
	#include "Composite.h"
}

%union{
	CSTNode *node;
}


%start compileUnit
%token <node> IDENTIFIER NUMBER
%token INDENT DEDENT
%token RETURN BREAK IF ELSE WHILE FUNCTION 
%token ERROR
%nonassoc IFPREC
%left '='
%left OR
%left AND
%nonassoc GTE GT LTE LT EQUAL NEQUAL
%left PLUS MINUS
%left MULT DIV
%nonassoc NOT ELSE
%type <node> compileUnit function_definition fargs statement if_statement while_statement compound_statement statement_list expression args
%%

compileUnit: statement								{ $$=g_root= new CCompileUnit($1);}
			| compileUnit statement					{ $$=g_root= new CCompileUnit($1,$2);}
			| function_definition					{ $$=g_root= new CCompileUnit($1);}
			| compileUnit function_definition		{ $$=g_root= new CCompileUnit($1,$2);}		
			;

function_definition : FUNCTION IDENTIFIER '(' fargs ')' ':''\n' compound_statement		{ $$ = new CFunctionDefinition($2,$4,$8); 
																						  g_symbolTable.GetSymbol(((CIDENTIFIER *)$2)->m_text)->syntaxNode =$$;}
					| FUNCTION IDENTIFIER '(' ')' ':''\n' compound_statement			{ $$ = new CFunctionDefinition($2,$7); 
																						  g_symbolTable.GetSymbol(((CIDENTIFIER *)$2)->m_text)->syntaxNode =$$;}
				;

fargs : IDENTIFIER					{ $$ = new CFormalArgs($1); }
		| fargs IDENTIFIER			{ $$ = new CFormalArgs($1,$2); }
		| fargs ',' IDENTIFIER		{ $$ = new CFormalArgs($1,$3); }
		;

statement : expression '\n'				{ $$ = new CExpressionStatement($1) ;}
		  | compound_statement
		  | if_statement
		  | while_statement
		  | RETURN expression '\n'		{ $$ = new CReturnStatement($2) ;}
		  | BREAK '\n'					{ $$ = new CBreakStatement() ;}
		  | '\n'						{ $$ = new CNullStatement() ;}
		  ;

if_statement : IF '(' expression ')' ':''\n' statement %prec IFPREC					{ $$ = new CIfStatement($3,$7) ;}
			| IF expression ':''\n' statement %prec IFPREC					{ $$ = new CIfStatement($2,$5) ;}
			| IF '(' expression ')' ':''\n' statement ELSE ':''\n' statement		{ $$ = new CIfStatement($3,$7,$11) ;}
			| IF expression ':''\n' statement ELSE ':''\n' statement		{ $$ = new CIfStatement($2,$5,$9) ;}
			;

while_statement : WHILE '(' expression ')' ':''\n' statement			{ $$ = new CWhileStatement($3,$7) ;}
				| WHILE expression ':''\n' statement			{ $$ = new CWhileStatement($2,$5) ;}
			;

compound_statement : INDENT DEDENT						{ $$ = new CCompoundStatement() ;}
					| INDENT statement_list DEDENT		{ $$ = new CCompoundStatement($2) ;}
					;

statement_list : statement						{ $$ = new CStatementList($1) ;}
			   | statement_list statement		{ $$ = new CStatementList($1,$2) ;}
			   ;

expression: NUMBER								{ $$ = $1; }
		  | IDENTIFIER							{ $$ = new CExpressionVariable($1);
												  g_symbolTable.GetSymbol(((CIDENTIFIER *)$1)->m_text)->syntaxNode =$$;}
		  | IDENTIFIER '(' ')'					{ $$ = new CExpressionFCall($1); }
		  | IDENTIFIER '(' args ')'				{ $$ = new CExpressionFCall($1,$3); }
		  | expression PLUS expression			{ $$ = new CExpressionAdd($1,$3); }
		  | expression MINUS expression			{ $$ = new CExpressionMinus($1,$3); }
		  | expression MULT expression			{ $$ = new CExpressionMult($1,$3); }
		  | expression DIV expression			{ $$ = new CExpressionDiv($1,$3); }
		  | PLUS expression						{ $$ = new CExpressionUnaryPlus($2); }
		  | MINUS expression					{ $$ = new CExpressionUnaryMinus($2); }
		  | '(' expression ')'					{ $$ = $2;}
		  | IDENTIFIER '=' expression			{ $$ = new CExpressionAssign($1,$3); }
		  | expression AND expression			{ $$ = new CExpressionAND($1,$3); }
		  | expression OR expression			{ $$ = new CExpressionOR($1,$3); }
		  | NOT expression						{ $$ = new CExpressionNOT($2); }
		  | expression GT expression			{ $$ = new CExpressionGT($1,$3); }
		  | expression GTE expression			{ $$ = new CExpressionGTE($1,$3); }
		  | expression LT expression			{ $$ = new CExpressionLT($1,$3); }
		  | expression LTE expression			{ $$ = new CExpressionLTE($1,$3); }
		  | expression EQUAL expression			{ $$ = new CExpressionEQUAL($1,$3); }
		  | expression NEQUAL expression		{ $$ = new CExpressionNEQUAL($1,$3); }
		  ;

args : expression					{ $$ = new CActualArgs($1); }
	 | args ',' expression			{ $$ = new CActualArgs($1,$3); }
	 ;

%%

namespace yy
{
	void parser::error(yy::location const &loc, const string &message)
	{
		std::cerr << "error at " << loc << ": " << message << std::endl;
	}
}
