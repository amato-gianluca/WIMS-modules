target=parity

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\text{iff=NECSUF}
\text{nec=NEC}
\text{suf=SUF}
\text{non=NONNECSUF}
\integer{gtype=random(0,1)}
\text{gnec=\gtype=1?\nec:\suf}
\text{gsuf=\gtype=1?\suf:\nec}
\text{choices=\iff,\nec,\suf,\non}
\text{prod=<i>ab</i>}
\text{sum=<i>a</i>+<i>b</i>}
\text{t1=\gtype=1?\prod:\sum}
\text{t2=\gtype=1?\sum:\prod}
\integer{p=random(1,2)}
\text{parity=item(\p,ODD,EVEN)}
\text{parity2=item(\p,EVEN,ODD)}
\text{good=item(\p,\suf,\nec)}

\statement{STATEMENT}

\choice{}{\good}{\choices}
