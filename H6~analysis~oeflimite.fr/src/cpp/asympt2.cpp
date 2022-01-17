target=asympt2

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"


\integer{a = randint(-5..5)}
\integer{b = randint(1..5)*random(-1,1)}
\text{droite = texmath(pari(\b*x+\a))}
\text{i = random(+,-)}

\integer{choix = randint(1..3)}
\text{lieu = item(\choix,\en \(\i \infty),,\en \(\i \infty))}
\text{equation = item(\choix,y = \a,x = \a,y = \droite)}
\text{rep1= item(\choix,\i inf,\a,\i inf)}
\text{rep2= item(\choix,f(x),f(x),f(x)-(\droite))}
\text{rep3= item(\choix,\a,inf,0)}

\text{rep1t= item(\choix,\i \infty,\a,\i \infty)}
\text{rep3t= item(\choix, \a,- \infty , 0)}
\text{rep4t= item(\choix,, ou \(+ \infty),)}

\text{pinf = \(+ \infty)}
\text{minf = \(- \infty)}


\statement{\name_statement1 \(f) \name_statement2 \(C) \name_statement3.
<br/>\name_statement4 \(C) \name_statement5 \equation \name_statement6 \lieu, \name_statement7\sbc: <p>
\lalimitede \embed{reply2,10} \quand \(x) \tendvers \embed{reply1,5} \estegalea \embed{reply3,5}
</p>
<b>\Remarque</b> \Pourecrire \minf, \taper <tt>-inf</tt>,
\pourecrire \pinf, \taper <tt>+inf</tt>.<br/>
\Pourecrire " \pinf \ou \minf ", \taper <tt>inf</tt>.

}

\answer{}{\rep1}{type = raw}{option = nospace}
\answer{}{\rep2}{type = formal}
\answer{}{\rep3}{type = raw}{option = nospace}

\feedback{1=1}{
\name_statement4 \(C) \name_statement5 \equation \name_statement6 \lieu, \name_statement7\sbc:
\(\lim_{x \to \rep1t} \rep2 = \rep3t) \rep4t
}
