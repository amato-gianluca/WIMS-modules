target=tan1

#include "header.inc"
#include "lang_titles.inc"



\steps{reply1, reply2, reply3
reply4, reply5
}

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

\statement{<p>
On consid�re la fonction \(f) d�finie par \(f(x) = \tp) et \(C) sa courbe repr�sentative.<br /> 
Le but de l'exercice est de calculer<strong> l'�quation r�duite de la tangente � la courbe</strong> \(C) au point d'abscisse \(\x0).</p>

\if{\step=1}{
Les questions qui suivent d�taillent la m�thode permettant d'obtenir cette �quation.<p> 
<strong>Premi�re �tape : </strong> Calculer \(f(\x0)), puis l'expression de \(f'(x)) et  \(f'(\x0)).</p>
<label for="reply1">\(f(\x0)= )</label>\embed{reply1,10} <br />
<label for="reply2">\(f'(x)= )</label>\embed{reply2,30} <br />
<label for="reply3">\(f'(\x0)= )</label>\embed{reply3,10} 
}

\if{\step=2 and \sc_reply1 = 1 and \sc_reply2 = 1 and \sc_reply3 = 1}{
<strong>Premi�re �tape : </strong> Trois bonnes r�ponses, tr�s bien ! <hr />
Vous avez trouv� : 
}
\if{\step=2 and \sc_reply1 = 0 or \sc_reply2 = 0 or \sc_reply3 = 0}{
<strong>Premi�re �tape : </strong> <span class="oef_indbad">Attention � vos calculs !</span> 
\if{\sc_reply1 = 0}{\(f(\x0)) ne vaut pas \reply1. <br />}{Vous avez trouv� la bonne valeur pour \(f(\x0)).<br />}
\if{\sc_reply2 = 0}{Votre calcul de d�riv�e est incorrect : \(f'(x) ) ne vaut pas \reply2 .<br />}
\if{\sc_reply3 = 0}{\(f'(\x0)) ne vaut pas \reply3. <br />}
\if{\sc_reply2 = 0 or \sc_reply3 = 0}{<span class="oef_indgood"><strong>Solution</strong> : \(f(x) = \tp) donc
\(f'(x) = \der ) et \(f'(\x0) = \sol )</span>}
<hr />
Faites la suite de l'exercice avec les bonnes valeurs : 
}




\if{\step=2}{ <span class="wims_emph"> \(f(\x0) = \sol2)  et \(f'(\x0) = \sol).</span><br class="spacer"/>
<strong>Deuxi�me �tape : </strong> Calculer l'�quation r�duite de la tangente � la courbe \(C) au point d'abscisse \(\x0)
<br />
<label for="reply4">�quation r�duite de la tangente : </label>\(y= )\embed{reply4,5}\(x + ) \embed{reply5,5} 
}

}

\hint{
\if{\step=1}{<p>Pour calculer \(f(\x0)), il faut remplacer \(x) par \(\x0) dans l'expression de \(f(x)). </p>
Pour calculer l'expression de \(f'(x)), il faut utiliser les formules du cours. <br />

Pour calculer \(f'(\x0)), il faut remplacer \(x) par \(\x0) dans l'expression de \(f'(x)). }
\if{\step=2}{
Deux m�thodes sont possibles, choisissez celle qui vous convient le mieux : 

<ul> <li> <strong>M�thode 1</strong> : La tangente a comme coefficient directeur \(f'(\x0))<p>
Donc  son �quation r�duite est de la forme : \(y = f'(\x0) x + b). </p>
Pour trouver \(b), utiliser le fait qu'elle passe par le point de coordonn�es \((\x0 ; f(\x0))) c'est � dire ici (\x0 ; \sol2).
 </li>
 <li> <strong>M�thode 2</strong> : Appliquer la formule du cours \( y = f'(\x0)(x-\x0)+f(\x0) ), puis d�velopper et r�duire le membre de droite.
 </li>

</ul>
 
  }}

\answer{\(f(\x0))}{\sol2}{type=numexp}{option = nonstop}{weight=1}
\answer{\(f'(x))}{\der}{type=formal}{option = nonstop }{weight=1}
\answer{\(f '(\x0))}{\sol}{type=numexp}{option = nonstop}{weight=1}
\answer{}{\sol}{type=numexp}{weight=1}
\answer{}{\sol3}{type=numexp}{weight=1}


\solution{Deux m�thodes sont propos�es ici. Vous pouvez choisir celle qui vous convient le mieux.<br class="spacer"/>
<strong>M�thode 1</strong> : <br />
\(f'(\x0) = \sol), donc l'�quation cherch�e est de la forme \(y=\sol x +b).<br />
La tangente passe par le point de coordonn�es \( (\x0 ; \sol2) ), donc \(\sol2 =(\sol) \times (\x0) + b) , ce qui permet de trouver  \(b = \sol3).<br class="spacer"/>

<strong>M�thode 2</strong> : <br />
La tangente a pour �quation r�duite \(y=f'(\x0)(x-\x0)+f(\x0)) avec : \(f(\x0) = \sol2)  et \(f'(\x0) = \sol).<br />
On obtient donc \(y= \sol (x-\x0)+ (\sol2)). Il ne reste qu'� d�velopper et r�duire cette expression.

}
