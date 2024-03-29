target=der1

#include "header.inc"
#include "lang_titles.inc"

%% This file is generated by preprocessor!
%% Do not edit it by hand.
%% Edit the source file cpp/derivee.cpp.


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
\lin,
\tri,
\tri2,
\pol
)}
\function{f = simplify(\f)}
\function{F=diff(\f,x)}
\text{ft=texmath(\f)}
\function{F = pari(\F)}
\text{Ft = texmath(\F)}


#include "lang.inc"

\statement{Calculez la <label for="reply1"> d�riv�e de la fonction \(f) d�finie par \(f(x) = \ft)</label>.<br />
\notation
}
\answer{\(f'(x))}{\F}{type=formal}
\hint{Si \(f(x)=x^{n}), alors \(f'(x)=n x^{n - 1}).<br />
La d�riv�e de \(u + v) est \(u' + v').<br />
La d�riv�e de \(k u) est \(k u'), si \(k) est une constante.<br />\aide}
