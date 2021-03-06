target=corrdomain

#include "header.inc"
#include "lang_titles.inc"


:Nombre de (paires) d'objets � faire correspondre.
\integer{tot=4}

:La taille verticale des cases en pixels.
Pensez aux gens qui augmentent la taille de polices de leur navigateur !
Ne mettez pas les cases trop petites.
\integer{sizev=80}

:La taille horizontale des cases � gauche en pixels.
\integer{sizel=250}

:La taille horizontale des cases � droite en pixels.
\integer{sizer=250}

\text{size=\sizev x \sizel x \sizer}
:Donn�es principales.
\integer{a=randint(2..10)}
\integer{b=randint(-10..10)}
\integer{c=random(1..3)}
\integer{d=random(1..5)}
\integer{dd=\d*\c}
\integer{cc=\c^2}
\ifval{\d=\b/\a}{\integer{b=\b +1}}
\function{f1=(\a*x + \b)/(\c*x-\dd)}
\function{f2=(\c*x-\dd)/(\a*x^2+\cc)}
\function{f3=sqrt(\c*x - \dd)}
\function{f4=sqrt(-\c*x + \dd)}

\text{g1=\(texmath(\f1)\)}
\text{g2=\(texmath(\f2)\)}
\text{g3=\(texmath(\f3)\)}
\text{g4=\(texmath(\f4)\)}
\text{D1=&#93;\(-\infty,\d\) &#91;\(\;\cup\;\)&#93; \(\d,+\infty\)&#91;}
\text{D2=\(\RR\)}
\text{D3= &#91; \(\d,+\infty\) &#91;}
\text{D4= &#93; \(-\infty,\d\) &#93;}

\matrix{data=\g1,\D1
\g2,\D2
\g3,\D3
\g4,\D4}

\text{enonce=Associer � chaque expression alg�brique l'ensemble de tous les r�els x pour lesquels elle est d�finie.}


#include "lang.inc"

\statement{\enonce
<div class="wimscenter">
\embed{reply 1,\size}
</div>
}

\answer{La r�ponse}{\data[;1];\data[;2]}{type=correspond}
