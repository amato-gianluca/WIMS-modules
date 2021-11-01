\text{name_and=et}
\text{name_or=ou}
\text{name_not=non}

#if defined TARGET_etneg1 || defined TARGET_impneg1
\text{name_statement=Soit P et Q deux propositions logiques. Déterminer la table de vérité de la proposition}
#endif

#if defined TARGET_etneg2 || defined TARGET_impneg2
\text{name_statement1=Soit P et Q deux propositions logiques. On considère une proposition T(P,Q), construite à partir des propositions P et Q, dont la table de vérité est donnée ci-dessous.}
\text{name_statement2=Parmi les propositions suivantes, laquelle est logiquement équivalente à T(P,Q) ?}
#endif

#if defined TARGET_etou1 || defined TARGET_impetou1
\text{name_statement=Soit P, Q et R, trois propositions logiques. Déterminer la table de vérité de la proposition}
#endif

#if defined TARGET_etou2 || defined TARGET_impetou2
\text{name_statement1=Soit P, Q et R, trois propositions logiques. On considère une proposition T(P,Q,R), construite à partir des propositions P, Q et R, dont la table de vérité est donnée ci-dessous.}
\text{name_statement2=Parmi les propositions suivantes, laquelle est logiquement équivalente à T(P,Q,R) ?}
#endif
