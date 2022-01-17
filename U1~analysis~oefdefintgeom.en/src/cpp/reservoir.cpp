target=reservoir

#include "header.inc"
#include "lang_titles.inc"

\language{en}

\real{dia=round(random(40..70))/10}
\real{normal=round(random(\dia*7..\dia*9))/10}
\real{now=round(random(\normal*4..\normal*7))/10}
\real{a=\now-\dia/2}
\real{b=\normal-\dia/2}
\real{sol=pi*((\b-\a)*\dia^2/4-(\b^3-\a^3)/3)}



#include "lang.inc"

\statement{A factory has a water reservoir under the form of a ball of 
\dia meters of (internal) diameter.
The usual water level is of \normal meters above the bottom of the 
reservoir. One day, due to a system breakdown, this level has dropped
to \now meters. How many cubic meters of water should be pumped into
the reservoir, in order to get it back to the usual level?}

\answer{Cubic meters}{\sol}

