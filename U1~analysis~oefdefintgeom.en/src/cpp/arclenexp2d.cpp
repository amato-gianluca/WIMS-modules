target=arclenexp2d

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\real{c1=randint(4..20)*random(-0.1,0.1)}
\real{c2=randint(4..20)*random(-0.1,0.1)}
\real{c3=randint(4..20)*random(-0.1,0.1)}
\real{c4=randint(4..20)*random(-0.1,0.1)}
\text{data=randomrow(
 \c1*x^2+\c2*x+\c3,-20,-4,4,20
 \c1*random(cos,sin)(x+\c2)+\c3*x,-40,-10,10,40
)}

\function{fn=item(1,\data)}
\integer{x11=item(2,\data)}
\integer{x12=item(3,\data)}
\integer{x21=item(4,\data)}
\integer{x22=item(5,\data)}
\real{x1=randint(\x11..\x12)/10}
\real{x2=randint(\x21..\x22)/10}
\real{xrange=\x2-(\x1)}
\real{px1=\x1-\xrange*0.15}
\real{px2=\x2+\xrange*0.15}
\text{ybounds=slib(function/bounds \fn,x,\px1,\px2)}
\real{y1=item(1,\ybounds)}
\real{y2=item(2,\ybounds)}
\real{yrange=\y2-(\y1)}
\real{py1=\y1-\yrange*0.1}
\real{py2=\y2+\yrange*0.1}
\function{der=diff(\fn,x)}
\real{len=integrate(sqrt(1+(\der)^2),x=\x1..\x2)}



#include "lang.inc"

\statement{Compute the length of the curve \(y = \fn), between \(x = \x1) and
\(x = \x2).
<p><center>
\draw{280,200}{xrange \px1,\px2
yrange \py1,\py2
arrow \px1,0,\px2,0,10,grey
arrow 0,\py1,0,\py2,10,grey
plot skyblue,\fn
trange \x1,\x2
linewidth 3
plot blue,\fn
}
</center> <p>
<small>Please give your reply with a precision of at least 4 digits after
the decimal point.</small>
}

\answer{The length}{\len}{type=number}

