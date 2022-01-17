target=pdt

#include "header.inc"
#include "lang_titles.inc"

\author {Chantal, Causse} d'apr�s V�ronique Royer
\email  {Chantal.Causse@noos.fr}
\format {html}

\integer{a1=random(1..8)*random(1,-1)}
\integer{a2=random(1..8)*random(1,-1)}
\integer{c1=random(1..8)*random(1,-1)}
\integer{c2=random(1..8)*random(1,-1)}
\integer{a3=random(1..8)*random(1,-1)}

\function{u=randitem(
 \a1*x+\a2,
 \a1*x,
 \a1*x^2+\a2*x+\a3
)}

\function{v=randitem(e^(\c1*x),
e^(\c1*x+\c2),
e^(\c1*x^2))}

\function{f=(\u)*(\v)}
\text{texf = texmath(\f)}
\function{U=diff(\u,x)}
\function{V=diff(\v,x)}
\function{F=diff(\f,x)}
\function{factorF=maxima(factor(\F))}
\function{devF=maxima(expand(\F))}

\text{numA=u' v + u v'}
\text{numB=u' v - u v'}
\text{numC=u v' - u' v}
\text{denoA= v^2}
\text{formule= \((u v)' = \numA)}
\text{list=  \((u v)'=u' v') , \((u v)' = \numB), \((u v)' = \frac{\numB}{\denoA}),\((u v)' = \frac{u'}{v'}),\((u v)' = \frac{\numA}{\denoA}),\((u v)' = \frac{\numC}{\denoA})}

\text{choix=shuffle(\list)}
\text{choix = \choix[1..3]}
\text{choix = \formule,\choix}
\text{choix=shuffle(\choix)}
\integer{rep3=position(\formule,\choix)}



#include "lang.inc"

\statement{
<div class="wimscenter">
<p style = "background-color: #FFCC66">
 M�thode pour calculer la d�riv�e de la fonction d�finie 
sur \RR par \(f(x) = \texf) 
</p></div>

\(f) est le produit des fonctions \(u) et \(v) d�finies par :
<p class="wimscenter">\(u(x) = \u )<br />\(v(x) = \v )</p>
Les fonctions \(u) et \(v) sont d�rivables sur \(\RR) et :
<p class="wimscenter"><label for="reply1">\(u'(x)) = </label>\embed{reply1,20} <br />
<label for="reply2">\(v'(x)) = </label> \embed{reply2,20} </p>
Cocher la formule exacte dans cette liste <b>(toutes les autres sont fausses)</b> :<p class="wimscenter">\embed{reply3}</p>
En utilisant cette formule,<label for="reply4"> on obtient la d�riv�e de \(f)  :</label>
<p class="wimsenter"><label for="reply4">\(f'(x)) = </label>\embed{reply4, 30}</p>
}
\answer{ \(u'(x)) }{\U}{type=formal}
\answer{ \(v'(x)) }{\V}{type=formal}
\answer{Formule de d�rivation }{\rep3;\choix}{type=radio}
\answer{ \(f'(x))  }{\F}{type=formal}
\feedback{0==0}{<b>Solution.</b> <br/>
La forme d�velopp�e de  \(f'(x))  est  \(\devF). <br/>
La forme factoris�e de  \(f'(x))  est  \(\factorF).}
