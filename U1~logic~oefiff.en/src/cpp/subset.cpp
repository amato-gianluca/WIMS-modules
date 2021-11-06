target=subset

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\text{iff=\name_NECSUF}
\text{nec=\name_NEC}
\text{suf=\name_SUF}
\text{non=\name_NONNECSUF}
\integer{gtype=random(0,1)}
\text{gnec=\gtype=1?\nec:\suf}
\text{gsuf=\gtype=1?\suf:\nec}
\text{choices=\iff,\nec,\suf,\non}
\text{atype=random(1,2)}
\text{btype=random(1,2)}
\text{gA=\gtype=1?A:B}
\text{gB=\gtype=1?B:A}
\text{good=item(\atype,\gsuf,\gnec)}
\text{good=\atype==\btype?\good:\non}

\statement{\name_statement
<p>
\name_thus
\name_quoteleft\(a\) \name_cases_list[\atype] \(\gA\)\name_quoteright
\name_iscond1 \embed{c1} \name_iscond2
\name_quoteleft\(a\) \name_cases_list[\btype] \(\gB\)\name_quoteright.
}

\choice{}{\good}{\choices}
