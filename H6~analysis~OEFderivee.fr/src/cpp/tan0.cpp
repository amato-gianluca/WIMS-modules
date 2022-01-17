target=tan0

#include "header.inc"
#include "lang_titles.inc"


\steps{reply1
reply2,reply3}

\rational{a=random(-1,1)*randint(1..3)/randint(1..4)}
\rational{b=randint(-4..4)/randint(1..2)}
\rational{c= randint(-3..3)}
\function{f=random(\a*x^2+\b*x+\c,\a*x^3+\b*x^2+\c*x)}
\rational{x0 = randint(-3..3)/2}
\function{fp = diff(\f,x)}
\rational{p0 = evalue(\fp,x=\x0)}
*******pour �viter les pentes trop fortes
\integer{i=\p0=0 ? 1 :ceil(abs(\p0)/10)}
\function{f =  (\f)/\i}
\function{fp = diff(\f,x)}
\rational{p0 = evalue(\fp,x=\x0)}
***

\function{f = pari(\f)}
\text{Tf = texmath(\f)}
\real{y0 = evalue(\f,x=\x0)}

\real{xmin = -2.5}
\real{xmax = 2.5}
\text{A=slib(function/bounds \f, x,\xmin,\xmax)}  
\integer{ymin = \A[1]-1}
\integer{ymax = \A[2]+1}

\if{\ymax-\ymin > 15}{
\integer{ymin = \y0-8}
\integer{ymax = \y0+8}}

\text{dessin = 
xrange \xmin,\xmax
yrange \ymin,\ymax

parallel \xmin+.5,\ymin,\xmin+.5,\ymax,1,0,\xmax - \xmin +1,grey 
parallel \xmin,\ymin,\xmax,\ymin,0,1,\ymax -\ymin +1,grey 
linewidth 2
hline 0,0,black
arrow  0,0,1,0,6,black
arrow 0,0,0,1,6,black
vline 0,0,black
plot blue, \f
fcircle \x0,\y0,7, green

linewidth 1
plot green, \y0+(x-\x0)*\p0
plot green, \y0+(x-\x0)*(\p0+2)
plot green, \y0+(x-\x0)*(\p0+4)
plot green, \y0+(x-\x0)*(\p0-2)
text black,\x0,\y0,medium,A 
}



#include "lang.inc"

\statement{<table><tr><td>
\draw{600,400}{\dessin}</td><td></td><td>
Une courbe est trac�e en bleu.<br /> Plusieurs droites sont trac�es en vert. <p>
Parmi ces droites, il y a la tangente � la courbe au point \(A).</p>
\if{\step = 1}{
D�terminer graphiquement une valeur approch�e du coefficient directeur de cette tangente.<p>
Vous vous aiderez pour cela du quadrillage : les lignes grises sont distantes les unes des autres d'une unit�. On ne demande pas une grande pr�cision de lecture.</p>}
\if{\step = 2 and \sc_reply1 = 1}{<span class="oef_indgood">
Vous avez trouv� comme valeur approch�e du coefficient directeur de cette tangente : \reply1.<br /> C�est une valeur approch�e correcte.</span>
Vous allez maintenant en d�terminer par le calcul la valeur exacte.}
\if{\step = 2 and \sc_reply1 = 0}{<span class="oef_indbad">
Vous avez trouv� comme valeur approch�e du coefficient directeur de cette tangente : \reply1.<br /> Cette valeur est loin de la valeur exacte.</span>
Vous allez maintenant en d�terminer par le calcul la valeur exacte.}
</td></tr></table>
\if{\step = 2}{La courbe est la repr�sentation graphique de la fonction \(f) d�finie par \(f(x) = \Tf)<br />
Le point \(A) a comme abscisse \(\x0).<br />
<label for="reply2">La d�riv�e de la fonction \(f) est d�finie par \(f'(x) = )</label>\embed{reply2}<p>
<label for="reply3">Le coefficient directeur de la tangente � la courbe en \(A) est</label> \embed{reply3} <b> Donner sa valeur exacte</b></p>}
}

\answer{coefficient directeur de la tangente}{\p0-1,\p0+1}{type =range }{option = nonstop}
\answer{}{\fp}{type = formal}
\answer{}{\p0}{type = numexp}
