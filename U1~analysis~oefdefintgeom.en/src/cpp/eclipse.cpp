target=eclipse

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\real{dist=round(random(350..550))/1000}
\real{d=\dist/2}
\real{sol=100-200*(\d*sqrt(1-\d^2)+asin(\d))/pi}



#include "lang.inc"

\statement{Here we have a partial sun eclipse, where the shade of the moon
has a radius exactly equal to that of the sun, and the distance between the
centers of the sun and the moon equals \dist times the radius of the sun.
Compute the percentage of the eclipse, that is, the percentage of the
sun surface (as a disk) hidden by the moon.
<p><center>
<img src=\imagedir/eclipse.gif></center> <p>
Please give the result of your computation with a precision of 0.1% or
better.}

\answer{The percentage}{\sol}


