target=subset

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\range{-5..5}
\computeanswer{yes}
\precision{10000}

\text{iff=\name_NECSUF}
\text{nec=\name_NEC}
\text{suf=\name_SUF}
\text{non=\name_NONNECSUF}
\integer{gtype=random(0,1)}
\text{gnec=\gtype=1?\nec:\suf}
\text{gsuf=\gtype=1?\suf:\nec}
\text{choices=\iff,\nec,\suf,\non}
\text{atype=random(1,2)}
\text{atext=item(\atype,\name_belongs,\name_nbelongs)}
\text{btype=random(1,2)}
\text{btext=item(\btype,\name_belongs,\name_nbelongs)}
\text{gA=\gtype=1?A:B}
\text{gB=\gtype=1?B:A}
\text{good=item(\atype,\gsuf,\gnec)}
\text{good=\atype==\btype?\good:\non}

#include "lang.inc"
\statement{\name_statement}

\choice{}{\good}{\choices}
