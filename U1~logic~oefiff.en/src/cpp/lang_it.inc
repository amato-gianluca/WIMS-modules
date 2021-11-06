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

\text{name_iscond1=è una condizione}
\text{name_iscond2=per}

#if defined TARGET_3func || defined TARGET_3func2
\text{name_statement1=Abbiamo tre funzioni reali:}
\text{name_and=e}
\text{name_statement2=Per lo stesso valore di}
\text{name_thus=Pertanto}
#endif

#if defined TARGET_chsymbol
\text{name_statement1=Durante una lezione, il professore parla di 4 proprietà riguardanti
le funzioni. Usiamo le lettere \(A, B, C, D\) per indicare queste 4 proprietà.}
\text{name_statement2=Il professore dimostra alla lavagna le seguenti relazioni tra queste
4 proprietà:}
\text{name_thus=Da questo concludiamo che}
#endif

#if defined TARGET_iff || defined TARGET_iff2 || defined TARGET_iff3 || defined TARGET_iff4
\text{name_statement1=Supponiamo che \(A\) e \(B\) siano due proposizioni.}
\text{name_statement2=Se diciamo che}
\text{name_statement3=questo significa che}
\text{name_istrue=è vera}
\text{name_isfalse=è falsa}
#endif

#if defined TARGET_iff4
\text{name_nothing=non ha niente a che vedere con}
#endif

#if defined TARGET_parity
\text{name_statement=Siano \(a\) e \(b\) due interi.,è,è una condizione,perché,sia}
\text{name_cases_list=dispari,pari}
#endif

#if defined TARGET_subset
\text{name_statement=Siano \(A\) e \(B\) due insiemi, e supponiamo che
\(A\) sia un sottoinsieme di \(B\).}
\text{name_thus=In questo caso,}
\text{name_cases_list=appartiene a,non appartiene a}
\text{name_quoteleft=&ldquo;}
\text{name_quoteright=&#32;&rdquo;}
#endif

#if defined TARGET_symbol || defined TARGET_symbol2
\text{name_statement=Supponiamo che \(A\) e \(B\) siano due proposizioni. La notazione simbolica}
\text{name_thus=significa che}
#endif

#if defined TARGET_symbol2
\text{name_cases_list=vale,non vale}
#endif
