target=parity

#include "header.inc"
#include "lang_titles.inc"
#include "lang1.inc"

\text{iff=\name_NECSUF}
\text{nec=\name_NEC}
\text{suf=\name_SUF}
\text{non=\name_NONNECSUF}
\integer{gtype=random(0,1)}
\text{gnec=\gtype=1?\nec:\suf}
\text{gsuf=\gtype=1?\suf:\nec}
\text{choices=\iff,\nec,\suf,\non}
\text{prod=<i>ab</i>}
\text{sum=<i>a</i>+<i>b</i>}
\text{t1=\gtype=1?\prod:\sum}
\text{t2=\gtype=1?\sum:\prod}
\integer{p=random(1,2)}
\text{parity=item(\p,\name_odd,\name_even)}
\text{parity2=item(\p,\name_odd,\name_even)}
\text{good=item(\p,\suf,\nec)}

#include "lang.inc"
\statement{\name_statement}

\choice{}{\good}{\choices}
