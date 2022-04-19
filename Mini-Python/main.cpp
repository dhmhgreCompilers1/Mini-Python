#include <iostream>
#include <stdlib.h>
#include <fstream>

#include "grammar.tab.h"
#include "STNode.h"

extern FILE* yyin;

int main(void) {

	fopen_s(&yyin, "test1.txt", "r");

	if (yyin == NULL) {
		printf("Unable to open input file.\n");
		return 0;
	}

	yy::parser* p = new yy::parser;
	p->parse();

	fclose(yyin);

	ofstream* f = new ofstream("stree.dot", ofstream::out);
	g_root->vistiSyntaxTreePrinter(f, nullptr);
	system("dot -Tgif stree.dot -o stree.dot.gif");
	
	g_root->visitEval();

	return 0;
}