target=ccrossarea

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\real{a=random(0.3,0.4,0.5)}
\real{b=randint(30..50)/10}
\real{c=randint(3..20)/10}
\function{cubic=\a*x^3-\b*x+\c}
\real{r1=solve(\cubic,x=-10..-2)}
\real{r2=solve(\cubic,x=-2..2)}
\real{r3=solve(\cubic,x=2..10)}
\function{prim=0.25*\a*x^4-0.5*\b*x^2+\c*x}
\real{x1=evalue(\prim,x=\r1)}
\real{x2=evalue(\prim,x=\r2)}
\real{x3=evalue(\prim,x=\r3)}
\real{sol=abs(2*(\x2)-(\x1)-(\x3))}
\integer{r=random(1..4)}
\text{f=item(\r,\a*x^3 - \b*x + \c,
		\a*x^3 - \b*x - \c,
		-\a*x^3 + \b*x + \c,
		-\a*x^3 + \b*x - \c)}
\text{f=htmlmath(\f)}
\text{img=item(\r,cubic11,cubic12,cubic21,cubic22)}



#include "lang.inc"

\statement{Compute the area of the blue region below, where
the red curve is that of the function
<i>f</i>(x)&nbsp;=&nbsp;\f.
<p><center>
<img src=\imagedir/\img.gif></center> <p>
Please give your result of computation with a precision of at least
5 decimal places.}

\answer{The area}{\sol}

