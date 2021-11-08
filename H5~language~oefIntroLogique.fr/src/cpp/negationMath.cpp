target=negationMath

#include "header.inc"
#include "lang_titles.inc"

\language{fr}
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
pour tout \(\x) réel&#44; &nbsp;  \(\dist \le \n),
l'inéquation \(f(\x) < \y ) a au moins \n solutions,
\(\y < \x < \z),
\(\x \in A \cap B) ,
pour tout réel \(\x)&#44;  &nbsp; \(\x \le \y),
pour tout réel \(\x) strictement positif&#44; &nbsp; \(f(\x) > \y ),
\(\x \in [\a,\b])
}


\text{nonA=
il existe un réel   \(\x)  tel que &nbsp; \( \dist > \n  ),
l'inéquation \(f(\x) < \y ) a au plus \m solutions,
\(\x \le \y) ou  \(\x \ge \z),
\(\x \notin A) ou \(\x \notin B) ,
il existe un réel \(\x) tel que \(\x > \y),
il existe un réel \(\x) strictement positif tel que  &nbsp; \(f(\x) \le \y ),
\(\x) &#8712;  &nbsp;&#93;-&#8734;&#44;\a &#91; &#8746; &#93; \b&#44;+&#8734; &#91;
}

\text{choix=(\cas==1)?il existe un réel \(\x)  tel que &nbsp; \( \dist \le \n  ), 
pour tout réel \(\x)&#44;  &nbsp; \( \dist > \n  ),
pour tout réel \(\x)&#44;  &nbsp; \( \dist > \n  )
}

\text{choix=(\cas==2)?l'inéquation \(f(\x) < \y ) a au plus \n solutions,
l'inéquation \(f(\x) < \y ) a  moins de \m solutions,
l'inéquation \(f(\x) < \y ) a  plus de \n solutions,
l'inéquation \(f(\x) < \y ) n'a aucune solution,
l'inéquation \(f(\x) < \y )  a une infinité de solutions
}

\text{choix=(\cas==3)?\(\x \le \y) et  \(\x \ge \z),
\(\x < \y) ou  \(\x > \z), \(\y < \x) ou  \(\x < \z)
}

\text{choix=(\cas==4)?\(\x \notin A) et \(\x \notin B),\(\x \in A) ou \(\x \in B)
}

\text{choix=(\cas==5)?pour tout réel \(\x) &#44; &nbsp; \(\x < \y),
il existe un réel \(\x) tel que  \(\x \ge \y)  et &nbsp; \(f(\x) \le 0 )
}

\text{choix=(\cas==6)?pour tout réel \(\x) strictement positif &#44; &nbsp; \(f(\x) \le \y ),
pour tout réel \(\x) négatif &#44; &nbsp; \(f(\x) >  \y ),
il existe un réel \(\x) négatif tel que   \(f(\x) >  \y )
}

\text{choix=(\cas==7)?\(\x\le\a) ou \(\x\ge\b),\(\x<\a) et \(\x<\b), 
\(\x) &#8712;  &nbsp; &#93; -&#8734; &#44;\a &#93; &#8746; &#91; \b &#44; +&#8734; &#91;
}
\integer{i=random(0,1)}
\text{aff=(i==0)?item(\cas,\A):item(\cas,\nonA)}
\text{neg=(i==0)?item(\cas,\nonA):item(\cas,\A)}



#include "lang.inc"

\statement{
<div style="background-color:#FFFF66;">

<p>Soit la proposition \(P) : &#34; \aff &#34; </p>
<p>Parmi les propositions suivantes, quelle est la négation de \(P) ?</p>
</div>
}

\choice{ \(\bar{P}) : }{\neg}{\choix}
