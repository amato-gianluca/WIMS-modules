target=iff3

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\range{-5..5}
\computeanswer{yes}
\precision{10000}

\text{iff=NECSUF}
\text{nec=NEC}
\text{suf=SUF}
\text{non=NONNECSUF}
\integer{gtype=random(0,1)}
\text{gnec=\gtype=1?\nec:\suf}
\text{gsuf=\gtype=1?\suf:\nec}
\text{choices=\iff,\nec,\suf,\non}
\integer{type=random(1,2,3)}
\text{sign=item(\type,IFF,IF,ONLYIF)}
\text{good=item(\type,\iff,\gsuf,\gnec)}
\text{gA=\gtype=1?A:B}
\text{gB=\gtype=1?B:A}

\statement{STATEMENT}

\choice{}{\good}{\choices}
