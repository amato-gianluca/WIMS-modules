target=simples

#include "header.inc"
#include "lang_titles.inc"


\text{x = random(x,t)}

\integer{x0 = random(0,randint(-2..2))}
\integer{a = randint(2..10)}
\integer{b=randint(1..10)*random(-1,1)}
\integer{c=randint(-4..4)}
\integer{g = gcd(\a,\b)}
\integer{aa = \a/\g}
\integer{bb = \b/\g}
\rational{rac = -\bb/\aa}
\text{sgmb = \bb > 0? - : +}
\function{linp = random(\a*\x,\x/\a)}
\function{linm = -\linp}
\function{affp = \aa*\x + \bb}
\function{affm = simplify(-(\affp))}
\function{trip = random(\a*\x^2,\x^2/\a,\aa*\x^2 + \bb*\x +\c)}
\function{trim = simplify(-(\trip))}
\function{expp1 = e^(random(\linp,\affp))}
\function{expp2 =  \aa*e^\x + \bb }
\function{expp3 = \aa*e^-\x + \bb}
\function{expm1 = e^(random(\linm,\affm))}
\function{expm2 = -\aa*e^\x + \bb}
\function{expm3 = -\aa*e^-\x + \bb}
\function{prod1 = \x*(random(\expp2,\expm2))}
\function{prod2 = \x*(random(\expp2,\expp1))}
\function{lnp1 = ln(\linp)}
\function{lnm1 = ln(\linm)}
\function{lnp2 = ln(\affp)}
\function{lnm2 = ln(\affm)}
\function{lnp3 = \aa*ln(\x) + \bb}
\function{lnm3 = - \aa*ln(\x) + \bb}

\text{listef= \linp,\linp,\linm,\linm,\affp,\affp,\affm,\affm,
\trip,\trip,\trim,\trim,
\expp1,\expp1,\expp2,\expp2,\expp3,\expp3,
\expm1,\expm1,\expm2,\expm2,\expm3,\expm3,
\prod1,\prod2,
\lnp1,\lnp1,\lnm1,\lnm1,
\lnp2,\lnp2,\lnm2,\lnm2,
\lnp3,\lnp3,\lnm3,\lnm3
}

\text{listex= -\infty, +\infty,-\infty, +\infty,-\infty, +\infty,-\infty, +\infty,
-\infty, +\infty,-\infty, +\infty,
-\infty, +\infty,-\infty, +\infty,-\infty, +\infty,
-\infty, +\infty,-\infty, +\infty,-\infty, +\infty,
-\infty, +\infty,
0, +\infty,0, -\infty,
\rac, +\infty,\rac, -\infty,
0, +\infty,0, +\infty}

\text{listelim = -\infty, +\infty,+\infty, -\infty,-\infty, +\infty,+\infty, -\infty,
+\infty, +\infty,-\infty, -\infty,
0, +\infty,\bb, +\infty,+\infty,\bb,
+\infty, 0,\bb, -\infty,-\infty,\bb,
\sgmb \infty, +\infty,
-\infty, +\infty,-\infty, +\infty,
-\infty, +\infty,-\infty, +\infty,
-\infty, +\infty,+\infty, -\infty}

\text{listerep = -inf, +inf,+inf, -inf,-inf, +inf,+inf, -inf,
+inf, +inf,-inf, -inf,
0, +inf,\bb, +inf,+inf,\bb,
+inf, 0,\bb, -inf,-inf,\bb,
\sgmb inf, +inf,
-inf, +inf,-inf, +inf,
-inf, +inf,-inf, +inf,
-inf, +inf,+inf, -inf}
\text{qu = shuffle(38)}


\text{pinf = \(+ \infty)}
\text{minf = \(- \infty)}



#include "lang.inc"

\statement{<table class="wimsnoborder wimscenter">
\for{k = 1 to 10}{
<tr>
<td>\(\displaystyle{\lim_{\x \to \listex[\qu[\k]]}})\(\listef[\qu[\k]]) </td><td> = </td><td>
\embed{reply\k,7} </td>
</tr>
}</table>
<p><b>Remarque: </b> Si la limite est �gale � \minf, taper <tt>-inf</tt>. Si
elle est �gale � \pinf, taper <tt>+inf</tt>.</p>
}

\answer{}{\listerep[\qu[1]]}{type=raw}{option = nospace}
\answer{}{\listerep[\qu[2]]}{type=raw}{option = nospace}
\answer{}{\listerep[\qu[3]]}{type=raw}{option = nospace}
\answer{}{\listerep[\qu[4]]}{type=raw}{option = nospace}
\answer{}{\listerep[\qu[5]]}{type=raw}{option = nospace}
\answer{}{\listerep[\qu[6]]}{type=raw}{option = nospace}
\answer{}{\listerep[\qu[7]]}{type=raw}{option = nospace}
\answer{}{\listerep[\qu[8]]}{type=raw}{option = nospace}
\answer{}{\listerep[\qu[9]]}{type=raw}{option = nospace}
\answer{}{\listerep[\qu[10]]}{type=raw}{option = nospace}

\feedback{1=1}{<table>
\for{k = 1 to 10}{
<tr>
<td>\(\lim_{\x \to \listex[\qu[\k]]})\(\listef[\qu[\k]]) </td><td> = </td><td>
\(\listelim[\qu[\k]]) </td>
</tr>
}</table>}
