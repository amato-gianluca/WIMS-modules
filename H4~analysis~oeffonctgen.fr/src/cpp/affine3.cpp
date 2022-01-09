target=affine3

#include "header.inc"
#include "lang_titles.inc"


donn�es
\integer{c=random(1..3)}
\integer{d=random(-5..5)}

\integer{dd=\d*\c}
\function{f=simplify(\c*x+\dd)}

\text{g=texmath(\f)}

\integer{s=-\d}

\text{size = 65x40}
\text{listtotal=\(\cap\),\s,\(\cup\)}
\matrix{good=&#93;,-&#8734;,&#44;,+&#8734;,&#91;}
\text{cnt=items(\good[1;])+6}
\text{rlist=r3}



#include "lang.inc"

\statement{<p>
Soit \(f\) une fonction de la variable r�elle \(x\) d�finie par \(f(x) = \f \).<br/>
L'ensemble de d�finition de la fonction \(f\) est </p>
<div class="wimscenter"> \embed{r1,\size x \cnt}.</div>
<div class="wims_instruction">Remplir le champ avec ces
�l�ments en rangeant par ordre croissant les bornes des intervalles.
</div>}

\answer{}{\good;\listtotal}{type=clickfill
