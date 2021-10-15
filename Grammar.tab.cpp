/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */
/* Line 279 of lalr1.cc  */
#line 3 "Grammar.y"

	#include <iostream>
	#include "Grammar.tab.h"
	#include "CompositeConcrete.h"
	using namespace std;
	extern int yylex(yy::parser::semantic_type *yylval ,yy::parser::location_type *yylloc);
	extern FILE *yyin;

/* Line 279 of lalr1.cc  */
#line 47 "Grammar.tab.cpp"


#include "Grammar.tab.h"

/* User implementation prologue.  */

/* Line 285 of lalr1.cc  */
#line 55 "Grammar.tab.cpp"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
/* Line 353 of lalr1.cc  */
#line 150 "Grammar.tab.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {
  }

  parser::~parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


/* User initialization code.  */
/* Line 545 of lalr1.cc  */
#line 16 "Grammar.y"
{
	// Filename for locations here
	yylloc.begin.filename = yylloc.end.filename = new std::string("test.txt");
}
/* Line 545 of lalr1.cc  */
#line 349 "Grammar.tab.cpp"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
        YYCDEBUG << "Reading a token: ";
        yychar = yylex (&yylval, &yylloc);
      }

    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 2:
/* Line 670 of lalr1.cc  */
#line 47 "Grammar.y"
    { (yyval.node)=g_root= new CCompileUnit((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 3:
/* Line 670 of lalr1.cc  */
#line 48 "Grammar.y"
    { (yyval.node)=g_root= new CCompileUnit((yysemantic_stack_[(2) - (1)].node),(yysemantic_stack_[(2) - (2)].node));}
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 49 "Grammar.y"
    { (yyval.node)=g_root= new CCompileUnit((yysemantic_stack_[(1) - (1)].node));}
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 50 "Grammar.y"
    { (yyval.node)=g_root= new CCompileUnit((yysemantic_stack_[(2) - (1)].node),(yysemantic_stack_[(2) - (2)].node));}
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 53 "Grammar.y"
    { (yyval.node) = new CFunctionDefinition((yysemantic_stack_[(8) - (2)].node),(yysemantic_stack_[(8) - (4)].node),(yysemantic_stack_[(8) - (8)].node)); 
																						  g_symbolTable.GetSymbol(((CIDENTIFIER *)(yysemantic_stack_[(8) - (2)].node))->m_text)->syntaxNode =(yyval.node);}
    break;

  case 7:
/* Line 670 of lalr1.cc  */
#line 55 "Grammar.y"
    { (yyval.node) = new CFunctionDefinition((yysemantic_stack_[(7) - (2)].node),(yysemantic_stack_[(7) - (7)].node)); 
																						  g_symbolTable.GetSymbol(((CIDENTIFIER *)(yysemantic_stack_[(7) - (2)].node))->m_text)->syntaxNode =(yyval.node);}
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 59 "Grammar.y"
    { (yyval.node) = new CFormalArgs((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 60 "Grammar.y"
    { (yyval.node) = new CFormalArgs((yysemantic_stack_[(2) - (1)].node),(yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 61 "Grammar.y"
    { (yyval.node) = new CFormalArgs((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 64 "Grammar.y"
    { (yyval.node) = new CExpressionStatement((yysemantic_stack_[(2) - (1)].node)) ;}
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 68 "Grammar.y"
    { (yyval.node) = new CReturnStatement((yysemantic_stack_[(3) - (2)].node)) ;}
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 69 "Grammar.y"
    { (yyval.node) = new CBreakStatement() ;}
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 70 "Grammar.y"
    { (yyval.node) = new CNullStatement() ;}
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 73 "Grammar.y"
    { (yyval.node) = new CIfStatement((yysemantic_stack_[(7) - (3)].node),(yysemantic_stack_[(7) - (7)].node)) ;}
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 74 "Grammar.y"
    { (yyval.node) = new CIfStatement((yysemantic_stack_[(5) - (2)].node),(yysemantic_stack_[(5) - (5)].node)) ;}
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 75 "Grammar.y"
    { (yyval.node) = new CIfStatement((yysemantic_stack_[(11) - (3)].node),(yysemantic_stack_[(11) - (7)].node),(yysemantic_stack_[(11) - (11)].node)) ;}
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 76 "Grammar.y"
    { (yyval.node) = new CIfStatement((yysemantic_stack_[(9) - (2)].node),(yysemantic_stack_[(9) - (5)].node),(yysemantic_stack_[(9) - (9)].node)) ;}
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 79 "Grammar.y"
    { (yyval.node) = new CWhileStatement((yysemantic_stack_[(7) - (3)].node),(yysemantic_stack_[(7) - (7)].node)) ;}
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 80 "Grammar.y"
    { (yyval.node) = new CWhileStatement((yysemantic_stack_[(5) - (2)].node),(yysemantic_stack_[(5) - (5)].node)) ;}
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 83 "Grammar.y"
    { (yyval.node) = new CCompoundStatement() ;}
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 84 "Grammar.y"
    { (yyval.node) = new CCompoundStatement((yysemantic_stack_[(3) - (2)].node)) ;}
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 87 "Grammar.y"
    { (yyval.node) = new CStatementList((yysemantic_stack_[(1) - (1)].node)) ;}
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 88 "Grammar.y"
    { (yyval.node) = new CStatementList((yysemantic_stack_[(2) - (1)].node),(yysemantic_stack_[(2) - (2)].node)) ;}
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 91 "Grammar.y"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 92 "Grammar.y"
    { (yyval.node) = new CExpressionVariable((yysemantic_stack_[(1) - (1)].node));
												  g_symbolTable.GetSymbol(((CIDENTIFIER *)(yysemantic_stack_[(1) - (1)].node))->m_text)->syntaxNode =(yyval.node);}
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 94 "Grammar.y"
    { (yyval.node) = new CExpressionFCall((yysemantic_stack_[(3) - (1)].node)); }
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 95 "Grammar.y"
    { (yyval.node) = new CExpressionFCall((yysemantic_stack_[(4) - (1)].node),(yysemantic_stack_[(4) - (3)].node)); }
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 96 "Grammar.y"
    { (yyval.node) = new CExpressionAdd((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 97 "Grammar.y"
    { (yyval.node) = new CExpressionMinus((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 98 "Grammar.y"
    { (yyval.node) = new CExpressionMult((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 99 "Grammar.y"
    { (yyval.node) = new CExpressionDiv((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 100 "Grammar.y"
    { (yyval.node) = new CExpressionUnaryPlus((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 101 "Grammar.y"
    { (yyval.node) = new CExpressionUnaryMinus((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 102 "Grammar.y"
    { (yyval.node) = (yysemantic_stack_[(3) - (2)].node);}
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 103 "Grammar.y"
    { (yyval.node) = new CExpressionAssign((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 104 "Grammar.y"
    { (yyval.node) = new CExpressionAND((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 105 "Grammar.y"
    { (yyval.node) = new CExpressionOR((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 106 "Grammar.y"
    { (yyval.node) = new CExpressionNOT((yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 107 "Grammar.y"
    { (yyval.node) = new CExpressionGT((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 108 "Grammar.y"
    { (yyval.node) = new CExpressionGTE((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 109 "Grammar.y"
    { (yyval.node) = new CExpressionLT((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 110 "Grammar.y"
    { (yyval.node) = new CExpressionLTE((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 111 "Grammar.y"
    { (yyval.node) = new CExpressionEQUAL((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 112 "Grammar.y"
    { (yyval.node) = new CExpressionNEQUAL((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 115 "Grammar.y"
    { (yyval.node) = new CActualArgs((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 116 "Grammar.y"
    { (yyval.node) = new CActualArgs((yysemantic_stack_[(3) - (1)].node),(yysemantic_stack_[(3) - (3)].node)); }
    break;


/* Line 670 of lalr1.cc  */
#line 748 "Grammar.tab.cpp"
      default:
        break;
      }

    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */
        if (yychar <= yyeof_)
          {
            /* Return failure if at end of input.  */
            if (yychar == yyeof_)
              YYABORT;
          }
        else
          {
            yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
            yychar = yyempty_;
          }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	  YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULL;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char parser::yypact_ninf_ = -94;
  const short int
  parser::yypact_[] =
  {
        47,   -14,   -94,    93,    87,   -20,   150,   159,    13,    87,
      87,    87,    87,   -94,    57,   -94,   -94,   -94,   -94,   -94,
     173,    87,   141,   -94,   -94,   123,   190,   -94,    87,   207,
      87,   223,   -11,     5,     5,   -94,   239,   -94,   -94,   -94,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,   -94,   284,   -94,   284,   -16,   -94,   -94,   -94,
     254,    -9,   269,    -8,    33,   -94,   295,   305,   315,   315,
     315,   315,   315,   315,     5,     5,   -94,   -94,   -94,    87,
     -10,   132,    -6,   132,   -94,    -4,     0,   284,     2,    19,
       3,   -94,    21,   -94,     6,    64,   132,    39,   132,    68,
      42,   -94,    73,    52,   -94,   -94,    68,    56,   132,   -94,
      60,   -94,   132,   -94
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         0,    29,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,     4,     2,    13,    14,    12,
       0,     0,     0,    24,    26,     0,     0,    16,     0,     0,
       0,     0,     0,    37,    36,    42,     0,     1,     5,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    39,    30,    49,     0,    25,    27,    15,
       0,     0,     0,     0,     0,    38,    41,    40,    48,    47,
      45,    46,    43,    44,    33,    32,    35,    34,    31,     0,
      38,     0,    38,     0,     8,     0,     0,    50,     0,    19,
       0,    23,     0,     9,     0,     0,     0,     0,     0,     0,
       0,    10,    18,     0,    22,     7,     0,     0,     0,     6,
       0,    21,     0,    20
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  parser::yypgoto_[] =
  {
       -94,   -94,    74,   -94,    -3,   -94,   -94,   -93,   -94,    -2,
     -94
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  parser::yydefgoto_[] =
  {
        -1,    14,    15,    86,    16,    17,    18,    19,    25,    20,
      56
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char parser::yytable_ninf_ = -1;
  const signed char
  parser::yytable_[] =
  {
        24,    21,    26,    93,    29,    31,   105,    33,    34,    35,
      36,    39,    27,   109,    78,    22,    32,    79,    64,    53,
      55,    88,    58,    81,    83,    90,    60,    92,    62,    97,
      94,    50,    51,    95,    96,    98,    84,   100,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       1,     2,     3,    99,     4,     5,     6,    37,     7,     8,
       1,     2,     3,    85,     4,     5,     6,   101,     7,     8,
     103,     9,    10,     3,   106,    11,    12,    87,    89,    13,
      91,     9,    10,   107,   108,    11,    12,   110,    38,    13,
       1,     2,   112,   102,     0,   104,     1,     2,     3,    23,
       4,     5,     6,     0,     7,   111,     0,     0,     0,   113,
       0,     9,    10,     0,     0,    11,    12,     9,    10,     0,
       0,    11,    12,     0,     0,    13,     1,     2,     3,    57,
       4,     5,     6,     0,     7,     1,     2,     3,     0,     4,
       5,     6,     0,     7,     1,     2,     0,     9,    10,     0,
       0,    11,    12,     1,     2,    13,     9,    10,     0,     0,
      11,    12,     1,     2,    13,     9,    10,     0,     0,    11,
      12,    54,     0,     0,     9,    10,     0,     0,    11,    28,
       0,     0,     0,     9,    10,     0,     0,    11,    30,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,     0,     0,    52,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,     0,     0,
       0,     0,    59,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,     0,     0,     0,    61,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,     0,    63,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,     0,     0,    65,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,     0,     0,    80,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,     0,     0,    82,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51
  };

  /* YYCHECK.  */
  const signed char
  parser::yycheck_[] =
  {
         3,    15,     4,     3,     6,     7,    99,     9,    10,    11,
      12,    14,    32,   106,    30,    29,     3,    33,    29,    21,
      22,    31,    25,    32,    32,    31,    28,    31,    30,    10,
      30,    26,    27,    33,    32,    32,     3,    31,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
       3,     4,     5,    32,     7,     8,     9,     0,    11,    12,
       3,     4,     5,    30,     7,     8,     9,     3,    11,    12,
      31,    24,    25,     5,    32,    28,    29,    79,    81,    32,
      83,    24,    25,    10,    32,    28,    29,    31,    14,    32,
       3,     4,    32,    96,    -1,    98,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,   108,    -1,    -1,    -1,   112,
      -1,    24,    25,    -1,    -1,    28,    29,    24,    25,    -1,
      -1,    28,    29,    -1,    -1,    32,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,     3,     4,     5,    -1,     7,
       8,     9,    -1,    11,     3,     4,    -1,    24,    25,    -1,
      -1,    28,    29,     3,     4,    32,    24,    25,    -1,    -1,
      28,    29,     3,     4,    32,    24,    25,    -1,    -1,    28,
      29,    30,    -1,    -1,    24,    25,    -1,    -1,    28,    29,
      -1,    -1,    -1,    24,    25,    -1,    -1,    28,    29,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    32,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    32,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,     3,     4,     5,     7,     8,     9,    11,    12,    24,
      25,    28,    29,    32,    35,    36,    38,    39,    40,    41,
      43,    15,    29,     6,    38,    42,    43,    32,    29,    43,
      29,    43,     3,    43,    43,    43,    43,     0,    36,    38,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    32,    43,    30,    43,    44,     6,    38,    32,
      43,    31,    43,    31,    29,    30,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    30,    33,
      30,    32,    30,    32,     3,    30,    37,    43,    31,    38,
      31,    38,    31,     3,    30,    33,    32,    10,    32,    32,
      31,     3,    38,    31,    38,    41,    32,    10,    32,    41,
      31,    38,    32,    38
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    61,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,    40,
      41,    58,    10,    44
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    34,    35,    35,    35,    35,    36,    36,    37,    37,
      37,    38,    38,    38,    38,    38,    38,    38,    39,    39,
      39,    39,    40,    40,    41,    41,    42,    42,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    44,
      44
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     8,     7,     1,     2,
       3,     2,     1,     1,     1,     3,     2,     1,     7,     5,
      11,     9,     7,     5,     2,     3,     1,     2,     1,     1,
       3,     4,     3,     3,     3,     3,     2,     2,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     1,
       3
  };


  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const parser::yytname_[] =
  {
    "$end", "error", "$undefined", "IDENTIFIER", "NUMBER", "INDENT",
  "DEDENT", "RETURN", "BREAK", "IF", "ELSE", "WHILE", "FUNCTION", "ERROR",
  "IFPREC", "'='", "OR", "AND", "NEQUAL", "EQUAL", "LT", "LTE", "GT",
  "GTE", "MINUS", "PLUS", "DIV", "MULT", "NOT", "'('", "')'", "':'",
  "'\\n'", "','", "$accept", "compileUnit", "function_definition", "fargs",
  "statement", "if_statement", "while_statement", "compound_statement",
  "statement_list", "expression", "args", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        35,     0,    -1,    38,    -1,    35,    38,    -1,    36,    -1,
      35,    36,    -1,    12,     3,    29,    37,    30,    31,    32,
      41,    -1,    12,     3,    29,    30,    31,    32,    41,    -1,
       3,    -1,    37,     3,    -1,    37,    33,     3,    -1,    43,
      32,    -1,    41,    -1,    39,    -1,    40,    -1,     7,    43,
      32,    -1,     8,    32,    -1,    32,    -1,     9,    29,    43,
      30,    31,    32,    38,    -1,     9,    43,    31,    32,    38,
      -1,     9,    29,    43,    30,    31,    32,    38,    10,    31,
      32,    38,    -1,     9,    43,    31,    32,    38,    10,    31,
      32,    38,    -1,    11,    29,    43,    30,    31,    32,    38,
      -1,    11,    43,    31,    32,    38,    -1,     5,     6,    -1,
       5,    42,     6,    -1,    38,    -1,    42,    38,    -1,     4,
      -1,     3,    -1,     3,    29,    30,    -1,     3,    29,    44,
      30,    -1,    43,    25,    43,    -1,    43,    24,    43,    -1,
      43,    27,    43,    -1,    43,    26,    43,    -1,    25,    43,
      -1,    24,    43,    -1,    29,    43,    30,    -1,     3,    15,
      43,    -1,    43,    17,    43,    -1,    43,    16,    43,    -1,
      28,    43,    -1,    43,    22,    43,    -1,    43,    23,    43,
      -1,    43,    20,    43,    -1,    43,    21,    43,    -1,    43,
      19,    43,    -1,    43,    18,    43,    -1,    43,    -1,    44,
      33,    43,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    22,    30,    32,
      35,    39,    42,    44,    46,    48,    52,    55,    57,    65,
      71,    83,    93,   101,   107,   110,   114,   116,   119,   121,
     123,   127,   132,   136,   140,   144,   148,   151,   154,   158,
     162,   166,   170,   173,   177,   181,   185,   189,   193,   197,
     199
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  parser::yyrline_[] =
  {
         0,    47,    47,    48,    49,    50,    53,    55,    59,    60,
      61,    64,    65,    66,    67,    68,    69,    70,    73,    74,
      75,    76,    79,    80,    83,    84,    87,    88,    91,    92,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   115,
     116
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    30,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,     2,
       2,    15,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 342;
  const int parser::yynnts_ = 11;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 37;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 34;

  const unsigned int parser::yyuser_token_number_max_ = 282;
  const parser::token_number_type parser::yyundef_token_ = 2;


} // yy
/* Line 1141 of lalr1.cc  */
#line 1399 "Grammar.tab.cpp"
/* Line 1142 of lalr1.cc  */
#line 119 "Grammar.y"


namespace yy
{
	void parser::error(yy::location const &loc, const string &message)
	{
		std::cerr << "error at " << loc << ": " << message << std::endl;
	}
}
