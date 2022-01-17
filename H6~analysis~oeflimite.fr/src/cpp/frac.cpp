target=frac

#include "header.inc"
#include "lang_titles.inc"




\text{infd=\(+\infty)}
\text{infg=\(-\infty)}
\text{listinf=\infd, \infg}
\text{lstlim=a comme limite 0, a une limite finie non nulle, a une limite infinie, n'a pas de limite}

\integer{a1=randint(1..9)*randint(1,-1)}
\integer{a2=randint(1..9)*randint(1,-1)}
\integer{b1=randint(1..9)*randint(1,-1)}
\integer{b2=randint(1..9)*randint(1,-1)}
\integer{c1=randint(1..9)*randint(1,-1)}
\integer{c2=randint(1..9)*randint(1,-1)}
\integer{n=randint(1..6)}
\integer{choix=randint(1..4)}

 
 \integer{indpos=randint(1,2)}
 \text{pos=\indpos=1?+\infty:-\infty}

\rational{coef=\c1/\c2}

\if{\choix=1}
   { \text{mstep=r1
                 r3}
     \if{\coef>0}{\text{liminf=\infd}}
              {\text{liminf=\infg}}
    \integer{n2=\n}
    \integer{n1=\n+randint(2,4)}
    \integer{indlim=3}
   }
 \if{\choix=2}
   { \text{mstep=r1
             r2}
      \integer{n1=\n}
      \integer{n2=\n}
    \integer{indlim=2}
    }
 \if{\choix=3}
    { \text{mstep=r1}
       \integer{n1=\n}
       \integer{n2=\n+randint(1..4)}
      \integer{indlim=1}
     }
 \if{\choix=4}
    { \text{mstep=r1
                  r3}
       \integer{n2=\n}
       \integer{n1=\n+randint(1,3)}
       \integer{indlim=3}
     \if{(\coef>0 and \indpos=1) or (\coef < 0 and \indpos=2)}{\text{liminf=\infd}}
              {\text{liminf=\infg}}
     }

\integer{i1 = randint(0..\n1-1)} 
\function{numerateur = random(pari(\c1*x^\n1)+pari(\a1*x^\i1),pari(\a1*x^\i1)+pari(\c1*x^\n1)) }
\if{\i1>0}{\integer{j1 = randint(0..\i1-1)}
\function{numerateur = random(\numerateur + pari(\b1*x^\j1) ,pari(\b1*x^\j1) +\numerateur ) }}
 
\integer{i2 = randint(0..\n2-1)} 
\function{denominateur = random(pari(\c2*x^\n2)+pari(\a2*x^\i2),pari(\a2*x^\i2)+pari(\c2*x^\n2)) }
\if{\i2>0}{\integer{j2 = randint(0..\i2-1)}
\function{denominateur = random(\denominateur+pari(\b2*x^\j2) ,pari(\b2*x^\j2) +\denominateur ) }}     

\text{f=(\numerateur)/(\denominateur)}
\text{ft=texmath(\f)}
 


\text{mstep=r4,r5
\mstep}
\text{nc=pari(\c1*x^\n1)}
\text{dc=pari(\c2*x^\n2)}
\steps{\mstep
}


#include "lang.inc"

\statement{
On veut d�terminer la limite �ventuelle en \(\pos) de la fonction \(f) d�finie par:
<p class ="wimscenter"> \(f(x)=\ft) </p>

\if{\step=1}{
En \(\pos), quels sont les termes pr�pond�rants au num�rateur et au d�nominateur ?
<table class="wimsnoborder wimscenter">
<tr><td> Au num�rateur</td><td>\embed{reply4,7}</td></tr>
<tr><td> Au d�nominateur</td><td>\embed{reply5,7}</td></tr>
</table>
}
{
En \(\pos), les termes pr�pond�rants au num�rateur et au d�nominateur sont:
<table class="wimsnoborder wimscenter">
<tr><td> Au num�rateur</td><td>\(\nc)</td></tr>
<tr><td> Au d�nominateur</td><td>\(\dc)</td></tr>
</table>
}
\if{\step=2}{
Choisissez la bonne r�ponse:<br />
En \(\pos), la fonction \(f) \embed{reply 1}
}
\if{\step=3}{
 \if{\indlim=2}{
Quelle est la limite finie de \(f) en \(\pos)?<br />
\(\displaystyle{\lim_{x \rightarrow \pos}f(x) = }) \embed{reply 2}
 }
 {
Choisissez la bonne r�ponse:<br />
\(\displaystyle{\lim_{x \rightarrow \pos}f(x) = }) \embed{reply 3}
  
 }
}
}
\answer{type limite}{\indlim;\lstlim}{type=menu}
\answer{}{\coef}{type=numexp}
\answer{}{\liminf;\infg,\infd}{type=clickfill}
\answer{num�rateur}{\nc}{type=formal}
\answer{d�nominateur}{\dc}{type=formal}
