%option noyywrap
%option noinput
%option nounput

%{
#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <string>
#include "naredba.hpp"
#include "izraz.hpp"
#include "parser.tab.hpp"

%}

%%
program     return program_token;
begin       return begin_token;
end         return end_token;
var         return var_token;
Integer     return integer_token;
Real        return real_token;
Boolean     return boolean_token;
true        return true_token;
false       return false_token;
if          return if_token;
then        return then_token;
else        return else_token;
while       return while_token;
do          return do_token;
for         return for_token;
to          return to_token;
downto      return downto_token;
write       return write_token;
read        return read_token;
":="        return dodela_token;
"<="        return manjeJednako_token;
">="        return veceJednako_token;
"="         return jesteJednako_token;
"<>"        return nijeJednako_token;

[1-9][0-9]* {
    yylval.i=atoi(yytext);
    return int_token;
}
[0-9]+[.][0-9]+ {
    yylval.f=atof(yytext);
    return float_token;
}

[a-zA-Z_0-9]+ {
    yylval.s=new string(yytext);
    return id_token;
}

['][^']*['] {
    yylval.s=new string(yytext);
    return string_token;
}

[+*-/();:,.=%<>] return *yytext;

[\t\n ] { }

. {
    cerr << "Leksicka greska: Neprepoznat karakter -> " << *yytext << endl;
    exit(EXIT_FAILURE);
}
%%