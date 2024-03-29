target=aff_exp

#include "header.inc"
#include "lang_titles.inc"




\integer{sa = random(-1,1)}
\integer{a = \sa*random(2..6)}
\integer{b = random(-1,1)*random(1..9)}
\integer{c = random(-1,1)*random(2..9)}
\integer{d = random(-1,1)*random(1..9)}
\if{\c=\a}{\integer{c = \c + \sa}}
\text{sk=random(-,+)}
\text{sx=random(-,+)}
\text{xlim=\sx\inf}
\text{texlim=\sx\infty}

\text{sb= \sx issametext + ? +1 : -1 }

\text{inf=&#8734;}

\integer{op=randint(1..4)}
\text{ensdef= &#93;  -\inf ; +\inf &#91;}
\if{\op = 4}{
\rational{vi = -(\d)/(\c)}
\text{ensdef = &#93;  -\inf ; \vi &#91; \union &#93;  \vi ; +\inf &#91; }
}

\function{u=pari(\a*x + \b)}
\text{tu = texmath(\u)}
\function{v=pari(\c*x + \d)}
\text{tv = texmath(\v)}

\text{g=\exp(t)}
\text{gg=\exp(u)}
\text{ggx=\exp(u(x))}
\text{gdeu=e^(\u)}
\function{f=item(\op,\v \sk  \gdeu,(\v)* (\gdeu), (\v)/(\gdeu),(\gdeu)/(\v))}
\text{forme=item(\op,v \sk  \gg, v \times \gg, \frac{v}{\gg},\frac{\gg}{v})}
\text{tf=texmath(\f)}
\text{tf = \op = 4 ?{e^{\tu} \over \tv} }


\text{vlim=(\c*\sb)>0?+inf,+\infty,1:-inf,-\infty,-1}
\text{rep1=item(1,\vlim)}
\text{sol1=item(2,\vlim)}

\text{ulim=(\a*\sb)>0?+inf,+\infty:-inf,-\infty}
\text{rep2=item(1,\ulim)}
\text{sol2=item(2,\ulim)}

\text{glim= \rep2 issametext -inf ? 0,0,0:+inf,+\infty,1}
\text{rep3=item(1,\glim)}
\text{sol3=item(2,\glim)}

\text{rep4=\rep3}
\text{sol4=\sol3}



\text{\typeindet=Oui car on n'a aucune forme ind�termin�e,
Non car on a une forme ind�termin�e  de type 0 x \inf, 
Non car on a une forme ind�termin�e de type 0 / 0,
Non car on a une forme ind�termin�e de type \inf / \inf ,
Non car on a  une forme ind�termin�e de type \inf - \inf
}

\text{\fi=, 0 x \inf,  0 / 0, \inf / \inf , \inf - \inf}

\integer{tmp=item(3,\vlim)}
\integer{tmp2=item(3,\glim)}
\integer{tmp2=\tmp*\tmp2}
\text{rep5=1}
\text{rep5=\op=1 and \sk issametext + and \tmp2<0?5}
\text{rep5=\op=1 and \sk issametext - and \tmp2>0?5}
\text{rep5=\op=2 and \tmp2=0?2}
\text{rep5=\op>2 and \tmp2!=0?4}
\text{lafi=item(\rep5,\fi)}

\if{\op=4}{\text{rep6=\tmp=1?+inf:-inf}}


\matrix{filims=\rep4,\rep1
\rep4,\rep1
0,\rep1
\rep6,0}

\if{\rep5=1}
{\text{sol6=\op!=4?\rep1:0}}
{\text{tmp=row(\op,\filims)}
 \text{sol6=item(1,\tmp)}
}
\if{\op=1 and \rep5=5 and \sk  issametext -}{\text{sol6=-inf}}
\text{sol7=\sol6 issametext +inf?+ \inf:- \inf}
\text{ind=}
\if{ \op=4 && \rep5=4}{
   \text{ind=On peut lever l'ind�termination en �crivant :<br />
   \(f(x) = {e^{\tu} \over \tv} = {e^{\tu} \over \tu} \times {\tu \over \tv})
   }
}
\if{ \op=3 && \rep5=4}{
   \text{ind=On peut lever l'ind�termination en �crivant :<br />
   \(f(x) = {\tv \over e^{\tu}} = {\tv \over \tu} \times {\tu \over e^{\tu}})
   }
}
\if{ \op=1 && \rep5=5}{
   \text{ind=On peut lever l'ind�termination en �crivant :<br />
  \(f(x) =  (\tv) \sk e^{\tu} = (\tu)({\tv \over \tu} \sk  {e^{\tu}\over \tu}) )
   }
}
\if{ \op=2 && \rep5=2}{
   \text{ind=On peut lever l'ind�termination en �crivant :<br />
   \(f(x) = (\tv) \times e^{\tu} = {\tv \over \tu} \times {\tu \over e^{\tu}} )
   }
}

\steps{reply1
reply2
reply3
reply4
reply5
reply6}



#include "lang.inc"

\statement{
<p> 
Soit \(f) la fonction   d�finie sur \(\ensdef) par :
\(f(x) = \tf).
</p><p>
On a donc \(f = \forme )  avec, pour tout r�el  \(x) de \(\ensdef), 
\(u(x) = \u)  &nbsp; et &nbsp; \(v(x) = \v).
</p><p> 
Le but de cet exercice est de calculer la limite de \(f) en \(\texlim).
</p>
<span class="wims_emph">\special{help saisie,Consignes de saisie}</span>


<ul>


\if{\step=1}
{<li>Donner la limite de \(v) en \(\texlim) : 
<p class="wimscenter">\(\displaystyle{\lim_{x \rightarrow \texlim} \tv} ) = \embed{reply1,5}</p>
</li>}

\if{\step>1}
{<li>
\if{\step=2}
    {\if{\sc_reply1=1}
     {<span class="oef_indgood">Votre r�ponse �tait juste!</span><br />}
     {<span class="oef_indbad">Attention, votre r�ponse (\reply1) n'�tait pas la bonne!</span><br />}
}
<span class="wims_emph"> La limite de \(v) en \(\texlim) est </span>:  
<p class="wimscenter">\(\displaystyle{\lim_{x \to \texlim} v(x) = \lim_{x\to\texlim} \tv  = \sol1})</p >

</li>
}


\if{\step=2}
{<li>Donner la limite de \(u) en \(\texlim) : 
<p class="wimscenter">\(\displaystyle{\lim_{x\to\texlim} \tu }) = \embed{reply2,5}</p>
</li>
}


\if{\step>2}
{<li>
\if{\step=3}
    {\if{\sc_reply2=1}
     {<span class="oef_indgood">Votre r�ponse �tait juste!</span><br />}
     {<span class="oef_indbad">H�las, votre r�ponse (\reply2) n'�tait pas bonne !</span><br />}
}
<span class="wims_emph"> La limite de \(u) en \(\texlim)  est</span> :  
<p class="wimscenter">\(\displaystyle{\lim_{x\to\texlim} u(x) = \lim_{x\to\texlim} \tu  = \sol2})</p >
</li>
}


\if{\step=3}
{<li>Donner la limite de \(\g) en \(\sol2) : 
<p class="wimscenter">\(\displaystyle{\lim_{t\to\sol2} \g }) = \embed{reply3,5}</p >
</li>
}


\if{\step=4}
{<li>
    \if{\sc_reply3=1}
     {<span class="oef_indgood">Votre r�ponse �tait juste!</span><br />}
     {<span class="oef_indbad">Humm, votre r�ponse (\reply3) n'�tait pas correcte !</span><br />}

En posant \(t = \u), sachant que \(\displaystyle{\lim_{t\to\sol2} \g  = \sol3}), on d�duit que : 
<p class="wimscenter">\(\displaystyle{ \lim_{x\to\texlim} e^{\tu} }) = \embed{reply4,5}</p >
</li> 
}


\if{\step>4}
{<li>

\if{\step=5}
    {\if{\sc_reply4=1}
     {<span class="oef_indgood">Votre r�ponse �tait juste!</span><br />}
     {<span class="oef_indbad">Votre r�ponse (\reply4) n'�tait pas correcte !</span><br />}
}

<span class="wims_emph"> la limite de \(\gg) en \(\texlim) est </span>:
<p class="wimscenter">\(\displaystyle{\lim_{x\to\texlim} \ggx =\lim_{x\to\texlim} e^{\tu}  = \lim_{t\to\sol2} \g = \sol4}). </p > 
</li>
}

\if{\step=5}
{<li> Peut-on  d�duire la limite en \(\texlim)  de \(f = \forme) en appliquant les r�gles op�ratoires sur les limites ? 
<p class="wimscenter">\embed{reply5,size=5}</p > 
</li>
}


\if{\step=6}
{<li>

   \if{\sc_reply5=1}
     {<span class="oef_indgood">Votre r�ponse �tait juste!</span><br />}
     {<span class="oef_indbad">Votre r�ponse (\reply5)  �tait erron�e !</span><br />}



<span class="wims_emph">
\if{\rep5=1}{
Les r�gles op�ratoires des limites sont valables ici, car il n'y a aucune
forme ind�termin�e.</span> }
{On ne peut pas appliquer les r�gles op�ratoires des limites, car
il y a une forme ind�termin�e du type \lafi .
 <br/> \ind </span>}
<br />On obtient donc :
<p class="wimscenter">\(\displaystyle{\lim_{x\to\texlim} f(x)}) = \embed{reply6,5} </p >
</li>} 

</ul>
}

\answer{limite de v : }{\rep1}{type=raw}{option=nospace,nonstop}
\answer{limite de u : }{\rep2}{type=raw}{option=nospace,nonstop}
\answer{limite de \(\g) : }{\rep3}{type=raw}{option=nospace,nonstop}
\answer{limite de \(\gg) : }{\rep4}{type=raw}{option=nospace,nonstop}
\answer{forme ind�termin�e :}{\rep5;\typeindet}{type=select}{option=nonstop}
\answer{limite de f : }{\sol6}{type=raw}{option=nospace}

\feedback{ \op=1 && \rep5=5}{
<span class="wims_emph"> 
\v tend vers \(\sol1) ,
\(\frac{\gdeu}{\u}) tend vers +\inf et \(\frac{\u}{\v}) tend vers \(\frac{\a}{\c}) donc \(f(x)) tend vers \sol7
</span>}


\feedback{ \op=2 && \rep5=2}{
<span class="wims_emph"> 
\(\frac{\v}{\u}) tend vers  \(\frac{\c}{\a}) et \((\u) \gdeu) tend vers 0 donc \(f(x)) tend vers 0.
</span>}

\feedback{ \op=4 && \rep5=4}{
<span class="wims_emph"> 
\(\frac{\gdeu}{\u}) tend vers +\inf et \(\frac{\u}{\v}) tend vers \(\frac{\a}{\c}) donc \(f(x)) tend vers \sol7
</span>}




\help{
  
 \if{\help_subject issametext saisie}{
<b>Consignes de saisie :</b><br/>
�crire <b>+inf</b> pour d�signer \(+\infty)  ;<br/> �crire  <b>-inf</b> pour d�signer \(-\infty). 
   }
}
