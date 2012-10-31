/* A recursive-descent parser generated by peg 0.1.9 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 14
 
//uncomment to get more debug instrumentation
//
//#define YY_DEBUG 

#include <ruby.h>

#define EMIT(sym, data) \
  rb_ary_push(ctx->rb_tokens, rb_ary_new3(2, ID2SYM(rb_intern(sym)), data)); 

#define yy_rb_str rb_str_new(yytext, yyleng)

#define YYSTYPE VALUE
#define YY_CTX_LOCAL
#define YY_CTX_MEMBERS VALUE rb_tokens; char *p; int p_len;

#define YY_INPUT(buf, result, max_size) { \
    result = ctx->p_len;  \
    if (result>0 || EOF == ctx->p[0]) { \
      if (max_size < result) { result = max_size; } \
      strncpy(buf, ctx->p, result); \
      buf[result] = '\0'; \
      yyprintf((stderr, "\nREFILLING %d chars now:<%s>", result, buf));      \
      ctx->p += result; ctx->p_len -= result; \
      yyprintf((stderr, "\nREFILLING DONE size left: %d <%s>", ctx->p_len, ctx->p));      \
    } \
  }

#ifndef YY_LOCAL
#define YY_LOCAL(T)	static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)	static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)	static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)	T
#endif
#ifndef YYPARSE
#define YYPARSE		yyparse
#endif
#ifndef YYPARSEFROM
#define YYPARSEFROM	yyparsefrom
#endif
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size)			\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#ifndef YY_BEGIN
#define YY_BEGIN	( ctx->begin= ctx->pos, 1)
#endif
#ifndef YY_END
#define YY_END		( ctx->end= ctx->pos, 1)
#endif
#ifdef YY_DEBUG
# define yyprintf(args)	fprintf args
#else
# define yyprintf(args)
#endif
#ifndef YYSTYPE
#define YYSTYPE	int
#endif

#ifndef YY_PART

typedef struct _yycontext yycontext;
typedef void (*yyaction)(yycontext *ctx, char *yytext, int yyleng);
typedef struct _yythunk { int begin, end;  yyaction  action;  struct _yythunk *next; } yythunk;

struct _yycontext {
  char     *buf;
  int       buflen;
  int       pos;
  int       limit;
  char     *text;
  int       textlen;
  int       begin;
  int       end;
  int       textmax;
  yythunk  *thunks;
  int       thunkslen;
  int       thunkpos;
  YYSTYPE   yy;
  YYSTYPE  *val;
  YYSTYPE  *vals;
  int       valslen;
#ifdef YY_CTX_MEMBERS
  YY_CTX_MEMBERS
#endif
};

#ifdef YY_CTX_LOCAL
#define YY_CTX_PARAM_	yycontext *yyctx,
#define YY_CTX_PARAM	yycontext *yyctx
#define YY_CTX_ARG_	yyctx,
#define YY_CTX_ARG	yyctx
#else
#define YY_CTX_PARAM_
#define YY_CTX_PARAM
#define YY_CTX_ARG_
#define YY_CTX_ARG
yycontext yyctx0;
yycontext *yyctx= &yyctx0;
#endif

YY_LOCAL(int) yyrefill(yycontext *ctx)
{
  int yyn;
  while (ctx->buflen - ctx->pos < 512)
    {
      ctx->buflen *= 2;
      ctx->buf= (char *)realloc(ctx->buf, ctx->buflen);
    }
  YY_INPUT((ctx->buf + ctx->pos), yyn, (ctx->buflen - ctx->pos));
  if (!yyn) return 0;
  ctx->limit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(yycontext *ctx)
{
  if (ctx->pos >= ctx->limit && !yyrefill(ctx)) return 0;
  ++ctx->pos;
  return 1;
}

YY_LOCAL(int) yymatchChar(yycontext *ctx, int c)
{
  if (ctx->pos >= ctx->limit && !yyrefill(ctx)) return 0;
  if ((unsigned char)ctx->buf[ctx->pos] == c)
    {
      ++ctx->pos;
      yyprintf((stderr, "  ok   yymatchChar(ctx, %c) @ %s\n", c, ctx->buf+ctx->pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchChar(ctx, %c) @ %s\n", c, ctx->buf+ctx->pos));
  return 0;
}

YY_LOCAL(int) yymatchString(yycontext *ctx, char *s)
{
  int yysav= ctx->pos;
  while (*s)
    {
      if (ctx->pos >= ctx->limit && !yyrefill(ctx)) return 0;
      if (ctx->buf[ctx->pos] != *s)
        {
          ctx->pos= yysav;
          return 0;
        }
      ++s;
      ++ctx->pos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(yycontext *ctx, unsigned char *bits)
{
  int c;
  if (ctx->pos >= ctx->limit && !yyrefill(ctx)) return 0;
  c= (unsigned char)ctx->buf[ctx->pos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++ctx->pos;
      yyprintf((stderr, "  ok   yymatchClass @ %s\n", ctx->buf+ctx->pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchClass @ %s\n", ctx->buf+ctx->pos));
  return 0;
}

YY_LOCAL(void) yyDo(yycontext *ctx, yyaction action, int begin, int end)
{
  while (ctx->thunkpos >= ctx->thunkslen)
    {
      ctx->thunkslen *= 2;
      ctx->thunks= (yythunk *)realloc(ctx->thunks, sizeof(yythunk) * ctx->thunkslen);
    }
  ctx->thunks[ctx->thunkpos].begin=  begin;
  ctx->thunks[ctx->thunkpos].end=    end;
  ctx->thunks[ctx->thunkpos].action= action;
  ++ctx->thunkpos;
}

YY_LOCAL(int) yyText(yycontext *ctx, int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (ctx->textlen < (yyleng + 1))
	{
	  ctx->textlen *= 2;
	  ctx->text= (char *)realloc(ctx->text, ctx->textlen);
	}
      memcpy(ctx->text, ctx->buf + begin, yyleng);
    }
  ctx->text[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(yycontext *ctx)
{
  int pos;
  for (pos= 0;  pos < ctx->thunkpos;  ++pos)
    {
      yythunk *thunk= &ctx->thunks[pos];
      int yyleng= thunk->end ? yyText(ctx, thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %p %s\n", pos, thunk->action, ctx->text));
      thunk->action(ctx, ctx->text, yyleng);
    }
  ctx->thunkpos= 0;
}

YY_LOCAL(void) yyCommit(yycontext *ctx)
{
  if ((ctx->limit -= ctx->pos))
    {
      memmove(ctx->buf, ctx->buf + ctx->pos, ctx->limit);
    }
  ctx->begin -= ctx->pos;
  ctx->end -= ctx->pos;
  ctx->pos= ctx->thunkpos= 0;
}

YY_LOCAL(int) yyAccept(yycontext *ctx, int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone(ctx);
      yyCommit(ctx);
    }
  return 1;
}

YY_LOCAL(void) yyPush(yycontext *ctx, char *text, int count)  { ctx->val += count; }
YY_LOCAL(void) yyPop(yycontext *ctx, char *text, int count)   { ctx->val -= count; }
YY_LOCAL(void) yySet(yycontext *ctx, char *text, int count)   { ctx->val[count]= ctx->yy; }

#endif /* YY_PART */

#define	YYACCEPT	yyAccept(ctx, yythunkpos0)

YY_RULE(int) yy_digit(yycontext *ctx); /* 14 */
YY_RULE(int) yy_float(yycontext *ctx); /* 13 */
YY_RULE(int) yy_integer(yycontext *ctx); /* 12 */
YY_RULE(int) yy_rangelet(yycontext *ctx); /* 11 */
YY_RULE(int) yy_identifier(yycontext *ctx); /* 10 */
YY_RULE(int) yy_accessors(yycontext *ctx); /* 9 */
YY_RULE(int) yy_numeric(yycontext *ctx); /* 8 */
YY_RULE(int) yy_string(yycontext *ctx); /* 7 */
YY_RULE(int) yy_const(yycontext *ctx); /* 6 */
YY_RULE(int) yy_hash(yycontext *ctx); /* 5 */
YY_RULE(int) yy_range(yycontext *ctx); /* 4 */
YY_RULE(int) yy_entity(yycontext *ctx); /* 3 */
YY_RULE(int) yy_primary(yycontext *ctx); /* 2 */
YY_RULE(int) yy_grammar(yycontext *ctx); /* 1 */

YY_ACTION(void) yy_4_const(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_4_const\n"));
   yy = Qnil; ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_3_const(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_3_const\n"));
   yy = Qnil; ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_2_const(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_2_const\n"));
   yy = Qfalse; ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_const(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_1_const\n"));
   yy = Qtrue; ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_integer(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_1_integer\n"));
   yy = rb_funcall(rb_cObject, rb_intern("Integer"), 1, yy_rb_str); ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_float(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_1_float\n"));
   yy = rb_funcall(rb_cObject, rb_intern("Float"), 1, yy_rb_str); ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_2_string(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_2_string\n"));
   yy = yy_rb_str; ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_string(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_1_string\n"));
   yy = yy_rb_str; ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_range(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_1_range\n"));
   EMIT("range", Qnil); ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_rangelet(yycontext *ctx, char *yytext, int yyleng)
{
#define var ctx->val[-1]
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_1_rangelet\n"));
   EMIT("id", var); ;
#undef yythunkpos
#undef yypos
#undef yy
#undef var
}
YY_ACTION(void) yy_1_entity(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_1_entity\n"));
   EMIT("id", yy_rb_str); EMIT("lookup", Qnil); ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_5_accessors(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_5_accessors\n"));
   EMIT("id", yy_rb_str); EMIT("call", Qnil); ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_4_accessors(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_4_accessors\n"));
   EMIT("buildin", rb_str_new2("size")); ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_3_accessors(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_3_accessors\n"));
   EMIT("buildin", rb_str_new2("last")); ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_2_accessors(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_2_accessors\n"));
   EMIT("buildin", rb_str_new2("first")); ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_accessors(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_1_accessors\n"));
   EMIT("call", Qnil); ;
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_3_primary(yycontext *ctx, char *yytext, int yyleng)
{
#define var ctx->val[-1]
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_3_primary\n"));
   EMIT("id", var); ;
#undef yythunkpos
#undef yypos
#undef yy
#undef var
}
YY_ACTION(void) yy_2_primary(yycontext *ctx, char *yytext, int yyleng)
{
#define var ctx->val[-1]
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_2_primary\n"));
   EMIT("id", var); ;
#undef yythunkpos
#undef yypos
#undef yy
#undef var
}
YY_ACTION(void) yy_1_primary(yycontext *ctx, char *yytext, int yyleng)
{
#define var ctx->val[-1]
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_1_primary\n"));
   EMIT("id", var); ;
#undef yythunkpos
#undef yypos
#undef yy
#undef var
}
YY_ACTION(void) yy_1_grammar(yycontext *ctx, char *yytext, int yyleng)
{
#define yy ctx->yy
#define yypos ctx->pos
#define yythunkpos ctx->thunkpos
  yyprintf((stderr, "do yy_1_grammar\n"));
   EMIT("lookup", Qnil); ;
#undef yythunkpos
#undef yypos
#undef yy
}

YY_RULE(int) yy_digit(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "digit"));  if (!yymatchClass(ctx, (unsigned char *)"\000\000\000\000\000\000\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l1;
  yyprintf((stderr, "  ok   %s @ %s\n", "digit", ctx->buf+ctx->pos));
  return 1;
  l1:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "digit", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_float(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "float"));  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_BEGIN)) goto l2;
  {  int yypos3= ctx->pos, yythunkpos3= ctx->thunkpos;  if (!yymatchChar(ctx, '-')) goto l3;  goto l4;
  l3:;	  ctx->pos= yypos3; ctx->thunkpos= yythunkpos3;
  }
  l4:;	  if (!yy_digit(ctx)) goto l2;  if (!yymatchChar(ctx, '.')) goto l2;  if (!yy_digit(ctx)) goto l2;
  l5:;	
  {  int yypos6= ctx->pos, yythunkpos6= ctx->thunkpos;  if (!yy_digit(ctx)) goto l6;  goto l5;
  l6:;	  ctx->pos= yypos6; ctx->thunkpos= yythunkpos6;
  }  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_END)) goto l2;  yyDo(ctx, yy_1_float, ctx->begin, ctx->end);
  yyprintf((stderr, "  ok   %s @ %s\n", "float", ctx->buf+ctx->pos));
  return 1;
  l2:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "float", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_integer(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "integer"));  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_BEGIN)) goto l7;
  {  int yypos8= ctx->pos, yythunkpos8= ctx->thunkpos;  if (!yymatchChar(ctx, '-')) goto l8;  goto l9;
  l8:;	  ctx->pos= yypos8; ctx->thunkpos= yythunkpos8;
  }
  l9:;	  if (!yy_digit(ctx)) goto l7;
  l10:;	
  {  int yypos11= ctx->pos, yythunkpos11= ctx->thunkpos;  if (!yy_digit(ctx)) goto l11;  goto l10;
  l11:;	  ctx->pos= yypos11; ctx->thunkpos= yythunkpos11;
  }  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_END)) goto l7;  yyDo(ctx, yy_1_integer, ctx->begin, ctx->end);
  yyprintf((stderr, "  ok   %s @ %s\n", "integer", ctx->buf+ctx->pos));
  return 1;
  l7:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "integer", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_rangelet(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;  yyDo(ctx, yyPush, 1, 0);
  yyprintf((stderr, "%s\n", "rangelet"));
  {  int yypos13= ctx->pos, yythunkpos13= ctx->thunkpos;  if (!yy_integer(ctx)) goto l14;  yyDo(ctx, yySet, -1, 0);  yyDo(ctx, yy_1_rangelet, ctx->begin, ctx->end);  goto l13;
  l14:;	  ctx->pos= yypos13; ctx->thunkpos= yythunkpos13;  if (!yy_entity(ctx)) goto l12;
  }
  l13:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "rangelet", ctx->buf+ctx->pos));  yyDo(ctx, yyPop, 1, 0);
  return 1;
  l12:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "rangelet", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_identifier(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "identifier"));  if (!yymatchClass(ctx, (unsigned char *)"\000\000\000\000\000\000\000\000\376\377\377\007\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l15;  if (!yymatchClass(ctx, (unsigned char *)"\000\000\000\000\000\040\377\003\376\377\377\207\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l15;
  l16:;	
  {  int yypos17= ctx->pos, yythunkpos17= ctx->thunkpos;  if (!yymatchClass(ctx, (unsigned char *)"\000\000\000\000\000\040\377\003\376\377\377\207\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l17;  goto l16;
  l17:;	  ctx->pos= yypos17; ctx->thunkpos= yythunkpos17;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "identifier", ctx->buf+ctx->pos));
  return 1;
  l15:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "identifier", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_accessors(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "accessors"));
  {  int yypos19= ctx->pos, yythunkpos19= ctx->thunkpos;  if (!yy_hash(ctx)) goto l20;  yyDo(ctx, yy_1_accessors, ctx->begin, ctx->end);  goto l19;
  l20:;	  ctx->pos= yypos19; ctx->thunkpos= yythunkpos19;  if (!yymatchString(ctx, ".first")) goto l21;  yyDo(ctx, yy_2_accessors, ctx->begin, ctx->end);  goto l19;
  l21:;	  ctx->pos= yypos19; ctx->thunkpos= yythunkpos19;  if (!yymatchString(ctx, ".last")) goto l22;  yyDo(ctx, yy_3_accessors, ctx->begin, ctx->end);  goto l19;
  l22:;	  ctx->pos= yypos19; ctx->thunkpos= yythunkpos19;  if (!yymatchString(ctx, ".size")) goto l23;  yyDo(ctx, yy_4_accessors, ctx->begin, ctx->end);  goto l19;
  l23:;	  ctx->pos= yypos19; ctx->thunkpos= yythunkpos19;  if (!yymatchChar(ctx, '.')) goto l18;  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_BEGIN)) goto l18;  if (!yy_identifier(ctx)) goto l18;  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_END)) goto l18;  yyDo(ctx, yy_5_accessors, ctx->begin, ctx->end);
  }
  l19:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "accessors", ctx->buf+ctx->pos));
  return 1;
  l18:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "accessors", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_numeric(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "numeric"));
  {  int yypos25= ctx->pos, yythunkpos25= ctx->thunkpos;  if (!yy_float(ctx)) goto l26;  goto l25;
  l26:;	  ctx->pos= yypos25; ctx->thunkpos= yythunkpos25;  if (!yy_integer(ctx)) goto l24;
  }
  l25:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "numeric", ctx->buf+ctx->pos));
  return 1;
  l24:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "numeric", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_string(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "string"));
  {  int yypos28= ctx->pos, yythunkpos28= ctx->thunkpos;  if (!yymatchClass(ctx, (unsigned char *)"\000\000\000\000\200\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l29;  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_BEGIN)) goto l29;
  l30:;	
  {  int yypos31= ctx->pos, yythunkpos31= ctx->thunkpos;
  {  int yypos32= ctx->pos, yythunkpos32= ctx->thunkpos;  if (!yymatchClass(ctx, (unsigned char *)"\000\000\000\000\200\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l32;  goto l31;
  l32:;	  ctx->pos= yypos32; ctx->thunkpos= yythunkpos32;
  }  if (!yymatchDot(ctx)) goto l31;  goto l30;
  l31:;	  ctx->pos= yypos31; ctx->thunkpos= yythunkpos31;
  }  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_END)) goto l29;  if (!yymatchClass(ctx, (unsigned char *)"\000\000\000\000\200\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l29;  yyDo(ctx, yy_1_string, ctx->begin, ctx->end);  goto l28;
  l29:;	  ctx->pos= yypos28; ctx->thunkpos= yythunkpos28;  if (!yymatchClass(ctx, (unsigned char *)"\000\000\000\000\004\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l27;  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_BEGIN)) goto l27;
  l33:;	
  {  int yypos34= ctx->pos, yythunkpos34= ctx->thunkpos;
  {  int yypos35= ctx->pos, yythunkpos35= ctx->thunkpos;  if (!yymatchClass(ctx, (unsigned char *)"\000\000\000\000\004\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l35;  goto l34;
  l35:;	  ctx->pos= yypos35; ctx->thunkpos= yythunkpos35;
  }  if (!yymatchDot(ctx)) goto l34;  goto l33;
  l34:;	  ctx->pos= yypos34; ctx->thunkpos= yythunkpos34;
  }  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_END)) goto l27;  if (!yymatchClass(ctx, (unsigned char *)"\000\000\000\000\004\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l27;  yyDo(ctx, yy_2_string, ctx->begin, ctx->end);
  }
  l28:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "string", ctx->buf+ctx->pos));
  return 1;
  l27:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "string", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_const(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "const"));
  {  int yypos37= ctx->pos, yythunkpos37= ctx->thunkpos;  if (!yymatchString(ctx, "true")) goto l38;  yyDo(ctx, yy_1_const, ctx->begin, ctx->end);  goto l37;
  l38:;	  ctx->pos= yypos37; ctx->thunkpos= yythunkpos37;  if (!yymatchString(ctx, "false")) goto l39;  yyDo(ctx, yy_2_const, ctx->begin, ctx->end);  goto l37;
  l39:;	  ctx->pos= yypos37; ctx->thunkpos= yythunkpos37;  if (!yymatchString(ctx, "nil")) goto l40;  yyDo(ctx, yy_3_const, ctx->begin, ctx->end);  goto l37;
  l40:;	  ctx->pos= yypos37; ctx->thunkpos= yythunkpos37;  if (!yymatchString(ctx, "null")) goto l36;  yyDo(ctx, yy_4_const, ctx->begin, ctx->end);
  }
  l37:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "const", ctx->buf+ctx->pos));
  return 1;
  l36:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "const", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_hash(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "hash"));  if (!yymatchChar(ctx, '[')) goto l41;
  {  int yypos42= ctx->pos, yythunkpos42= ctx->thunkpos;  if (!yy_primary(ctx)) goto l43;  goto l42;
  l43:;	  ctx->pos= yypos42; ctx->thunkpos= yythunkpos42;  if (!yy_entity(ctx)) goto l41;
  }
  l42:;	  if (!yymatchChar(ctx, ']')) goto l41;
  yyprintf((stderr, "  ok   %s @ %s\n", "hash", ctx->buf+ctx->pos));
  return 1;
  l41:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "hash", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_range(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "range"));  if (!yymatchChar(ctx, '(')) goto l44;  if (!yy_rangelet(ctx)) goto l44;  if (!yymatchString(ctx, "..")) goto l44;  if (!yy_rangelet(ctx)) goto l44;  if (!yymatchChar(ctx, ')')) goto l44;  yyDo(ctx, yy_1_range, ctx->begin, ctx->end);
  yyprintf((stderr, "  ok   %s @ %s\n", "range", ctx->buf+ctx->pos));
  return 1;
  l44:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "range", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_entity(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "entity"));  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_BEGIN)) goto l45;  if (!yy_identifier(ctx)) goto l45;  yyText(ctx, ctx->begin, ctx->end);  if (!(YY_END)) goto l45;  yyDo(ctx, yy_1_entity, ctx->begin, ctx->end);
  l46:;	
  {  int yypos47= ctx->pos, yythunkpos47= ctx->thunkpos;  if (!yy_accessors(ctx)) goto l47;  goto l46;
  l47:;	  ctx->pos= yypos47; ctx->thunkpos= yythunkpos47;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "entity", ctx->buf+ctx->pos));
  return 1;
  l45:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "entity", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_primary(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;  yyDo(ctx, yyPush, 1, 0);
  yyprintf((stderr, "%s\n", "primary"));
  {  int yypos49= ctx->pos, yythunkpos49= ctx->thunkpos;  if (!yy_const(ctx)) goto l50;  yyDo(ctx, yySet, -1, 0);  yyDo(ctx, yy_1_primary, ctx->begin, ctx->end);  goto l49;
  l50:;	  ctx->pos= yypos49; ctx->thunkpos= yythunkpos49;  if (!yy_string(ctx)) goto l51;  yyDo(ctx, yySet, -1, 0);  yyDo(ctx, yy_2_primary, ctx->begin, ctx->end);  goto l49;
  l51:;	  ctx->pos= yypos49; ctx->thunkpos= yythunkpos49;  if (!yy_numeric(ctx)) goto l48;  yyDo(ctx, yySet, -1, 0);  yyDo(ctx, yy_3_primary, ctx->begin, ctx->end);
  }
  l49:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "primary", ctx->buf+ctx->pos));  yyDo(ctx, yyPop, 1, 0);
  return 1;
  l48:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "primary", ctx->buf+ctx->pos));
  return 0;
}
YY_RULE(int) yy_grammar(yycontext *ctx)
{  int yypos0= ctx->pos, yythunkpos0= ctx->thunkpos;
  yyprintf((stderr, "%s\n", "grammar"));
  {  int yypos53= ctx->pos, yythunkpos53= ctx->thunkpos;  if (!yy_primary(ctx)) goto l54;  goto l53;
  l54:;	  ctx->pos= yypos53; ctx->thunkpos= yythunkpos53;  if (!yy_entity(ctx)) goto l55;  goto l53;
  l55:;	  ctx->pos= yypos53; ctx->thunkpos= yythunkpos53;  if (!yy_range(ctx)) goto l56;  goto l53;
  l56:;	  ctx->pos= yypos53; ctx->thunkpos= yythunkpos53;  if (!yy_hash(ctx)) goto l52;  yyDo(ctx, yy_1_grammar, ctx->begin, ctx->end);
  }
  l53:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "grammar", ctx->buf+ctx->pos));
  return 1;
  l52:;	  ctx->pos= yypos0; ctx->thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "grammar", ctx->buf+ctx->pos));
  return 0;
}

#ifndef YY_PART

typedef int (*yyrule)(yycontext *ctx);

YY_PARSE(int) YYPARSEFROM(YY_CTX_PARAM_ yyrule yystart)
{
  int yyok;
  if (!yyctx->buflen)
    {
      yyctx->buflen= 1024;
      yyctx->buf= (char *)malloc(yyctx->buflen);
      yyctx->textlen= 1024;
      yyctx->text= (char *)malloc(yyctx->textlen);
      yyctx->thunkslen= 32;
      yyctx->thunks= (yythunk *)malloc(sizeof(yythunk) * yyctx->thunkslen);
      yyctx->valslen= 32;
      yyctx->vals= (YYSTYPE *)malloc(sizeof(YYSTYPE) * yyctx->valslen);
      yyctx->begin= yyctx->end= yyctx->pos= yyctx->limit= yyctx->thunkpos= 0;
    }
  yyctx->begin= yyctx->end= yyctx->pos;
  yyctx->thunkpos= 0;
  yyctx->val= yyctx->vals;
  yyok= yystart(yyctx);
  if (yyok) yyDone(yyctx);
  yyCommit(yyctx);
  return yyok;
}

YY_PARSE(int) YYPARSE(YY_CTX_PARAM)
{
  return YYPARSEFROM(YY_CTX_ARG_ yy_grammar);
}

#endif
 

VALUE liquid_context_parse_impl(VALUE self, VALUE text) {
  char *p; 
  int len; 
  yycontext ctx;  

  memset(&ctx, 0, sizeof(yycontext));
  ctx.p = RSTRING_PTR(text);  
  ctx.p_len = (int) RSTRING_LEN(text);
  ctx.rb_tokens = rb_ary_new();

  yyprintf((stderr, "About to start: %s %d\n", ctx.p, ctx.p_len));
  
  //while(yyparse(&ctx))
  // ;
  
  yyparse(&ctx);

  return ctx.rb_tokens;
}
