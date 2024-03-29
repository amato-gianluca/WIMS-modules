target=tan2

#include "header.inc"
#include "lang_titles.inc"



\integer{choixdeg=random(1,2,2)}

\real{a=item(\choixdeg,0,randint(1..3)*random(-1,1))}
\real{b=item(\choixdeg,randint(1..5)*random(-1,1),randint(-5..5))}
\real{c=randint(-5..5)}
\real{d=randint(-3..3)}
\integer{x0=random(-3..3)}
\function{p=simplify(\a*x^3+\b*x^2+\c*x+\d)}


\function{p=pari(\p)}
\text{tp=texmath(\p)}
\function{der=diff(\p,x)}
\function{der=pari(\der)}
\text{tder= texmath(\der)}
\real{sol=evalue(\der,x=\x0)}
\real{sol2=evalue(\p,x=\x0)}
\function{tan=\sol*(x-\x0)+\sol2}
\function{tans=pari(\tan)}
\real{sol3=evalue(\tans,x=0)}





#include "lang.inc"

\statement{
On consid�re la fonction \(f) d�finie par \(f(x) = \tp) et \(C) sa courbe repr�sentative.<br /> 
<p>
<label for="reply1">L'�quation r�duite de la tangente � la courbe \(C) au point d'abscisse \(\x0) est :</label><br /> y =  \embed{reply1}. </p>
<b>(L'�crire sous la forme y = ax+b)</b>}




\hint{
Calculer <i>f</i> (\x0) et  <i>f</i> '(\x0)<p> <b>
La tangente passe par le point de coordonn�es (\x0 ; <i>f</i> (\x0)) et a comme coefficient directeur <i>f</i> '(\x0)</b><p>

  }


\answer{}{\tans}{type =formal}

\hint{
Deux m�thodes sont possibles, choisissez celle qui vous convient le mieux : 

<ul> <li> <strong>M�thode 1</strong> : La tangente a comme coefficient directeur \(f'(\x0))<p>
Donc  son �quation r�duite est de la forme : \(y = f'(\x0) x + b). </p>
Pour trouver \(b), utiliser le fait qu'elle passe par le point de coordonn�es \((\x0 ; f(\x0))) c'est � dire ici (\x0 ; \sol2).
 </li>
 <li> <strong>M�thode 2</strong> : Appliquer la formule du cours \( y = f'(\x0)(x-\x0)+f(\x0) ), puis d�velopper et r�duire le membre de droite.
 </li>

</ul>
 
  }


\solution{Deux m�thodes sont propos�es ici. Vous pouvez choisir celle qui vous convient le mieux.<br class="spacer"/>
<strong>M�thode 1</strong> : <br />
\(f'(\x0) = \sol), donc l'�quation cherch�e est de la forme \(y=\sol x +b).<br />
La tangente passe par le point de coordonn�es \( (\x0 ; \sol2) ), donc \(\sol2 =(\sol) \times (\x0) + b) , ce qui permet de trouver  \(b = \sol3).<br class="spacer"/>

<strong>M�thode 2</strong> : <br />
La tangente a pour �quation r�duite \(y=f'(\x0)(x-\x0)+f(\x0)) avec : \(f(\x0) = \sol2)  et \(f'(\x0) = \sol).<br />
On obtient donc \(y= \sol (x-\x0)+ (\sol2)). Il ne reste qu'� d�velopper et r�duire cette expression.

}
