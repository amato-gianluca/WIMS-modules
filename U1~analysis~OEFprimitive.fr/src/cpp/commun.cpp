target= cosinus,sinus,expo,puissn,inverse

\language{fr}
\range{-5..5}
\author{Fabrice,Guerimand}
\email{fwguerima@free.fr}
\computeanswer{no}
\format{html}
\precision{100000}

\text{f=randitem(f,g,h,u,v)}
\text{F=wims(upper \f)}
\text{x=randitem(x,y,t)}
\text{lt=wims(values v,-v for v=2 to 10)}
\text{lt=shuffle(\lt,-1)}

choix de la fonction u
\text{lch=wims(listintersect \confparm1 and 1,2,3,4,5,6)}
\text{lch=\lch=?1,2,3,4,5,6}
\integer{ch=randitem(\lch)}
\if{\ch=1}{
  \text{u=\lt[1]*\x+\lt[2]}
}
\if{\ch=2}{
  \integer{d=randitem(2,3)}
  \text{u=\lt[1]*\x+\lt[2]}
  \for{k=2 to \d}{\text{u=\u+\lt[\k+1]*\x^\k}}
}
\if{\ch=3}{\text{u=randitem(ln(\lt[1]*\x),exp(\lt[1]*\x))}}
\if{\ch=4}{\text{u=randitem(cos(\lt[1]*\x),sin(\lt[1]*\x))}}
\if{\ch=5}{\text{u=randitem(sqrt(\x),1/sqrt(\x),1/\x^2,1/\x^3,\x*sqrt(\x))}}
\if{\ch=6}{
  \integer{d=randitem(2,3)}
  \text{u=\lt[1]*\x+\lt[2]}
  \for{k=2 to \d}{\text{u=\u+\lt[\k+1]*\x^\k}}
  \text{u=exp(\u)}
}

#if #TARGET (cosinus)
 \title{Forme u'cos(u)}
 \text{sol=sin(\u)}
#endif

#if #TARGET (sinus)
 \title{Forme u'sin(u)}
 \text{sol=cos(\u)}
#endif

#if #TARGET (expo)
 \title{Forme u'exp(u)}
 \text{sol=exp(\u)}
#endif

#if #TARGET (puissn)
 \title{Forme u'u^n}
 \integer{n=randitem(-2,-3,2,3)}
 \text{sol=(\u)^\n}
#endif

#if #TARGET (inverse)
 \title{Forme u'/u}
 \if{(\ch=2 and \d=2) and \lt[3]<0}{
  \text{u=simplify(-(\u))}
 }
 \text{sol=ln(\u)}
 \text{ua=texmath(\u)}
 \text{compenonce=, sur un intervalle o� la fonction \(\x \mapsto \ua) est strictement positive,}
#endif


\text{sol=1/\lt[-1]*\sol}
\text{formule=diff(\sol,\x)}
\text{aff=texmath(\formule)}
\statement{D�terminer\compenonce une primitive de la fonction \(\f:\x\mapsto \aff).}

\answer{\F(\x)}{\rep}{type=auto}

\integer{test=diff(\rep-\sol,\x)}
\condition{Analyse}{\test=0}
