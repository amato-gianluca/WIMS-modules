\text{name_NECSUF=necessary and sufficient}
\text{name_NEC=necessary (only)}
\text{name_SUF=sufficient (only)}
\text{name_NEC2=necessary (only)}
\text{name_SUF2=sufficient (only)}
\text{name_NONNECSUF=neither necessary nor sufficient}
\text{name_IFF=if and only if}
\text{name_IF=if}
\text{name_ONLYIF=only if}
\text{name_NONIFONLYIF=neither if nor only if}
\text{name_PERNON=perhaps neither necessary nor sufficient}

\text{name_iscond1=is a}
\text{name_iscond2=condition of}

#if defined TARGET_3func || defined TARGET_3func2
\text{name_statement1=We have 3 real functions:}
\text{name_and=and}
\text{name_statement2=For a same value of}
\text{name_thus=Consequently}
#endif

#if defined TARGET_chsymbol
\text{name_statement1=During a lecture, the professor talks about 4 properties concerning
functions. We use the characters \(A, B, C, D\) to denote these 4 properties.}
\text{name_statement2=The professor proves on the blackboard the following relations between these
4 properties:}
\text{name_thus=From this we conclude that}
#endif

#if defined TARGET_iff || defined TARGET_iff2 || defined TARGET_iff3 || defined TARGET_iff4
\text{name_statement1=Suppose that \(A\) and \(B\) are two propositions.}
\text{name_statement2=If one says that}
\text{name_statement3=this means that}
\text{name_istrue=is true}
\text{name_isfalse=is false}
#endif

#if defined TARGET_iff4
\text{name_nothing=has nothing to do with}
#endif

#if defined TARGET_parity
\text{name_statement=Let \(a\) and \(b\) be two integers.,is,is a,condition for,to be}
\text{name_cases_list=odd,even}
#endif

#if defined TARGET_subset
\text{name_statement=Let \(A\) and \(B\) be two sets, and suppose that
\(A\) is a subset of \(B\).}
\text{name_thus=In this case,}
\text{name_cases_list=belongs to,does not belong to}
#endif

#if defined TARGET_symbol || defined TARGET_symbol2
\text{name_statement=Suppose that \(A\) and \(B\) are two propositions. The symbol}
\text{name_thus=means that}
#endif

#if defined TARGET_symbol2
\text{name_cases_list=holds,does not hold}
#endif
