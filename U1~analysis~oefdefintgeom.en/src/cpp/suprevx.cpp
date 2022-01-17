target=suprevx

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\real{c1=randint(4..14)/10}
\real{c2=randint(1..14)/10}
\real{c3=randint(3..6)/10}
\real{c4=randint(10..20)/10}
\real{c5=randint(1..5)}
\real{c6=randint(1..3)}

\text{data=randomrow(
\c1*x^2-\c2*x+random(2,3,4),0
-\c3*x^2+\c4*x+randint(3..6),\c4/(2*\c3)
\c4*cos(\c6*x+\c5)+randint(3..6),-\c5/\c6
)}
\function{f=item(1,\data)}
\real{xm=item(2,\data)}
\real{x1=randint(-10..1)/10}
\real{x2=randint(10..30)/10}
\real{y1=evalue(\f,x=\x1)}
\real{y2=evalue(\f,x=\x2)}
\real{ym=evalue(\f,x=\xm)}
\real{xext=\x2-(\x1)}
\real{yext=max(\y1,\y2)}
\real{yext=max(\yext,\ym)}

\real{more=0.3}
\real{x0=\x1-\more*\xext}
\real{x3=\x2+\more*\xext}
\real{y0=-\more*\yext}
\real{y3=(1+\more)*\yext}
\real{xrange=\x3-(\x0)}
\real{yrange=\y3-(\y0)}
\function{diff=diff(\f,x)}
\real{sol=integrate(2*pi*(\f)*sqrt((\diff)^2+1),x=\x1..\x2)}
\if{random(1,2)=1}{
 \text{kind=lateral}
}{
 \text{kind=total}
 \real{sol=\sol+pi*((\y1)^2+(\y2)^2)}
}



#include "lang.inc"

\statement{Compute the \kind surface of the solid du solide resulting from the
rotation of the following red curve
<p><center>\(y = \f)</center> <p>
round the \(x) axis, for \(x) going from \x1 to \x2.
<p><center>
\draw{300,200}{
 xrange \x0,\x3
 yrange \y0,\y3
 arrow \x0,0,\x3,0,10,grey
 arrow 0,\y0,0,\y3,10,grey
 text black,\x3-0.04*(\xrange),0.08*(\yrange),small,x
 text black,0.03*(\xrange),\y3-0.02*(\yrange),small,y
 dline \x1,0,\x1,\y1,black
 dline \x2,0,\x2,\y2,black
 trange \x1,\x2
 plot red,\f
 v=0.3
 u=0.8
 r=\x3-0.12*(\xrange)
 m=0.03*\xrange
 n=0.07*\yrange
 trange v,2*pi-v
 plot black,m*cos(t)+r,n*sin(t)
 arrow m*cos(u)+r,n*sin(u),m*cos(v)+r,n*sin(v),8,black
}
</center>
}

\answer{The \kind surface}{\sol}
