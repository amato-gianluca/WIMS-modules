target=connecteursLN

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\language{fr}
\range{-10..10}
\text{monaide=}
\for{ii = 1 to 3}{
  \text{currrecord=wims(record \ii of \glossaire)}
  \text{monaide=\monaide
	\currrecord}
}
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
\(A \etconn  B), \(\overline{A} \etconn  B), \(A \etconn  \overline{B}), \(\overline{A} \etconn  \overline{B}),
\(A \ouconn B), \(A \ouconn \overline{B}), \(\overline{A} \ouconn  B), \(\overline{A} \ouconn \overline{B}),
\(A \rightarrow B), \(\overline{A}\rightarrow B),
\(A\rightarrow\overline{B}), \(\overline{A}\rightarrow\overline{B}),
\(B\rightarrow A), \(\overline{B}\rightarrow A),
\(B\rightarrow\overline{A}), \(\overline{B}\rightarrow\overline{A})
}

\text{list1=item(\ind[1],\ass),item(\ind[2],\ass),item(\ind[3],\ass),
item(\ind[4],\ass),item(\ind[5],\ass)}

\text{list2=item(\ind[1],\typ),item(\ind[2],\typ),item(\ind[3],\typ),
item(\ind[4],\typ),item(\ind[5],\typ)}

\statement{<div class="wims_question">
<p>\name_statement1</p>
<p><i>\Remarque</i>\spacebeforecolon: \name_statement2</p>
<div class="wimscenter">
<span class="fraseA"> \(A) : " \A "</span>
&nbsp; \et &nbsp; <span class="fraseB">\(B) : " \B "</span>
</div>
</div>

<div class="wims_instruction">\name_statement3</div>

<div class="wimscenter">\embed{reply1,40x400x100}</div>
}

\answer{\list1;\list2}{\list1;\list2}{type=correspond}{option=split}
