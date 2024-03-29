target=parabary

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\integer{a=random(2..5)}
\integer{b=random(2..5)}
\integer{type=random(1,2)}
\text{x=x}
\text{ft=\a-\b\x<sup>2</sup>}
\real{x0=\type=2?-0.375*sqrt(\a/\b):0.375*sqrt(\a/\b)}
\real{y0=0.4*\a}



#include "lang.inc"

\statement{Compute the barycenter
<i>p</i><sub>0</sub>=(x<sub>0</sub>,y<sub>0</sub>)
of the shaded region below, where
<font color=red><i>C</i></font> is the curve of the function
<i>f</i>(x) = \ft.
<p><center>
<img src=\imagedir/area\type.gif></center> <p>
Please give your result of computation with a precision of at least
5 decimal places.}

\answer{x<sub>0</sub>}{\x0}
\answer{y<sub>0</sub>}{\y0}

