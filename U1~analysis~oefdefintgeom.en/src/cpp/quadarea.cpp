target=quadarea

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\real{a=randint(5..20)/10}
\real{b=randint(50..300)/50*random(-1,1)}
\real{delta=(\b)^2/(4*\a)}
\real{c=randint(100..500)/100}
\integer{sign=random(-1,1)}
\real{aa=\sign*\a}
\real{cc=\sign*(-\c+floor(100*\delta)/100)}
\function{fn=\aa*x^2+\b*x+\cc}
\function{func=\aa*x^2+\b*x+c}
\function{primitive=\aa*x^3/3+\b*x^2/2+\cc*x}
\real{r1=(-(\b)-sqrt((\b)^2-4*(\aa)*(\cc)))/(2*\aa)}
\real{r2=(-(\b)+sqrt((\b)^2-4*(\aa)*(\cc)))/(2*\aa)}
\real{rmid=-(\b)/(2*\aa)}
\real{area=abs(evalue(\primitive,x=\r2)-evalue(\primitive,x=\r1))}
\real{rmin=min(\r1,\r2)}
\real{rmax=max(\r1,\r2)}
\real{rdist=\rmax-\rmin}
\real{x1=\rmin-\rdist*0.3}
\real{x2=\rmax+\rdist*0.3}
\real{xdist=\x2-\x1}
\real{y1=\sign>0?-\c*1.3:-\c*0.3}
\real{y2=\sign>0?\c*0.3:\c*1.3}
\real{ydist=\y2-\y1}



#include "lang.inc"

\statement{Consider the function \(f(x)=\func). Its curve is shown by the
following picture. Given that the area of the yellow region is equal to
\area, what is the value of c?
<p><center>
\draw{280,200}{xrange \x1,\x2
yrange \y1,\y2
plot black,\fn
arrow \x1,0,\x2,0,10,grey
fill \rmid,\sign*(-1)*0.1,yellow
arrow 0,\y1,0,\y2,10,grey
text grey,\x2-0.04*\xdist,0.07*\ydist,small,x
text grey,0.03*\xdist,\y2-0.01*\ydist,small,y
}
</center> <p>
Please give your reply with a precision of at least 2 digits after
the decimal point.}

\answer{c}{\cc}{type=default}



