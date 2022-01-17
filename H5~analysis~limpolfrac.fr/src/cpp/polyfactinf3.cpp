target=polyfactinf3

#include "header.inc"
#include "lang_titles.inc"


% Tirage al�atoire du type de limite : en +inf ou -inf.

\if{randitem(1,2)=1}{
\text{x0=-inf}
\text{xx0=-\infty}
}{
\text{x0=+inf}
\text{xx0=+\infty}
}

% Tirage al�atoire du polyn�me

\text{s=shuffle(5)}
\text{a=\s[1]}
\text{b=\s[2]}
\text{d=randint(2..7)}
\text{Q=randitem(\a*x+\b,\a*x-\b,\b-\a*x)}
\text{Q=(\Q)^\d}
\text{s=shuffle(5)}
\text{a=\s[1]}
\text{b=\s[2]}
\text{d=randint(2..7)}
\text{R=randitem(\a*x+\b,\a*x-\b,\b-\a*x)}
\text{R=(\R)^\d}
\text{P=\Q*\R}

% Codes Latex pour l'�nonc� et la correction

\text{PP=texmath(\P)}
\text{QQ=texmath(\Q)}
\text{RR=texmath(\R)}

% Calcul des limites avec Maxima

\text{limQ=maxima(limit((\Q),x,\x0))}
\if{\limQ=minf}{\text{limQ=-\infty}}
\if{\limQ=inf}{\text{limQ=+\infty}}

\text{limR=maxima(limit((\R),x,\x0))}
\if{\limR=minf}{\text{limR=-\infty}}
\if{\limR=inf}{\text{limR=+\infty}}

\text{rep=maxima(limit((\P),x,\x0))}
\if{\rep=minf}{\text{rep=-inf}}
\text{rrep=texmath(\rep)}
\if{\rep=inf}{\text{rrep=+\infty}}

% Enonc�



#include "lang.inc"

\statement{Calculer la limite suivante.<br class="spacer"/>
\(\displaystyle \lim_{x \rightarrow \xx0}\; \PP=\)\embed{reply1,4}<br class="spacer"/>
<div class="wims_instruction"> Pour une limite �gale � \(+\infty\), �crire <span class="tt">+inf</span> dans le champ de r�ponse. Pour une limite �gale � \(-\infty\), �crire <span class="tt">-inf</span>.</div>
}

% Analyse de la r�ponse

\answer{}{\rep}{type=litexp}

% Correction

\feedback{1=1}{<br/><div class="bold" style="color:gray">Correction</div><br/>
On a \(\displaystyle \lim_{x \rightarrow \xx0}\; \QQ = \limQ\) &nbsp; et &nbsp; \(\displaystyle \lim_{x \rightarrow \xx0}\; \RR = \limR\).<br/> 
Donc \(\displaystyle \lim_{x \rightarrow \xx0}\; \PP = \rrep\).
 }
