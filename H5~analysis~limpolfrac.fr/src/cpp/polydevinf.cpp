target=polydevinf

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

% Tirage al�atoire des coeffcients et des degr�s des termes du polyn�me

\text{np=randitem(3,4)} % nombre de termes du polyn�me
\text{dmax=7} % degr� max
\text{sp=shuffle(\dmax+1)} % tirage al�atoire de la liste des degr�s des termes
\text{sp=\sp[1..\np]}
\text{cp=slib(matrix/non0 1,\np,5)} % tirage al�atoire de la liste des coefficients
\text{ddp=pari(vecmax([\sp]))} 
\text{i0=wims(positionof item \ddp in \sp)} % place du terme de plus haut degr�
\integer{dp=\ddp-1} % degr� du polyn�me

% Construction du polyn�me (et d'autres expressions pour la correction)

\text{P=}
\text{Pf=}
\for{i=1 to \np}{
\integer{k=\sp[\i]-1}
\text{P=\P + simplify(\cp[\i]*x^\k)}
\text{Pf=\Pf + simplify(\cp[\i]/\cp[\i0]*x^(\k-\dp))}
}
\text{ap=simplify(\cp[\i0]*x^\dp)}

% Codes Latex pour l'�nonc� et la correction

\text{PP=texmath(\P)}
\text{PPf=texmath(\Pf)}
\text{aap=texmath(\ap)}

% Calcul de la limite avec Maxima

\text{rep=maxima(limit((\P),x,\x0))}
\if{\rep=minf}{\text{rep=-inf}}
\text{rrep=texmath(\rep)}
\if{\rep=inf}{\text{rrep=+\infty}}

% Enonc�



#include "lang.inc"

\statement{Calculer la limite suivante.<br class="spacer"/>
\(\displaystyle \lim_{x \rightarrow \xx0}\; \left(\PP\right)=\)\embed{reply1,4}<br class="spacer"/>
<div class="wims_instruction"> Pour une limite �gale � \(+\infty\), �crire <span class="tt">+inf</span> dans le champ de r�ponse. Pour une limite �gale � \(-\infty\), �crire <span class="tt">-inf</span>.</div>
}

% Analyse de la r�ponse

\answer{}{\rep}{type=litexp}{option=noanalyzeprint}

% Correction

\feedback{1=1}{<br/><div class="bold" style="color:gray">Correction</div><br/>
En mettant en facteur le terme de plus haut degr�, on obtient :<br/> 
\(\PP=\aap \times \left(\PPf \right)\).<br/> 
Or \(\displaystyle \lim_{x \rightarrow \xx0} \aap = \rrep\) &nbsp; et &nbsp; \(\displaystyle \lim_{x \rightarrow \xx0} \left(\PPf\right) = 1\).<br/> 
D'o� \(\displaystyle \lim_{x \rightarrow \xx0}\; \left(\PP\right) = \rrep \).
 }
