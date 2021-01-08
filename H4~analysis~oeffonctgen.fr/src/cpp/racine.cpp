target=racine

#include "header.inc"
#include "lang_titles.inc"


donn�es
\integer{a=randint(2..10)}
\integer{b=randint(2..20)}
\integer{c=random(-1,1)}
\integer{d=random(-1,1)}

\integer{bb=\d*\b*\a}
\integer{a=\c*\a}

\function{f=sqrt(\a x +  \bb)}

Questions et r�ponses
�tapes
\steps{
reply1,reply2
reply3}
questions et r�ponses de la premi�re �tape
\text{liste=strictement inf�rieurs �, inf�rieurs ou �gaux �, diff�rents de, sup�rieurs ou �gaux �, strictement sup�rieurs �}
\integer{p=\c=1? 4 : 2}
\integer{rep1=\p}
\integer{s=-\d*\c*\b}
\real{rep2=\s}
question et r�ponse de la deuxi�me �tape type clickfill
\text{size = 65x40}
\text{good1=&#91;,\rep2,&#44;,+&#8734;,&#91;}
\text{good2=&#93;,-&#8734;,&#44;,\rep2,&#93;}
\text{listtotal1=-&#8734;,&#93;,&#93;}
\text{listtotal2=+&#8734;,&#91;,&#91;}
\if{\c=1}{\matrix{good=\good1}
\text{listtotal=\listtotal1}
}
{\matrix{good=\good2}
\text{listtotal=\listtotal2}
}
\text{cnt=items(\listtotal)+items(\good[1;])}
\text{rlist=r3}

\text{C=slib(utilities/mathcalc)}


#include "lang.inc"

\statement{<em>Cet exercice comporte deux �tapes.</em> <br/>
Soit \(f\) une fonction de la variable r�elle \(x\) d�finie par \(f(x) = \f \).<br/>
\if{\step=1}{<div class="float_right">
\C</div> La fonction est d�finie pour tous les \(x\)\embed{reply1} \embed{reply2,5} 
et seulement pour ceux-ci. }
\if{\step=2}{La fonction est d�finie pour tous les \(x\) \liste[\p] \(\s\) et seulement pour ceux-ci.<br/>
L'ensemble de d�finition de la fonction f est
 \embed{r3,\size x \cnt}
<hr /> <em>Remplir le champ avec ces �l�ments.</em>}
}
\answer{}{\rep1;\liste}{type=menu}
\answer{}{\rep2}{type=numeric}
\answer{}{\good;\listtotal}{type=clickfill}

\feedback{\reply2<>\rep2}{<b>Le nombre \(\reply2\) n'annule pas \(\f\).</b>}
\feedback{\reply2=\rep2 and \reply1 issametext \liste[4] and \c=-1}{<b>Quand on multiplie une in�galit� par un nombre n�gatif, elle change de sens.</b>}

\help{On appelle <b>ensemble de d�finition de la fonction \(f\)</b> l'ensemble des nombres r�els poss�dant une image par  \(f\).}
\hint{Le carr� d'un nombre r�el est positif ou nul.
La racine carr�e d'un nombre positif \(a\) est le nombre positif \(b\) tel que \(b^2=a\).<br/>
L'ensemble des \(x\) sup�rieurs au �gaux � un r�el \(c\) est l'intervalle &#91;\(c,+\infty\)&#91;.
<br/>L'ensemble des \(x\) inf�rieurs au �gaux � un r�el \(c\) est l'intervalle &#93;\(-\infty,c\)&#93;.}
