$$
\begin{align}
[\text{exit}] &\to exit([\text{expr}])
\\
[\text{expr}] &\to \text{num\_lit:[add]:[mul]}
\\
[\text{add}] &\to \text{num\_lit+num\_lit:[add]:[mul]}
\\
[\text{mul}] &\to \text{num\_lit*num\_lit:[mul]}
\end{align}
$$