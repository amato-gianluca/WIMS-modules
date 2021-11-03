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
\text{prod=\(a b\)}
\text{sum=\(a+b\)}
\text{t1=\gtype=1?\prod:\sum}
\text{t2=\gtype=1?\sum:\prod}
\integer{p=random(1,2)}
\integer{q=\p=1?2:1}
text{parity=item(\p,\name_odd,\name_even)}
text{parity2=item(\p,\name_odd,\name_even)}
\text{good=item(\p,\suf,\nec)}

#include "lang.inc"

\statement{\name_statement[1]
<div class="wims_question">\t1 \name_statement[2] \name_cases_list[\p]</div>
\name_statement[3] \embed{c1}
\name_statement[4] \t2 \name_statement[5] \name_cases_list[\q]}

\choice{}{\good}{\choices}
