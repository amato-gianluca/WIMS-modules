target=lenpolclose lenpolopen lenpolspiral

#include "xiao.inc"
\integer{c1=random(1..5)*random(-1,1)}
\integer{c2=random(1..5)*random(-1,1)}
\integer{c3=random(1..5)*random(-1,1)}
#if #TARGET (lenpolclose)
 #define cpptit closed
 \text{pi1=random(0,pi)}
 \text{pi2=random(0,pi/2,pi,3*pi/2)}
 \text{pi3=random(0,2*pi/3,4*pi/3)}
 \text{data=randomrow(
  \c1*random(sin,cos)(t)random(+,-)\c1,,0,2*pi,0,2*pi
  \c1*random(sin,cos)(t+\c2)random(+,-)\c1,,0,2*pi,0,2*pi
  \c1*random(sin,cos)(2*t)random(+,-)\c1,,0,2*pi,0,2*pi
  \c1*cos(2*t)-\c1,,\pi1,\pi1+pi,0,2*pi
  \c1*sin(2*t)+\c1,,\pi1-pi/4,\pi1+3*pi/4,0,2*pi
  \c1*sin(2*t),,\pi2,\pi2+pi/2,0,2*pi
  \c1*cos(2*t),,\pi2-pi/4,\pi2+pi/4,0,2*pi
  \c1*random(sin,cos)(2*t),,0,2*pi,0,2*pi
  \c1*random(sin,cos)(2*t+\c2),,0,2*pi,0,2*pi
  \c1*random(sin,cos)(3*t),,0,pi,0,pi
  \c1*sin(3*t),,\pi3,\pi3+pi/3,0,pi
  \c1*cos(3*t),,\pi3-pi/6,\pi3+pi/6,0,pi
 )}
#endif
#if #TARGET (lenpolopen)
 #define cpptit open
 \real{t1=randint(0..50)/10}
 \real{t2=randint(10*\t1+10..10*\t1+50)/10}
 \real{n1=randint(-50..0)/10}
 \real{n2=randint(10*\t1+10..10*\t1+50)/10}
 \text{data=randomrow(
  t^2+\c1*t+\c2,,\t1,\t2
  t^2+\c1*t+\c2,,\n1,\n2
  \c1*random(sin,cos)(t/random(2,3,4,5,6))-\c2,,\t1,\t2
 )}
#endif
#if #TARGET (lenpolspiral)
 #define cpptit spiral
 \integer{t1=randint(1..20)}
 \integer{t2=randint(\t1+5..\t1+20)}
 \integer{n1=randint(-20..-1)}
 \integer{n2=randint(\t1+5..\t1+20)}
 \real{s1=randint(2..50)/random(-100,100)}
 \real{s2=randint(2..20)/random(-100,100)}
 \text{data=randomrow(
  \s1*t+\c1,(spiral of Archimedes),\t1,\t2
  \s1*t+\c1,(spiral of Archimedes),\n1,\n2
  exp(\s2*t+\c1),(logarithmic spiral),\n1,\n2
  \c2*exp(\s2*t),(logarithmic spiral),\n1,\n2
  \c1*(t+\c2)^2,(parabolic spiral),\t1,\t2
  \c1*(t+\c2)^2,(parabolic spiral),\n1,\n2
)}
#endif

\title{Polar length cpptit}
\computeanswer{no}

text{data=
  \c1*t,,\t1,\t2
}

\function{r=item(1,\data)}
\text{cname=item(2,\data)}
\function{t1=item(3,\data)}
\function{t2=item(4,\data)}

#if #TARGET (lenpolclose)
 \function{pt1=item(5,\data)}
 \function{pt2=item(6,\data)}
#else
 \real{tr=\t2-(\t1)}
 \real{pt1=\t1-(\tr)}
 \real{pt2=\t2+(\tr)}
#endif
\text{mm=slib(function/bounds \r,t,\t1,\t2)}
\text{m1=item(1,\mm)}
\text{m2=item(2,\mm)}
\real{max=1.15*max(abs(\m1),abs(\m2))}
\function{dr=diff(\r,t)}
\real{len=integrate(sqrt((\r)^2+(\dr)^2),t=\t1..\t2)}

\statement{The following curve \cname is defined by the polar equation
\(r = \r), where \(t) is the polar angle.
#if #TARGET (lenpolclose)
 Compute the length of
 \if{\t1!=\pt1 or \t2!=\pt2}{the marked part of} 
 this curve.
#else
 Compute the length of this curve
 for \(t) going from \(\t1) to \(\t2).
#endif
<p><center>
\draw{200,200}{
 xrange -\max,\max
 yrange -\max,\max
 fill 0,0,white
 tstep 500
 trange \pt1,\pt2
 arrow 0,0,\max,0,12,grey
 disk 0,0,6,red
 plot skyblue,(\r)*cos(t),(\r)*sin(t)
 trange \t1,\t2
 linewidth 2
 plot blue,(\r)*cos(t),(\r)*sin(t)
}
</center>
}

\answer{The length}{\len}{type=number}

