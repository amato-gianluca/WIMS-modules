target=negationMath

#include "header.inc"
#include "lang_titles.inc"
#include "lang.inc"

\range{-10..10}
\text{monaide=wims(record 11 of glossaire)}
\help{\monaide}

\integer{y=random(-20..20)}
\integer{z=random(-20..20)}
\integer{n=random(1..20)}
\integer{m=\n-1}
\text{x=randitem(x,y,z,t)}
\function{diff= \x-\z}
\text{dist= |\diff|}

\integer{cas=random(1..7)}
\integer{a=random(-12..12)}
\integer{b=\a+random(0..10)}

\text{A=
\forall \(\x) \real&#44; &nbsp;  \(\dist \le \n),
\theinequation \(f(\x) < \y ) \hasatleast \n \solutions,
\(\y < \x < \z),
\(\x \in A \cap B) ,
\forall \real \(\x)&#44;  &nbsp; \(\x \le \y),
\forall \real \(\x) \strictlypositive&#44; &nbsp; \(f(\x) > \y ),
\(\x \in [\a,\b])
}


\text{nonA=
\exists \real \(\x) \st &nbsp; \( \dist > \n  ),
\theinequation \(f(\x) < \y ) \hasatmost \m \solutions,
\(\x \le \y) \ou  \(\x \ge \z),
\(\x \notin A) \ou \(\x \notin B) ,
\exists \real \(\x) \st \(\x > \y),
\exists \real \(\x) \strictlypositive \st &nbsp; \(f(\x) \le \y ),
\(\x) &#8712;  &nbsp;&#93;-&#8734;&#44;\a &#91; &#8746; &#93; \b&#44;+&#8734; &#91;
}

\text{choix=(\cas==1)?\exists \real \(\x) \st &nbsp; \( \dist \le \n  ),
\forall \real \(\x)&#44;  &nbsp; \( \dist > \n  ),
\forall \real \(\x)&#44;  &nbsp; \( \dist > \n  )
}

\text{choix=(\cas==2)?\theinequation \(f(\x) < \y ) \hasatmost \n \solutions,
\theinequation \(f(\x) < \y ) \hasless \m \solutions,
\theinequation \(f(\x) < \y ) \hasmore \n \solutions,
\theinequation \(f(\x) < \y ) \hasno \solution,
\theinequation \(f(\x) < \y ) \hasinfinite \solutions
}

\text{choix=(\cas==3)?\(\x \le \y) \et  \(\x \ge \z),
\(\x < \y) \ou  \(\x > \z), \(\y < \x) \ou  \(\x < \z)
}

\text{choix=(\cas==4)?\(\x \notin A) \et \(\x \notin B),\(\x \in A) \ou \(\x \in B)
}

\text{choix=(\cas==5)?\forall \real \(\x) &#44; &nbsp; \(\x < \y),
\exists \real \(\x) \st \(\x \ge \y) \et &nbsp; \(f(\x) \le 0 )
}

\text{choix=(\cas==6)?\forall \real \(\x) \strictlypositive &#44; &nbsp; \(f(\x) \le \y ),
\forall \real \(\x) \negative &#44; &nbsp; \(f(\x) >  \y ),
\exists \real \(\x) \negative \st \(f(\x) >  \y )
}

\text{choix=(\cas==7)?\(\x\le\a) \ou \(\x\ge\b),\(\x<\a) \et \(\x<\b),
\(\x) &#8712;  &nbsp; &#93; -&#8734; &#44;\a &#93; &#8746; &#91; \b &#44; +&#8734; &#91;
}
\integer{i=random(0,1)}
\text{aff=(i==0)?item(\cas,\A):item(\cas,\nonA)}
\text{neg=(i==0)?item(\cas,\nonA):item(\cas,\A)}

\statement{
<div style="background-color:#FFFF66;">

<p>\name_statement1 \(P) : &#34; \aff &#34; </p>
<p>\name_statement2 \(P) ?</p>
</div>
}

\choice{ \(\bar{P}) : }{\neg}{\choix}
