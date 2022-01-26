target=formules02

#include "header.inc"
#include "lang_titles.inc"


\text{x = random(x,t)}

\text{listef= \x,\x,\x^2,\x^2,\x^3,\x^3,\x^4,\x^4,\sqrt{\x},\sqrt{\x},1/\x,1/\x,1/\x,1/\x,1/\x^2,1/\x^2,1/\x^2}
\text{listex = + \infty,- \infty,+ \infty,- \infty,+ \infty,- \infty,+ \infty,- \infty,+ \infty,0,+ \infty,- \infty,0+ ,0-,+ \infty,- \infty,0 }
\text{listelim = + \infty,- \infty,+ \infty,+ \infty,+ \infty,- \infty,+ \infty,+ \infty,+ \infty,0,0,0,+ \infty,- \infty,0 ,0,+ \infty}
\text{listerep = +inf,-inf,+inf,+inf,+inf,-inf,+inf,+inf,+inf,0,0,0,+inf,-inf,0,0,+inf}
\text{qu = shuffle(items(\listef))}


\text{pinf = \(+ \infty)}
\text{minf = \(- \infty)}



#include "lang.inc"

\statement{<table class="wimsnoborder wimscenter">
\for{k = 1 to 6}{
<tr>
<td>\(\displaystyle{\lim_{\x \to \listex[\qu[\k]]}\listef[\qu[\k]]}) </td><td> = </td><td>
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