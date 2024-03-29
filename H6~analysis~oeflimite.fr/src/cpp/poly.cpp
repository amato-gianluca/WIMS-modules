target=poly

#include "header.inc"
#include "lang_titles.inc"




\text{infd=\(+\infty)}
\text{infg=\(-\infty)}
\text{listinf=\infd, \infg}


\integer{a1=randint(1..9)*randint(1,-1)}
\integer{a2=randint(1..9)*randint(1,-1)}
\integer{a3=randint(1..9)*randint(1,-1)}
\integer{a4=randint(1..9)*randint(1,-1)}
\integer{a5=randint(1..9)*randint(1,-1)}
\text{coef = \a2,\a3,\a4,\a5}

\integer{n=randint(1..8)}
 \integer{choix=randint(1,2)}
 \text{pos=\choix=1?+\infty:-\infty}
\if{(\a1>0 and \choix=1) or (\a1*(-1)^\n > 0 and \choix=2)}{\text{liminf=\infd}}
              {\text{liminf=\infg}}

\text{expo=randint(0..\n-1) }
\for{i=1 to 3}{
	\if{\expo[\i]>0}{\text{expo = \expo,randint(0..\expo[\i]-1)}}
	}
     
\function{f=pari(\a1*x^\n)}
\for{k=1 to items(\expo)}{
	\function{f = random(\f+pari(\coef[\k]*x^\expo[\k]), pari(\coef[\k]*x^\expo[\k]) + \f)}
}



\text{ft=texmath(\f)}
 



\text{nc=pari(\a1*x^\n)}




#include "lang.inc"

\statement{
On veut déterminer la limite éventuelle en \(\pos) de la fonction \(f) définie par:
<p class ="wimscenter"> \(f(x)=\ft) </p>



En \(\pos), le terme prépondérant est:\embed{reply1,7}



\(\displaystyle{\lim_{x \rightarrow \pos}f(x) = }) \embed{reply2,150}
}  
\answer{terme prépondérant}{\nc}{type=formal}
\answer{}{\liminf;\infg,\infd,0,une autre limite}{type=clickfill}
