## Building
Compiling with `-Ofast` is strongly recommended.
## References
Nilsson's original paper on space-efficient [Kolakoski sequence](https://en.wikipedia.org/wiki/Kolakoski_sequence) computation can be found [here](https://www.emis.de/journals/JIS/VOL15/Nilsson/nilsson5.pdf) in the Journal of Integer Sequences. This program tests the conjecture that exactly half of the sequence's terms are ones using its first $n = 3\cdot10^8$ values. This $n$ is the first term count appearing in a [published paper](https://www.emis.de/journals/JIS/VOL9/Steinsky/steinsky5.pdf) on this sequence that also involved brute-force computation. Finding the number of ones for any $n$ may be done by changing the value of a constant `TERM_CNT` in the source code.
