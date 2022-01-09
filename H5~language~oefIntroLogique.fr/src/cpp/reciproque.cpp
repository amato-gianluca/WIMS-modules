target=reciproque

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\integer{init= 10}

\text{elles=L�a,Lili,Julie,Leila,Lola}
\text{luis=L�o,Lulu,Jules,Malik,Luis}
\integer{i=random(1..4)}
\text{Elle=\elles[\i]}
\text{Lui=\luis[\i]}

\integer{a=random(1..6)}
\integer{cas=random(1..3)}

\text{A=\Alist[\a]}
\text{B=\Blist[\a]}
\text{C=\Clist[\a]}
\text{D=\Dlist[\a]}
\text{E=\Elist[\a]}

\text{nonA=\nonAlist[\a]}
\text{nonB=\nonBlist[\a]}
\text{nonC=\nonClist[\a]}
\text{nonD=\nonDlist[\a]}
\text{nonE=\nonElist[\a]}

\text{si=\a<4?\si1:\si2}

\text{ass=
\si \A \alors \C,
\si \A \ou \si \B \alors \C,
\si \A \et \si \B \alors \D,
\si \A \alors \C \ou \D,
\si \B \alors \C \et \D,
\si \nonA \ou \si \B \alors \C,
\si \A et \si \nonB \alors \D,
\si \A \alors \nonC \ou \D,
\si \B \alors \C \ou \nonD,
\si \A \alors \C \et \nonD,
\si \B \alors \nonC \et \D
}

\text{contra=
\si \nonC \alors \nonA,
\si \nonC \alors \nonA \et \nonB,
\si \nonD \alors \nonA \ou \nonB,
\si \nonC \et \si \nonD \alors  \nonA,
\si \nonC \ou \si \nonD \alors  \nonB,
\si \nonC \alors \A et \nonB,
\si \nonD \alors \nonA \ou \B,
\si \C \et \si \nonD \alors \nonA,
\si \nonC \et \si \D \alors \nonB,
\si \nonC \ou \si \D \alors \nonA,
\si \C \ou \si \nonD \alors  \nonB
}

\text{rec=
\si \C \alors \A,
\si \C \alors \A \ou \B,
\si \D \alors \A \et \B,
\si \C \ou \si \D \alors \A,
\si \C \et \si \D \alors \B,
\si \C \alors \nonA \ou \B,
\si \D \alors \A \et \nonB,
\si \nonC \ou \si \D \alors \A,
\si \C \ou \si \nonD \alors \B,
\si \C \et \si \nonD \alors \A,
\si \nonC \et \si \D \alors \B
}

\integer{rep=random(1..3)}
\integer{i=random(1..11)}

\text{prop1=item(\i,\ass)}

\integer{j=\i-1}
\integer{k=\i+1}
\text{autre=\rep==3 and \j==0?item(2..11,\rec),item(2..11,\contra)}
\text{autre=\rep==3 and \j>0?item(1..\j,\rec),item(\k..11,\contra)}

\text{prop2=\rep==1?item(\i,\rec)}
\text{prop2=\rep==2?item(\i,\contra)}
\text{prop2=\rep==3?randitem(\autre)}

\statement{
 <div style="background-color:#FFFF66;">

<ul><li><p>\Lui \enunciateimpl :</p>
<center>
<font color="green"> \(P_1) : " \prop1 "</font>
</center>

</li>
<li>
<p>\Later \Elle \enunciateprop \(P_2 ) :</p>
<center>
<font color="blue">\(P_2) : " \prop2 "</font>
</center>

</li>
</ul>

<p>\Theprop \(P_2) \formulatedby \Elle
 \embed{reply1} \ofproposition \(P_1) \enunciatedby \Lui.  </p>

</div>
}


\answer{}{\rep;\name_answers}{type=menu}

\hint{
<ul>\considerimpl "\si \(A) \alors \(B)". \Alors :
<li>
\its <b>\reciproque</b> \isprop "\si \(B) \alors \(A)" ;
</li>
<li>
\its <b>\contraposed</b> \isprop "\si \(non B) \alors \(non A)"
</li>
</ul>
\Theconj "\(A) \et \(B)" \hasnegation "\(\non A) \ou \(\non B)".  <bt/>
\Thedisj "\(A) \ou \(B)" \hasnegation "\(\non A) \et \(\non B)".  <br/>
}