target=3func2

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\text{iff=\name_IFF}
\text{nec=\name_IF}
\text{suf=\name_ONLYIF}
\text{non=\name_NONIFONLYIF}
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
\text{c1= item(\cc,\iff,\iff,  \iff,  \cnec1,\csuf1,\cnec1,\csuf1,\cnec1,\csuf1)}
\text{c2= item(\cc,\iff,\cnec2,\csuf2,\iff,  \iff,  \cnec2,\csuf2,\csuf2,\cnec2)}
\text{good=item(\cc,\iff,\gnec,\gsuf, \gnec, \gsuf, \gnec, \gsuf, \non,  \non)}

#include "lang.inc"
\statement{\name_statement}

\choice{}{\good}{\choices}
