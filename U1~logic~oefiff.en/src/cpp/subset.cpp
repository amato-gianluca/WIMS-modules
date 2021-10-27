target=subset

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
\text{atype=random(1,2)}
\text{atext=item(\atype,BELONGS,NBELONGS)}
\text{btype=random(1,2)}
\text{btext=item(\btype,BELONGS,NBELONGS)}
\text{gA=\gtype=1?A:B}
\text{gB=\gtype=1?B:A}
\text{good=item(\atype,\gsuf,\gnec)}
\text{good=\atype==\btype?\good:\non}

\statement{STATEMENT}

\choice{}{\good}{\choices}
