#define NECSUF necessary and sufficient
#define NEC necessary (only)
#define SUF sufficient (only)
#define NEC2 necessary (only)
#define SUF2 sufficient (only)
#define NONNECSUF neither necessary nor sufficient
#define IFF if and only if
#define IF if
#define ONLYIF only if
#define NONIFONLYIF neither if nor only if
#define PERNON perhaps neither necessary nor sufficient

#if defined TARGET_3func
#define STATEMENT \
We have 3 real functions: <i>f</i>(x), <i>g</i>(x) and \
<i>h</i>(x).\
<p>\
For a same value of x, <i>\f1</i>(x)&gt;0 is a \c1 condition \
for <i>\f2</i>(x)&gt;0, and <i>\g1</i>(x)&gt;0 is a \c2 condition \
for <i>\g2</i>(x)&gt;0.\
<p>\
Consequently, <i>\tf</i>(x)&gt;0 \
is a ____________&nbsp;condition for <i>\th</i>(x)&gt;0.
#endif

#if defined TARGET_3func2
#define STATEMENT \
We have 3 real functions: <i>f</i>(x), <i>g</i>(x) and \
<i>h</i>(x).\
<p>\
For a same value of x, <i>\f1</i>(x)&lt;0 \c1 \
<i>\f2</i>(x)&lt;0, and <i>\g1</i>(x)&lt;0 \c2 <i>\g2</i>(x)&lt;0. \
<p>
Consequently, <i>\tf</i>(x)&lt;0 \
____________ <i>\th</i>(x)&lt;0.
#endif

#if defined TARGET_chsymbol
#define STATEMENT \
During a lecture, the professor talks about 4 properties concerning \
functions. We use the characters <i>A,B,C,D</i> to denote these 4 properties.\
<p>\
The professor proves on the blackboard the following relations between these \
4 properties:<p><center>\
<i>A</i>&nbsp;\s1&nbsp;<i>B</i>&nbsp;\s2&nbsp;<i>C</i>&nbsp;\s3&nbsp;<i>D</i>\
</center> <p>\
From this we conclude that \
<i>\gA</i> is a ____________&nbsp;condition of <i>\gB</i>.
#endif

#if defined TARGET_iff
#define STATEMENT \
Suppose that <i>A</i> and <i>B</i> are two propositions. \
If one says that <i>A</i> is true \sign <i>B</i> is true, \
this means that \
<i>\gA</i> is a ____________&nbsp;condition of <i>\gB</i>.
#endif

#if defined TARGET_iff2
#define STATEMENT \
Suppose that <i>A</i> and <i>B</i> are two propositions. \
If one says that <i>A</i> is a \good condition of <i>B</i>, \
this means that \
<i>\gA</i> is true ____________ <i>\gB</i> is true.
#endif

#if defined TARGET_iff3
#define STATEMENT \
Suppose that <i>A</i> and <i>B</i> are two propositions. \
If one says that <i>A</i> is false \sign <i>B</i> is false, \
this means that \
<i>\gA</i> is a ____________&nbsp;condition of <i>\gB</i>.
#endif

#if defined TARGET_iff4
#define STATEMENT \
Suppose that <i>A</i> and <i>B</i> are two propositions. \
If one says that <i>A</i> is a \good condition of <i>B</i>, \
this means that \
<i>\gA</i> is false ____________ <i>\gB</i> is false.
#define NOTHING has nothing to do with
#endif

#if defined TARGET_parity
#define ODD odd
#define EVEN even
#define STATEMENT \
Let <i>a</i> and <i>b</i> be two integers. \
<p>\
"\t1 is \parity" \
is a ____________&nbsp;condition for \
\t2 to be \parity2.
#endif

#if defined TARGET_subset
#define BELONGS belongs
#define NBELONGS does not belong
#define STATEMENT \
Let <i>A</i> and <i>B</i> be two sets, and suppose that \
<i>A</i> is a subset of <i>B</i>.\
<p>In this case, an element <i>a</i> \atext to <i>\gA</i> \
is a ____________&nbsp;condition for that \
<i>a</i> \btext to <i>\gB</i>.
#endif

#if defined TARGET_symbol
#define STATEMENT \
Suppose that <i>A</i> and <i>B</i> are two propositions. \
The symbol\
<p><center><i>A</i>&nbsp;\sign&nbsp;<i>B</i></center> <p>\
means that \
<i>\gA</i> is a ____________&nbsp;condition of <i>\gB</i>.
#endif

#if defined TARGET_symbol2
#define HOLDS holds
#define NHOLDS does not hold
#define STATEMENT \
Suppose that <i>A</i> and <i>B</i> are two propositions. \
The symbol\
<p><center><i>A</i>&nbsp;\sign&nbsp;<i>B</i></center> <p>\
means that \
<i>\gA</i> \ttext ____________ <i>\gB</i> \ttext.
#endif
