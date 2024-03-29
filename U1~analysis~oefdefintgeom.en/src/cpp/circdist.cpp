target=circdist

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\real{r=randint(20..50)/10}
\real{d=randint(10..100)/10}
\function{f=sqrt((\r*cos(x))^2+(\r*sin(x)+\d)^2)}
\real{dist=int(\f/(2*pi),x=0..2*pi)}



#include "lang.inc"

\statement{A point \(A) turns around a circle of radius \r with constant
speed, and another point \(B) stays at a constant position at distance of
\d towards the center of the circle. Compute the average distance between
the two points.
<p>
Please give your reply with a precision of at least 4 digits after the
decimal point.
}

\answer{The average distance}{\dist}{type=number}

