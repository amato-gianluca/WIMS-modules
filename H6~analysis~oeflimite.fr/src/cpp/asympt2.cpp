target=asympt2

#include "header.inc"
#include "lang_titles.inc"


\integer{a = randint(-5..5)}
\integer{b = randint(1..5)*random(-1,1)}
\text{droite = texmath(pari(\b*x+\a))}
\text{i = random(+,-)}



\integer{choix = randint(1..3)}
\text{lieu = item(\choix,en \(\i \infty),,en \(\i \infty))}
\text{equation = item(\choix,y = \a,x = \a,y = \droite)}
\text{rep1= item(\choix,\i inf,\a,\i inf)}
\text{rep2= item(\choix,f(x),f(x),f(x)-(\droite))}
\text{rep3= item(\choix,\a,inf,0)}

\text{rep1t= item(\choix,\i \infty,\a,\i \infty)}
\text{rep3t= item(\choix, \a,- \infty , 0)}
\text{rep4t= item(\choix,, ou \(+ \infty),)}

\text{pinf = \(+ \infty)}
\text{minf = \(- \infty)}



#include "lang.inc"

\statement{On consid�re une fonction \(f) de courbe repr�sentative \(C) dans un rep�re orthogonal.
<br/>Pour montrer que la courbe \(C) admet la droite d'�quation \equation comme asymptote \lieu, il faut montrer que : <p>
la limite de \embed{reply2,10} quand \(x) tend vers \embed{reply1,5} est �gale � \embed{reply3,5}
</p>
<b>Remarque</b> Pour �crire \minf, taper <tt>-inf</tt>, 
pour �crire \pinf, taper <tt>+inf</tt>.<br/>
Pour �crire " \pinf ou \minf ", taper <tt>inf</tt>.

}

\answer{}{\rep1}{type = raw}{option = nospace}
\answer{}{\rep2}{type = formal}
\answer{}{\rep3}{type = raw}{option = nospace}

\feedback{1=1}{
Pour montrer que la courbe \(C) admet la droite d'�quation \equation comme asymptote \lieu, il faut montrer que : 
\(\lim_{x \to \rep1t} \rep2 = \rep3t) \rep4t
}
