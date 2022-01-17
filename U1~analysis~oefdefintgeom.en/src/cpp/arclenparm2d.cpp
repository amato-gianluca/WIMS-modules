target=arclenparm2d

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\real{c1=randint(4..20)*random(-0.1,0.1)}
\real{c2=randint(4..40)*random(-0.1,0.1)}
\real{c3=randint(4..20)*random(-0.1,0.1)}
\real{c4=randint(4..20)*random(-0.1,0.1)}
\real{c5=randint(4..40)*random(-0.1,0.1)}
\real{c6=randint(4..20)*random(-0.1,0.1)}
\function{f=\c1*t^random(2,3)+\c2*t+\c3}
\function{g=\c4*t^random(2,3)+\c5*t+\c6}

\real{t1=randint(-25..-8)/10}
\real{t2=randint(8..25)/10}
\real{trange=\t2-(\t1)}
\real{pt1=\t1-\trange*0.3}
\real{pt2=\t2+\trange*0.3}
\text{xbounds=slib(function/bounds \f,t,\t1,\t2)}
\real{x1=item(1,\xbounds)}
\real{x2=item(2,\xbounds)}
\real{xrange=\x2-(\x1)}
\real{px1=\x1-\xrange*0.15}
\real{px2=\x2+\xrange*0.15}
\text{ybounds=slib(function/bounds \g,t,\t1,\t2)}
\real{y1=item(1,\ybounds)}
\real{y2=item(2,\ybounds)}
\real{yrange=\y2-(\y1)}
\real{py1=\y1-\yrange*0.15}
\real{py2=\y2+\yrange*0.15}
\function{df=diff(\f,t)}
\function{dg=diff(\g,t)}
\real{len=integrate(sqrt((\df)^2+(\dg)^2),t=\t1..\t2)}



#include "lang.inc"

\statement{Compute the length of the parametric curve
<p><center>
	\( ( x = \f , y = \g ) ) ,
</center> <p>
between \(t = \t1) and \(t = \t2).
<p><center>
\draw{280,200}{xrange \px1,\px2
yrange \py1,\py2
trange \pt1,\pt2
arrow \px1,0,\px2,0,10,grey
arrow 0,\py1,0,\py2,10,grey
plot skyblue,\f,\g
trange \t1,\t2
linewidth 3
plot blue,\f,\g
}
</center> <p>
<small>Please give your reply with a precision of at least 4 digits after
the decimal point.</small>
}

\answer{The length}{\len}{type=number}

