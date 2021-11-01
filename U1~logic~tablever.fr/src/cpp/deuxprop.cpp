target=etneg1 etneg2 impneg1 impneg2
#if defined TARGET_etneg1
\title{Deux propositions (et, ou, négation) 1}
#endif
#if defined TARGET_etneg2
\title{Deux propositions (et, ou, négation) 2}
#endif
#if defined TARGET_impneg1
\title{Deux propositions (implication, négation) 1}
#endif
#if defined TARGET_impneg2
\title{Deux propositions (implication, négation) 2}
#endif
\language{fr}
\author{David Doyen}
\email{david.doyen@u-pem.fr}

\if{randitem(1,2)=1}{
\text{A=1,1,0,0;1,0,1,0}
}{
\text{A=0,0,1,1;0,1,0,1}
}
\text{AA=wims(replace char 1 by V in \A)}
\text{AA=wims(replace char 0 by F in \AA)}


#if defined TARGET_etneg1 || defined TARGET_etneg2
\if{randitem(1,2)=1}{
\text{lprop=P et non (Q),non (P) et Q,P ou non (Q),non (P) ou Q}
}{
\text{lprop=non (Q) et P,Q et non (P),non (Q) ou P,Q ou non (P)}
}
\text{nprop=randint(1..4)}
\text{prop=\lprop[\nprop]}
#endif

#if defined TARGET_impneg1 || defined TARGET_impneg2
\text{nprop=randint(1..4)}
\if{randitem(1,2)=1}{
\text{lprop=P \({\Rightarrow}\) Q,Q \({\Rightarrow}\) P,non (P) \({\Rightarrow}\) Q,P \({\Rightarrow}\) non (Q)}
}{
#if defined TARGET_impneg1
\text{lprop=non (Q) \({\Rightarrow}\) non (P),non (P) \({\Rightarrow}\) non (Q),non (Q) \({\Rightarrow}\) P,Q \({\Rightarrow}\) non (P)}
#endif
#if defined TARGET_impneg2
\text{lprop=P \({\Rightarrow}\) Q,Q \({\Rightarrow}\) P,non (Q) \({\Rightarrow}\) P,Q \({\Rightarrow}\) non (P)}
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
\statement{Soit P et Q deux propositions logiques. Déterminer la table de vérité de la proposition &laquo; \prop &raquo;.<br class="spacer"/>
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

\statement{Soit P et Q deux propositions logiques. On considère une proposition T(P,Q), construite à partir des propositions P et Q, dont la table de vérité est donnée ci-dessous. <br class="spacer"/>
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

Parmi les propositions suivantes, laquelle est logiquement équivalente à T(P,Q) ?<br class="spacer"/>

<div>\embed{reply1}</div>
}

\answer{}{\nprop;\lprop}{type=radio}
#endif
