target=der4

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\author {Chantal, Causse}
\email {Chantal.Causse@noos.fr}
\format {html}
\integer{a1=random(-4..4)}
\integer{a2=random(-4..4)}
\integer{a3=random(-4..4)}
\integer{c1=random(1..8)*random(1,-1)}
\integer{c2=random(1..8)*random(1,-1)}
\integer{c3=random(1..8)*random(1,-1)}
\integer{c4=random(1..8)*random(1,-1)}
\function{lin=\c1*x+\c2}
\function{lin1 = pari(\c3*x+\a1)}
\function{lin2=(\c3*x+\c4)/\c2}
\function{tri=\c1*x^2+\c2*x+\c3}
\function{tri2=pari(\c1*x^2+\a1*x+\a2)}
\function{pol = pari(\c1*x^3+\a1*x^2+\a2*x+\a3)}
\function{f=randitem(
 ln(\pol),
 (\lin)+\c3*ln(x),
 \pol+ln(\lin),
  \tri2+\c4*ln(x),
 \c1*ln(x+\c2),
 \c3*ln(\lin)
)}
\function{F=diff(\f,x)}
\text{ft=texmath(\f)}
\text{Ft=texmath(\F)}
\text{aide = \Laderivee \(\ln(u)) \est \(\frac{u'}{u}).<br />}

\statement{\name_statement1 <label for="reply1"> \name_statement2 \(f) \name_statement3 \(f(x) = \ft)</label>.<br />
\notation
}
\answer{\(f'(x))}{\F}{type=formal}
\hint{\Si \(f(x)=x^{n}), \alors \(f'(x)=n x^{n - 1}).<br />
\Laderivee \(u + v) \est \(u' + v').<br />
\Laderivee \(k u) \est \(k u'), \si \(k) \estconstante.<br />\aide}
