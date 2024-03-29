target=fracdevinf

#include "header.inc"
#include "lang_titles.inc"

\text{dmax=7}

% Tirage al�atoire du type de limite : en +inf ou -inf.

\text{ordre=randint(1..1)}
\if{randitem(1,2)=1}{
\text{x0=-inf}
\text{xx0=-\infty}
}{
\text{x0=+inf}
\text{xx0=+\infty}
}

% Tirage al�atoire du nombre de termes du num�rateur et du d�nominateur.

\text{np=randitem(2,3)}
\text{nq=randitem(2,3)}

% Tirage al�atoire des degr�s du num�rateur et du d�nominateur.

\text{cas=randint(1..3)}
\if{\cas=1}{
\text{dp=randint(2..\dmax)}
\text{dq=\dp}
}
\if{\cas=2}{
\text{dp=randint(2..\dmax-1)}
\text{dq=randint(\dp+1..\dmax)}
}
\if{\cas=3}{
\text{dp=randint(3..\dmax)}
\text{dq=randint(2..\dp-1)}
}

% Cr�ation du num�rateur et du d�nominateur

\text{s=shuffle(\dp)}
\text{cp=wims(makelist 0 for x = 0 to \dmax)}
\for{i = 1 to \np-1}{
\text{k=\s[\i]}
\integer{c0=randitem(-1,1)*randint(1..5)}
\text{cp=pari(c=[\cp];c[\k]=\c0;c)}
}
\integer{c0=randitem(-1,1)*randint(1..5)}
\text{cp=pari(c=[\cp];c[\dp+1]=\c0;c)}

\text{s=shuffle(\dq)}
\text{cq=wims(makelist 0 for x = 0 to \dmax)}
\for{i = 1 to \nq-1}{
\text{k=\s[\i]}
\integer{c0=randitem(-1,1)*randint(1..5)}
\text{cq=pari(c=[\cq];c[\k]=\c0;c)}
}
\integer{c0=randitem(-1,1)*randint(1..5)}
\text{cq=pari(c=[\cq];c[\dq+1]=\c0;c)}


\if{\ordre=1}{
\text{s=wims(makelist x for x = 1 to \dmax+1)}
}{
\text{s=wims(makelist \dmax+1-x for x = 0 to \dmax)}
}
\text{P=}
\text{Pf=}
\for{i=1 to \dmax+1}{
\text{k=\s[\i]}
\ifval{\cp[\k]<>0}{
\text{P=\P + simplify(\cp[\k]*x^(\k-1))}
\text{Pf=\Pf + simplify(\cp[\k]/\cp[\dp+1]*x^(\k-1-\dp))}
}
}

\text{Q=}
\text{Qf=}
\for{i=1 to \dmax+1}{
\text{k=\s[\i]}
\ifval{\cq[\k]<>0}{
\text{Q=\Q + simplify(\cq[\k]*x^(\k-1))}
\text{Qf=\Qf + simplify(\cq[\k]/\cq[\dq+1]*x^(\k-1-\dq))}
}
}

\text{PP=texmath(\P)}
\text{QQ=texmath(\Q)}
\text{PPf=texmath(\Pf)}
\text{QQf=texmath(\Qf)}
\text{ap=simplify(\cp[\dp+1]*x^\dp)}
\text{aq=simplify(\cq[\dq+1]*x^\dq)}
\text{a=simplify((\ap)/(\aq))}
\text{aa=texmath(\a)}
\text{aap=texmath(\ap)}
\text{aaq=texmath(\aq)}

% Calcul de la limite avec Maxima

\text{rep=maxima(limit((\P)/(\Q),x,\x0))}
\if{\rep=minf}{\text{rep=-inf}}
\text{rrep=texmath(\rep)}
\if{\rep=inf}{\text{rrep=+\infty}}


#include "lang.inc"

\statement{\name_statement1.<br class="spacer"/>
\(\displaystyle \lim_{x \rightarrow \xx0}\: \frac{\PP}{\QQ}=\)\embed{reply1,4}<br class="spacer"/>
<div class="wims_instruction"> \Pourune \(+\infty\), \ecrire <span class="tt">+inf</span> \danslechamp. \Pourune \(-\infty\), \ecrire  <span class="tt">-inf</span>.</div>
}
\answer{}{\rep}{type=formal}
\feedback{1=1}{<br/><div class="bold" style="color:gray">\Correction</div><br/>
\name_feedback1 (\en \(\xx0\)) \name_feedback2\sbc:<br/>
 \(\frac{\PP}{\QQ}=\frac{\aap \left(\PPf\right)}{\aaq \left(\QQf\right)} = \aa \times \frac{\PPf}{\QQf}\).<br/>
\if{\cas=1}{
\Or \(\displaystyle \lim_{x \rightarrow \xx0} \left(\PPf\right) = 1\) \et \(\displaystyle \lim_{x \rightarrow \xx0} \left(\QQf\right) = 1\).<br/>
}{
\Or \(\displaystyle \lim_{x \rightarrow \xx0} \aa = \rrep\), \(\displaystyle \lim_{x \rightarrow \xx0} \left(\PPf\right) = 1\) \et \(\displaystyle \lim_{x \rightarrow \xx0} \left(\QQf\right) = 1\).<br/>
}
\Dou \(\displaystyle \lim_{x \rightarrow \xx0} \frac{\PP}{\QQ}= \rrep \).
 }
