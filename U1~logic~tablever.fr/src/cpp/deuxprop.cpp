target=etneg1 etneg2 impneg1 impneg2

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\if{\confparm1=1}{
  \text{P=(P)}
  \text{Q=(Q)}
}
\if{\confparm1=2}{
  \text{P=P}
  \text{Q=Q}
}

\if{randitem(1,2)=1}{
\text{A=1,1,0,0;1,0,1,0}
}{
\text{A=0,0,1,1;0,1,0,1}
}
\text{AA=wims(replace char 1 by V in \A)}
\text{AA=wims(replace char 0 by F in \AA)}


#if defined TARGET_etneg1 || defined TARGET_etneg2
\if{randitem(1,2)=1}{
\text{lprop=P \name_and \name_not \Q,\name_not \P \name_and Q,P \name_or \name_not \Q,\name_not \P \name_or Q}
}{
\text{lprop=\name_not \Q \name_and P,Q \name_and \name_not \P,\name_not \Q \name_or P,Q \name_or \name_not \P}
}
\text{nprop=randint(1..4)}
\text{prop=\lprop[\nprop]}
#endif

#if defined TARGET_impneg1 || defined TARGET_impneg2
\text{nprop=randint(1..4)}
\if{randitem(1,2)=1}{
\text{lprop=P \({\Rightarrow}\) Q,Q \({\Rightarrow}\) P,\name_not \P \({\Rightarrow}\) Q,P \({\Rightarrow}\) \name_not \Q}
}{
#if defined TARGET_impneg1
\text{lprop=\name_not \Q \({\Rightarrow}\) \name_not \P,\name_not \P \({\Rightarrow}\) \name_not \Q,\name_not \Q \({\Rightarrow}\) P,Q \({\Rightarrow}\) \name_not \P}
#endif
#if defined TARGET_impneg2
\text{lprop=P \({\Rightarrow}\) Q,Q \({\Rightarrow}\) P,\name_not \Q \({\Rightarrow}\) P,Q \({\Rightarrow}\) \name_not \P}
#endif
}
\text{prop=\lprop[\nprop]}
#endif

% Calcul de la table de vérité

\text{valT=}
#if defined TARGET_etneg1 || defined TARGET_etneg2
\for{i=1 to 4}{
\if{\nprop=1}{
\integer{valTi=min(\A[1;\i],1-\A[2;\i])}
}
\if{\nprop=2}{
\integer{valTi=min(1-\A[1;\i],\A[2;\i])}
}
\if{\nprop=3}{
\integer{valTi=max(\A[1;\i],1-\A[2;\i])}
}
\if{\nprop=4}{
\integer{valTi=max(1-\A[1;\i],\A[2;\i])}
}
\text{valT=wims(append item \valTi to \valT)}
}
#endif

#if defined TARGET_impneg1 || defined TARGET_impneg2
\for{i=1 to 4}{
\if{\nprop=1}{
\integer{valTi=max(1-\A[1;\i],\A[2;\i])}
}
\if{\nprop=2}{
\integer{valTi=max(\A[1;\i],1-\A[2;\i])}
}
\if{\nprop=3}{
\integer{valTi=max(\A[1;\i],\A[2;\i])}
}
\if{\nprop=4}{
\integer{valTi=max(1-\A[1;\i],1-\A[2;\i])}
}

\text{valT=wims(append item \valTi to \valT)}
}
#endif
\text{valT=wims(replace item 1 by V in \valT)}
\text{valT=wims(replace item 0 by F in \valT)}

#if defined TARGET_etneg1 || defined TARGET_impneg1
\statement{\name_statement &laquo; \prop &raquo;.<br class="spacer"/>
<div style="text-align:center;">
<table class="wimsborder wimscenter">
<tr>
<th>P</th>
<th>Q</th>
<th>\prop</th>
</tr>
<tr>
<td>\AA[1;1]</td>
<td>\AA[2;1]</td>
<td>\embed{reply1,20x20x1}</td>
</tr><tr>
<td>\AA[1;2]</td>
<td>\AA[2;2]</td>
<td>\embed{reply2,20x20x1}</td>
</tr><tr>
<td>\AA[1;3]</td>
<td>\AA[2;3]</td>
<td>\embed{reply3,20x20x1}</td>
</tr><tr>
<td>\AA[1;4]</td>
<td>\AA[2;4]</td>
<td>\embed{reply4,20x20x1}</td>
</tr></table></div>
}

\answer{}{\valT[1];V,F}{type=clickfill}{option=noanalyzeprint}
\answer{}{\valT[2];V,F}{type=clickfill}{option=noanalyzeprint}
\answer{}{\valT[3];V,F}{type=clickfill}{option=noanalyzeprint}
\answer{}{\valT[4];V,F}{type=clickfill}{option=noanalyzeprint}
#endif

#if defined TARGET_etneg2 || defined TARGET_impneg2

\statement{\name_statement1 <br class="spacer"/>
<div style="text-align:center;">
<table class="wimsborder wimscenter">
<tr>
<th>P</th>
<th>Q</th>
<th>T(P,Q)</th>
</tr>
<tr>
<td>\AA[1;1]</td>
<td>\AA[2;1]</td>
<td>\valT[1]</td>
</tr><tr>
<td>\AA[1;2]</td>
<td>\AA[2;2]</td>
<td>\valT[2]</td>
</tr><tr>
<td>\AA[1;3]</td>
<td>\AA[2;3]</td>
<td>\valT[3]</td>
</tr><tr>
<td>\AA[1;4]</td>
<td>\AA[2;4]</td>
<td>\valT[4]</td>
</tr></table></div><br class="spacer"/>

\name_statement2<br class="spacer"/>

<div>\embed{reply1}</div>
}

\answer{}{\nprop;\lprop}{type=radio}
#endif
