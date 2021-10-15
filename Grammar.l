%option noyywrap

%{
	#include <iostream>
	#include <cstdlib>
	#include "Grammar.tab.h"
	#include "CompositeConcrete.h"
	#include "SymbolTable.h"
	#define YY_DECL int yylex(yy::parser::semantic_type *yylval ,yy::parser::location_type *yylloc)
	typedef yy::parser::token token;
	// make location include the current token
	# define YY_USER_ACTION yylloc->columns(yyleng);
	int g_counter = 0;	//Counts Identation level
	int g_flag = 0;	//Becomes '1' right after encountering a ":" which signifies an increase in expected identation level. Used to release an "INDENT" token instead of just a "\t"
	int g_tabs = 0;	//Counts the tabs of every line
	int termination = 0;	//When reading EOF, we may need to return DEDENTS instead for proper syntax. In that case, we return the necessary DEDENTS instead of EOF and terminate manually.
%}

INT "0"|[1-9][0-9]*	


%%

%{
	// start where previous token ended
	yylloc->step ();
%}

"if"			{ if(g_tabs < g_counter)
				  {
					g_counter--;
					yyless(0);
					return token::DEDENT;
				  }
				  else if(g_tabs > g_counter)
				  {
					printf("Error: Invalid Identation.\n");
					return token::ERROR;
				  }
				  else
				  {
				    return token::IF;
				  }
				}
"else"			{ if(g_tabs < g_counter)
				  {
					g_counter--;
					yyless(0);
					return token::DEDENT;
				  }
				  else if(g_tabs > g_counter)
				  {
					printf("Error: Invalid Identation.\n");
					return token::ERROR;
				  }
				  else
				  {
				    return token::ELSE;
				  }
				}
"return"		{ if(g_tabs < g_counter)
				  {
					g_counter--;
					yyless(0);
					return token::DEDENT;
				  }
				  else if(g_tabs > g_counter)
				  {
					printf("Error: Invalid Identation.\n");
					return token::ERROR;
				  }
				  else
				  {
				    return token::RETURN;
				  } 
				}
"break"			{ if(g_tabs < g_counter)
				  {
					g_counter--;
					yyless(0);
					return token::DEDENT;
				  }
				  else if(g_tabs > g_counter)
				  {
					printf("Error: Invalid Identation.\n");
					return token::ERROR;
				  }
				  else
				  {
				    return token::BREAK;
				  }
				}
"while"			{ if(g_tabs < g_counter)
				  {
					g_counter--;
					yyless(0);
					return token::DEDENT;
				  }
				  else if(g_tabs > g_counter)
				  {
					printf("Error: Invalid Identation.\n");
					return token::ERROR;
				  }
				  else
				  {
				    return token::WHILE;
				  } 
				}
"def"			{ if(g_tabs < g_counter)
				  {
					g_counter--;
					yyless(0);
					return token::DEDENT;
				  }
				  else if(g_tabs > g_counter)
				  {
					printf("Error: Invalid Identation.\n");
					return token::ERROR;
				  }
				  else
				  {
				    return token::FUNCTION;
				  } 
				}
"("				{ return '(';}
")"				{ return ')';}
"+"				{ return token::PLUS;}
"-"				{ return token::MINUS;}
"*"				{ return token::MULT;}
"/"				{ return token::DIV;}
"and"			{ return token::AND;}
"or"			{ return token::OR;}
"not"			{ return token::NOT;}
"<"				{ return token::LT;}
">"				{ return token::GT;}
">="			{ return token::GTE;}
"<="			{ return token::LTE;}
"=="			{ return token::EQUAL;}
"!="			{ return token::NEQUAL;}
"="				{ return '=';}
","				{ return ',';}
"\n"			{ if(termination == 1)
				  {
					if(g_counter > g_tabs)
					{
						g_counter--;
						unput('\n');
						return token::DEDENT;
					}
					yyterminate();
				  }
				  if(g_flag == 1)
				  {
					g_tabs = g_counter;
					yylloc->lines(1);
					return '\n';
				  }
				  if(g_tabs < g_counter)
				  {
					g_counter--;
					g_tabs = 0;
					yyless(0);
					return token::DEDENT;
				  }
				  else
				  {
					yylloc->lines(1);
					g_tabs = 0;
					return '\n';
				  }
				}
"\t"			{ yylloc->step();
				  if((g_flag == 1)&&(g_tabs == g_counter))
				  {
					g_flag = 0;
					g_tabs = 1;
					return token::INDENT;
				  }
				  g_tabs++;
				  
				}
":"				{ g_flag = 1;
				  g_counter++;
				  return ':';}

";"				{}
({INT}?\.{INT})|({INT}\.{INT}?)		{ yylval->node = new CExpressionNUMBER(yytext,atof(yytext));
									  return token::NUMBER; }
{INT}								{ yylval->node = new CExpressionNUMBER(yytext,(double)atoi(yytext));
									  return token::NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*				{ if(g_tabs < g_counter)
									  {
										g_counter--;
										yyless(0);
										return token::DEDENT;
									  }
									  else if(g_tabs > g_counter)
									  {
										printf("Error: Invalid Identation.\n");
										return token::ERROR;
									  }
									  else
									  {
										yylval->node = g_symbolTable.GetSymbol(yytext)->Idnode;
										return token::IDENTIFIER;
									  }
									 }
" "				{ yylloc->step();}
"\r"			{ yylloc->lines(1);}
(#.*[^\n])|(\"{3}(.|\n)*?\"{3})|(\'{3}(.|\n)*?\'{3})			{/*Ignore Comments*/} 

<<EOF>>		{
					if(g_counter > g_tabs)
					{
						unput('\n');
						termination = 1;
						g_counter--;
						return token::DEDENT;
					}
					else
					{
						yyterminate();
					}
				}

%%