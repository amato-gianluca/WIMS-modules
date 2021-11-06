target=3func 3func2

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

#if defined TARGET_3func
\text{iff=\name_NECSUF}
\text{nec=\name_NEC}
\text{suf=\name_SUF}
\text{non=\name_NONNECSUF}
#endif
#if defined TARGET_3func2
\text{iff=\name_IFF}
\text{nec=\name_IF}
\text{suf=\name_ONLYIF}
\text{non=\name_NONIFONLYIF}
#endif
\integer{gtype=random(0,1)}
\text{gnec=\gtype=1?\nec:\suf}
\text{gsuf=\gtype=1?\suf:\nec}
\text{choices=\iff,\nec,\suf,\non}
\text{tf=\gtype=1?f:h}
\text{th=\gtype=1?h:f}
\integer{s1=random(1,2)}
\integer{s2=random(1,2)}
\text{f1=item(\s1,f,g)}
\text{f2=item(\s1,g,f)}
\text{g1=item(\s2,g,h)}
\text{g2=item(\s2,h,g)}
\text{cnec1=item(\s1,\nec,\suf)}
\text{cnec2=item(\s2,\nec,\suf)}
\text{csuf1=item(\s1,\suf,\nec)}
\text{csuf2=item(\s2,\suf,\nec)}
\integer{cc=random(1..9)}
\text{c1= item(\cc,\iff,\iff,\iff,\cnec1,\csuf1,\cnec1,\csuf1,\cnec1,\csuf1)}
\text{c2= item(\cc,\iff,\cnec2,\csuf2,\iff,\iff,\cnec2,\csuf2,\csuf2,\cnec2)}
\text{good=item(\cc,\iff,\gnec,\gsuf,\gnec,\gsuf,\gnec,\gsuf,\non,\non)}

\statement{\name_statement1 \(f(x)\), \(g(x)\) \name_and \(h(x)\).
<div class="wims_question">
\name_statement2 \(x\),
#if defined TARGET_3func
\(\f1(x)>0\) \name_iscond1 <span class="wims_emph">\c1</span> \name_iscond2 \(\f2(x)>0\),
\name_and \(\g1(x)>0\) \name_iscond1 <span class="wims_emph">\c2</span> \name_iscond2 \(\g2(x)>0\).
#endif
#if defined TARGET_3func2
\(\f1(x)<0\) <span class="wims_emph">\c1</span> \(\f2(x)<0\), \name_and \(\g1(x)<0\) <span class="wims_emph">\c2</span> \(\g2(x)<0\).
#endif
</div><p>
\name_thus,
#if defined TARGET_3func
\(\tf(x)>0\)
\name_iscond1
#endif
#if defined TARGET_3func2
\(\tf(x)<0\)
#endif
\embed{c1}
#if defined TARGET_3func
\name_iscond2 \(\th(x)>0\).
#endif
#if defined TARGET_3func2
\(\th(x)<0\).
#endif
</p>}

\choice{}{\good}{\choices}
