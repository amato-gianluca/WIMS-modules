target=pararea

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\language{en}

\real{qc=floor(random(40..80))/100}
\integer{cy=random(6..10)}
\real{cx=round(random(0.5*\cy..0.9*\cy))}
\real{cc=round(random(1.5*\cy..2.5*\cy))}
\integer{type=random(1,2)}
\integer{rtype=random(1..5)}
\text{subt=\type=1?-}
\text{x=x}
\text{y=y}
\real{triangle=\cc^2/(2*\cx*\cy)}
\real{b=\cx/\cy}
\real{c=\cc/\cy}
\real{root1=(sqrt(\b^2+4*\qc*\c)+\b)/(2*\qc)}
\real{root2=(sqrt(\b^2+4*\qc*\c)-\b)/(2*\qc)}
\function{f=-\qc*x^2-\b*x+\c}
\function{integral=-\qc*x^3/3-\b*x^2/2+\c*x}
\real{area1=-evalue(\integral,x=-\root1)}
\real{area2=evalue(\integral,x=\root2)}
\real{area3=\triangle-\area2}
\real{sol=item(\rtype,\area1+\area2,\area1+\triangle,\area1,\area2,\area3)}




\statement{\name_statement1
<font color=red><i>C</i></font> \name_statement2
<i>f</i>(x)&nbsp;=&nbsp;\qc\x<sup>2</sup>, \and <font color=green><i>L</i></font>
\name_statement3 \subt\cx\x+\cy\y=\cc.
<p><center>
<img src=\imagedir/quad\type\rtype.gif></center> <p>
\name_precision}

\answer{\Thearea}{\sol}
