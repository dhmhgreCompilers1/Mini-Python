
%{
#include <iostream>
#include <stdlib.h>
#include "grammar.tab.h"

extern int yylex(yy::parser::semantic_type *yylval);
%}

%language "C++"

%code requires {
	#include "STNode.h"
	#include "SymbolNodes.h"
}

%union { STNode* node; }

%start compileUnit

%token ENDLINE ERROR
%token INDENT DEDENT

%type <node> compileUnit
%type <node> statement statements compoundStatement 
%type <node> expressionArithmetic expressionLogical

%token <node> NUMBER_INTEGER BOOLEAN_VALUE
%token <node> IDENTIFIER_INTEGER

%right '='
%left OR
%left AND
%nonassoc L G LE GE EQ NE
%left '+' '-'
%left '*' '/'
%nonassoc NOT

%token POW SQRT

%token FUNCTION_DEF
%type <node> functionDefinition
%type <node> formalArgs actualArgs
%token RETURN

%token IF WHILE BREAK CONTINUE
%nonassoc PARTIALIFRULE
%nonassoc ELSE
%type <node> ifStatement whileStatement


%%

compileUnit	:	statement	{
						$$ = new C_Compile_Unit();
						g_root = $$;
						$$->addChild($1);
					}
					|	compileUnit statement	{
						$$ = new C_Compile_Unit();
						g_root = $$;
						$$->addChild($1);
						$$->addChild($2);
					}
					;

statement	:	expressionArithmetic ENDLINE {
					$$ = $1;
				}
				|	expressionLogical ENDLINE {
					$$ = $1;
				}
				|	functionDefinition	{
					$$ = $1;
				}
				|	RETURN expressionArithmetic ENDLINE	{
					$$ = new C_RETURN_Statement();
					$$->addChild($2);
				}
				|	ifStatement	{
					$$ = $1;
				}
				|	whileStatement	{
					$$ = $1;
				}
				|	BREAK ENDLINE	{
					$$ = new C_Break_Statement();
				}
				|	CONTINUE ENDLINE	{
					$$ = new C_Continue_Statement();
				}
				|	ENDLINE	{
					$$ = new C_Statement();
				}
				;

statements	:	statement	{
						$$ = new C_Statements();
						$$->addChild($1);
					}
					|	statements statement	{
						$$ = new C_Statements();
						$$->addChild($1);
						$$->addChild($2);
					}
					; 

compoundStatement	: INDENT statements DEDENT	{
									$$ = new C_Compound_Statement();
									$$->addChild($2);
								}
								;

expressionArithmetic	:	NUMBER_INTEGER	{ $$ = $1; }
								|	IDENTIFIER_INTEGER { $$ = $1; }	
								|	IDENTIFIER_INTEGER '=' expressionArithmetic {
									$$ = new C_Assignment_Expression();
									$$->addChild($1);
									$$->addChild($3);
								}
								|	'(' expressionArithmetic ')'	{ $$ = $2; }
								|	expressionArithmetic '+' expressionArithmetic	{
									$$ = new C_Addition_Expression();
									$$->addChild($1);
									$$->addChild($3);
								}
								|	expressionArithmetic '-' expressionArithmetic	{
									$$ = new C_Subtraction_Expression();
									$$->addChild($1);
									$$->addChild($3);
								}
								|	expressionArithmetic '*' expressionArithmetic	{
									$$ = new C_Multiplication_Expression();
									$$->addChild($1);
									$$->addChild($3);
								}
								|	expressionArithmetic '/' expressionArithmetic	{
									$$ = new C_Division_Expression();
									$$->addChild($1);
									$$->addChild($3);
								}
								|	expressionLogical	{ $$ = $1; }
								|	IDENTIFIER_INTEGER '(' ')'	{
									//function call with no arguments
									$$ = new C_Function_Call_Expression();
									$$->addChild($1);
								} 
								|	IDENTIFIER_INTEGER '(' actualArgs ')'	{
									//function call with arguments
									$$ = new C_Function_Call_Expression();
									$$->addChild($1);
									$$->addChild($3);
								}
								| SQRT '(' expressionArithmetic ')'	{
									$$ = new C_SquareRoot_Expression();
									$$->addChild($3);
								}
								| POW '(' expressionArithmetic ',' expressionArithmetic ')'	{
									$$ = new C_Power_Expression();
									$$->addChild($3);
									$$->addChild($5);
								}
								;

expressionLogical	:	BOOLEAN_VALUE	{ $$ = $1; }
							|	'(' expressionLogical ')'	{ $$ = $2; }
							|	expressionArithmetic L expressionArithmetic	{
								$$ = new C_Less_Expression();
								$$->addChild($1);
								$$->addChild($3);
							}
							|	expressionArithmetic G expressionArithmetic	{
								$$ = new C_Greater_Expression();
								$$->addChild($1);
								$$->addChild($3);
							}
							|	expressionArithmetic LE expressionArithmetic	{
								$$ = new C_LessEqual_Expression();
								$$->addChild($1);
								$$->addChild($3);
							}
							|	expressionArithmetic GE expressionArithmetic	{
								$$ = new C_GreaterEqual_Expression();
								$$->addChild($1);
								$$->addChild($3);
							}
							|	expressionArithmetic EQ expressionArithmetic	{
								$$ = new C_Equal_Expression();
								$$->addChild($1);
								$$->addChild($3);
							}
							|	expressionArithmetic NE expressionArithmetic	{
								$$ = new C_NotEqual_Expression();
								$$->addChild($1);
								$$->addChild($3);
							}
							|	expressionArithmetic AND expressionArithmetic	{
								$$ = new C_AND_Expression();
								$$->addChild($1);
								$$->addChild($3);
							}
							|	expressionArithmetic OR expressionArithmetic	{
								$$ = new C_OR_Expression();
								$$->addChild($1);
								$$->addChild($3);
							}
							|	NOT expressionArithmetic	{
								$$ = new C_NOT_Expression();
								$$->addChild($2);
							}
							;

functionDefinition	:	FUNCTION_DEF IDENTIFIER_INTEGER '(' ')' ':' ENDLINE compoundStatement	{
								$$ = new C_Function_Definition();
								((C_IDENTIFIER_INTEGER*) $2)->m_root = $$;
								$$->addChild($2); //0
								$$->addChild($7); //1
							}
							|	FUNCTION_DEF IDENTIFIER_INTEGER '(' formalArgs ')' ':' ENDLINE compoundStatement	{
									$$ = new C_Function_Definition();
									((C_IDENTIFIER_INTEGER*) $2)->m_root = $$;
									$$->addChild($2); //0
									$$->addChild($4); //1
									$$->addChild($8); //2
							}
							;

formalArgs	:	IDENTIFIER_INTEGER	{
						$$ = new C_Formal_Args();
						$$->addChild($1);
					}
					|	formalArgs ',' IDENTIFIER_INTEGER	{
						$$ = new C_Formal_Args();
						$$->addChild($1);
						$$->addChild($3);
					}
					;

actualArgs	:	expressionArithmetic	{
					$$ = new C_Actual_Args();
					$$->addChild($1);
				}
				|	actualArgs ',' expressionArithmetic	{
					$$ = new C_Actual_Args();
					$$->addChild($1);
					$$->addChild($3);
				}
				;

ifStatement	:	IF expressionArithmetic ':' ENDLINE compoundStatement %prec PARTIALIFRULE	{
						$$ = new C_If_Statement();
						$$->addChild($2);
						$$->addChild($5);
					}
					|	IF expressionArithmetic ':' ENDLINE compoundStatement ELSE ':' ENDLINE compoundStatement	{
						$$ = new C_If_Statement();
						$$->addChild($2);
						$$->addChild($5);
						//if it has 3 childs means there is else statement at 3rd child
						$$->addChild($9);
					}
					;

whileStatement	:	WHILE expressionArithmetic ':' ENDLINE compoundStatement	{
							$$ = new C_While_Statement();
							$$->addChild($2);
							$$->addChild($5);
						}
						;

%%

void yy::parser::error(const location_type& loc, const std::string& msg) {
	std::cerr << "error at " << loc << ": " << msg << std::endl;
}