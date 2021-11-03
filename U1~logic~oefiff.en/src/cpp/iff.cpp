target=iff iff2 iff3 iff4

#include "header.inc"
#include "lang_titles.inc"
#include "lang1.inc"

\range{-5..5}
\computeanswer{yes}
\precision{10000}

#if defined TARGET_iff || defined TARGET_iff3
\text{iff=\name_NECSUF}
\text{nec=\name_NEC}
\text{suf=\name_SUF}
\text{non=\name_NONNECSUF}
#endif
#if defined TARGET_iff2 || defined TARGET_iff4
\text{iff=\name_NECSUF}
\text{nec=\name_NEC2}
\text{suf=\name_SUF2}
\text{non=\name_NONNECSUF}
#endif
\integer{gtype=random(0,1)}
\text{gnec=\gtype=1?\nec:\suf}
\text{gsuf=\gtype=1?\suf:\nec}
\text{choices=\iff,\nec,\suf,\non}
\integer{type=random(1,2,3)}
#if defined TARGET_iff
\text{sign=item(\type,\name_IFF,\name_ONLYIF,\name_IF)}
\text{good=item(\type,\iff,\gsuf,\gnec)}
#endif
#if defined TARGET_iff3
\text{sign=item(\type,\name_IFF,\name_IF,\name_ONLYIF)}
\text{good=item(\type,\iff,\gsuf,\gnec)}
#endif
#if defined TARGET_iff2
\text{ifs=\name_IFF,\name_ONLYIF,\name_IF}
\text{sign=item(\type,\ifs)}
\text{good=item(\type,\iff,\gsuf,\gnec)}
#endif
#if defined TARGET_iff4
\text{ifs=\name_IFF,\name_IF,\name_ONLYIF}
\text{sign=item(\type,\ifs)}
\text{good=item(\type,\iff,\gsuf,\gnec)}
#endif
\text{gA=\gtype=1?A:B}
\text{gB=\gtype=1?B:A}

#include "lang.inc"
\statement{\name_statement}

#if defined TARGET_iff || defined TARGET_iff3
\choice{}{\good}{\choices}
#endif
#if defined TARGET_iff2
\choice{}{\sign}{\ifs}
#endif
#if defined TARGET_iff4
\choice{}{\sign}{\ifs,\name_nothing}
#endif
