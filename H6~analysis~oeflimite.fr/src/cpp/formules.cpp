target=formules

#include "header.inc"
#include "lang_titles.inc"


\text{x = random(x,t)}

\text{listef= \x,\x,\x^2,\x^2,\x^3,\x^3,\x^4,\x^4,e^\x,e^\x,ln(\x),ln(\x)}
\text{listex = + \infty,- \infty,+ \infty,- \infty,+ \infty,- \infty,+ \infty,- \infty,+ \infty,- \infty,+ \infty,0}
\text{listelim = + \infty,- \infty,+ \infty,+ \infty,+ \infty,- \infty,+ \infty,+ \infty,+ \infty,0,+ \infty,- \infty}
\text{listerep = +inf,-inf,+inf,+inf,+inf,-inf,+inf,+inf,+inf,0,+inf,-inf}
\text{qu = shuffle(items(\listef))}


\text{pinf = \(+ \infty)}
\text{minf = \(- \infty)}




#include "lang.inc"

\statement{<table class="wimsnoborder">
\for{k = 1 to 6}{
<tr>
<td>La limite de \(\listef[\qu[\k]]) </td><td>quand \(\x) tend vers \(\listex[\qu[\k]])</td><td> est : </td><td>
\embed{reply\k} </td>
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
