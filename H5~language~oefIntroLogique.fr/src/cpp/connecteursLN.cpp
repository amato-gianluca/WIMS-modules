target=connecteursLN

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\language{fr}
\range{-10..10}
\text{monaide=wims(record 1 to 3 of \glossaire)}
\help{\monaide}

\integer{n=random(1..17)}

\text{ouconn=\;\ou\;}
\text{etconn=\;\et\;}

\text{A=item(\n,\Alist)}
\text{nonA=item(\n,\nonAlist)}
\text{B=item(\n,\Blist)}
\text{nonB=item(\n,\nonBlist)}

\text{AouB=\A \ou \B}
\text{nonAouB=\nonA \ou \B}
\text{AounonB=\A \ou \nonB}
\text{nonAounonB=\nonA \ou \nonB}
\text{AetB=\A \et \B}
\text{nonAetB=\nonA \et \B}
\text{AetnonB=\A \et \nonB}
\text{niAniB=\nonA \et \nonB}

\text{si=\n<5?\si1:\si2}

\text{AimplB= randitem(\si \A \alors \B, \B \si \A)}
\text{nonAimplB= randitem(\si \nonA \alors \B, \B \si \nonA)}
\text{AimplnonB= randitem(\si \A \alors \nonB , \nonB \si \A) }
\text{nonAimplnonB= randitem(\si \nonA \alors  \nonB, \nonB \si \nonA)}
\text{BimplA= randitem(si \B \alors  \A, \A si \B)}
\text{nonBimplA= randitem(si \nonB \alors  \A, \A si \nonB)}
\text{BimplnonA=randitem(si \B \alors  \nonA, \nonA si \B)}
\text{nonBimplnonA= randitem(si \nonB \alors \nonA, \nonA si \nonB)}

\text{ind=shuffle(1,2,3,4,5,6,7,8,9,10,11,12)}

\text{ass=
\AetB,\nonAetB,\AetnonB,\niAniB,
\AouB,\AounonB,\nonAouB,\nonAounonB,
\AimplB,\nonAimplB,\AimplnonB,\nonAimplnonB,
\BimplA,\nonBimplA,\BimplnonA,\nonBimplnonA
}
\text{typ=
\(A \etconn  B), \(\bar{A} \etconn  B), \(A \etconn  \bar{B}), \(\bar{A} \etconn  \bar{B}),
\(A \ouconn B), \(A \ouconn \bar{B}), \(\bar{A} \ouconn  B), \(\bar{A} \ouconn \bar{B}),
\(A \rightarrow B), \(\bar{A}\rightarrow B),
\(A\rightarrow\bar{B}), \(\bar{A}\rightarrow\bar{B}),
\(B\rightarrow A), \(\bar{B}\rightarrow A),
\(B\rightarrow\bar{A}), \(\bar{B}\rightarrow\bar{A})
}

\text{list1=item(\ind[1],\ass),item(\ind[2],\ass),item(\ind[3],\ass),
item(\ind[4],\ass),item(\ind[5],\ass)}

\text{list2=item(\ind[1],\typ),item(\ind[2],\typ),item(\ind[3],\typ),
item(\ind[4],\typ),item(\ind[5],\typ)}

\statement{

<div style="background-color:#FFFF66;">

<p>\name_statement1</p>
<p><i>\Remarque</i> : \name_statement2</p>
<center>
<font color="blue"><b> \(A) : " \A "</b></font>
&nbsp; \et  &nbsp; <font color="green"><b>  \(B) : " \B "</b></font>
</center>

<p align="center"><i>
\name_statement3</i></p>

</div>


<center>\embed{reply1,40x400x100}</center>

}

\answer{\list1;\list2}{\list1;\list2}{type=correspond}{option=split}
