\text{name_NECSUF=necessaria e sufficiente}
\text{name_NEC=necessaria (solo)}
\text{name_SUF=sufficiente (solo)}
\text{name_NEC2=necessaria}
\text{name_SUF2=sufficiente}
\text{name_NONNECSUF=né necessaria né sufficiente}
\text{name_IFF=se e solo se}
\text{name_IF=se}
\text{name_ONLYIF=solo se}
\text{name_NONIFONLYIF=né se né solo se}
\text{name_PERNON=probabilmente né necessaria né sufficiente}

#if defined TARGET_3func
\text{name_statement=
Abbiamo tre funzioni reali: <i>f</i>(x), <i>g</i>(x) e
<i>h</i>(x).
<p>
Per lo stesso valore di x, <i>\f1</i>(x)&gt;0 è una condizione \c1
per <i>\f2</i>(x)&gt;0, e <i>\g1</i>(x)&gt;0 è una condizione \c2
per <i>\g2</i>(x)&gt;0.
<p>
Pertanto, <i>\tf</i>(x)&gt;0
è una condizione ____________&nbsp;per <i>\th</i>(x)&gt;0.
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

#if defined TARGET_iff
\text{name_statement=
Supponiamo che <i>A</i> e <i>B</i> siano due proposizioni.
Se diciamo che <i>A</i> è vera \sign <i>B</i> è vera,
questo significa che
<i>\gA</i> è una condizione ____________&nbsp;per <i>\gB</i>.
}
#endif

#if defined TARGET_iff2
\text{name_statement=
Supponiamo che <i>A</i> e <i>B</i> siano due proposizioni.
Se diciamo che <i>A</i> è una condizione \good per <i>B</i>,
questo significa che
<i>\gA</i> è vera ____________ <i>\gB</i> è vera.
}
#endif

#if defined TARGET_iff3
\text{name_statement= \
Supponiamo che <i>A</i> e <i>B</i> siano due proposizioni.
Se diciamo che <i>A</i> è falsa \sign <i>B</i> è falsa,
questo significa che
<i>\gA</i> è una condizione ____________&nbsp;per <i>\gB</i>.
}
#endif

#if defined TARGET_iff4
\text{name_statement= \
Supponiamo che <i>A</i> e <i>B</i> siano due proposizioni.
Se diciamo che <i>A</i> è una condizione \good per <i>B</i>,
questo significa che
<i>\gA</i> è falsa ____________ <i>\gB</i> è falsa.
}
\text{name_nothing=non ha niente a che vedere con}
#endif

#if defined TARGET_parity
\text{name_odd=dispari}
\text{name_even=pari}
\text{name_statement=
Siano <i>a</i> e <i>b</i> due interi.
<p>
"\t1 è \parity"
è una condizione ____________&nbsp;perché
\t2 sia \parity2.
}
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
