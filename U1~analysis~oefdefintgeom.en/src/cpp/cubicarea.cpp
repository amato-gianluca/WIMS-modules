target=cubicarea

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\integer{a=random(2..6)}
\integer{b=random(2..6)}
\text{c=random(-9,-8,-7,-6,-5,-4,-3,-2,-1,+1,+2,+3,+4,+5,+6,+7,+8,+9)}
\text{itype=random(cub1,cub2)}
\text{x=x}
\real{sol=0.75*\b^2/\a}



#include "lang.inc"

\statement{Compute the area of the shaded region below, where
<font color=red><i>C</i></font> is the curve of the function
<i>f</i>(x)&nbsp;=&nbsp;\a\x<sup>3</sup>-\b\x\c, and <font color=green><i>L</i></font>
is a horizontal line tangent to <font color=red><i>C</i></font>.
<p><center>
<img src=\imagedir/\itype.gif></center> <p>
Please give your result of computation with a precision of at least
5 decimal places.}

\answer{The area}{\sol}
\hint{You should compute first the equation of <i>L</i>, then
 the two intersection points of <i>L</i> with <i>C</i>, and
 finally make a definite integral.}

