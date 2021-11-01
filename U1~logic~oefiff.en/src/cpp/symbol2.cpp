target=symbol2

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\text{iff=\name_IFF}
\text{nec=\name_IF}
\text{suf=\name_ONLYIF}
\integer{gtype=random(0,1)}
\text{gnec=\gtype=1?\nec:\suf}
\text{gsuf=\gtype=1?\suf:\nec}
\text{choices=\iff,\nec,\suf}
\integer{type=random(1,2,3)}
\text{sign=item(\type,&lt;=&gt;,=&gt;,&lt;=)}
\text{gA=\gtype=1?A:B}
\text{gB=\gtype=1?B:A}
\integer{ttype=random(1,2)}
\text{ttext=item(\ttype,\name_holds,\name_nholds)}
\text{tnec=item(\ttype,\gnec,\gsuf)}
\text{tsuf=item(\ttype,\gsuf,\gnec)}
\text{good=item(\type,\iff,\tsuf,\tnec)}

#include "lang.inc"
\statement{\name_statement}

\choice{}{\good}{\choices}
