target=div1

#include "header.inc"
#include "lang_titles.inc"

\author {Chantal, Causse} d'apr�s un exercice de V�ronique Royer. Modifi� par Fabien Sommier.
\email  {Chantal.Causse@noos.fr}
\format {html}


\integer{a1=random(1..4)}
\integer{a2=random(1..8)*random(1,-1)}
\integer{a3=random(1..4)*random(1,-1)}
\integer{c1=random(1..4)*random(1,-1)}
\integer{c2=random(1..8)*random(1,-1)}
\integer{c3=random(1..4)*random(1,-1)}
\integer{c4=random(2..8)*random(1,-1)}

***pour �viter u/v = cste
\integer{a3 = \c1 * \a2 - \c2 * \a3 = 0 ? 5 : \a3 }
\integer{a1 = \c1 * \a2 - \c2 * \a1 = 0 ? 5 : \a1 } % �vite d'avoir un quotient qui se simplifie trop simplement

\text{ulist= \c1*x,
  \c2+\c1*x,
  \c1*x^2+\c2*x +\c3
}
\text{vlist= \a3*x+\a2,
 \a1*random(x,x^2)+\a2,
 x^2+\a1
}
\integer{casv=random(1..3)}
\integer{casu= \casv == 2 ? random(2,3) : random(1..3)}

\function{num=pari(item(\casu , \ulist))}
\text{texnum=texmath(\num)}
\function{deno=pari(item(\casv , \vlist))}
\text{texdeno=texmath(\deno)}
\text{texdeno2=texmath((\deno)^2)}
\rational{vi = \casv==1 ?-\a2 / \a3}
\rational{vi = \casv==2 ?0}

\text{ensder=\casv==3?\(\RR):\(\RR \setminus\{\vi\})}


\function{dernum=pari(diff(\num,x))}
\function{derdeno=pari(diff(\deno,x))}
\function{f= (\num)/(\deno)}
\text{texf = \frac{\texnum}{\texdeno}}


\function{numder0=(\dernum)*(\deno)-(\num)*(\derdeno)}
\text{texnumder0=texmath(\numder0)}
\function{numder=pari((\dernum)*(\deno)-(\num)*(\derdeno))}
\text{texnumder=texmath(\numder)}
\function{derf=(\numder)/((\deno)^2)}


\text{numA=u' v + u v'}
\text{numB=u' v - u v'}
\text{numC=u v' - u' v}
\text{denoA=v^2}

\text{formule= \(f' = \frac{\numB}{\denoA})}
\text{list= \(f'=u' v') , \(f' = \numA) , \(f' = \numB),\(f' = \frac{u'}{v'}),\(f' = \frac{\numA}{\denoA}),\(f' = \frac{\numC}{\denoA})}
\text{choix=shuffle(\formule,\list[1..4])}
\integer{rep3=position(\formule,\choix)}





#include "lang.inc"

\statement{<div class="wimscenter">
<p style = "background-color: #FFCC66">
M�thode pour calculer la d�riv�e de la fonction d�finie
sur  \ensder par \(f(x) = \texf)
</p></div>

<ul>
<li>
On remarque que\(f) est de la forme \(\frac{u}{v}) avec :<br />
<label for="reply1">\(u(x)) = </label> \embed{reply1, 15}  &nbsp; &nbsp;  et &nbsp; &nbsp;
<label for="reply2">\(v(x)) =  </label> \embed{reply2, 15}
<br /> d'o� :<br />
<label for="reply3">\(u'(x)) = </label>  \embed{reply3, 15}  &nbsp; &nbsp;  et &nbsp; &nbsp;
<label for="reply4">\(v'(x) = ) </label> \embed{reply4, 15} <br />
</li>
<li> Cocher la formule de d�rivation de \(f = \frac{u}{v}):<br />
 \embed{reply5}
</li>
<li> En appliquant cette formule, on obtient :
<p class = "wimscenter">
<label for="reply6">\(f'(x)) =  </label>\embed{reply6, 50}
</p>
</li>


</ul>
}

\answer{num�rateur : \(u(x)) }{\num}{type=formal}
\answer{d�nominateur: \(v(x)) }{\deno}{type=formal}

\answer{D�riv�e du num�rateur : \(u'(x)) }{\dernum}{type=formal}
\answer{D�riv�e du d�nominateur: \(v'(x)) }{\derdeno}{type=formal}

\answer{Formule de d�rivation }{\rep3;\choix}{type=radio}
\answer{La d�riv�e est d�finie par : \(f'(x))}{\derf}{type=formal}

\feedback{0==0}{<b>Solution.</b> La fonction d�riv�e \(f') est d�finie
\if{\casv==3}{pour tout r�el \(x)}{pour tout r�el \(x) diff�rent de  \(\vi)}
 par &nbsp;
 \(f'(x)  =\frac{\texnumder0}{\texdeno2}= \frac{\texnumder}{\texdeno2})  .
}
