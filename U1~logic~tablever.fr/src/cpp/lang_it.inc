#define AND e
#define OR o
#define NOT non

#if defined TARGET_etneg1 || defined TARGET_impneg1
#define STATEMENT Siano P e Q due proposizioni. Determinare la tabella di verità della forma proposizionale
#endif

#if defined TARGET_etneg2 || defined TARGET_impneg2
#define STATEMENT1 Siano P e Q due proposizioni. Si consideri la forma proposizionale T(P,Q), costruita a partire dalle proposizioni P e Q, la cui tabella di verità è indicata di seguito.
#define STATEMENT2 Quale delle seguenti forme proposizionali è logicamente equivalente a T(P,Q) ?
#endif

#if defined TARGET_etou1 || defined TARGET_impetou1
#define STATEMENT Siano P e Q tre proposizioni. Determinare la tabella di verità della forma proposizionale
#endif

#if defined TARGET_etou2 || defined TARGET_impetou2
#define STATEMENT1 Siano P, Q ed R tre proposizioni. Si consideri la forma proposizionale T(P,Q,R), costruita a partire dalle proposizioni P, Q ed R, la cui tabella di verità è indicata di seguito.
#define STATEMENT2 Quale delle seguenti forme proposizionali è logicamente equivalente a T(P,Q,R) ?
#endif
