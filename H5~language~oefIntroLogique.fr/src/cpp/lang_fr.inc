\text{ou=ou}
\text{et=et}
\text{si1=s'}
\text{si2=si}
\text{Si1=S'}
\text{Si2=Si}
\text{ssi=si et seulement si}
\text{alors=alors}
\text{oui=oui}
\text{non=non}
\text{non2=non}
\text{spacebeforecolon=&#32;}

#if defined TARGET_connecteursLN
\text{Alist =
il y a grève de bus,
il pleut ce matin,
il fait froid,
il y a du soleil,
il pleut,
je  mange beaucoup de gâteaux,
je suis joyeux,
j'écoute  Radio Latina,
je veux progresser en maths,
je veux perfectionner mon anglais,
je suis enrhumé(e),
elle danse,
tu joues de la guitare,
elle  ne veut pas devenir ingénieur,
vous êtes nuls en maths,
on est triste,
le travail est motivant
}

\text{Blist =
j'arrive en retard au lycée,
je prends mon parapluie,
je mets un pull,
je porte des lunettes noires,
il fait froid,
je grossis,
je ris,
je  danse  la salsa,
je m'entraîne sous WIMS,
je ne vais voir que des films en VO,
ma voix est cassée,
elle court,
tu chantes,
elle veut partir à l'étranger,
vous êtes forts français,
on est amoureux,
la satisfaction est totale
}

\text{nonAlist=
il n'y a pas grève de bus,
il ne pleut pas ce matin,
il ne fait pas froid,
il n'y a pas de soleil,
il ne pleut pas,
je mange peu de gâteaux,
je suis triste,
je n'écoute pas Radio Latina,
je ne veux pas progresser  en maths,
je ne veux pas améliorer mon anglais,
je ne suis pas enrhumé(e),
elle ne danse pas,
tu ne joues pas de la guitare,
elle  veut devenir ingénieur,
vous êtes forts en maths,
on est joyeux,
le travail n'est pas motivant
}

\text{nonBlist=
je n'arrive pas en retard au lycée,
je ne prends pas mon parapluie,
je n'ai pas mis de pull,
je ne porte pas de lunettes noires,
il fait chaud,
je ne grossis pas,
je ne ris pas,
je ne danse pas la salsa,
je ne m'entraîne pas  sous WIMS,
je regarde Lost In Translation en VF,
je parle normalement,
elle ne court pas,
tu ne chantes pas,
elle veut rester en France,
vous êtes nuls en français,
on n'est pas amoureux,
la satisfaction est partielle
}

\text{name_remark=Remarque}
\text{name_statement1=Pour chacune des propositions  suivantes, à gauche, déterminer sa structure logique.}
\text{name_statement2=les propositions peuvent être vraies ou fausses ...}
\text{name_statement3=(Cliquer sur les élements qui se correspondent deux à deux.)}
#endif


#if defined TARGET_deduction
\text{Alist =
il y a grève de bus,
il pleut le matin,
il fait froid,
il y a du soleil,
je  mange beaucoup de gâteaux,
je suis joyeux,
je danse la salsa,
je veux progresser,
je veux améliorer mon anglais,
je suis enrhumé(e)
}

\text{Blist =
j'arrive en retard au lycée,
je prends mon parapluie,
je mets un pull,
je porte des lunettes noires,
je grossis,
je ris,
je n'écoute que Radio Latina,
je m'entraîne sous WIMS ,
je  vois tous les films en VO,
ma voix est cassée
}

\text{nonAlist=
les bus ne sont pas grève,
il ne pleut pas le matin,
il ne faisait pas froid,
il n'y a pas de soleil aujourd'hui,
j'ai mangé peu de gâteaux,
je suis triste,
je n'aime pas la salsa,
je ne veux pas progresser,
je ne veux pas améliorer mon anglais,
je ne suis pas enrhumé(e)
}

\text{nonBlist=
je n'arrive pas en retard au lycée,
je ne prend pas mon  parapluie,
je n'ai pas mis de pull,
je ne porte pas de lunettes noires,
je n'ai pas grossi,
je ne ris pas,
j'ai écouté Fun Radio,
je ne me suis pas entraîné(e) sous WIMS,
je regarde Lost In Translation en VF,
je parle normalement
}

\text{name_statement1=On suppose que l'implication suivante est vraie :}
\text{name_statement2=Quelqu'un me rencontre et constate que :}
\text{name_statement3=Cette personne en déduit que  :}
\text{name_statement4=Son raisonnement est-il valide  ?}
\text{name_answer=Raisonnement juste}
#endif

#if defined TARGET_implication
\text{Quand=Quand}
\text{Chaque=Chaque fois que}
\text{whatif=Sans faire aucune autre hypothèse,que peut-on dire qu'il se passe lorsque}

\text{prem = Mr Alex s'installe devant la télé,
Mme Alice sort se promener dans le parc,
Fred  est dans le parc,Suzy grimpe sur l'arbre,
Nestor  vire-volte dans le parc,
Bubu s'enfouit sous  terre,
Fred  farfouille dans la terre,
Mme Alice est très fâchée}

\text{conc = Mme Alice sort se promener dans le parc,
son chien Fred l'accompagne,
Suzy grimpe sur l'arbre,
Nestor quitte l'arbre pour vire-volter dans le parc,
Bubu  s'enfouit sous  terre,
Fred farfouille dans la terre,
Mme Alice se fâche,
Mr Alex s'installe devant la télé
}

\text{nonPr = Mr Alex ne s'installe pas devant la télé,
Mme Alice ne sort pas se promener dans le parc,
Fred  n'est pas dans le parc,
Suzy ne grimpe pas sur l'arbre,
Nestor  ne  vire-volte pas dans le parc,
Bubu  ne s'enfouit pas sous  terre,
Fred  ne farfouille pas dans la terre,
Mme Alice ne se  fâche pas}

\text{nonCo = Mme Alice ne sort pas se promener dans le parc,
Fred n'accompagne pas Mme Alice,
Suzy ne grimpe pas sur l'arbre,
Nestor ne quitte pas l'arbre pour vire-volter dans le parc,
Bubu ne s'enfouit pas sous  terre,
Fred  ne farfouille pas dans la terre,
Mme Alice ne se fâche pas,
Mr Alex ne s'installe pas devant la télé
}

\text{sujPr=Mr Alex, Mme Alice, Fred le chien, Suzy la chatte, Nestor le moineau, Bubu le ver de terre, Fred le chien, Mme Alice}
\text{sujCo=Mme Alice, Fred le chien, Suzy la chatte, Nestor le moineau, Bubu le ver de terre, Fred le chien, Mme Alice, Mr Alex}
\text{none=on ne peut rien conclure}

\text{name_citation=Cet exercice s'inspire d'un exemple
donné par Alan Selby, dans "Elements
of Reason : understanding and explaining
 reason and math"
Volume 1,
Printed in Canada
ISBN 0-9697564-1-0.
http://whyslopes.com/volume1a/}

\text{Question=Question}
\text{name_characters=Nos personnages sont}
\text{name_statement1=On donne l'implication suivante, qu'on suppose vraie :}
\text{mame_statement2=On donne les implications suivantes, qu'on suppose toutes deux vraies :}
#endif

#if defined TARGET_incoherence
\text{Alist=il est suédois,il est écossais,il est australien,elle est allemande,elle est cubaine, elle est japonaise}
\text{Blist=il joue au tennis,
il joue du biniou, il surfe, elle joue du piano , elle danse la salsa,
elle fait du Kendo}
\text{Clist=il est blond,
il porte une jupe, il ne porte pas de cravate,  elle ne se maquille pas , elle est brune, elle  porte des kimonos}
\text{Dlist=il fait du ski,
il joue du rugby, il passe ses vacances à Bali, elle roule en vélo ,elle adore les maths, elle fait de l'origami}
\text{Elist=il est végétarien,
il est marié, il aime la bière, elle aime la Bratwurst , elle boit de la tequila, elle est célibataire
}

\text{nonAlist= il n'est pas suédois, il n'est pas écossais, il n'est pas australien, elle n'est pas allemande , elle n'est pas cubaine, elle n'est pas japonaise}
\text{nonBlist =il ne joue pas au tennis,
il ne joue pas du biniou , il ne  surfe pas , elle ne joue pas du piano , elle ne danse pas la salsa, elle ne fait pas Kendo}
\text{nonClist= il n'est pas blond,
il ne porte pas de jupe, il porte  une cravate, elle se maquille , elle n'est pas brune, elle ne porte pas de kimono }
\text{nonDlist= il ne fait pas de ski,
il ne joue pas du rugby, il ne passe pas ses vacances à Bali, elle ne roule pas en vélo , elle déteste les maths, elle ne fait pas de l'origami}
\text{nonElist=il n'est pas végétarien,
il est célibataire, il n'aime pas la bière, elle n'aime pas la Bratwurst, elle ne boit pas de tequila, elle est mariée}

\text{name_statement1=Pour adhérer à un club de loisir}
\text{name_statement2=masculin, tout candidat est censé}
\text{name_statement3=féminin, toute candidate est censée}
\text{name_statement4=remplir chacune des conditions suivantes :}

\text{name_question1=Cochez dans la liste suivante une proposition \(A\), qui devrait être}
\text{name_question2=à la fois vraie et fausse}
\text{name_question3=et ce,}
\text{name_question4=dans toute interprétation}
\text{name_question5=où les conditions du règlement seraient simultanément vraies.}
\text{name_question6=Cela prouve par l'absurde que les conditions du règlement sont incompatibles.}

\text{\name_remark=Remarque :  vous devez, tel  Sherlock Holmes, savoir envisager tous les cas et pister toutes les déductions ...}
\text{Contradiction=Contradiction}

\text{\name_cases=Faire une analyse de cas}
\text{\name_case1=considerez  les interprétations dans laquelleles conditions du règlement soient toutes vraies ;}
\text{\name_case2=envisagez les différents cas, et pour chacun affectez les valeurs de vérité aux différentes propositions élémentaires ;}
\text{\name_case3=trouvez \(A) telle que, dans toute interprétation,   \(A) devrait être vraie et fausse à la fois ;}
\text{\name_casesend=Ceci prouve par l'absurde qu'il n'existe aucune interprétation rendant simultanément vraies  toutes les conditions du règlement.}

\text{Exemple=Exemple}
\text{name_example1=Supposons que les conditions suivantes soient simultanément vraies  :}
\text{name_example2=\(P_1) donne à distinguer deux cas : ou bien \(A) est vrai ou bien \(B) est vrai.}
\text{name_example3=Si \(A) est vrai et \(B) quelconque :  par \(P_2) et \(P_4) on déduit que  C est nécessairement vrai ; par \(P_3)
on déduit alors que \(A) est faux.}
\text{name_example4=Si \(A) est faux et donc \(B) est vrai :  par \(P_4) on déduit que \(A) est vrai.}
\text{name_example5=Dans tous les cas, \(A) devrait donc être à la fois vrai et faux. Ceci est  absurde.  Il n'existe donc
aucune interprétation dans laquelle \(P_1), \(P_2) et \(P_3) soient simultanément vraies.  On dit que \(P_1), \(P_2) et \(P_3) sont incompatibles.}
#endif


#if defined TARGET_negationLN
#endif

#if defined TARGET_negationMath
#endif

#if defined TARGET_reciproque
#endif

#if defined TARGET_tautologie
#endif

#if defined TARGET_valeursVerite
#endif

#if defined TARGET_validite
#endif

