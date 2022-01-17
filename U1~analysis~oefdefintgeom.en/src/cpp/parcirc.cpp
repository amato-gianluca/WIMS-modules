target=parcirc

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\text{x=x}
\text{y=y}
\real{r=round(10*random(2..5))/10}
\real{a=round(10*random(1.5..3)/\r)/10}
\real{b=round(10*random(0.3*\r..0.7*\r))/10}
\text{texta=\a=1?:\a}
\real{circle=pi*\r^2}
\real{root=sqrt((2*\a*\b-1+sqrt(4*\a^2*\r^2-4*\a*\b+1))/(2*\a^2))}
\real{area1=evalue(x*sqrt(\r^2-x^2)+\r^2*asin(x/\r)-2*\a*x^3/3+2*\b*x,x=\root)}
\integer{type=random(1,2)}
\integer{vtype=random(1,2)}
\text{f=\vtype=1?\texta\x<sup>2</sup>-\b:-\texta\x<sup>2</sup>+\b}
\real{sol=item(\type,\area1,\circle-\area1)}



#include "lang.inc"

\statement{Compute the area of the shaded region below, where
<font color=red><i>C</i></font> is a circle of radius \r with center at the
origin, and <font color=green><i>P</i></font>
is the curve of the function <i>f</i>(x)&nbsp;=&nbsp;\f.
<p><center>
<img src=\imagedir/area\vtype\type.gif></center> <p>
Please give your result of computation with a precision of at least
5 decimal places.}

\answer{The area}{\sol}

