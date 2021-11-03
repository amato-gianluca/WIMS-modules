#if defined TARGET_3func
\text{name_statement=
Abbiamo tre funzioni reali: \(f(x)\), \(g(x)\) e
\(h(x)\).
<p>
Per lo stesso valore di \(x\), \(\f1(x)>0\) è una condizione \c1
per \(\f2(x)>0\), e \(\g1(x)>0\) è una condizione \c2
per \(\g2(x)>0\).
<p>
Pertanto, \(\tf(x)>0\)
è una condizione ____________&nbsp;per \(\th(x)>0\).
}
#endif

#if defined TARGET_3func2
\text{name_statement=
Abbiamo tre funzioni reali: <i>f</i>(x), <i>g</i>(x) e
<i>h</i>(x).
<p>
Per lo stesso valore di x, <i>\f1</i>(x)&lt;0 \c1
<i>\f2</i>(x)&lt;0, e <i>\g1</i>(x)&lt;0 \c2 <i>\g2</i>(x)&lt;0.
<p>
Pertanto, <i>\tf</i>(x)&lt;0
____________ <i>\th</i>(x)&lt;0.
}
#endif

#if defined TARGET_chsymbol
\text{name_statement=
Durante una lezione, il professore parla di 4 proprietà riguardanti
le funzioni. Usiamo le lettere <i>A,B,C,D</i> per indicare queste 4 proprietà.
<p>
Il professore dimostra alla lavagna le seguenti relazioni tra queste
4 proprietà:<p><center>
<i>A</i>&nbsp;\s1&nbsp;<i>B</i>&nbsp;\s2&nbsp;<i>C</i>&nbsp;\s3&nbsp;<i>D</i>
</center> <p>
Da questo concludiamo che
<i>\gA</i> è una condizione ____________&nbsp;per <i>\gB</i>.
}
#endif

#if defined TARGET_iff || defined TARGET_iff2 || defined TARGET_iff3 || defined TARGET_iff4
\text{name_statement1=Supponiamo che \(A\) e \(B\) siano due proposizioni}
\text{name_statement2=Se diciamo che}
\text{name_statement3=questo significa che}
#endif
#if defined TARGET_iff
\text{name_question=\(A\) è vera \sign \(B\) è vera}
\text{name_statement4=è una condizione}
\text{name_statement5=per}
\text{name_statement6=.}
text{name_statement=
<i>\gA</i> è una condizione ____________&nbsp;per <i>\gB</i>.
}
#endif

#if defined TARGET_iff2
\text{name_question=\(A\) è una condizione \good per \(B\)}
\text{name_statement4=è vera}
\text{name_statement5=}
\text{name_statement6=&nbsp;è vera.}
text{name_statement=
<i>\gA</i> è vera ____________ <i>\gB</i> è vera.
}
#endif

#if defined TARGET_iff3
\text{name_question=\(A\) è falsa \sign \(B\) è falsa}
\text{name_statement4=è una condizione}
\text{name_statement5=per}
\text{name_statement6=.}
text{name_statement=
<i>\gA</i> è una condizione ____________&nbsp;per <i>\gB</i>.
}
#endif

#if defined TARGET_iff4
\text{name_question=\(A\) è una condizione \good per \(B\)}
\text{name_statement4=è falsa}
\text{name_statement5=}
\text{name_statement6=&nbsp;è falsa.}
text{name_statement=
<i>\gA</i> è falsa ____________ <i>\gB</i> è falsa.
}
\text{name_nothing=non ha niente a che vedere con}
#endif

#if defined TARGET_parity
\text{name_cases_list=dispari,pari}
text{name_odd=dispari}
text{name_even=pari}
note for translators: keep commas in the following
\text{name_statement=Siano \(a\) e \(b\) due interi.,è,è una condizione,perché,sia}
text{name_statement1=Siano \(a\) e \(b\) due interi.}
text{name_is=è }
text{\name_statement2=è una condizione}
text{\name_statement3=perché}
text{\name_statement4=sia}
#endif

#if defined TARGET_subset
\text{name_belongs=ppartiene}
\text{name_nbelongs=non appartiene}
\text{name_statement=
Siano <i>A</i> e <i>B</i> due insisemi, e supponiamo che
<i>A</i> sia un sottoinsieme di <i>B</i>.
<p>In questo caso, <i>a</i> \atext a <i>\gA</i>
è una condizione ____________&nbsp;per
<i>a</i> \btext a <i>\gB</i>.
}
#endif

#if defined TARGET_symbol
\text{name_statement=
Supponiamo che <i>A</i> e <i>B</i> siano due proposizioni.
Il simbolo
<p><center><i>A</i>&nbsp;\sign&nbsp;<i>B</i></center> <p>
significa che
<i>\gA</i> è una condizione ____________&nbsp;per <i>\gB</i>.
}
#endif

#if defined TARGET_symbol2
\text{name_holds=vale}
\text{name_nholds=non vale}
\text{name_statement=
Supponiamo che <i>A</i> e <i>B</i> siano due proposizioni.
Il simbolo
<p><center><i>A</i>&nbsp;\sign&nbsp;<i>B</i></center> <p>
significa che
<i>\gA</i> \ttext ____________ <i>\gB</i> \ttext.
}
#endif
