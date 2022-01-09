target=implication

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\language{fr}
\range{-10..10}
\text{monaide=wims(record 12  of \glossaire)}
\help{\monaide}

\steps{reply1
reply2}

\text{si=randitem(\Si2,\Quand,\Chaque)}
\text{alors=randitem(\alors,&#44;)}

\for{i = 1 to 8 }{
\text{Ai = item(\i,\prem)}
\text{Bi = item(\i,\conc)}
\if{\i=1}{\text{rules=\si \Ai \alors \Bi}}{\text{ rules=\rules, \si \Ai  \alors \Bi}}
}

\integer{n=randint(1..8)}
\integer{n2=(\n==8)?1:\n+1}
\text{rule=item(\n,\rules)}
\text{rule2=item(\n2,\rules)}
\text{A=item(\n,\prem)}
\text{B=item(\n,\conc)}
\text{C=item(\n2,\conc)}
\text{nonA=item(\n,\nonPr)}
\text{nonB=item(\n,\nonCo)}
\text{nonC=item(\n2,\nonCo)}
\text{sujA=item(\n,\sujPr)}
\text{sujB=item(\n,\sujCo)}
\text{sujC=item(\n2,\sujCo)}

\integer{q=randint(1..4)}

!!!! les questions réponses à l'étape 1
\matrix{qcm1=(\q==1)?
\A
1
\B,\nonB,\none}

\matrix{qcm1=\q==2?
\nonA
3
\B,\nonB,\none}

\matrix{qcm1=\q==3?
\B
3
\A,\nonA,\none}

\matrix{qcm1=\q==4?
\nonB
2
\A,\nonA,\none}

\text{query1=row(1, \qcm1)}
\text{rep1=row(2, \qcm1)}
\text{liste1=row(3,\qcm1)}

!!!! les questions réponses à l'étape 2


\integer{q=randint(1..4)}
\matrix{qcm2=\q==1?
\A
1,3
\B,\nonB,\C,\nonC,\none}

\matrix{qcm2=\q==2?
\nonA
5
\B,\nonB,\C,\nonC,\none}



\matrix{qcm2=\q==3?
\B
3
\A,\nonA,\C,\nonC,\none}


\matrix{qcm2=\q==4?
\nonB
2
\A,\nonA,\C,\nonC,\none}


\matrix{qcm2=\q==5?
\C
5
\A,\nonA,\B,\nonB,\none}


\matrix{qcm2=\q==6?
\nonC
3,4
\A,\nonA,\B,\nonB,\none}


\text{query2=row(1, \qcm2)}
\text{rep2=row(2, \qcm2)}
\text{liste2=row(3,\qcm2)}

\statement{
<p><i><small><font color="blue">\name_citation
</font></small></i></p>

<div style="background-color:#FFFF66;">

\if{\step=1}{
<p><b>\Question \step.</b> <br/>\subject \sujA \et \sujB.
\name_statement1
<center><font color="green"><b> \rule </b></font></center>
</p>
<p> \whatif  \query1 ?</p>
<p align="center"> \embed{reply1} </p>
}

\if{\step=2}{
<p><b>\Question \step.</b> <br/>\name_characters \sujA, \sujB \et \sujC.
\name_statement2
<font color="green"><b>
<ul><li> \rule </li><li> \rule2 </li></ul>
</b></font> </p>
<p> \whatif  \query2 ?</p>
<p align="center"> \embed{reply2} </p>
}

</div>
}

\answer{\Question 1}{\rep1 ; \liste1}{type=radio}
\answer{\Question 2}{\rep2 ; \liste2}{type=checkbox}
