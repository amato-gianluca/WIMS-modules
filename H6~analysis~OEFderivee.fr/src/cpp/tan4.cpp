target=tan4

#include "header.inc"
#include "lang_titles.inc"




\real{a=randint(1..4)*random(-1,1)}
\real{b=randint(1..5)*random(-1,1)}
\real{c=randint(2..5)}
\real{d=randint(1..7)}
\rational{q=(1-\d)/\c}

\integer{choix=randint(1..2)} 

\function{lin = simplify(\b*x+\c)}

\function{p=item(\choix,
(\lin)*e^(\a*x),
\lin + \d*e^(\a*x),
ln(\c*x+\d),
(\a*x+\b)*ln(\c*x+\d),
\b*x+\a*ln(\c*x+\d)
)}



\function{p=wims(\p)}
\text{tp=texmath(\p)}

\function{der=diff(\p,x)}
\if{\choix=1}{ !!! cela pour presenter la derivee sous forme factorisee
\function{fact=(\der)/(e^(\a*x))}
\function{fact=maxima(expand(\fact))}
\text{der=(\fact)*(e^(\a*x))}}

\text{dermath=texmath(\der)} (pour la solution)



\text{x0=0}
\function{sol=evalue(\der,x=\x0)} 
\function{solmath=maxima(expand(\sol))}

\function{sol2=evalue(\p,x=\x0)}

\function{tan=(\sol)*(x)-(\sol)*(\x0)+\sol2}
\function{tans=maxima(expand(\tan))}



\text{a=\tans}
\text{a=evalue(\a,e=y)}
\text{b1=pari(a=\a;polcoeff(a,1,x))}
\text{b1=wims(replace internal y by e in \b1)}
\function{b1=maxima(expand(\b1))} 


\text{b2=pari(a=\a;polcoeff(a,0,x))}
\text{b2=wims(replace internal y by e in \b2)}
\function{b2=maxima(expand(\b2))} 

\text{b=(\b1)*x+\b2}
\text{bm=texmath(\b)}




#include "lang.inc"

\statement{Soit \(f(x) = \tp).
<ul>
<li>Calculer \(f'(x)).</li>
<li>Calculer l'�quation r�duite de la tangente T � la courbe repr�sentant \(f) au point A d'abscisse \x0.</li>
<li>Donner les coordonn�es d'un point B de la tangente T autre que A.</li>
</ul>
}

\hint{
Calculer \(f(\x0)) et  \(f'(\x0))<br />
<span class="wims_emph"> 
La tangente passe par le point de coordonn�es \((\x0 ; f(\x0))) et a comme coefficient directeur \(f'(\x0))</span>
}

\answer{\(f'(x))}{\der}{type = function} option=noanalyzeprint (pr�f�rable de garder trace de la r�ponse)
\answer{Equation de la tangente : y }{\tans}{type = function} option=noanalyzeprint
\answer{Abscisse de B}{\rep4}{}
\answer{Ordonn�e de B}{\rep5}{}
\condition{B est sur la droite T}{\rep5 = \sol*(\rep4-\x0)+\sol2}
\condition{B est diff�rent de A}{\rep4 <> \x0}

\solution{
\(f'(x)= \dermath).<br />
On en d�duit que
\(f'(\x0)=\solmath) puis que la tangente au point d'abscisse \(\x0) a pour �quation \(y = \bm)<br />
Pour les coordonn�es de B, on choisit pour \(x_B) une valeur de \(x) diff�rente de \(\x0) et on calcule l'ordonn�e de B en rempla�ant \(x) par \(x_B) dans l'�quation r�duite de T.


}
