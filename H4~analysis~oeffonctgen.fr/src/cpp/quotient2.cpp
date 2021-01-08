target=quotient2

#include "header.inc"
#include "lang_titles.inc"


donn�es
\integer{a=randint(2..10)}
\integer{b=randint(-10..10)}
\integer{c=random(1..3)}
\integer{d=random(-5..5)}

\integer{dd=\d*\c}
\integer{b=\d=\b/\a ? \b+1}
\function{f=simplify((\a*x + \b)/(\c*x+\dd))}

\text{g=texmath(\f)}

Questions et r�ponses
�tapes
\steps{
reply1,reply2
reply3}
questions et r�ponses de la premi�re �tape
\text{liste=strictement inf�rieurs �, inf�rieurs ou �gaux �, diff�rents de, sup�rieurs ou �gaux �, strictement sup�rieurs �}
\integer{rep1=3}
\integer{s=-\d}
\real{rep2=\s}
question et r�ponse de la deuxi�me �tape type clickfill
\text{size = 65x40}
\text{listtotal=\(\cap\)}
\matrix{good=&#93;,-&#8734;,&#44;,\rep2, &#91;,\(\cup\),&#93;,\rep2,&#44;,+&#8734;,&#91;}
\text{cnt=items(\good[1;])}
\text{rlist=r3}




#include "lang.inc"

\statement{<em>Cet exercice comporte deux �tapes.</em><br/>
Soit \(f\) une fonction de la variable r�elle \(x\) d�finie par \(f(x) = \f \).<br/>
\if{\step=1}{La fonction est d�finie pour tous les \(x\)\embed{reply1} \embed{reply2,5}
et seulement pour ceux-ci. }
\if{\step=2}{<p>
La fonction est d�finie pour tous les \(x\) \liste[3] \(\s\) et seulement pour ceux-ci.
</p>
<p>L'ensemble de d�finition de la fonction f est </p>
<div class="wimscenter"> \embed{r3,\size x \cnt}</div>
<div class="wims_instruction">Remplir le champ avec ces �l�ments
en rangeant par ordre croissant
les bornes des intervalles.</div>}
}


\answer{}{\rep1;\liste}{type=menu}
\answer{}{\rep2}{type=numeric}
\answer{}{\good;\listtotal}{type=clickfill}

\help{On appelle <span class="bold">ensemble de d�finition de la fonction \(f\)</span> l'ensemble des nombres r�els poss�dant une image par \(f\).}
\hint{Le quotient d'un nombre par z�ro n'est pas d�fini.}
