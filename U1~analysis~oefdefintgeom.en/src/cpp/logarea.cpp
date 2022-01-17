target=logarea

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\function{fn=ln(randint(2..10)*x^randint(2..10))}
\function{primitive=integrate(\fn,x)}
\real{root=solve(\fn,x=0.01..10)}
\real{bias=evalue(\primitive,x=\root)}
\integer{area=random(5..30)}
\real{c=solve(\primitive-(\bias)-\area,x=\root..100)}
\real{max=evalue(\fn,x=\c)}
\real{x1=-random(0.06..0.2)*\c}
\real{x2=random(1.1..1.3)*\c}
\real{y1=-random(0.2..0.4)*\max}
\real{y2=random(1.2..1.4)*\max}
\function{ft=evalue(\fn,x=t)}


#include "lang.inc"

\statement{Consider the function \(f(x)=\fn). The following picture shows 
the curve of \f(x). The red vertical line in the picture is given by 
an equation x=c. Given that the blue region has an area equal to
\area, what is the value of c?
<p><center>
\draw{280,200}{xrange \x1,\x2
yrange \y1,\y2
arrow \x1,0,\x2,0,10,grey
arrow 0,\y1,0,\y2,10,grey
text grey,0.95*\x2,0.1*\y2,small,x
text grey,0.03*\x2,0.98*\y2,small,y
trange 0,\x2
plot black,t,\ft
vline \c,0,red
fill 0.8*\c,0.2*\max,skyblue
}
</center> <p>
Please give your reply with a precision of at least 4 digits after
the decimal point.}


\answer{c}{\c}{type=default}



