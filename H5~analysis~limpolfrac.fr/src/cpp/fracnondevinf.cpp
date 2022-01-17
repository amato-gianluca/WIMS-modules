target=fracnondevinf

#include "header.inc"
#include "lang_titles.inc"


\text{dmax=7}
\text{dev=randint(1..2)}

% Tirage al�atoire du type de limite : en +inf ou -inf.

\if{randitem(1,2)=1}{
\text{x0=-inf}
\text{xx0=-\infty}
}{
\text{x0=+inf}
\text{xx0=+\infty}
}

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

\if{\dev=1}{
\text{dr=\dq}
\text{ds=\dp}
}{
\text{dr=\dp}
\text{ds=\dq}
}

\text{a=randint(1..5)}
\integer{b=randitem(-1,1)*randint(1..5)}
\text{R1=\a*x+\b}
\text{a=randint(1..5)}
\integer{b=randitem(-1,1)*randint(1..5)}
\text{R2=randitem(\a*x^2+\b*x,\a*x^2+\b)}
\text{a=randint(1..5)}
\integer{b=randitem(-1,1)*randint(1..5)}
\text{R3=randitem(\a*x^3+\b*x^2,\a*x^3+\b*x,\a*x^3+\b)}
\text{a=randint(1..5)}
\integer{b=randitem(-1,1)*randint(1..5)}
\text{R4=randitem(\a*x^4+\b*x^2,\a*x^4+\b*x,\a*x^4+\b)}

\if{\dr=2}{
\text{R=(\R1)^2}
}
\if{\dr=3}{
\text{R=randitem((\R1)^3,(\R1)*(\R2),(\R2)*(\R1))}
}
\if{\dr=4}{
\text{R=randitem((\R2)^2,(\R3)*(\R1),(\R1)*(\R3))}
}
\if{\dr=5}{
\text{R=randitem((\R4)*(\R1),(\R1)*(\R4),(\R3)*(\R2),(\R2)*(\R3))}
}
\if{\dr=6}{
\text{R=randitem((\R3)^2,(\R2)*(\R4),(\R4)*(\R2))}
}
\if{\dr=7}{
\text{R=randitem((\R4)*(\R3),(\R3)*(\R4))}
}
\text{ar=pari(polcoeff(\R,\dr))}
\text{ar=simplify(\ar*x^\dr)}

% Cr�ation des polyn�mes du num�rateur et du d�nominateur

\text{np=randitem(2,3)} % nombre de termes du polyn�me
\text{sp=shuffle(\ds)}
\text{sp=\ds+1,\sp} % tirage al�atoire de la liste des degr�s des termes
\text{sp=\sp[1..\np]}
\text{cp=slib(matrix/non0 1,\np,5)} % tirage al�atoire de la liste des coefficients
\text{S=0}
\for{i=1 to \np}{
\text{S=\S+\cp[\i]*x^(\sp[\i]-1)}
}
\text{S=pari(\S)}
\text{as=pari(polcoeff(\S,\ds))}
\text{as=simplify(\as*x^\ds)}

\if{\dev=1}{
\text{Q=\R}
\text{P=\S}
\text{nomS=num�rateur}
\text{nomR=d�nominateur}
}{
\text{Q=\S}
\text{P=\R}
\text{nomR=num�rateur}
\text{nomS=d�nominateur}
}

\text{PP=texmath(\P)}
\text{QQ=texmath(\Q)}

% Calcul de la limite avec M

\text{rep=maxima(limit((\P)/(\Q),x,\x0))}
\if{\rep=minf}{\text{rep=-inf}}
\text{rrep=texmath(\rep)}
\if{\rep=inf}{\text{rrep=+\infty}}



#include "lang.inc"

\statement{Calculer la limite suivante.<br class="spacer"/>
\(\displaystyle \lim_{x \rightarrow \xx0}\: \frac{\PP}{\QQ}=\)\embed{reply1,4}<br class="spacer"/>
<div class="wims_instruction"> Pour une limite �gale � \(+\infty\), �crire <span class="tt">+inf</span> dans le champ de r�ponse. Pour une limite �gale � \(-\infty\), �crire <span class="tt">-inf</span>.</div>
}
\answer{}{\rep}{type=formal}
\feedback{1=1}{<br/><div class="bold" style="color:gray">Correction</div><br/>
Le terme dominant du \nomS est \(\as\). Le terme dominant du \nomR, qu'on obtient par un d�veloppement partiel, est \(\ar\).<br />
D'o� \(\displaystyle \lim_{x \rightarrow \xx0}\: \frac{\PP}{\QQ}=\rrep\)
}
