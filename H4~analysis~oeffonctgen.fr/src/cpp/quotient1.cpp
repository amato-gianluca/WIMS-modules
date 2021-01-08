target=quotient1

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

questions et r�ponses de la premi�re �tape
\text{liste=strictement inf�rieurs �, inf�rieurs ou �gaux �, diff�rents de, sup�rieurs ou �gaux �, strictement sup�rieurs �}
\integer{rep1=3}
\integer{s=-\d}
\real{rep2=\s}



#include "lang.inc"

\statement{Soit \(f\) une fonction de la variable r�elle \(x\) d�finie par \(f(x) = \f \).<br/>
La fonction est d�finie pour tous les \(x\)\embed{reply1} \embed{reply2,5}
et seulement pour ceux-ci.
}


\answer{}{\rep1;\liste}{type=menu}
\answer{}{\rep2}{type=numeric}

\help{On appelle <span class="bold">ensemble de d�finition de la fonction \(f\)</span> l'ensemble
 des nombres r�els poss�dant une image par \(f\).}
\hint{Le quotient par z�ro n'existe pas.}
