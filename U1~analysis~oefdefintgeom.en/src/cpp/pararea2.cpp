target=pararea2

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\integer{qc=random(2..8)}
\integer{c1=random(5..20)}
\integer{c2=random(1.7*\c1..2.5*\c1)}
\text{x=x}
\real{sol=4*(\c2^(3/2)-\c1^(3/2))/(3*sqrt(\qc))}



#include "lang.inc"

\statement{Compute the area of the shaded region below, where
<font color=red><i>C</i></font> is the curve of the function
<i>f</i>(x)&nbsp;=&nbsp;\qc\x<sup>2</sup>, and the two lines
<font color=green><i>L</i><sub>1</sub></font> and
<font color=green><i>L</i><sub>2</sub></font>
are given by y=\c2 and y=\c1 respectively.
<p><center>
<img src=\imagedir/area.gif></center> <p>
Please give your result of computation with a precision of at least
5 decimal places.}

\answer{The area}{\sol}
\hint{Exchange x and y before making a definite integral!}

