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
\text{sign=item(\type,\Leftrightarrow,\Rightarrow,\Leftarrow)}
\text{gA=\gtype=1?A:B}
\text{gB=\gtype=1?B:A}
\integer{ttype=random(1,2)}
\text{tnec=item(\ttype,\gnec,\gsuf)}
\text{tsuf=item(\ttype,\gsuf,\gnec)}
\text{good=item(\type,\iff,\tsuf,\tnec)}

\statement{\name_statement
<div class="wims_question">
\(A \sign B\)
</div>
\name_thus
<div class="wims_question">
\(\gA\) \name_cases_list[\ttype] \embed{c1} \(\gB\) \name_cases_list[\ttype] .
</div>
}

\choice{}{\good}{\choices}
