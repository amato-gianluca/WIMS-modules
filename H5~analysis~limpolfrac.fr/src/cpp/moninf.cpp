target=moninf

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

% Tirage al�atoire du coeffcients et du degr� du mon�me

\integer{a=randitem(1,-1)*randint(1..5)}
\text{d=randint(2..7)}

% Construction du polyn�me (et d'autres expressions pour la correction)

\text{P=\a*x^\d}

% Codes Latex pour l'�nonc� et la correction

\text{PP=texmath(\P)}

% Calcul de la limite avec Maxima

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

\answer{}{\rep}{type=litexp}{option=noanalyzeprint}

% Correction

\feedback{1=1}{<br/><div class="bold" style="color:gray">Correction</div><br/>
\(\displaystyle \lim_{x \rightarrow \xx0}\; \PP = \rrep \).
}
