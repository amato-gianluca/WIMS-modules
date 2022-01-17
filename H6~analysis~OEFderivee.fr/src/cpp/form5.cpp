target=form5

#include "header.inc"
#include "lang_titles.inc"

%% This file is generated by preprocessor!
%% Do not edit it by hand.
%% Edit the source file cpp/formule.cpp.

\author {Chantal, Causse}
\email {Chantal.Causse@noos.fr}
\format {html}
\integer{k=random(1..8)*random(-1,1)}
\integer{a1=random(1..5)*random(-1,1)}
\integer{a2=random(1..5)*random(-1,1)}
\integer{a3=random(1..5)*random(-1,1)}
\integer{a4=random(1..5)*random(-1,1)}
\integer{b1=random(1..8)}
\integer{b2=random(1..8)}
\integer{b3=random(1..8)}
\integer{b4=random(1..8)}
************
**************
***********
***************************
********************
\text{liste = \a1/x,\a2*sqrt(x),1/(\a3*x),sqrt(x)/\a4}
\text{liste = shuffle(\liste)}
\text{f1 = \liste[1]}
\text{f2 = \liste[2]}
\text{f3 = \liste[3]}
\text{liste2 = \k,\a1*x,\a2*x^2,\a3*x^3,\a4*x^4}
\text{Liste = shuffle(\liste2)}
\text{f4 = \Liste[1]+\liste[4]}
\text{f5 = \Liste[2]-\liste[3]}
\text{f6 = \liste[1]- \Liste[3]}
\text{notation = <div class="wims_instruction">
Pour �crire \(sqrt(3x)) par exemple, taper : sqrt(3x).
 </div>}
\text{indication = Si \(f(x)=\frac{1}{x}), alors \(f'(x)=\frac{-1}{x^{2}})<br />
Si \(f(x)=\sqrt{x}), alors \(f'(x)=\frac{1}{2\sqrt{x}})
}
**********************
\text{f1t = texmath(\f1)}
\text{f2t = texmath(\f2)}
\text{f3t = texmath(\f3)}
\text{f4t = texmath(\f4)}
\text{f5t = texmath(\f5)}
\text{f6t = texmath(\f6)}
\text{fonctions=\f1t, \f2t, \f3t, \f4t, \f5t, \f6t}
\function{d1 = diff(\f1,x)}
\function{d2 = diff(\f2,x)}
\function{d3 = diff(\f3,x)}
\function{d4=diff(\f4,x)}
\function{d5=diff(\f5,x)}
\function{d6=diff(\f6,x)}
\function{derivees=\d1,\d2,\d3,\d4,\d5,\d6}


#include "lang.inc"

\statement{
<ul>
\for{ j = 1 to 6 }
{<li> Si \(f(x)=\fonctions[\j]), <label for="reply\j"> alors \(f'(x))=</label>\embed{reply\j,15}</li>}
</ul>
\notation
}
\answer{D�riv�e de \(\f1t)}{\d1}{type=formal}
\answer{D�riv�e de \(\f2t)}{\d2}{type=formal}
\answer{D�riv�e de \(\f3t)}{\d3}{type=formal}
\answer{D�riv�e de \(\f4t)}{\d4}{type=formal}
\answer{D�riv�e de \(\f5t)}{\d5}{type=formal}
\answer{D�riv�e de \(\f6t)}{\d6}{type=formal}
\solution{<p>
\for{ j = 1 to 3}
{Si \(f(x)=\fonctions[\j]), alors \(f'(x))= \(\derivees[\j]).<br />
}</p><p>
\for{ j = 4 to 6}
{Si \(f(x)=\fonctions[\j]), alors \(f'(x))= \(\derivees[\j]).<br />
}</p>
}
\hint{Si \(f(x)=ax + b), alors \(f'(x)=a).<br />
Si \(f(x)=x^{n}), alors \(f'(x)=n x^{n-1})<br />\indication.
}
