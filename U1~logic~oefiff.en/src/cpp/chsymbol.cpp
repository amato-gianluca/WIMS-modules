target=chsymbol

#include "header.inc"
#include "lang_titles.inc"
#include "lang1.inc"

\range{-5..5}
\computeanswer{yes}
\precision{10000}

\text{iff=\name_NECSUF}
\text{nec=\name_NEC}
\text{suf=\name_SUF}
\text{non=\name_PERNON}
\integer{gtype=random(0,1)}
\text{gnec=\gtype=1?\nec:\suf}
\text{gsuf=\gtype=1?\suf:\nec}
\text{choices=\iff,\nec,\suf,\non}
\text{gA=\gtype=1?A:D}
\text{gB=\gtype=1?D:A}
\integer{dir=random(1,2)}
\text{gdir=item(\dir,\gsuf,\gnec)}
\text{sdir=item(\dir,=&gt;,&lt;=)}
\text{rdir=item(\dir,&lt;=,=&gt;)}
\text{tiff=&lt;=&gt;}
\integer{chtype=random(1..6)}
\text{ch1=item(\chtype,\tiff,\tiff,\tiff,\sdir,\tiff,\sdir)}
\text{ch2=item(\chtype,\tiff,\tiff,\sdir,\sdir,\sdir,\sdir)}
\text{ch3=item(\chtype,\tiff,\sdir,\sdir,\sdir,\rdir,\rdir)}
\integer{order=random(1..6)}
\text{s1=item(\order,\ch1,\ch1,\ch2,\ch2,\ch3,\ch3)}
\text{s2=item(\order,\ch2,\ch3,\ch1,\ch3,\ch1,\ch2)}
\text{s3=item(\order,\ch3,\ch2,\ch3,\ch1,\ch2,\ch1)}
\text{good=item(\chtype,\iff,\gdir,\gdir,\gdir,\non,\non)}

#include "lang.inc"
\statement{\name_statement}

\choice{}{\good}{\choices}
