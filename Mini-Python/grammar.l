
%option noyywrap

%{
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "grammar.tab.h"
#include "SymbolNodes.h"
#include "SymbolTable.h"

#define YY_DECL int yylex(yy::parser::semantic_type *yylval)

typedef yy::parser::token::yytokentype token;

// INDENTATION // 
int indentationCheck(int T);
int indentationLevel = 0;
int currentTabs = 0;
bool restartIndentation = false;
bool reachedEOF = false;

bool finishedReadingIndentation = false;

%}

SPACES		[ ]*
WS			[ \t\r]*

%%

({WS}\n)+	{
	finishedReadingIndentation = false;

	if( reachedEOF ) {
		if( indentationLevel > 0 ) {
			unput('\n');
			indentationLevel--;
			return token::DEDENT;
		}
		yyterminate();
	}
	
	//line end and empty lines
	currentTabs = 0;
	return token::ENDLINE;
}

\t	{
	if( finishedReadingIndentation ) {
		//ignore tab
	}
	else {
		if( restartIndentation ) {
			restartIndentation = false;
			currentTabs = 1; //the tab that matched
			return token::INDENT;
		}
		currentTabs++;
	}
}

":"	{
	restartIndentation = true;
	indentationLevel++;
	return ':';
}

<<EOF>> {
	reachedEOF = true;
	unput('\n');
	return token::ENDLINE;
}

","	{ return ','; }
";"	{ return ';'; }
"+"	{ return '+'; }
"-"	{ return '-'; }
"*"	{ return '*'; }
"/"	{ return '/'; }
")"	{ return ')'; }
"("	{ return '('; }
"="	{ return '='; }
"}"	{ return '}'; }
"{"	{ return '{'; }

"pow" {
	return indentationCheck(token::POW);
}

"sqrt" {
	return indentationCheck(token::SQRT);
}

"<"			{ return token::L; }
">"			{ return token::G; }
"<="		{ return token::LE; }
">="		{ return token::GE; }
"=="		{ return token::EQ; }
"!="		{ return token::NE; }
"and"		{ return token::AND; }
"or"		{ return token::OR; }
"not"		{ return token::NOT; }

"True"	{
	yylval->node = new C_NUMBER_INTEGER(1);
	return indentationCheck(token::BOOLEAN_VALUE);
}

"False"	{
	yylval->node = new C_NUMBER_INTEGER(0);
	return indentationCheck(token::BOOLEAN_VALUE);
}

"def"	{
	return indentationCheck(token::FUNCTION_DEF);
}

"return"	{
	return indentationCheck(token::RETURN);
}

"if"	{
	return indentationCheck(token::IF);
}

"else"	{
	return indentationCheck(token::ELSE);
}

"while"	{
	return indentationCheck(token::WHILE);
}

"break"	{
	return indentationCheck(token::BREAK);
}

"continue"	{
	return indentationCheck(token::CONTINUE);
}

0|[+-]?[1-9][0-9]* {
//integer numbers
	int x = atoi(yytext);
	yylval->node = new C_NUMBER_INTEGER(x);
	return indentationCheck(token::NUMBER_INTEGER);
}

[a-zA-Z][a-zA-Z0-9_]*	{
//identifier
	yylval->node = g_symbolTable.getIdentifier(yytext);
	return indentationCheck(token::IDENTIFIER_INTEGER);
}

{SPACES}

%%

//returns correct Token for Parser
//param: the Token Lexer matched
int indentationCheck(int Token) {
	if( !finishedReadingIndentation )
		finishedReadingIndentation = true;
	if( currentTabs > indentationLevel ) {
		printf("Error: Invalid Identation.\n");
		return token::ERROR;
	}
	if( currentTabs < indentationLevel ) {
		indentationLevel--;
		yyless(0); //return to the input that matched
		//this will happen until indentationLevel matches currentTabs
		//then the Token matched will be send to Parser
		return token::DEDENT;
	}
	//correct indentation
	return Token;
}