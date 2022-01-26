target=valeursVerite

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\range{-10..10}
\text{monaide=}
\for{ii = 2 to 5}{
  \text{currrecord=wims(record \ii of \glossaire)}
  \text{monaide=\monaide
	\currrecord}
}
\help{\monaide}

\integer{a=random(1..6)}

\text{Alist=A,P,X}
\text{Blist=B,Q,Y}
\text{Clist=C,R,Z}
\text{Dlist=D,S,T}

\integer{a=random(1..3)}
\text{A=\Alist[\a]}
\text{B=\Blist[\a]}
\text{C=\Clist[\a]}
\text{D=\Dlist[\a]}
\text{\nonA=\overline{\Alist[\a]}}
\text{\nonB=\overline{\Blist[\a]}}
\text{\nonC=\overline{\Clist[\a]}}
\text{\nonD=\overline{\Dlist[\a]}}

\text{val=randint(0,1),randint(0,1),randint(0,1),randint(0,1)}

\text{op_ou=\;\ou\;}
\text{op_et=\;\et\;}

\text{form1=
\(\A \op_ou \B),
\(\C \op_ou \D),
\(\A \op_et \B),
\(\C \op_et \D),
\(\A \op_ou \nonB),
\(\nonC \op_ou \D),
\(\A \op_et \nonB),
\(\nonC \op_et \D),
\(\nonC \op_et \nonD),
\(\nonA \op_ou \nonB)
}

\text{form2=
\(\A \rightarrow \B),
\(\nonA \rightarrow \B),
\(\nonC \rightarrow \D),
\( \A \op_et \B \rightarrow  \D ),
\( \B \op_et \nonC \rightarrow  \D),
\( \C \op_et \nonA \rightarrow \nonD) ,
\( \B \op_ou \D \rightarrow \A),
\(\A \leftrightarrow \D ),
\(\A \leftrightarrow \C \op_ou \D),
\(\A \op_et \nonB \leftrightarrow \C)
}

\text{ind=shuffle(1,2,3,4,5,6,7,8,9,10)}
\integer{i1=\ind[1]}
\integer{i2=\ind[2]}
\integer{i3=\ind[3]}
\integer{i4=\ind[4]}

\integer{cond1=\val[1]==1 or \val[2]==1?1:2}

\integer{cond2=\val[3]==1 or \val[4]==1?1:2}

\integer{cond3=\val[1]==1 and \val[2]==1?1:2}

\integer{cond4=\val[3]==1 and  \val[4]==1?1:2}

\integer{cond5=\val[1]==1 or \val[2]==0?1:2}

\integer{cond6=\val[3]==0 or \val[4]==1?1:2}

\integer{cond7=\val[1]==1 and \val[2]==0?1:2}

\integer{cond8=\val[3]==0 and  \val[4]==1?1:2}

\integer{cond9=\val[3]==0 and  \val[4]==0?1:2}

\integer{cond10=\val[1]==0 or  \val[2]==0?1:2}


\integer{cond11=\val[1]==0 or  \val[2]==1?1:2}
\integer{cond12=\val[1]==1 or  \val[2]==1?1:2}
\integer{cond13=\val[3]==1 or  \val[4]==1?1:2}

\integer{cond14=(\val[1]==0 or \val[2]==0 or \val[4]==1)?1:2}
\integer{cond15=(\val[2]==0 or \val[3]==1 or \val[4]==1)?1:2}
\integer{cond16=(\val[1]==1 or \val[3]==0 or \val[4]==0)?1:2}

\integer{cond17=(\val[2]==0  and  \val[4]==0) or \val[1]==1?1:2}
\integer{cond18=\val[1]==\val[4] ?1:2}
\integer{valCouD= \val[4]==1 or \val[3]==1?1:0}
\integer{cond19=\valCouD==\val[1]?1:2}
\integer{valAetnonB=\val[1]==1 and \val[2]==0?1:0}
\integer{cond20=\valAetnonB==\val[3] ?1:2}

\text{conds=\cond1,\cond2,\cond3,\cond4,\cond5,\cond6,\cond7,\cond8,\cond9,
\cond10,\cond11,\cond12,\cond13,\cond14,\cond15,\cond16,\cond17,\cond18,
\cond19,\cond20}
\integer{rep1=\conds[\i1]}
\integer{rep2=\conds[\i2]}
\integer{rep3=\conds[(10+\i3)]}
\integer{rep4=\conds[(10+\i4)]}

\statement{
<div class="wims_question">

<p>
\Soient \A, \B, \C \et \D \name_statement1.<br/>
\name_statement2
</p>
<table border="solid" cellpadding="5" align="center">
<tr><td>\A</td><td>\B</td><td>\C</td><td>\D</td></tr>
<tr><td>\if{\val[1]==1}{V}{F}</td>
<td>\if{\val[2]==1}{V}{F}</td>
<td>\if{\val[3]==1}{V}{F}</td>
<td>\if{\val[4]==1}{V}{F}</td>
</tr>
</table>

<p>\name_question1
</p>
<table width="50%" align="center" cellpadding=10>
<tr>
<td width="10%">1.</td>
<td width="65%">\form1[\i1]</td>
<td width="30%">\embed{reply1}</td>
</tr>
<tr>
<td width="10%">2.</td>
<td width="60%">\form1[\i2]</td>
<td width="30%">\embed{reply2}</td>
</tr>
<tr>
<td width="10%">3.</td>
<td width="60%">\form2[\i3]</td>
<td width="30%">\embed{reply3}</td>
</tr>
<tr>
<td width="10%">4.</td>
<td width="60%">\form2[\i4]</td>
<td width="30%">\embed{reply4}</td>
</tr>
</table>
</div>

<p><i>\name_statement3</i></p>
}

\answer{clause 1}{\rep1;\V,\F}{type=radio}
\answer{clause 2}{\rep2;\V,\F}{type=radio}
\answer{clause 3}{\rep3;\V,\F}{type=radio}
\answer{clause 4}{\rep4;\V,\F}{type=radio}
