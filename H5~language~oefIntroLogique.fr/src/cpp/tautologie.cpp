target=tautologie

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\range{-10..10}
\text{monaide=wims(record 6  of \glossaire)}
\help{\monaide}

\integer{a=random(1..18)}
\text{A=item(\a,\Alist)}
\text{nonA=item(\a,\nonAlist)}
\text{B=item(\a,\Blist)}
\text{nonB=item(\a,\nonBlist)}

\text{si=\a<6?\si1:\si2}

\text{tau=\si \A \alors  \A,
\si \A \alors  \A \ou \B,
\si \A \alors \si2 \B \alors  \A,
\si \A \et \si \B \alors \A,
\A \ou \B \ou (\nonA \et \nonB),
\A \ou \nonA,
\A \ou \B \ou \nonA,
\si \nonA \alors  \A \ou \nonA,
\si \nonA \et \si \A \alors \B,
\si \A \et \si2 \B \alors \A \ou \B,
\si \A \alors \B \ou \si2 \B \alors \A,
\si \A \alors \B \ou \si2 \nonA \alors \B
}

/** les 12 premières  sont tautologiques , les 11 suivantes non **/
\text{ass=\tau,
\A \ou \B,
\A \et \B,
\si \A \alors \B,
\A \et \nonA,
\si \A \alors \nonA,
\si \A \alors \nonA \ou \B,
\si \A \alors \A \et \B,
\si \nonA \alors \A \ou  \B,
\si \A \ou \si \B \alors \A et \B,
\si \nonA \ou \si \A \alors  \B,
\si \A \alors \B \et \si \B \alors \A
}

\text{typ=
\(A \rightarrow A),
\(A \rightarrow A \;\ou\; B),
\(A \rightarrow (B \rightarrow  A)),
\(A  \; \et  \; B \rightarrow  A),
\(A  \; \ou  \; B  \; \ou \;  (\bar{A} \;\et\; \bar{B})),
\(A  \; \ou \;  \bar{A}),
\(A  \; \ou \;  B \; \ou \;  \bar{A}),
\(\bar{A} \rightarrow  A \;\ou\; \bar{A}),
\(\bar{A}  \; \et  \; A  \rightarrow  B),
\(A  \; \et \;  B  \rightarrow  A \;ou\; B),
\(A \rightarrow  B \; \ou \; B  \rightarrow A),
\(A \rightarrow  B \; \ou \;  \bar{A}  \rightarrow B),
\(A  \; \ou \;  B),
\(A  \; \et \;  B),
\( A \rightarrow B),
\(A \;\et\;\bar{ A}),
\(A  \rightarrow \bar{A}),
\( A  \rightarrow \bar{A} \;\ou\; B),
\(A \rightarrow A \;\et\; B),
\(\bar{A}  \rightarrow A \;\ou\;  B),
\(A \;\ou\; B  \rightarrow A \;\et\; B),
\(\bar{ A} \;\ou\; A \rightarrow  B),
\(A \rightarrow  B \; \et \;B  \rightarrow A)
}

\integer{ind=random(1..23)}
\text{P=item(\ind,\ass)}
\text{typP=item(\ind,\typ)}
\text{shtyp=shuffle(\typ)}

\text{choix=item(1,\shtyp),item(2,\shtyp),item(3,\shtyp),
item(4,\shtyp),item(5,\shtyp)}
\text{liste=
(\typP isitemof \choix)?shuffle(\choix):shuffle(\typP,\choix)}

\integer{rep1=position(\typP,\liste)}
\integer{rep2=\ind<13?1:2}
\integer{test=(\typP isitemof \choix)?\oui:\non}

\statement{
<div style="background-color:#FFFF66;">

<p>\Soient \(A) : " \A " \et  \(B) : " \B ". </p>
<p>\name_statement1 \(P) \name_statement2 :</p>
<center><font color="blue"> \(P) : " \P "</font></center>
<p>\name_question1 \(P) ?</p>
<center>\embed{reply1}</center>
<p> \(P) \name_question2 ?  \embed{reply2}</p>
</div>
}

\answer{Type formule}{\rep1;\liste}{type=checkbox}
\answer{Tautologie?}{\rep2;\oui,\non}{type=checkbox}
\hint{\name_hint.}
