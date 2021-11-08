target=deduction

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\language{fr}
\integer{init= 10}
\text{monaide=wims(record 8 to  10 of glossaire)}
\help{\monaide}

\integer{a=random(1..\init)}

\text{A=item(\a,\Alist)}
\text{B=item(\a,\Blist)}
\text{nonA=item(\a,\nonAlist)}
\text{nonB=item(\a,\nonBlist)}

\text{AouB=\A \ou \B}
\text{AetB=\A \et \B}

\text{nonAouB=\nonA \ou  \B}
\text{AounonB=\A \ou  \nonB}
\text{nonAounonB=\nonA \ou  \nonB}
\text{nonAetB=\nonA \et  \B}
\text{AetnonB=\A \et  \nonB}
\text{niAniB= \nonA \et  \nonB}

\text{si=\a<4?\Si1:\Si2}

\integer{casH=random(1..2)}
\integer{casC=random(1..6)}
\text{hyp=\A,\nonB}
\text{H=item(\casH,\hyp)}

/** liste d'assertions ; les  4 premières sont justes **/
\text{ass=\casH==1?
\B,\AetB,\AounonB,\nonAouB,\nonAounonB,\nonAetB,\AetnonB,\niAniB:
\nonA,\nonAounonB,\niAniB,\AounonB, \nonAetB,\AetnonB,\A,\AetB}

\text{C=item(\casC,\ass)}

\integer{rep=\casC<5?1:2}

\statement{

<div style="background-color:#FFFF66;">
<ul>
<li>
<p>\name_statement1</p>
<center>
<font color= green><b> \(H_1) : " \si \A, \alors \B "</b></font></center></p>
</li>
<li>
<p>\name_statement2</p>
<center> <font color= blue><b> \(H_2) : " \H "</b> </font></center>
</li>
<li>
<p>\name_statement3</p>
<center><font color= red><b> \(C) : "  \C "</b> </font></center>
</li>
</ul>

<p>\name_statement4 \embed{reply1} </p>
</div>}

\Alist
\answer{\name_answer}{\rep;\oui,\non}{type=checkbox}
