target=symbol

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
\integer{type=random(1,2,3)}
\text{sign=item(\type,\Leftrightarrow,\Rightarrow,\Leftarrow)}
\text{good=item(\type,\iff,\gsuf,\gnec)}
\text{gA=\gtype=1?A:B}
\text{gB=\gtype=1?B:A}

\statement{\name_statement
<div class="wims_question">
\(A \sign B\)
</div>
\name_thus
<div class="wims_question">
\(\gA\) \name_iscond1 \embed{c1} \name_iscond2 \(\gB\).
</div>
}

\choice{}{\good}{\choices}
