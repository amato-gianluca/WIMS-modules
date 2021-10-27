#define NECSUF necessaria e sufficiente
#define NEC necessaria (solo)
#define SUF sufficiente (solo)
#define NEC2 necessaria
#define SUF2 sufficiente
#define NONNECSUF né necessaria né sufficiente
#define IFF se e solo se
#define IF se
#define ONLYIF solo se
#define NONIFONLYIF né se né solo se
#define PERNON probabilmente né necessaria né sufficiente

#if defined TARGET_3func
#define STATEMENT \
Abbiamo tre funzioni reali: <i>f</i>(x), <i>g</i>(x) e \
<i>h</i>(x).\
<p>\
Per lo stesso valore di x, <i>\f1</i>(x)&gt;0 è una condizione \c1 \
per <i>\f2</i>(x)&gt;0, e <i>\g1</i>(x)&gt;0 è una condizione \c2 \
per <i>\g2</i>(x)&gt;0.\
<p>\
Pertanto, <i>\tf</i>(x)&gt;0 \
è una condizione ____________&nbsp;per <i>\th</i>(x)&gt;0.
#endif

#if defined TARGET_3func2
#define STATEMENT \
Abbiamo tre funzioni reali: <i>f</i>(x), <i>g</i>(x) and \
<i>h</i>(x).\
<p>\
Per lo stesso valore di x, <i>\f1</i>(x)&lt;0 \c1 \
<i>\f2</i>(x)&lt;0, e <i>\g1</i>(x)&lt;0 \c2 <i>\g2</i>(x)&lt;0. \
<p>
Pertanto, <i>\tf</i>(x)&lt;0 \
____________ <i>\th</i>(x)&lt;0.
#endif

#if defined TARGET_chsymbol
#define STATEMENT \
Durante una lezione, il professore parla di 4 proprietà riguardanti \
le funzioni. Usiamo le lettere <i>A,B,C,D</i> per indicare queste 4 proprietà.\
<p>\
Il professore dimostra alla lavagna le seguenti relazioni tra queste \
4 proprietà:<p><center>\
<i>A</i>&nbsp;\s1&nbsp;<i>B</i>&nbsp;\s2&nbsp;<i>C</i>&nbsp;\s3&nbsp;<i>D</i>\
</center> <p>\
Da questo concludiamo che \
<i>\gA</i> è una condizione ____________&nbsp;per <i>\gB</i>.
#endif

#if defined TARGET_iff
#define STATEMENT \
Supponiamo che <i>A</i> e <i>B</i> siano due proposizioni. \
Se diciamo che <i>A</i> è vera \sign <i>B</i> è vera, \
qiuesto significa che \
<i>\gA</i> è una condizione ____________&nbsp;per <i>\gB</i>.
#endif

#if defined TARGET_iff2
#define STATEMENT \
Supponiamo che <i>A</i> e <i>B</i> siano due proposizioni. \
Se diciamo che <i>A</i> è una condizione \good per <i>B</i>, \
questo singifica che \
<i>\gA</i> è vera ____________ <i>\gB</i> è vera.
#endif

#if defined TARGET_iff3
#define STATEMENT \
Supponiamo che <i>A</i> e <i>B</i> siano due proposizioni. \
Se diciamo che <i>A</i> è falsa \sign <i>B</i> è falsa, \
questo significa che \
<i>\gA</i> è una condizione ____________&nbsp;per <i>\gB</i>.
#endif

#if defined TARGET_iff4
#define STATEMENT \
Supponiamo che <i>A</i> e <i>B</i> siano due proposizioni. \
Se diciamo che <i>A</i> è una condizione \good per <i>B</i>, \
questo signifcia che \
<i>\gA</i> è falsa ____________ <i>\gB</i> è falsa.
#define NOTHING non ha niente a che vedere con
#endif

#if defined TARGET_parity
#define ODD dispari
#define EVEN pari
#define STATEMENT \
Siano <i>a</i> e <i>b</i> due interi. \
<p>\
"\t1 è \parity" \
è una condizione ____________&nbsp;perché \
\t2 sia \parity2.
#endif

#if defined TARGET_subset
#define BELONGS appartiene
#define NBELONGS non appartiene
#define STATEMENT \
Siano <i>A</i> e <i>B</i> due insisemi, e supponiamo che \
<i>A</i> sia un sottoinsieme di <i>B</i>.\
<p>In questo caso, <i>a</i> \atext a <i>\gA</i> \
è una condizione ____________&nbsp;per \
<i>a</i> \btext a <i>\gB</i>.
#endif

#if defined TARGET_symbol
#define STATEMENT \
Supponiamo che <i>A</i> e <i>B</i> siano due proposizioni. \
Il simbolo\
<p><center><i>A</i>&nbsp;\sign&nbsp;<i>B</i></center> <p>\
significa che \
<i>\gA</i> è una condizione ____________&nbsp;per <i>\gB</i>.
#endif

#if defined TARGET_symbol2
#define HOLDS vale
#define NHOLDS non vale
#define STATEMENT \
Supponiamo che <i>A</i> e <i>B</i> siano due proposizioni. \
Il simbolo\
<p><center><i>A</i>&nbsp;\sign&nbsp;<i>B</i></center> <p>\
significa che \
<i>\gA</i> \ttext ____________ <i>\gB</i> \ttext.
#endif
