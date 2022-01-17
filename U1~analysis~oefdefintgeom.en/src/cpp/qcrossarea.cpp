target=qcrossarea

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\real{b=randint(20..30)/10}
\real{c=randint(11..50)/10}
\real{v=randint(50..80)/10}
\function{qua=x^2-\b*x-\c}
\real{r1=(\b+sqrt(\b^2+4*\c))/2}
\function{prim=x^3/3-0.5*\b*x^2-\c*x}
\real{x1=evalue(\prim,x=\r1)}
\real{x2=evalue(\prim,x=\v)}
\real{sol=abs(2*(\x1)-(\x2))}
\integer{r=random(1..4)}
\text{f=item(\r,x^2 - \b*x - \c,
		x^2 + \b*x - \c,
		-x^2 + \b*x + \c,
		-x^2 - \b*x + \c)}
\text{f=htmlmath(\f)}
\text{img=item(\r,q11,q12,q21,q22)}
\text{x0=item(\r,\v,-\v,\v,-\v)}



#include "lang.inc"

\statement{Compute the area of the blue region below, where
<font color=red>C</font> is the graph of the function
<i>f</i>(x)&nbsp;=&nbsp;\f, and <font color=red>L</font> is the line
x&nbsp;=&nbsp;\x0.
<p><center>
<img src=\imagedir/\img.gif></center> <p>
Please give your result of computation with a precision of at least
5 decimal places.}

\answer{The area}{\sol}

