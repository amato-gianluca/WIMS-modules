target=asympt2hv

#include "header.inc"
#include "lang_titles.inc"


\integer{a = randint(-5..5)}
\integer{b = randint(1..5)*random(-1,1)}
\text{droite = texmath(pari(\b*x+\a))}
\text{i = random(+,-)}



\integer{choix = randint(1,2)}
\text{lieu = item(\choix,en \(\i \infty),)}
\text{equation = item(\choix,y = \a,x = \a)}
\text{rep1= item(\choix,\i inf,\a)}

\text{rep2= item(\choix,\a,inf)}

\text{rep1t= item(\choix,\i \infty,\a)}
\text{rep3t= item(\choix, \a,- \infty)}
\text{rep4t= item(\choix,, ou \(+ \infty),)}

\text{pinf = \(+ \infty)}
\text{minf = \(- \infty)}



#include "lang.inc"

\statement{On consid�re une fonction \(f) de courbe repr�sentative \(C) dans un rep�re orthogonal.
<br/>Pour montrer que la courbe \(C) admet la droite d'�quation \equation comme asymptote \lieu, il faut montrer que : <p>
la limite de \(f(x)) quand \(x) tend vers \embed{reply1,5} est �gale � \embed{reply2,5}
</p>
<b>Remarque</b> Pour �crire \minf, taper <tt>-inf</tt>, 
pour �crire \pinf, taper <tt>+inf</tt>.<br/>
Pour �crire " \pinf ou \minf ", taper <tt>inf</tt>.

}

\answer{}{\rep1}{type = raw}{option = nospace}

\answer{}{\rep2}{type = raw}{option = nospace}

\feedback{1=1}{
Pour montrer que la courbe \(C) admet la droite d'�quation \equation comme asymptote \lieu, il faut montrer que : 
\(\lim_{x \to \rep1t} f(x) = \rep3t) \rep4t
}
