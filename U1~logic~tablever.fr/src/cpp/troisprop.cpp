target= etou1 etou2 impetou1 impetou2

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"


\if{randitem(1,2)=1}{
\text{A=1,1,1,1,0,0,0,0;1,1,0,0,1,1,0,0;1,0,1,0,1,0,1,0}
}{
\text{A=0,0,0,0,1,1,1,1;0,0,1,1,0,0,1,1;0,1,0,1,0,1,0,1}
}
\text{AA=wims(replace char 1 by V in \A)}
\text{AA=wims(replace char 0 by F in \AA)}

#if defined TARGET_etou1 || defined TARGET_impetou1
\text{l=P,Q,R}
\text{s=shuffle(3)}
\text{i1=\s[1]}
\text{i2=\s[2]}
\text{i3=\s[3]}
\text{P=\l[\i1]}
\text{Q=\l[\i2]}
\text{R=\l[\i3]}
#endif

#if defined TARGET_etou1
\text{nprop=randint(1..2)}
\if{\nprop=1}{
\text{prop=randitem((\P \name_and \Q) \name_or \R,\R \name_or (\P \name_and \Q))}
}
\if{\nprop=2}{
\text{prop=randitem((\P \name_or \Q) \name_and \R,\R \name_and (\P \name_or \Q))}
}
#endif

#if defined TARGET_impetou1
\text{nprop=randint(1..4)}
\text{lprop=\P \({\Rightarrow}\) (\Q \name_or \R),\P \({\Rightarrow}\) (\Q \name_and \R),(\P \name_or \Q) \({\Rightarrow}\) \R,(\P \name_and \Q) \({\Rightarrow}\) \R}
\text{prop=\lprop[\nprop]}
#endif

#if defined TARGET_etou2
\text{lprop2=(P \name_and Q) \name_or R,(P \name_and R) \name_or Q,(Q \name_and R) \name_or P,(P \name_or Q) \name_and R,(P \name_or R) \name_and Q,(Q \name_or R) \name_and P}
\text{nprop=randint(1..2)}
\text{nper=randint(1..3)}
\integer{nprop2=(\nprop-1)*3+\nper}
\matrix{ss=1,2,3
1,3,2
2,3,1}
\text{i1=\ss[\nper;1]}
\text{i2=\ss[\nper;2]}
\text{i3=\ss[\nper;3]}
#endif

#if defined TARGET_impetou2
\text{n1=randitem(0,2)}
\text{n2=randint(1..2)}
\integer{nprop=\n1+\n2}
\if{\nprop<=2}{
\matrix{ss=1,2,3
2,1,3
3,2,1}
\text{lprop2=P \({\Rightarrow}\) (Q \name_or R),Q \({\Rightarrow}\) (P \name_or R),R \({\Rightarrow}\) (P \name_or Q),P \({\Rightarrow}\) (Q \name_and R),Q \({\Rightarrow}\) (P \name_and R),R \({\Rightarrow}\) (P \name_and Q)}
}{
\matrix{ss=1,2,3
1,3,2
2,3,1}
\text{lprop2=(P \name_or Q) \({\Rightarrow}\) R,(P \name_or R) \({\Rightarrow}\) Q,(Q \name_or R) \({\Rightarrow}\) P,(P \name_and Q) \({\Rightarrow}\) R,(P \name_and R) \({\Rightarrow}\) Q,(Q \name_and R) \({\Rightarrow}\) P}
}
\text{nper=randint(1..3)}
\integer{nprop2=(\n2-1)*3+\nper}
\text{i1=\ss[\nper;1]}
\text{i2=\ss[\nper;2]}
\text{i3=\ss[\nper;3]}
#endif

\text{valT=}
#if defined TARGET_etou1 || defined TARGET_etou2
\for{i=1 to 8}{
\if{\nprop=1}{
\integer{valTi=max(min(\A[\i1;\i],\A[\i2;\i]),\A[\i3;\i])}
}
\if{\nprop=2}{
\integer{valTi=min(max(\A[\i1;\i],\A[\i2;\i]),\A[\i3;\i])}
}
\text{valT=wims(append item \valTi to \valT)}
}
#endif

% Calcul de la table de vérité

#if defined TARGET_impetou1 || defined TARGET_impetou2
\for{i=1 to 8}{
\if{\nprop=1}{
\integer{valTi=max(1-\A[\i1;\i],max(\A[\i2;\i],\A[\i3;\i]))}
}
\if{\nprop=2}{
\integer{valTi=max(1-\A[\i1;\i],min(\A[\i2;\i],\A[\i3;\i]))}
}
\if{\nprop=3}{
\integer{valTi=max(1-max(\A[\i1;\i],\A[\i2;\i]),\A[\i3;\i])}
}
\if{\nprop=4}{
\integer{valTi=max(1-min(\A[\i1;\i],\A[\i2;\i]),\A[\i3;\i])}
}
\text{valT=wims(append item \valTi to \valT)}
}
#endif
\text{valT=wims(replace item 1 by V in \valT)}
\text{valT=wims(replace item 0 by F in \valT)}

#if defined TARGET_etou1 || defined TARGET_impetou1
\statement{\name_statement &laquo; \prop &raquo;.<br/ class="spacer">
<div style="text-align:center;">
<table class="wimsborder wimscenter">
<tr>
<th>P</th>
<th>Q</th>
<th>R</th>
<th>\prop</th>
</tr>
<tr>
<td>\AA[1;1]</td>
<td>\AA[2;1]</td>
<td>\AA[3;1]</td>
<td>\embed{reply1,20x20x1}</td>
</tr><tr>
<td>\AA[1;2]</td>
<td>\AA[2;2]</td>
<td>\AA[3;2]</td>
<td>\embed{reply2,20x20x1}</td>
</tr><tr>
<td>\AA[1;3]</td>
<td>\AA[2;3]</td>
<td>\AA[3;3]</td>
<td>\embed{reply3,20x20x1}</td>
</tr><tr>
<td>\AA[1;4]</td>
<td>\AA[2;4]</td>
<td>\AA[3;4]</td>
<td>\embed{reply4,20x20x1}</td>
</tr><tr>
<td>\AA[1;5]</td>
<td>\AA[2;5]</td>
<td>\AA[3;5]</td>
<td>\embed{reply5,20x20x1}</td>
</tr><tr>
<td>\AA[1;6]</td>
<td>\AA[2;6]</td>
<td>\AA[3;6]</td>
<td>\embed{reply6,20x20x1}</td>
</tr><tr>
<td>\AA[1;7]</td>
<td>\AA[2;7]</td>
<td>\AA[3;7]</td>
<td>\embed{reply7,20x20x1}</td>
</tr><tr>
<td>\AA[1;8]</td>
<td>\AA[2;8]</td>
<td>\AA[3;8]</td>
<td>\embed{reply8,20x20x1}</td>
</tr></table></div>
}

\answer{}{\valT[1];V,F}{type=clickfill}{option=noanalyzeprint}
\answer{}{\valT[2];V,F}{type=clickfill}{option=noanalyzeprint}
\answer{}{\valT[3];V,F}{type=clickfill}{option=noanalyzeprint}
\answer{}{\valT[4];V,F}{type=clickfill}{option=noanalyzeprint}
\answer{}{\valT[5];V,F}{type=clickfill}{option=noanalyzeprint}
\answer{}{\valT[6];V,F}{type=clickfill}{option=noanalyzeprint}
\answer{}{\valT[7];V,F}{type=clickfill}{option=noanalyzeprint}
\answer{}{\valT[8];V,F}{type=clickfill}{option=noanalyzeprint}
#endif

#if defined TARGET_etou2 || defined TARGET_impetou2

\statement{\name_statement1 <br/ class="spacer">

<div style="text-align:center;">
<table class="wimsborder wimscenter">
<tr>
<th>P</th>
<th>Q</th>
<th>R</th>
<th>T(P,Q,R)</th>
</tr>
<tr>
<td>\AA[1;1]</td>
<td>\AA[2;1]</td>
<td>\AA[3;1]</td>
<td>\valT[1]</td>
</tr><tr>
<td>\AA[1;2]</td>
<td>\AA[2;2]</td>
<td>\AA[3;2]</td>
<td>\valT[2]</td>
</tr><tr>
<td>\AA[1;3]</td>
<td>\AA[2;3]</td>
<td>\AA[3;3]</td>
<td>\valT[3]</td>
</tr><tr>
<td>\AA[1;4]</td>
<td>\AA[2;4]</td>
<td>\AA[3;4]</td>
<td>\valT[4]</td>
</tr><tr>
<td>\AA[1;5]</td>
<td>\AA[2;5]</td>
<td>\AA[3;5]</td>
<td>\valT[5]</td>
</tr><tr>
<td>\AA[1;6]</td>
<td>\AA[2;6]</td>
<td>\AA[3;6]</td>
<td>\valT[6]</td>
</tr><tr>
<td>\AA[1;7]</td>
<td>\AA[2;7]</td>
<td>\AA[3;7]</td>
<td>\valT[7]</td>
</tr><tr>
<td>\AA[1;8]</td>
<td>\AA[2;8]</td>
<td>\AA[3;8]</td>
<td>\valT[8]</td>
</tr></table></div><br/ class="spacer">

\name_statement2<br/ class="spacer">

<div>\embed{reply1}</div>
}

\answer{}{\nprop2;\lprop2}{type=radio}
#endif
