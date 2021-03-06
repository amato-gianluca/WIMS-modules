target=qcmensdef

#include "header.inc"
#include "lang_titles.inc"


:Donn�es principales.
\integer{a=randint(2..10)}
\integer{b=randint(-10..10)}
\integer{c=random(1..3)}
\integer{d=random(1..5)}
\integer{dd=\d*\c}
\integer{cc=\c^2}
\ifval{\d=\b/\a}{\integer{b=\b+1}}
\function{f1=(\a*x + \b)/(\c*x-\dd)}
\function{f2=(\c*x-\dd)/(\a*x^2+\cc)}
\function{f3=sqrt(\c*x - \dd)}
\function{f4=sqrt(-\c*x + \dd)}

\text{g1=texmath(\f1)}
\text{g2=texmath(\f2)}
\text{g3=texmath(\f3)}
\text{g4=texmath(\f4)}
\text{D1=\(\rbrack -\infty,\d \lbrack \cup \rbrack \d,+\infty \lbrack\)}
\text{D2=\(\mathbb{R}\)}
\text{D3=\(\lbrack \d,+\infty \lbrack\)}
\text{D4= \(\rbrack-\infty,\d \rbrack\)}

\matrix{data=\g1,\D1
\g2,\D2
\g3,\D3
\g4,\D4}

:Nombre de type de fonctions.
\integer{tot=rows(\data\)}
: choix d'un type c'est-�-dire d'une ligne de la matrice data
\integer{q=randint(1..\tot)}



#include "lang.inc"

\statement{Choisir l'ensemble de d�finition de la fonction \(f\) de la variable r�elle
\(x\) d�finie par \(f(x) = \data[\q;1]\).
<div>
<ul><li>\embed{reply 1,1}</li>
\for{t=2 to \tot}{<li>\embed{reply 1,\t}</li>}</ul>
</div>
}

\answer{La r�ponse}{\q;\data[;2]}{type=radio}{option=shuffle}
